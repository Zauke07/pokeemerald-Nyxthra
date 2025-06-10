Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	call Common_EventScript_SetupRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, Route110_EventScript_MayBattleRegion
	goto_if_eq VAR_RESULT, STYLE_MAY, Route110_EventScript_BrendanBattleRegion
	goto_if_eq VAR_RESULT, STYLE_RED, Route110_EventScript_LeafBattleRegion
	goto_if_eq VAR_RESULT, STYLE_LEAF, Route110_EventScript_RedBattleRegion
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_DOWSING_MACHINE
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE110_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE110_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE110_RIVAL
	addobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_MayBattleRegion::
	switch VAR_STARTER_REGION
	case 0, Route110_EventScript_MayBattleKanto
	case 1, Route110_EventScript_MayBattleJohto
	case 2, Route110_EventScript_MayBattleHoenn
	case 3, Route110_EventScript_MayBattleSinnoh
	case 4, Route110_EventScript_MayBattleUnova
	case 5, Route110_EventScript_MayBattleKalos
	case 6, Route110_EventScript_MayBattleAlola
	case 7, Route110_EventScript_MayBattleGalar
	case 8, Route110_EventScript_MayBattlePaldea
	end

Route110_EventScript_BrendanBattleRegion::
	switch VAR_STARTER_REGION
	case 0, Route110_EventScript_BrendanBattleKanto
	case 1, Route110_EventScript_BrendanBattleJohto
	case 2, Route110_EventScript_BrendanBattleHoenn
	case 3, Route110_EventScript_BrendanBattleSinnoh
	case 4, Route110_EventScript_BrendanBattleUnova
	case 5, Route110_EventScript_BrendanBattleKalos
	case 6, Route110_EventScript_BrendanBattleAlola
	case 7, Route110_EventScript_BrendanBattleGalar
	case 8, Route110_EventScript_BrendanBattlePaldea
	end

Route110_EventScript_LeafBattleRegion::
	switch VAR_STARTER_REGION
	case 0, Route110_EventScript_LeafBattleKanto
	case 1, Route110_EventScript_LeafBattleJohto
	case 2, Route110_EventScript_LeafBattleHoenn
	case 3, Route110_EventScript_LeafBattleSinnoh
	case 4, Route110_EventScript_LeafBattleUnova
	case 5, Route110_EventScript_LeafBattleKalos
	case 6, Route110_EventScript_LeafBattleAlola
	case 7, Route110_EventScript_LeafBattleGalar
	case 8, Route110_EventScript_LeafBattlePaldea
	end

Route110_EventScript_RedBattleRegion::
	switch VAR_STARTER_REGION
	case 0, Route110_EventScript_RedBattleKanto
	case 1, Route110_EventScript_RedBattleJohto
	case 2, Route110_EventScript_RedBattleHoenn
	case 3, Route110_EventScript_RedBattleSinnoh
	case 4, Route110_EventScript_RedBattleUnova
	case 5, Route110_EventScript_RedBattleKalos
	case 6, Route110_EventScript_RedBattleAlola
	case 7, Route110_EventScript_RedBattleGalar
	case 8, Route110_EventScript_RedBattlePaldea
	end

Route110_EventScript_MayBattleKanto::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleBULBASAUR
    case 1, Route110_EventScript_MayBattleCHARMANDER
    case 2, Route110_EventScript_MayBattleSQUIRTLE
    end

Route110_EventScript_MayBattleJohto::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleCHIKORITA
    case 1, Route110_EventScript_MayBattleCYNDAQUIL
    case 2, Route110_EventScript_MayBattleTOTODILE
    end

Route110_EventScript_MayBattleHoenn::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleTREECKO
    case 1, Route110_EventScript_MayBattleTORCHIC
    case 2, Route110_EventScript_MayBattleMUDKIP
    end

