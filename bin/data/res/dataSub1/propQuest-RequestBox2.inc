//이 파일 수정 시에 절대 EditPlus를 사용하시지 마십시요.
//유니코드 부분에 충돌이 있습니다.
//메모장을 사용하여 주십시요.
/*
	주의 !!!!!!!!!!!!!!!!!!!!!!!!!!!!! SetLinkCharacter -> SetCharacter로 변경
	SetRemove( bTureOrFalse ); // 0이면 삭제하지 않는다. 1이면 삭제(1이 디폴트)
	SetRepeat( bRepeat ) // 1이면 무한 반복 퀘스트
 	nComp : 0 = 같다,  -1은 내가 지정 수치보다 같거나 작을 경우, 1은 내가 지정 수치보다 같거나 클 경우
 	
	SetBeginSetAddGold( 1000 ); // 퀘스트 시작시  돈 추가
	SetBeginSetDisguise( MI_AIBATT2 ); // 퀘스트 시작시  돈 추가. 아이바트로 변신. 종료시 자동 해제
	SetBeginSetAddItem( nIdx, nItemIdx, nNum ); // 퀘스트 시작시 아이템 추가
 	SetBeginCondSex( nSex ); // nSex == -1, 모든 성, SEX_MALE, SEX_FEMALE
	SetBeginCondSkillLvl( nComp, nSkillIdx, nSkillLvl ); 
	SetBeginCondKarmaPoint( nComp, nKarmaPoint );
	SetBeginCondChaotic( nChaotic ); // 0 설정 무효, 1 범죄 상태, 2 면죄 상태
	SetBeginCondPreviousQuest( nType, nQuestId, ... ); // 6개까지. 이전 퀘스트가 어떤 상태인가. nType : 0 = 퀘스트를 하던 중이던 완료했던 두가지 다경우 모두 인정, 1 = 퀘스트 완료, 2 = 퀘스트 비완료
	SetBeginCondExecusivQuest( nQuestId, ... ); // 6개까지. nQuestId가  퀘스트가 없어야 조건 성립 
	SetBeginCondDisguise( nMoverIndex );
	SetBeginCondItem( nSex, nType, nJob, nItemIndex, nNum ); // nSex = -1은 무시, 0 남자, 1 여자,  nType = 0은 직업, 1은 아이템, nJob = 직업 id, -1은 모든 직업,nIndex = (0~3), nItemIdx = 프로퍼티의 아이템, nNum = 갯수 
	SetEndCondLimitTime( nMin ) // 시간 제한 : 분단위
	SetEndCondItem( nSex, nType, nJob, nItemIndex, nNum ); // nSex = -1은 무시, 0 남자, 1 여자,  nType = 0은 직업, 1은 아이템, nJob = 직업 id, -1은 모든 직업, nIndex = (0~3), nItemIdx = 프로퍼티의 아이템, nNum = 갯수 
	SetEndCondKillNPC( nIdx, nNPCIdx, nNPCNum ); // 죽일 NPC 설정 : nIdx (0~1) 두개까지 세팅 가능 
	SetEndCondPatrolZone( nWorldId, nLeft, nTop, nRight, nBottom ); // 정찰 영역 설정 
	SetEndCondSkillLvl( nSkillIdx, nSkillLvl ); 
	SetEndCondKarmaPoint( nComp, nKarmaPoint );
	SetEndCondChaotic( nChaotic ); // 0 설정 무효, 1 범죄 상태, 2 면죄 상태
	SetEndCondDialog( szCharKey, szAddKey ); // 대화 조건 szCharKey 키의 캐릭터와 szAddKey의 대화를 하게 되면 조건 만족  
	SetEndCondDisguise( nMoverIndex );
	SetDlgReward( nIndex, nItemIdx, nNum ); // 지원 안함!!!!!!!!!!!!!!! SetEndCondDialog조건이 만족하는 순간 유저에게 지급될 아이템. nIndex = (0~3), nItemIdx = 프로퍼티의 아이템, nNum = 갯수 
	SetEndRewardItem( nSex, Type, nJob, nItemIdx, nMum ); // nSex = -1은 무시, 0 남자, 1 여자, nType = 0은 직업, 1은 아이템, nJob = -1이면 직업 상관없음, nIdx = 0~3, nItemIdx = 프롭아이디, nMum 갯수
	SetEndRewardHide( bBool ); // 1이면 보상 목록을 ??로 나오게 한다. 0이면 보상 출력 
	SetEndRewardGold( nMin, nMax );
	SetEndRewardExp( nMin, nMax );
	SetEndRewardKarmaPoint( bSet, nKarmaPoint ); // bSet = 1은 세팅, 2는 추가. 0이면 입력하지 않은 것과 같다.


	SetEndCondState( nState ); // nState와 같아야 된다. (구버젼을 위한 기능)
	SetEndCondCompleteQuest( nOper, nQuest, ... ); // nOper = 0은 or, 1은 and, nQuest 완료된 퀘스트. 설정된 것중 하나라도 완료되었으면 조건 성립

	SetBeginCondGroup // 삭제 됐음
	SetBeginCondParty( nParty, nComp, nMemberNum, nLeader ); 
	// nParty = 0이면 파티 상관 없임, 1이면 솔로여야함, 2이면 파티여야함.
	// nComp = Comp 설명 참고
	// nMemberNum = 맴버수, 0이면 맴버수 무시.
	// nLeader = 0이면 리더 여부 상관 없음, 1이면 반드시 맴버여야함, 2이면 리더여야함
	SetBeginCondGuild( nParty, nComp, nMemberNum, nLeader ); // SetBeginCondParty 설명과 동일
	SetEndCondParty( nParty, nComp, nMemberNum, nLeader ); // SetBeginCondParty 설명과 동일
	SetEndCondGuild( nParty, nComp, nMemberNum, nLeader ); // SetBeginCondParty 설명과 동일
	SetEndRemoveQuest( nQuestId, ... ); 
	// 총 6개까지 추가할 수 있음, 현재, 완료 모두 제거됨. 
	// 완료된 퀘스트는 내부 버퍼에 남는다. 어떤 퀘스트 이야기가 끝날 때 이전 퀘스트를 지워준다
	// 그러므로서 삭제된 퀘스트를 다시할 수 밖에 없는 경우가 있다면 익스쿠르시브를 적당히 사용한다.


	SetMultiCharacter( szChar, nItemIdx, ..., ... );
	// SetCharacter 또는 SetMultiCharacter 둘중 하나를 사용한다. 하나의 퀘스트를 여러 NPC가 공유할 때 사용
	// szChar는 캐릭터 키, nItemIdx는 유저가 소유하고 있어야할 아이템.. NPC가 퀘스트 소유 여부를 판단한다. 
	// 가령 nItemIdx기 A라는 아이템일 때 A라는 아이템을 갖고 있지 않으면 조건에 만족못하므로 NPC는 퀘스틀 소유하고 있지 않는다. 
	// szChar, nItemIdx는 한쌍으로 10개까지 입력함.

	SetEndCondMultiCharacter( szChar, nItemIdx, ..., ... );
	// SetEndCondCharacter또는 SetEndCondMultiCharacter둘중 하나를 사용한다. 
	// 나머지는 SetMultiCharacter과 같음

	SetHeadQuest( nQuestId ); // nQuestId로 지정된 퀘스트를 해드 퀘스트로 지정.. 해드 퀘스트는 퀘스트 창에서 루트를 의미한다.
                                  // 해드 퀘스트는 퀘스트로서는 의미가 없다. 해드 퀘스트는 퀘스트 창에 출력하기 위해 존재한다.


	[New!!!] SenEndRewardJob( nNewJob, bInitStat ); // 퀘스트 보상으로 전직해준다.
*/

