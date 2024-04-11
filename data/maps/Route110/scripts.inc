.set LOCALID_CHALLENGE_BIKER, 21
.set LOCALID_RIVAL, 28
.set LOCALID_RIVAL_ON_BIKE, 29
.set LOCALID_BIRCH, 36

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
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
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
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
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
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
	removeobject LOCALID_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
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
    .string "TEAM AQUA's Aktivitäten …\n"
    .string "müssen im Moment geheim bleiben!$"

Route110_Text_KickUpARuckus:
    .string "Ich möchte nach Graphitport gehen und\n"
    .string "ein bisschen für Aufsehen sorgen!$"

Route110_Text_MyFirstJobInAqua:
    .string "Dies ist mein erster Auftrag, nachdem ich\n"
    .string "TEAM AQUA beigetreten bin.\p"
	.string "Es ist ein wenig beängstigend.$"

Route110_Text_AquaActionsBringSmiles:
    .string "Die Aktionen von TEAM AQUA sollten\n"
    .string "den Menschen ein Lächeln ins Gesicht zaubern!$"

Route110_Text_MayLetsBattle:
    .string "Brigitte: Hallo, {PLAYER}{KUN}, lange nicht gesehen!\p"
    .string "Während ich nach anderen POKéMON\n"
    .string "gesucht habe, sind meine POKéMON stärker geworden.\p"
    .string "Also…\n"
    .string "Wie wäre es mit einem kleinen Kampf?$"

Route110_Text_MayDefeated:
    .string "Huch!\n"
    .string "Du bist besser als ich erwartet hatte!$"

Route110_Text_MayTakeThis:
    .string "Brigitte: {PLAYER}{KUN}, du hast dich auch\n"
    .string "fleißig trainiert, oder?\p"
    .string "Ich denke, du verdienst eine Belohnung!\n"
    .string "Das ist von mir!$"

Route110_Text_MayExplainItemfinder:
    .string "Brigitte: Das ist ein ITEMFINDER.\p"
    .string "Probier ihn aus. Wenn es ein\n"
    .string "nicht sichtbares Item gibt, gibt er ein Geräusch von sich.\p"
    .string "Okay, {PLAYER}{KUN}, wir sehen uns wieder!\p"
    .string "Ich weiß, es klingt ein wenig albern von mir,\n"
    .string "aber ich denke, du solltest viel härter trainieren\n"
    .string "für das nächste Mal.$"

Route110_Text_BrendanLetsBattle:
    .string "Hans: Hey, {PLAYER}.\n"
    .string "Also, hier bist du also.\l"
    .string "Wie läuft's?\p"
    .string "Hast du deine POKéMON trainiert?\n"
    .string "Ich werde das für dich überprüfen.$"

Route110_Text_BrendanDefeated:
    .string "Hmm…\n"
    .string "Du bist ziemlich gut.$"

Route110_Text_BrendanTakeThis:
    .string "Hans: {PLAYER}, du hast dich\n"
    .string "trainiert, ohne dass ich es bemerkt habe…\p"
    .string "Gut genug!\n"
    .string "Hier, nimm das.$"

Route110_Text_BrendanExplainItemfinder:
    .string "Hans: Das ist ein ITEMFINDER.\p"
    .string "Benutze ihn, um nach Items zu suchen,\n"
    .string "die nicht sichtbar sind.\p"
    .string "Wenn er etwas bemerkt, gibt er\n"
    .string "ein Geräusch von sich.\p"
    .string "Wie auch immer, ich gehe los, um nach neuen\n"
    .string "POKéMON zu suchen.$"

Route110_Text_RideBikeAtFullSpeed:
    .string "Wäre es nicht großartig, mit voller\n"
    .string "Geschwindigkeit auf dem RADWEG zu fahren?$"

Route110_Text_HairStreamsBehindMe:
    .string "Wie gefällt dir, wie mein rabenfarbenes\n"
    .string "Haar hinter mir her weht?\p"
    .string "Ich habe mir meine Haare extra dafür wachsen lassen.$"

