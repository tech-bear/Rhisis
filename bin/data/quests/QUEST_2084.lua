QUEST_2084 = {
	title = 'IDS_PROPQUEST_REQUESTBOX_INC_000925',
	character = 'MaDa_Lurif',
	end_character = 'MaDa_Lurif',
	start_requirements = {
		min_level = 115,
		max_level = 121,
		job = { 'JOB_KNIGHT', 'JOB_BLADE', 'JOB_JESTER', 'JOB_RANGER', 'JOB_RINGMASTER', 'JOB_BILLPOSTER', 'JOB_PSYCHIKEEPER', 'JOB_ELEMENTOR', 'JOB_KNIGHT_MASTER', 'JOB_BLADE_MASTER', 'JOB_JESTER_MASTER', 'JOB_RANGER_MASTER', 'JOB_RINGMASTER_MASTER', 'JOB_BILLPOSTER_MASTER', 'JOB_PSYCHIKEEPER_MASTER', 'JOB_ELEMENTOR_MASTER', 'JOB_KNIGHT_HERO', 'JOB_BLADE_HERO', 'JOB_JESTER_HERO', 'JOB_RANGER_HERO', 'JOB_RINGMASTER_HERO', 'JOB_BILLPOSTER_HERO', 'JOB_PSYCHIKEEPER_HERO', 'JOB_ELEMENTOR_HERO' },
		previous_quest = '',
	},
	rewards = {
		gold = 2200000,
		exp = 1377910975,
	},
	end_conditions = {
		items = {
			{ id = 'II_GEN_GEM_GEM_DRAGONCANINE', quantity = 100, sex = 'Any', remove = true },
		},
	},
	dialogs = {
		begin = {
			'IDS_PROPQUEST_REQUESTBOX_INC_000926',
		},
		begin_yes = {
			'IDS_PROPQUEST_REQUESTBOX_INC_000927',
		},
		begin_no = {
			'IDS_PROPQUEST_REQUESTBOX_INC_000928',
		},
		completed = {
			'IDS_PROPQUEST_REQUESTBOX_INC_000929',
		},
		not_finished = {
			'IDS_PROPQUEST_REQUESTBOX_INC_000930',
		},
	}
}