Route110_EventScript_MayBattleSinnoh::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleTURTWIG
    case 1, Route110_EventScript_MayBattleCHIMCHAR
    case 2, Route110_EventScript_MayBattlePIPLUP
    end

Route110_EventScript_MayBattleUnova::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleSNIVY
    case 1, Route110_EventScript_MayBattleTEPIG
    case 2, Route110_EventScript_MayBattleOSHAWOTT
    end

Route110_EventScript_MayBattleKalos::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleCHESPIN
    case 1, Route110_EventScript_MayBattleFENNEKIN
    case 2, Route110_EventScript_MayBattleFROAKIE
    end

Route110_EventScript_MayBattleAlola::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleROWLET
    case 1, Route110_EventScript_MayBattleLITTEN
    case 2, Route110_EventScript_MayBattlePOPPLIO
    end

Route110_EventScript_MayBattleGalar::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleGROOKEY
    case 1, Route110_EventScript_MayBattleSCORBUNNY
    case 2, Route110_EventScript_MayBattleSOBBLE
    end

Route110_EventScript_MayBattlePaldea::
    msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_MayBattleSPRIGATITO
    case 1, Route110_EventScript_MayBattleFUECOCO
    case 2, Route110_EventScript_MayBattleQUAXLY
    end

Route110_EventScript_BrendanBattleKanto::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleBULBASAUR
    case 1, Route110_EventScript_BrendanBattleCHARMANDER
    case 2, Route110_EventScript_BrendanBattleSQUIRTLE
    end

Route110_EventScript_BrendanBattleJohto::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleCHIKORITA
    case 1, Route110_EventScript_BrendanBattleCYNDAQUIL
    case 2, Route110_EventScript_BrendanBattleTOTODILE
    end

Route110_EventScript_BrendanBattleHoenn::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleTREECKO
    case 1, Route110_EventScript_BrendanBattleTORCHIC
    case 2, Route110_EventScript_BrendanBattleMUDKIP
    end

Route110_EventScript_BrendanBattleSinnoh::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleTURTWIG
    case 1, Route110_EventScript_BrendanBattleCHIMCHAR
    case 2, Route110_EventScript_BrendanBattlePIPLUP
    end

Route110_EventScript_BrendanBattleUnova::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleSNIVY
    case 1, Route110_EventScript_BrendanBattleTEPIG
    case 2, Route110_EventScript_BrendanBattleOSHAWOTT
    end

Route110_EventScript_BrendanBattleKalos::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleCHESPIN
    case 1, Route110_EventScript_BrendanBattleFENNEKIN
    case 2, Route110_EventScript_BrendanBattleFROAKIE
    end

Route110_EventScript_BrendanBattleAlola::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleROWLET
    case 1, Route110_EventScript_BrendanBattleLITTEN
    case 2, Route110_EventScript_BrendanBattlePOPPLIO
    end

Route110_EventScript_BrendanBattleGalar::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleGROOKEY
    case 1, Route110_EventScript_BrendanBattleSCORBUNNY
    case 2, Route110_EventScript_BrendanBattleSOBBLE
    end

Route110_EventScript_BrendanBattlePaldea::
    msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_MON
    case 0, Route110_EventScript_BrendanBattleSPRIGATITO
    case 1, Route110_EventScript_BrendanBattleFUECOCO
    case 2, Route110_EventScript_BrendanBattleQUAXLY
    end

Route110_EventScript_LeafBattleKanto::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleBULBASAUR
	case 1, Route110_EventScript_LeafBattleCHARMANDER
	case 2, Route110_EventScript_LeafBattleSQUIRTLE
	end

Route110_EventScript_LeafBattleJohto::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleCHIKORITA
	case 1, Route110_EventScript_LeafBattleCYNDAQUIL
	case 2, Route110_EventScript_LeafBattleTOTODILE
	end

Route110_EventScript_LeafBattleHoenn::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleTREECKO
	case 1, Route110_EventScript_LeafBattleTORCHIC
	case 2, Route110_EventScript_LeafBattleMUDKIP
	end

