﻿using Rhisis.Core.Common;
using Rhisis.Core.Data;
using Rhisis.Core.Resources.Include;
using Rhisis.Core.Structures.Game.Quests;
using Rhisis.Scripting.Quests;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Rhisis.CLI.Commands.Game.Quests
{
    internal class LegacyQuestLoader
    {
        private readonly List<QuestData> _quests;

        /// <summary>
        /// Gets the quests.
        /// </summary>
        public IEnumerable<QuestData> Quests => _quests;

        /// <summary>
        /// Creates a new <see cref="LegacyQuestLoader"/> instance.
        /// </summary>
        public LegacyQuestLoader()
        {
            _quests = new List<QuestData>();
        }

        /// <summary>
        /// Loads an official quest property file.
        /// </summary>
        /// <param name="filePath">Official quest property file path.</param>
        public void Load(string filePath)
        {
            using var questIncludeFile = new IncludeFile(filePath);

            foreach (IStatement questStatement in questIncludeFile.Statements)
            {
                if (!(questStatement is Block questBlock))
                    continue;

                QuestData quest = CreateQuest(questBlock);

                if (IsQuestValid(quest))
                    _quests.Add(quest);
            }
        }

        /// <summary>
        /// Creates a new <see cref="QuestData"/> based on an official quest block instruction.
        /// </summary>
        /// <param name="questBlock"></param>
        /// <returns></returns>
        private QuestData CreateQuest(Block questBlock)
        {
            var quest = new QuestData
            {
                Name = int.TryParse(questBlock.Name, out int _) ? $"{QuestScriptConstants.QuestPrefix}{questBlock.Name}" : questBlock.Name,
                Title = questBlock.GetInstruction("SetTitle")?.GetParameter<string>(0)
            };

            Block questSettingsBlock = questBlock.GetBlockByName("setting");

            if (questSettingsBlock != null)
            {
                quest.StartCharacter = questSettingsBlock.GetInstruction("SetCharacter")?.GetParameter<string>(0);
                quest.EndCharacter = questSettingsBlock.GetInstruction("SetEndCondCharacter")?.GetParameter<string>(0);
                quest.MinLevel = questSettingsBlock.GetInstruction("SetBeginCondLevel")?.GetParameter<int>(0) ?? default;
                quest.MaxLevel = questSettingsBlock.GetInstruction("SetBeginCondLevel")?.GetParameter<int>(1) ?? default;
                quest.StartJobs = questSettingsBlock.GetInstruction("SetBeginCondJob")?.Parameters.Select(x => x.ToString()).ToArray();
                quest.PreviousQuestId = questSettingsBlock.GetInstruction("SetBeginCondPreviousQuest")?.GetParameter<string>(1) ?? default;

                LoadEndConditions(quest, questSettingsBlock);
                LoadQuestRewards(quest, questSettingsBlock);
            }

            LoadQuestDialogs(quest, questBlock);

            return quest;
        }

        private void LoadEndConditions(QuestData quest, Block settingsBlock)
        {
            // Load items
            IEnumerable<Instruction> questEndItems = settingsBlock.GetInstructions("SetEndCondItem");

            if (questEndItems != null && questEndItems.Any())
            {
                IEnumerable<QuestItem> itemsToRemove = settingsBlock.GetInstructions("SetEndRemoveItem").Select(x => new QuestItem
                {
                    Id = x.GetParameter<string>(1)
                });

                quest.EndQuestItems = questEndItems.Select(x => new QuestItem
                {
                    Sex = x.GetParameter<GenderType>(0),
                    Id = x.GetParameter<string>(3),
                    Quantity = x.GetParameter<int>(4),
                    Remove = itemsToRemove.Any(y => y.Id == x.GetParameter<string>(3))
                }).ToList();
            }

            // Load kill monsters

            IEnumerable<Instruction> questKillNpcs = settingsBlock.GetInstructions("SetEndCondKillNPC");

            if (questKillNpcs != null && questKillNpcs.Any())
            {
                quest.EndQuestMonsters = questKillNpcs.OrderBy(x => x.GetParameter<int>(0)).Select(x => new QuestMonster
                {
                    Id = x.GetParameter<string>(1),
                    Amount = x.GetParameter<int>(2)
                });
            }

            // Load patrols

            IEnumerable<Instruction> questPatrols = settingsBlock.GetInstructions("SetEndCondPatrolZone");

            if (questPatrols != null && questPatrols.Any())
            {
                quest.EndQuestPatrols = questPatrols.Select(x => new QuestPatrol
                {
                    MapId = x.GetParameter<string>(0),
                    Left = x.GetParameter<int>(1),
                    Top = x.GetParameter<int>(2),
                    Right = x.GetParameter<int>(3),
                    Bottom = x.GetParameter<int>(4)
                });
            }
        }

        private void LoadQuestRewards(QuestData quest, Block settingsBlock)
        {
            quest.MinGold = settingsBlock.GetInstruction("SetEndRewardGold")?.GetParameter<int>(0) ?? default;
            quest.MaxGold = settingsBlock.GetInstruction("SetEndRewardGold")?.GetParameter<int>(1) ?? default;

            // Load items
            IEnumerable<Instruction> questRewardItems = settingsBlock.GetInstructions("SetEndRewardItem");

            if (questRewardItems != null && questRewardItems.Any())
            {
                quest.RewardItems = questRewardItems.Select(x => new QuestItem
                {
                    Sex = x.GetParameter<GenderType>(0),
                    Id = x.GetParameter<string>(3),
                    Quantity = x.GetParameter<int>(4)
                }).ToList();
            }
        }

        private void LoadQuestDialogs(QuestData quest, Block questBlock)
        {
            IDictionary<QuestDialogKeys, string> dialogs = (from x in questBlock.Statements
                                                            where x.Name == "SetDialog" && x.Type == StatementType.Instruction
                                                            let instruction = x as Instruction
                                                            select KeyValuePair.Create(
                                                                (QuestDialogKeys)Enum.Parse(typeof(QuestDialogKeys), instruction.GetParameter<string>(0)),
                                                                instruction.GetParameter<string>(1))
                                                            ).ToDictionary(x => x.Key, x => x.Value);

            if (dialogs.Any())
            {
                quest.BeginDialogs = dialogs.Where(x => x.Key >= QuestDialogKeys.QSAY_BEGIN1 && x.Key <= QuestDialogKeys.QSAY_BEGIN5).Select(x => x.Value).ToArray();
                quest.AcceptDialogs = dialogs.Where(x => x.Key == QuestDialogKeys.QSAY_BEGIN_YES).Select(x => x.Value).ToArray();
                quest.DeclinedDialogs = dialogs.Where(x => x.Key == QuestDialogKeys.QSAY_BEGIN_NO).Select(x => x.Value).ToArray();
                quest.FailureDialogs = dialogs.Where(x => x.Key >= QuestDialogKeys.QSAY_END_FAILURE1 && x.Key <= QuestDialogKeys.QSAY_END_FAILURE3).Select(x => x.Value).ToArray();
                quest.CompletedDialogs = dialogs.Where(x => x.Key >= QuestDialogKeys.QSAY_END_COMPLETE1 && x.Key <= QuestDialogKeys.QSAY_END_COMPLETE3).Select(x => x.Value).ToArray();
            }
        }

        private bool IsQuestValid(QuestData quest)
        {
            if (string.IsNullOrEmpty(quest.StartCharacter))
            {
                Console.WriteLine($"{quest.Name}: Start charcter is missing.");
                return false;
            }

            if (quest.StartJobs == null || (quest.StartJobs != null && !quest.StartJobs.Any()))
            {
                Console.WriteLine($"{quest.Name}: A quest must be linked to a job.");
                return false;
            }

            if (quest.MinLevel <= 0 || quest.MaxLevel <= 0)
            {
                Console.WriteLine($"{quest.Name}: A quest must have a min level and a max level.");
                return false;
            }

            return true;
        }
    }
}