505
{
	SetTitle
	(
		IDS_PROPQUEST_REQUESTBOX2_INC_000000
	);
}

500
{
	SetTitle
	(
		IDS_PROPQUEST_REQUESTBOX2_INC_000001
	);

	setting
	{
		SetCharacter( "MaFl_Series1" );
		SetQuestType( QT_GENERAL);
		SetHeadQuest( 505 );
		//Quest Start Process///////////////////////////////////////////////////////////////////////////////////////////
//		SetBeginCondPreviousQuest( 0, 500 ); // 0
//		SetBeginCondLevel( 7, 11 );
//		SetBeginCondJob( JOB_VAGRANT );
		SetBeginCondDisguise( -1 ); // 변신하지 않은 상태. 변신 중복 퀘스트를 방지한다.
		SetBeginCondItem( -1, 0, JOB_VAGRANT, II_GEN_GEM_GEM_CHUPIM, 1 );
		// Quest 시작시 세팅 상황
 		SetBeginSetAddGold( 1000 );
		SetBeginSetDisguise( MI_AIBATT2 ); // 아이바트로 변신. 종료시 자동 해제
		//Quest End Process///////////////////////////////////////////////////////////////////////////////////////////
		SetEndCondLimitTime( 3 ) // 시간 제한 : 분단위
		SetEndCondKillNPC( 0, MI_AIBATT2, 1 ); // 죽일 NPC 설정 : nIdx (0~1) 두개까지 세팅 가능 
		//SetEndCondKillNPC( 1, MI_AIBATT4, 1 ); // 죽일 NPC 설정 : nIdx (0~1) 두개까지 세팅 가능 
		//SetEndCondPatrolZone( WI_WORLD_MADRIGAL, 6992, 3331, 7000, 3323 ); // 정찰 영역 설정 
		//SetEndCondCharacter( "MaFl_Series2" );
//		SetEndCondItem( -1, 0, -1,  II_GEN_GEM_GEM_CHUPIM, 5 );
		SetEndRemoveItem( 0,  II_GEN_GEM_GEM_CHUPIM, 5 );
		//SetEndCondSkillLvl( SI_VAG_ONE_OVERCUTTER, 2 ); 
		//SetEndCondKarmaPoint( 0, -100 );
		//SetEndCondChaotic( 1 );
		//SetEndCondDialog( "MaFl_Player", "dildo" );
		//SetEndCondDisguise( MI_AIBATT2 ); // 아이바트로 변신했는지 확인
		//SetEndCondParty( 1, 0, 0, 0 ); // SetBeginCondParty 설명과 동일
		//SetEndCondItem( -1, 0, JOB_VAGRANT, II_GEN_GEM_GEM_CHUPIM, 1 );
		// 제거 
		SetEndRemoveItem( 0, II_GEN_GEM_GEM_CHUPIM, 5 );
		// 보상 
		SetEndRewardHide( 0 );
		SetEndRewardGold( 3500, 3600 );
		SetEndRewardExp( 70, 210 );
		SetEndRewardKarmaPoint( 1, 1000 );
		SetEndRewardItem( -1, 0, -1, II_WEA_SWO_PARMIL, 1 );
		SenEndRewardJob( JOB_ACROBAT, 1 );	
	}
	SetPatrolZoneName
	(
		IDS_PROPQUEST_REQUESTBOX2_INC_000002
	);
	SetDialog
	(
		QSAY_BEGIN1, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000003
	);
	SetDialog
	(
		QSAY_BEGIN_YES,
		IDS_PROPQUEST_REQUESTBOX2_INC_000004
	);
	SetDialog
	(
		QSAY_BEGIN_NO, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000005
	);
	SetDialog
	(
		QSAY_END_COMPLETE1, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000006
	);
	SetDialog
	(
		QSAY_END_FAILURE1,
		IDS_PROPQUEST_REQUESTBOX2_INC_000007
	);
	SetDialog
	(
		QSAY_END_FAILURE2,
		IDS_PROPQUEST_REQUESTBOX2_INC_000008
	);
	state 0
	{

		SetDesc
		(
			IDS_PROPQUEST_REQUESTBOX2_INC_000009
		);
	}
	state 14
	{

		SetDesc
		(
			IDS_PROPQUEST_REQUESTBOX2_INC_000010
		);
	}
}
501
{
	SetTitle
	(
		IDS_PROPQUEST_REQUESTBOX2_INC_000011
	);

	setting
	{
		SetCharacter( "MaFl_Series2" );
		SetQuestType( QT_GENERAL);
		SetHeadQuest( 505 );
		//Quest Start Process///////////////////////////////////////////////////////////////////////////////////////////
//		SetBeginCondLevel( 7, 11 );
//		SetBeginCondJob( JOB_VAGRANT );
		SetBeginCondPreviousQuest( 0, 19 );
		//Quest End Process///////////////////////////////////////////////////////////////////////////////////////////
		SetEndCondCharacter( "MaFl_Series2" ); // 종료 판정 : 목표 NPC
		SetEndCondItem( -1, 0, -1,  II_GEN_GEM_GEM_CHUPIM, 5 );
		SetEndCondDialog( "MaFl_Series2", "FUCK" );
		SetEndRemoveItem( 0,  II_GEN_GEM_GEM_CHUPIM, 5 );
//		SetEndCondParty( 2, 0, 0, 0 ); 
//		SetEndCondState( 1 ); // nState와 같아야 된다. (구버젼을 위한 기능)
		SetEndRemoveQuest( 500 );
		// 퀘스트 성공 보상
		SetEndRewardItem( -1, 0, -1, II_WEA_SWO_OUTLAW, 2 );
		SetEndRewardItem( -1, 0, -1, II_WEA_SWO_OUTLAW, 1 );
		SetEndRewardItem( -1, 0, -1, II_WEA_SWO_OUTLAW, 1 );
		SetEndRewardItem( -1, 0, -1, II_WEA_SWO_OUTLAW, 1 );
		SetEndRewardGold( 3500, 3500 );
		SetEndRewardExp( 70, 70 );
		SetEndRemoveQuest( 19 );
	}


	SetDialog
	(
		QSAY_BEGIN1, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000012
	);
	SetDialog
	(
		QSAY_BEGIN2, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000013
	);

	SetDialog
	(
		QSAY_BEGIN_YES,
		IDS_PROPQUEST_REQUESTBOX2_INC_000014
	);
	SetDialog
	(
		QSAY_BEGIN_NO, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000015
	);
	SetDialog
	(
		QSAY_END_COMPLETE1, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000016
	);
	SetDialog
	(
		QSAY_END_FAILURE1,
		IDS_PROPQUEST_REQUESTBOX2_INC_000017
	);
	SetDialog
	(
		QSAY_END_FAILURE2,
		IDS_PROPQUEST_REQUESTBOX2_INC_000018
	);


	state 0
	{

		SetDesc
		(
			IDS_PROPQUEST_REQUESTBOX2_INC_000019
		);
	}
	state 14
	{

		SetDesc
		(
			IDS_PROPQUEST_REQUESTBOX2_INC_000020
		);

	}
}