Route110_EventScript_LeafBattleSinnoh::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleTURTWIG
	case 1, Route110_EventScript_LeafBattleCHIMCHAR
	case 2, Route110_EventScript_LeafBattlePIPLUP
	end

Route110_EventScript_LeafBattleUnova::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleSNIVY
	case 1, Route110_EventScript_LeafBattleTEPIG
	case 2, Route110_EventScript_LeafBattleOSHAWOTT
	end

Route110_EventScript_LeafBattleKalos::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleCHESPIN
	case 1, Route110_EventScript_LeafBattleFENNEKIN
	case 2, Route110_EventScript_LeafBattleFROAKIE
	end

Route110_EventScript_LeafBattleAlola::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleROWLET
	case 1, Route110_EventScript_LeafBattleLITTEN
	case 2, Route110_EventScript_LeafBattlePOPPLIO
	end

Route110_EventScript_LeafBattleGalar::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleGROOKEY
	case 1, Route110_EventScript_LeafBattleSCORBUNNY
	case 2, Route110_EventScript_LeafBattleSOBBLE
	end

Route110_EventScript_LeafBattlePaldea::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_LeafBattleSPRIGATITO
	case 1, Route110_EventScript_LeafBattleFUECOCO
	case 2, Route110_EventScript_LeafBattleQUAXLY
	end

Route110_EventScript_RedBattleKanto::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleBULBASAUR
	case 1, Route110_EventScript_RedBattleCHARMANDER
	case 2, Route110_EventScript_RedBattleSQUIRTLE
	end

Route110_EventScript_RedBattleJohto::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleCHIKORITA
	case 1, Route110_EventScript_RedBattleCYNDAQUIL
	case 2, Route110_EventScript_RedBattleTOTODILE
	end

Route110_EventScript_RedBattleHoenn::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleTREECKO
	case 1, Route110_EventScript_RedBattleTORCHIC
	case 2, Route110_EventScript_RedBattleMUDKIP
	end

Route110_EventScript_RedBattleSinnoh::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleTURTWIG
	case 1, Route110_EventScript_RedBattleCHIMCHAR
	case 2, Route110_EventScript_RedBattlePIPLUP
	end

Route110_EventScript_RedBattleUnova::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleSNIVY
	case 1, Route110_EventScript_RedBattleTEPIG
	case 2, Route110_EventScript_RedBattleOSHAWOTT
	end

Route110_EventScript_RedBattleKalos::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleCHESPIN
	case 1, Route110_EventScript_RedBattleFENNEKIN
	case 2, Route110_EventScript_RedBattleFROAKIE
	end

Route110_EventScript_RedBattleAlola::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleROWLET
	case 1, Route110_EventScript_RedBattleLITTEN
	case 2, Route110_EventScript_RedBattlePOPPLIO
	end

Route110_EventScript_RedBattleGalar::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleGROOKEY
	case 1, Route110_EventScript_RedBattleSCORBUNNY
	case 2, Route110_EventScript_RedBattleSOBBLE
	end

Route110_EventScript_RedBattlePaldea::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_RedBattleSPRIGATITO
	case 1, Route110_EventScript_RedBattleFUECOCO
	case 2, Route110_EventScript_RedBattleQUAXLY
	end

