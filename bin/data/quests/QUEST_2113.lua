QUEST_2113 = {
	title = 'IDS_PROPQUEST_REQUESTBOX_INC_001252',
	character = 'MaHa_Jano',
	end_character = 'MaHa_Jano',
	start_requirements = {
		min_level = 121,
		max_level = 129,
		job = { 'JOB_KNIGHT_HERO', 'JOB_BLADE_HERO', 'JOB_JESTER_HERO', 'JOB_RANGER_HERO', 'JOB_RINGMASTER_HERO', 'JOB_BILLPOSTER_HERO', 'JOB_PSYCHIKEEPER_HERO', 'JOB_ELEMENTOR_HERO' },
		previous_quest = '',
	},
	rewards = {
		gold = 0,
		exp = 1231217351,
	},
	end_conditions = {
		items = {
			{ id = 'II_GEN_GEM_GEM_GRIFFINFEATHER', quantity = 50, sex = 'Any', remove = true },
		},
	},
	dialogs = {
		begin = {
			'IDS_PROPQUEST_REQUESTBOX_INC_001253',
			'IDS_PROPQUEST_REQUESTBOX_INC_001254',
		},
		begin_yes = {
			'IDS_PROPQUEST_REQUESTBOX_INC_001255',
		},
		begin_no = {
			'IDS_PROPQUEST_REQUESTBOX_INC_001256',
		},
		completed = {
			'IDS_PROPQUEST_REQUESTBOX_INC_001257',
		},
		not_finished = {
			'IDS_PROPQUEST_REQUESTBOX_INC_001258',
		},
	}
}
