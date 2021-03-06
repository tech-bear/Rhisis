QUEST_SCE_MYSTGEM = {
	title = 'IDS_PROPQUEST_SCENARIO_INC_000427',
	character = 'MaSa_Gothante',
	end_character = 'MaSa_Gothante',
	start_requirements = {
		min_level = 20,
		max_level = 129,
		job = { 'JOB_VAGRANT', 'JOB_MERCENARY', 'JOB_ACROBAT', 'JOB_ASSIST', 'JOB_MAGICIAN', 'JOB_KNIGHT', 'JOB_BLADE', 'JOB_JESTER', 'JOB_RANGER', 'JOB_RINGMASTER', 'JOB_BILLPOSTER', 'JOB_PSYCHIKEEPER', 'JOB_ELEMENTOR', 'JOB_KNIGHT_MASTER', 'JOB_BLADE_MASTER', 'JOB_JESTER_MASTER', 'JOB_RANGER_MASTER', 'JOB_RINGMASTER_MASTER', 'JOB_BILLPOSTER_MASTER', 'JOB_PSYCHIKEEPER_MASTER', 'JOB_ELEMENTOR_MASTER', 'JOB_KNIGHT_HERO', 'JOB_BLADE_HERO', 'JOB_JESTER_HERO', 'JOB_RANGER_HERO', 'JOB_RINGMASTER_HERO', 'JOB_BILLPOSTER_HERO', 'JOB_PSYCHIKEEPER_HERO', 'JOB_ELEMENTOR_HERO' },
		previous_quest = 'QUEST_SCE_SCEALTAR',
	},
	rewards = {
		gold = 0,
		exp = 3435,
	},
	end_conditions = {
		items = {
			{ id = 'II_SYS_SYS_QUE_MYSTGEMB', quantity = 1, sex = 'Any', remove = false },
			{ id = 'II_SYS_SYS_QUE_MYSTGEMR', quantity = 1, sex = 'Any', remove = false },
		},
	},
	dialogs = {
		begin = {
			'IDS_PROPQUEST_SCENARIO_INC_000428',
			'IDS_PROPQUEST_SCENARIO_INC_000429',
			'IDS_PROPQUEST_SCENARIO_INC_000430',
			'IDS_PROPQUEST_SCENARIO_INC_000431',
			'IDS_PROPQUEST_SCENARIO_INC_000432',
		},
		begin_yes = {
			'IDS_PROPQUEST_SCENARIO_INC_000433',
		},
		begin_no = {
			'IDS_PROPQUEST_SCENARIO_INC_000434',
		},
		completed = {
			'IDS_PROPQUEST_SCENARIO_INC_000435',
			'IDS_PROPQUEST_SCENARIO_INC_000436',
			'IDS_PROPQUEST_SCENARIO_INC_000437',
		},
		not_finished = {
			'IDS_PROPQUEST_SCENARIO_INC_000438',
		},
	}
}