Route110_EventScript_MayBattleBULBASAUR::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_BULBASAUR, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleCHARMANDER::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_CHARMANDER, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleSQUIRTLE::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_SQUIRTLE, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleCHIKORITA::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_CHIKORITA, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleCYNDAQUIL::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_CYNDAQUIL, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleTOTODILE::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TOTODILE, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleTREECKO::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleTORCHIC::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleMUDKIP::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleTURTWIG::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TURTWIG, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleCHIMCHAR::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_CHIMCHAR, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattlePIPLUP::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_PIPLUP, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleSNIVY::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_SNIVY, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleTEPIG::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TEPIG, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleOSHAWOTT::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_OSHAWOTT, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleCHESPIN::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_CHESPIN, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleFENNEKIN::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_FENNEKIN, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleFROAKIE::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_FROAKIE, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleROWLET::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_ROWLET, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleLITTEN::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_LITTEN, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattlePOPPLIO::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_POPPLIO, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleGROOKEY::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_GROOKEY, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleSCORBUNNY::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_SCORBUNNY, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleSOBBLE::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_SOBBLE, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleSPRIGATITO::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_SPRIGATITO, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleFUECOCO::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_FUECOCO, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_MayBattleQUAXLY::
    trainerbattle_no_intro TRAINER_MAY_ROUTE_110_QUAXLY, Route110_Text_MayDefeated
    goto Route110_EventScript_MayDefeated
    end

Route110_EventScript_BrendanBattleBULBASAUR::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_BULBASAUR, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleCHARMANDER::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_CHARMANDER, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleSQUIRTLE::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_SQUIRTLE, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleCHIKORITA::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_CHIKORITA, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleCYNDAQUIL::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_CYNDAQUIL, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleTOTODILE::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TOTODILE, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleTREECKO::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleTORCHIC::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleMUDKIP::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleTURTWIG::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TURTWIG, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleCHIMCHAR::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_CHIMCHAR, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattlePIPLUP::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_PIPLUP, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleSNIVY::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_SNIVY, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleTEPIG::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TEPIG, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleOSHAWOTT::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_OSHAWOTT, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleCHESPIN::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_CHESPIN, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleFENNEKIN::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_FENNEKIN, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleFROAKIE::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_FROAKIE, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleROWLET::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_ROWLET, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleLITTEN::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_LITTEN, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattlePOPPLIO::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_POPPLIO, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleGROOKEY::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_GROOKEY, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleSCORBUNNY::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_SCORBUNNY, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleSOBBLE::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_SOBBLE, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleSPRIGATITO::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_SPRIGATITO, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleFUECOCO::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_FUECOCO, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_BrendanBattleQUAXLY::
    trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_QUAXLY, Route110_Text_BrendanDefeated
    goto Route110_EventScript_BrendanDefeated
    end

Route110_EventScript_LeafBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_BULBASAUR, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_CHARMANDER, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_SQUIRTLE, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_CHIKORITA, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_CYNDAQUIL, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_TOTODILE, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleTREECKO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_TURTWIG, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_CHIMCHAR, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_PIPLUP, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleSNIVY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_SNIVY, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleTEPIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_TEPIG, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_OSHAWOTT, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_CHESPIN, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_FENNEKIN, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_FROAKIE, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleROWLET::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_ROWLET, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleLITTEN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_LITTEN, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_POPPLIO, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_GROOKEY, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_SCORBUNNY, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_SOBBLE, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_SPRIGATITO, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_FUECOCO, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_LeafBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_110_QUAXLY, Route110_Text_MayDefeated
	goto Route110_EventScript_LeafDefeated
	end