502
{
	SetTitle
	(
		IDS_PROPQUEST_REQUESTBOX2_INC_000021
	);

	setting
	{
		SetMultiCharacter( "MaFl_MultiQuest1", II_WEA_SWO_WOODEN, "MaFl_MultiQuest2", II_WEA_SWO_LONG, "MaFl_MultiQuest3", II_WEA_SWO_LONG );
		SetQuestType( QT_GENERAL);
		SetHeadQuest( 505 );
		//Quest Start Process///////////////////////////////////////////////////////////////////////////////////////////
//		SetBeginCondLevel( 7, 11 );
//		SetBeginCondJob( JOB_VAGRANT );
		SetBeginCondPreviousQuest( 0, 19 );
		//Quest End Process///////////////////////////////////////////////////////////////////////////////////////////
		SetEndCondMultiCharacter( "MaFl_MultiQuest1", II_WEA_SWO_WOODEN, "MaFl_MultiQuest2", II_WEA_SWO_LONG, "MaFl_MultiQuest3", II_WEA_SWO_LONG );
		SetEndCondItem( -1, 0, -1,  II_GEN_GEM_GEM_CHUPIM, 5 );
		SetEndRemoveItem( 0,  II_GEN_GEM_GEM_CHUPIM, 5 );
//		SetEndCondParty( 2, 0, 0, 0 ); 
//		SetEndCondState( 1 ); // nState와 같아야 된다. (구버젼을 위한 기능)
		SetEndRemoveQuest( 500 );
		// 퀘스트 성공 보상
		SetEndRewardItem( -1, 1, II_WEA_SWO_WOODEN , II_WEA_SWO_PARMIL  , 1 );
		SetEndRewardItem( -1, 1, II_WEA_SWO_LONG , II_WEA_SWO_PARMIL, 1 );
		SetEndRewardItem( -1, 1, II_WEA_SWO_LONG   , II_WEA_SWO_CRIMSON , 1 );
		SetEndRewardGold( 3500, 3500 );
		SetEndRewardExp( 70, 70 );
	}


	SetDialog
	(
		QSAY_BEGIN1, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000022
	);
	SetDialog
	(
		QSAY_BEGIN2, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000023
	);

	SetDialog
	(
		QSAY_BEGIN_YES,
		IDS_PROPQUEST_REQUESTBOX2_INC_000024
	);
	SetDialog
	(
		QSAY_BEGIN_NO, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000025
	);
	SetDialog
	(
		QSAY_END_COMPLETE1, 
		IDS_PROPQUEST_REQUESTBOX2_INC_000026
	);
	SetDialog
	(
		QSAY_END_FAILURE1,
		IDS_PROPQUEST_REQUESTBOX2_INC_000027
	);
	SetDialog
	(
		QSAY_END_FAILURE2,
		IDS_PROPQUEST_REQUESTBOX2_INC_000028
	);


	state 0
	{

		SetDesc
		(
			IDS_PROPQUEST_REQUESTBOX2_INC_000029
		);
	}
	state 14
	{

		SetDesc
		(
			IDS_PROPQUEST_REQUESTBOX2_INC_000030
		);

	}
}