Route110_Text_YouGotBikeFromRydel:
    .string "Oh, hey, du hast dieses RAD von RYDEL!\p"
    .string "Oh, es ist offensichtlich.\n"
    .string "Es steht direkt auf deinem Fahrrad…\p"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
    .string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
    .string "Dieser Name ist überall.\p"
    .string "Du solltest damit überall herumfahren--\n"
    .string "es ist gute Werbung!$"

Route110_Text_TwoRoads:
    .string "Die beiden Straßen, eine oben, eine unten…\p"
    .string "Eine Straße für Menschen und eine für POKéMON.\n"
    .string "Vielleicht ist das richtig und fair.$"

Route110_Text_WalkOnTheLowRoad:
    .string "Ich habe kein FAHRRAD, also werde ich\n"
    .string "gemütlich auf der unteren Straße spazieren gehen.$"

Route110_Text_BikeTechniques:
    .string "Das Erlernen von Techniken macht das\n"
    .string "RADFAHREN noch unterhaltsamer.\p"
    .string "Es gibt einige Orte, die du nur mit einer\n"
    .string "RADFAHRTECHNIK erreichen kannst.$"

Route110_Text_WhichShouldIChoose:
    .string "Was soll ich wählen?\p"
    .string "Direkt nach MAUZIEN auf dem\n"
    .string "RADWEG oder die untere Straße nehmen\l"
    .string "und nach POKéMON suchen?$"

Route110_Text_CyclingChallengeResultSummary:
    .string "Anzahl der Zusammenstöße:\n"
    .string "… … {STR_VAR_1}!\p"
    .string "Gesamtzeit:\n"
    .string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
    .string "Bravo! Prächtige Leistung!\p"
    .string "Deine Liebe zum Radfahren kommt\n"
    .string "aus tiefstem Herzen.\l"
    .string "Du hast mich bis ins Mark erschüttert!$"

Route110_Text_ChallengeReactionGood:
    .string "Deine Technik ist bemerkenswert.\p"
    .string "Ich schlage vor, dass du etwas\n"
    .string "schneller fährst, während du\l"
    .string "dennoch Zusammenstöße vermeidest.$"

Route110_Text_ChallengeReactionOk:
    .string "Ich würde sagen, du bist noch in der\n"
    .string "Entwicklung.\p"
    .string "Trotzdem hoffe ich, dass du die reine\n"
    .string "Freude am Radfahren nicht vergisst.$"

Route110_Text_ChallengeReactionBad:
    .string "Mein Gott… Deine Radfahrkünste\n"
    .string "grenzen an furchterregend.\p"
    .string "Ganz sicher brauchst du viel mehr\n"
    .string "Übung im Fahren.$"

Route110_Text_ChallengeReactionWorst:
    .string "… Ich bin entsetzt…\p"
    .string "Vielleicht bist du für dieses\n"
    .string "unglückselige Radfahren nicht gemacht.\p"
    .string "Du solltest ernsthaft darüber nachdenken,\n"
    .string "dieses FAHRRAD an RYDEL zurückzugeben.$"

Route110_Text_RatedForNumberOfCollisions:
    .string "Dies ist der RADWEG.\p"
    .string "Wenn du von MAUZIEN nach FALESIA\n"
    .string "mit einem FLITZRAD fährst, wirst du\n"
    .string "für die Anzahl der Zusammenstöße\n"
    .string "und deine Gesamtzeit bewertet.$"

Route110_Text_AlwaysAimHigher:
    .string "Unabhängig von den Ergebnissen zähle ich\n"
    .string "darauf, dass du weitere Herausforderungen\n"
    .string "annimmst. Strebe immer höher!$"

Route110_Text_AcroBikesDoNotQualify:
    .string "Auf diesem RADWEG werden diejenigen,\n"
    .string "die MACH FAHRRÄDER fahren, für ihre\l"
    .string "Anzahl der Zusammenstöße und ihre\n"
    .string "Gesamtzeit bewertet.\p"
    .string "ACRO FAHRRÄDER qualifizieren sich nicht\n"
    .string "für eine Bewertung.\n"
    .string "Sie sind leicht zu lenken, daher ist es\n"
    .string "nicht fair.$"