Route110_EventScript_RedBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_BULBASAUR, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_CHARMANDER, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_SQUIRTLE, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_CHIKORITA, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_CYNDAQUIL, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleTOTODILE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_TOTODILE, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleTREECKO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleTORCHIC::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleMUDKIP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleTURTWIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_TURTWIG, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_CHIMCHAR, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattlePIPLUP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_PIPLUP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleSNIVY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_SNIVY, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleTEPIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_TEPIG, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_OSHAWOTT, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleCHESPIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_CHESPIN, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_FENNEKIN, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleFROAKIE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_FROAKIE, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleROWLET::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_ROWLET, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleLITTEN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_LITTEN, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_POPPLIO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleGROOKEY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_GROOKEY, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_SCORBUNNY, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleSOBBLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_SOBBLE, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_SPRIGATITO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleFUECOCO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_FUECOCO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_RedBattleQUAXLY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_110_QUAXLY, Route110_Text_BrendanDefeated
	goto Route110_EventScript_RedDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_LeafDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_RedDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_ROUTE110_BIRCH
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_ROUTE110_BIRCH, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_ROUTE110_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_ROUTE110_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_EventScript_BigSnorlax::
    lockall
    faceplayer
    goto_if_unset FLAG_GOT_POKE_FLUTE, Route110_EventScript_SnorlaxNoFlute
    msgbox Route110_Text_UseFlute, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Route110_EventScript_SnorlaxDontUse

    call Route110_EventScript_AwakenSnorlax
    setwildbattle SPECIES_SNORLAX, 30
    setflag FLAG_SYS_CTRL_OBJ_DELETE
    setflag FLAG_FORCE_SHINY_WILD_BATTLE
    setflag FLAG_SPECIAL_BATTLE_MUSIC
    dowildbattle
    clearflag FLAG_SYS_CTRL_OBJ_DELETE
    clearflag FLAG_FORCE_SHINY_WILD_BATTLE
    clearflag FLAG_SPECIAL_BATTLE_MUSIC
    specialvar VAR_RESULT, GetBattleOutcome

    goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route110_EventScript_SnorlaxDefeated
    goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route110_EventScript_SnorlaxDefeated
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route110_EventScript_SnorlaxDefeated
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route110_EventScript_SnorlaxDefeated

    releaseall
    end

Route110_EventScript_SnorlaxDefeated::
    fadescreen FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreen FADE_FROM_BLACK
    setflag FLAG_HIDE_ROUTE_110_BIG_SNORLAX
    setflag FLAG_WOKE_UP_BIG_SNORLAX
    msgbox Route110_Text_SnorlaxLeft, MSGBOX_DEFAULT
    releaseall
    end

Route110_EventScript_SnorlaxDontUse::
    releaseall
    end

Route110_EventScript_SnorlaxNoFlute::
    msgbox Route110_Text_SnorlaxSleeping, MSGBOX_DEFAULT
    message Route110_Text_SnorlaxSearchBag
    waitmessage
    delay 20
    message Route110_Text_SnorlaxNoFluteFound
    waitmessage
    releaseall
    end

Route110_EventScript_AwakenSnorlax::
    message Route110_Text_PlayedFlute
    waitmessage
    playfanfare MUS_RG_POKE_FLUTE
    waitfanfare
    msgbox Route110_Text_SnorlaxWokeUp, MSGBOX_DEFAULT
    return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "TEAM AQUA's activities…\n"
	.string "We can't talk about them yet.$"

Route110_Text_KickUpARuckus:
	.string "I want to get going to SLATEPORT and\n"
	.string "kick up a ruckus!$"

Route110_Text_MyFirstJobInAqua:
	.string "This is my first job after joining\n"
	.string "TEAM AQUA. It's a little scary.$"

Route110_Text_AquaActionsBringSmiles:
	.string "TEAM AQUA's actions should bring\n"
	.string "smiles to people's faces!$"

Route110_Text_MayLetsBattle:
	.string "{RIVAL}: Hi, {PLAYER}{KUN}, wir haben uns ja\n"
	.string "lange nicht gesehen!\p"
	.string "Während ich auf der Suche nach\n"
	.string "weiteren Pokémon war, sind meine\l"
	.string "Pokémon stärker geworden.\p"
	.string "Daher…\n"
	.string "Wie wäre es mit einem kleinen Kampf?$"

Route110_Text_MayDefeated:
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route110_Text_MayTakeThis:
	.string "{RIVAL}: {PLAYER}{KUN}, du hast auch fleißig\n"
	.string "trainiert, nicht wahr?\p"
	.string "Ich denke, du verdienst eine Belohnung!\n"
	.string "Hier, dies ist von mir für dich!$"

