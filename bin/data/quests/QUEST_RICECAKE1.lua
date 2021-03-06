QUEST_RICECAKE1 = {
	title = 'IDS_PROPQUEST_INC_001811',
	character = 'MaFl_Iblis01',
	end_character = '',
	start_requirements = {
		min_level = 1,
		max_level = 129,
		job = { 'JOB_VAGRANT', 'JOB_MERCENARY', 'JOB_ACROBAT', 'JOB_ASSIST', 'JOB_MAGICIAN', 'JOB_KNIGHT', 'JOB_BLADE', 'JOB_JESTER', 'JOB_RANGER', 'JOB_RINGMASTER', 'JOB_BILLPOSTER', 'JOB_PSYCHIKEEPER', 'JOB_ELEMENTOR' },
		previous_quest = '',
	},
	rewards = {
		gold = 0,
		exp = 0,
		items = {
			{ id = 'II_SYS_SYS_EVE_REDBALL', quantity = 1, sex = 'Any' },
		},
	},
	end_conditions = {
		items = {
			{ id = 'II_SYS_SYS_EVE_SONGPYUN', quantity = 1000, sex = 'Any', remove = true },
		},
	},
	dialogs = {
		begin = {
			'IDS_PROPQUEST_INC_001812',
			'IDS_PROPQUEST_INC_001813',
		},
		begin_yes = {
			'IDS_PROPQUEST_INC_001814',
		},
		begin_no = {
			'IDS_PROPQUEST_INC_001815',
		},
		completed = {
			'IDS_PROPQUEST_INC_001816',
		},
		not_finished = {
			'IDS_PROPQUEST_INC_001817',
		},
	}
}