Route110_Text_SlateportCitySign:
    .string "ROUTE 110\n"
    .string "{DOWN_ARROW} Graphitport City$"

Route110_Text_CyclingRoadSign:
    .string "RADWEG AM MEER$"

Route110_Text_AquaWasHere:
    .string "“TEAM AQUA war hier!”\p"
    .string "Jemand hat das auf dieses Schild gemalt,\n"
    .string "aber dann hat es jemand anders übermalt.\p"
    .string "Jetzt steht dort “TEAM MAGMA regiert!”.$"

Route110_Text_Route103Sign:
    .string "ROUTE 110\n"
    .string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
    .string "STRANDPARKPLATZ$"

Route110_Text_MauvilleCitySign:
    .string "ROUTE 110\n"
    .string "{UP_ARROW} MAUZIEN$"

Route110_Text_TrainerTipsPrlzSleep:
    .string "TRAINER TIPPS\p"
    .string "Der Gegner kann hilflos gemacht werden,\n"
    .string "indem man ihn lähmt oder zum Schlafen bringt.\p"
    .string "Es ist eine wichtige Technik für\n"
    .string "POKéMON-Kämpfe.$"

Route110_Text_TrainerTipsRegisterItems:
    .string "TRAINER TIPPS\p"
    .string "Die Gegenstände im BEUTEL können durch\n"
    .string "Drücken von SELECT neu sortiert werden.$"

Route110_Text_TrickHouseSign:
    .string "“Drei Schritte {RIGHT_ARROW} und zwei Schritte {UP_ARROW}\n"
    .string "um zum wundersamen TRICK-HAUS zu gelangen.”$"

Route110_Text_BestRecord:
    .string "DER BESTE REKORD BISHER…\p"
    .string "Anzahl der Zusammenstöße: {STR_VAR_1}\p"
    .string "Vergehene Zeit: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
    .string "DER BESTE REKORD BISHER…\p"
    .string "Es scheint, als hätte niemand die\n"
    .string "Herausforderung angenommen. Es gibt keinen Rekord…$" 

Route110_Text_ImagineSeeingYouHere:
    .string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
    .string "Dich hier zu sehen, ist eine Überraschung!\p"
    .string "Und wo mag mein {RIVAL} sein?$"

Route110_Text_HeardYouInstallMatchCall:
    .string "Oh, ich verstehe!\n"
    .string "Ihr beiden seid getrennt unterwegs.\l"
    .string "Nun, das ist in Ordnung.\p"
    .string "Oh ja, ich habe gehört, dass dein POKéNAV\n"
    .string "das MATCH CALL-System installiert hat.\p"
    .string "Dann sollte ich dich auch in meinem POKéNAV Speichern.\p"
    .string "So kann ich deine POKéDEX auch bewerten,\n"
    .string "wenn wir getrennt sind.\p"
    .string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav:
    .string "PROF. BIRCH wurde im POKéNAV registriert.$"

Route110_Text_KeepAnEyeOutForRival:
    .string "PROF. BIRCH: {PLAYER}{KUN}…\p"
    .string "Bitte halte Ausschau nach meinem {RIVAL}.\n"
    .string "… … … … … …\p"
    .string "Nun, ich sollte besser weitermachen.\n"
    .string "Bis bald, {PLAYER}{KUN}!$"

Route110_EventScript_Geckabor::
    msgbox Route110_Text_Geckabor, MSGBOX_NPC
    end

Route110_Text_Geckabor:
    .string "Hey {PLAYER}, hier der Tipp:\p"
	.string "Irgendwo auf dieser Route ver-\n"
	.string "steckt sich ein Starter aus der\l"
	.string "3 Generation mit einer Spawnrate\n"
	.string "von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