Route110_Text_MayExplainItemfinder:
	.string "{RIVAL}: Das ist ein DETEKTOR.\p"
	.string "Probier ihn mal aus. Wenn irgendwo ein\n"
	.string "Item versteckt ist, gibt er ein\l"
	.string "Geräusch von sich.\p"
	.string "Bis zum nächsten Mal, {PLAYER}{KUN}.\p"
	.string "Es hört sich aus meinem Munde zwar blöd\n"
	.string "an, aber bis dahin solltest du viel mehr\l"
	.string "trainiert haben.$"

Route110_Text_BrendanLetsBattle:
	.string "{RIVAL}: Hey, {PLAYER}.\n"
	.string "Hier treibst du dich also herum.\l"
	.string "Wie geht es?\p"
	.string "Hast du deine Pokémon gut aufgezogen?\n"
	.string "Ich werde das für dich überprüfen.$"

Route110_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route110_Text_BrendanTakeThis:
	.string "{RIVAL}: {PLAYER}, du hast trainiert,\n"
	.string "ohne dass ich etwas davon\l"
	.string "mitbekommen habe…\p"
	.string "Aber genug!\n"
	.string "Hier, das ist für dich!$"

Route110_Text_BrendanExplainItemfinder:
	.string "{RIVAL}: Das ist ein DETEKTOR.\p"
	.string "Probier ihn mal aus. \p"
	.string "Ist irgendwo ein Item versteckt, gibt\n"
	.string "er ein Geräusch von sich.\p"
	.string "Wie auch immer, ich suche jetzt weiter\n"
	.string "nach Pokémon.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Wouldn't it be great to ride a BIKE\n"
	.string "at full speed on CYCLING ROAD?$"

Route110_Text_HairStreamsBehindMe:
	.string "How do you like the way my raven-\n"
	.string "colored hair streams behind me?\p"
	.string "I grew my hair out just for that.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
	.string "Oh, it's glaringly obvious.\n"
	.string "It says right on your bike…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "That name's everywhere.\p"
	.string "You should ride it around all over\n"
	.string "the place--it's good advertising!$"

Route110_Text_TwoRoads:
	.string "The two roads, one above, one below…\p"
	.string "A road each for people and POKéMON.\n"
	.string "Perhaps that is right and fair.$"

Route110_Text_WalkOnTheLowRoad:
	.string "I don't have a BIKE, so I'll take\n"
	.string "a leisurely walk on the low road.$"

Route110_Text_BikeTechniques:
	.string "Learning techniques will make BIKE\n"
	.string "riding even more fun.\p"
	.string "There are some places that you can\n"
	.string "reach only by using a BIKE technique.$"

Route110_Text_WhichShouldIChoose:
	.string "Which should I choose?\p"
	.string "Make a beeline for MAUVILLE on\n"
	.string "CYCLING ROAD, or take the low road\l"
	.string "and look for POKéMON?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"

Route110_Text_ChallengeReactionGood:
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"

Route110_Text_ChallengeReactionOk:
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"

Route110_Text_ChallengeReactionBad:
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"

Route110_Text_ChallengeReactionWorst:
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that BIKE to RYDEL.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "This is CYCLING ROAD.\p"
	.string "If you were to ride from MAUVILLE to\n"
	.string "SLATEPORT on a MACH BIKE, you would\l"
	.string "be rated for the number of collisions\l"
	.string "and your total time.$"

Route110_Text_AlwaysAimHigher:
	.string "Regardless of the results, I count on\n"
	.string "seeing more challenges from you.\l"
	.string "Always aim higher!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "On this CYCLING ROAD, those riding\n"
	.string "MACH BIKES are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "ACRO BIKES do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

Route110_Text_SlateportCitySign:
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} SLATEPORT CITY$"

Route110_Text_CyclingRoadSign:
	.string "SEASIDE CYCLING ROAD$"

