QUEST_SCENARIO1_2 = {
	title = 'IDS_PROPQUEST_SCENARIO_INC_000035',
	character = 'MaFl_Roji',
	end_character = 'MaFl_Zaikun',
	start_requirements = {
		min_level = 15,
		max_level = 129,
		job = { 'JOB_VAGRANT', 'JOB_MERCENARY', 'JOB_ACROBAT', 'JOB_ASSIST', 'JOB_MAGICIAN', 'JOB_KNIGHT', 'JOB_BLADE', 'JOB_JESTER', 'JOB_RANGER', 'JOB_RINGMASTER', 'JOB_BILLPOSTER', 'JOB_PSYCHIKEEPER', 'JOB_ELEMENTOR', 'JOB_KNIGHT_MASTER', 'JOB_BLADE_MASTER', 'JOB_JESTER_MASTER', 'JOB_RANGER_MASTER', 'JOB_RINGMASTER_MASTER', 'JOB_BILLPOSTER_MASTER', 'JOB_PSYCHIKEEPER_MASTER', 'JOB_ELEMENTOR_MASTER', 'JOB_KNIGHT_HERO', 'JOB_BLADE_HERO', 'JOB_JESTER_HERO', 'JOB_RANGER_HERO', 'JOB_RINGMASTER_HERO', 'JOB_BILLPOSTER_HERO', 'JOB_PSYCHIKEEPER_HERO', 'JOB_ELEMENTOR_HERO' },
		previous_quest = 'QUEST_SCENARIO1',
	},
	rewards = {
		gold = 0,
		exp = 0,
	},
	end_conditions = {
		items = {
			{ id = 'II_SYS_SYS_QUE_RATTOOTH', quantity = 50, sex = 'Any', remove = false },
		},
	},
	dialogs = {
		begin = {
			'IDS_PROPQUEST_SCENARIO_INC_000036',
			'IDS_PROPQUEST_SCENARIO_INC_000037',
			'IDS_PROPQUEST_SCENARIO_INC_000038',
			'IDS_PROPQUEST_SCENARIO_INC_000039',
			'IDS_PROPQUEST_SCENARIO_INC_000040',
		},
		begin_yes = {
			'IDS_PROPQUEST_SCENARIO_INC_000041',
		},
		begin_no = {
			'IDS_PROPQUEST_SCENARIO_INC_000042',
		},
		completed = {
			'IDS_PROPQUEST_SCENARIO_INC_000043',
			'IDS_PROPQUEST_SCENARIO_INC_000044',
			'IDS_PROPQUEST_SCENARIO_INC_000045',
		},
		not_finished = {
			'IDS_PROPQUEST_SCENARIO_INC_000046',
		},
	}
}