Route110_Text_AquaWasHere:
	.string "“TEAM AQUA was here!”\p"
	.string "Someone painted that onto this sign,\n"
	.string "but then someone else painted over it.\p"
	.string "“TEAM MAGMA rules!” is what it\n"
	.string "says now.$"

Route110_Text_Route103Sign:
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
	.string "SEASIDE PARKING$"

Route110_Text_MauvilleCitySign:
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE CITY$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "TRAINER TIPS\p"
	.string "The foe can be made helpless by\n"
	.string "paralyzing it or causing it to sleep.\p"
	.string "It is an important technique for\n"
	.string "POKéMON battles.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "TRAINER TIPS\p"
	.string "The items in the BAG can be reorganized\n"
	.string "by pressing SELECT.$"

Route110_Text_TrickHouseSign:
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
	.string "to reach the wondrous TRICK HOUSE.”$"

Route110_Text_BestRecord:
	.string "THE BEST RECORD TO DATE…\p"
	.string "No. of collisions: {STR_VAR_1}\p"
	.string "Elapsed time: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "THE BEST RECORD TO DATE…\p"
	.string "No one seems to have taken the\n"
	.string "challenge. There is no record…$"

Route110_Text_ImagineSeeingYouHere:
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Imagine seeing you here!\p"
	.string "And where might my {RIVAL} be?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Oh, I see!\n"
	.string "You two are running separately.\l"
	.string "Well, that's fine.\p"
	.string "Oh, yes, I heard that your POKéNAV\n"
	.string "had the MATCH CALL system installed.\p"
	.string "Well, then, I should register you in\n"
	.string "my POKéNAV as well.\p"
	.string "That way, even when we're apart,\n"
	.string "I can rate your POKéDEX anytime.\p"
	.string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav:
	.string "Registered PROF. BIRCH\n"
	.string "in the POKéNAV.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "PROF. BIRK: {PLAYER}{KUN}…\p"
	.string "Bitte achte ein wenig auf {RIVAL}.\n"
	.string "… … … … …\l"
	.string "…\p"
	.string "Nun muss ich mich aber beeilen.\n"
	.string "Man sieht sich, {PLAYER}{KUN}.$"

Route110_EventScript_Flemmli::
    msgbox Route110_Text_Flemmli, MSGBOX_NPC
    end

Route110_Text_Flemmli:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 3 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

Route110_Text_SnorlaxSleeping::
    .string "{COLOR RED}{PLAYER}: Meine Fresse...\n"
    .string "Was ist das denn?!\p"
    .string "{PLAYER}: Ah, ein dickes fettes\n"
    .string "{COLOR BLUE}Relaxo{COLOR RED}.\p"
    .string "{PLAYER}: Wenn ich hier durch will,\n"
    .string "muss ich wohl die Pokéflöte spielen…{COLOR WHITE}$"

Route110_Text_SnorlaxSearchBag::
    .string "{COLOR RED}{PLAYER}: Durchsucht den Beutel…\n"
    .string "…\n"
    .string "…\n"
    .string "…{COLOR WHITE}$"

Route110_Text_SnorlaxNoFluteFound::
    .string "{COLOR RED}{PLAYER}: Fuck!\n"
    .string "Ich hab noch keine Pokéflöte…{COLOR WHITE}$"

Route110_Text_UseFlute::
    .string "Willst du die Pokéflöte benutzen?$"

Route110_Text_PlayedFlute::
    .string "{PLAYER} spielt die Pokéflöte.$"

Route110_Text_SnorlaxWokeUp::
    .string "{COLOR BLUE}Relaxo{COLOR WHITE} wacht auf!\n"
    .string "Es wirkt extrem genervt!$"

Route110_Text_SnorlaxLeft::
    .string "{COLOR BLUE}Relaxo{COLOR WHITE} beruhigte sich…\n"
    .string "und verschwand in den Büschen.$"

