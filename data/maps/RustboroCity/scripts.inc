RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end

RustboroCity_EventScript_PositionScientistForExit::
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit::
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall::
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	waitmovement 0
	playse SE_EXIT
	delay 10
	addobject LOCALID_RUSTBORO_SCIENTIST
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	waitmovement 0
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav::
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial::
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	waitstate
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	waitstate
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_RUSTBORO_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown:
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown:
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer:
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave:
	walk_up
	step_end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Man1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy::
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Man2::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_StolenGoodsTrigger0::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4::
	lockall
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene::
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_RUSTBORO_GRUNT
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_RUSTBORO_GRUNT
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	waitmovement 0
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff::
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou::
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	waitmovement 0
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp:
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_EventScript_DevonEmployee1::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_Movement_EmployeeApproachPlayerDown:
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_BagFull::
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerRight::
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	setvar VAR_0x8004, LOCALID_RUSTBORO_RIVAL
	spawnrival_style
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	lockall
	call Common_EventScript_SetupRivalMusic
	return

RustboroCity_EventScript_RivalTrigger0::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter::
	lockall
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_ShowRivalMessage

RustboroCity_EventScript_ShowRivalMessage::
	getplayerstyle
	copyvar VAR_TEMP_0, VAR_RESULT
	copyvar VAR_TEMP_1, VAR_STARTER_REGION

	compare VAR_TEMP_0, STYLE_BRENDAN
	goto_if_eq RustboroCity_EventScript_Rival_MAY
	compare VAR_TEMP_0, STYLE_MAY
	goto_if_eq RustboroCity_EventScript_Rival_BRENDAN
	compare VAR_TEMP_0, STYLE_RED
	goto_if_eq RustboroCity_EventScript_Rival_LEAF
	compare VAR_TEMP_0, STYLE_LEAF
	goto_if_eq RustboroCity_EventScript_Rival_RED
	compare VAR_TEMP_0, STYLE_ETHAN
	goto_if_eq RustboroCity_EventScript_Rival_LYRA
	compare VAR_TEMP_0, STYLE_LYRA
	goto_if_eq RustboroCity_EventScript_Rival_ETHAN
	compare VAR_TEMP_0, STYLE_LUCAS
	goto_if_eq RustboroCity_EventScript_Rival_DAWN
	compare VAR_TEMP_0, STYLE_DAWN
	goto_if_eq RustboroCity_EventScript_Rival_LUCAS
	compare VAR_TEMP_0, STYLE_HILBERT
	goto_if_eq RustboroCity_EventScript_Rival_HILDA
	compare VAR_TEMP_0, STYLE_HILDA
	goto_if_eq RustboroCity_EventScript_Rival_HILBERT
	end

RustboroCity_EventScript_Rival_MAY::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleMay::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleMay_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleMay_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleMay_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleMay_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleMay_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleMay_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleMay_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleMay_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleMay_Paldea
	end

RustboroCity_EventScript_MayBrineyHint::
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

@ ---------- KANTO ----------
RustboroCity_EventScript_BattleMay_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Bulbasaur
	case 1, RustboroCity_EventScript_BattleMay_Charmander
	case 2, RustboroCity_EventScript_BattleMay_Squirtle
	end

RustboroCity_EventScript_BattleMay_Bulbasaur::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_BULBASAUR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Charmander::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_CHARMANDER, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Squirtle::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_SQUIRTLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- JOHTO ----------
RustboroCity_EventScript_BattleMay_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Chikorita
	case 1, RustboroCity_EventScript_BattleMay_Cyndaquil
	case 2, RustboroCity_EventScript_BattleMay_Totodile
	end

RustboroCity_EventScript_BattleMay_Chikorita::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_CHIKORITA, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Cyndaquil::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_CYNDAQUIL, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Totodile::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TOTODILE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- HOENN ----------
RustboroCity_EventScript_BattleMay_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- SINNOH ----------
RustboroCity_EventScript_BattleMay_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Turtwig
	case 1, RustboroCity_EventScript_BattleMay_Chimchar
	case 2, RustboroCity_EventScript_BattleMay_Piplup
	end

RustboroCity_EventScript_BattleMay_Turtwig::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TURTWIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Chimchar::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_CHIMCHAR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Piplup::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_PIPLUP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- UNOVA ----------
RustboroCity_EventScript_BattleMay_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Snivy
	case 1, RustboroCity_EventScript_BattleMay_Tepig
	case 2, RustboroCity_EventScript_BattleMay_Oshawott
	end

RustboroCity_EventScript_BattleMay_Snivy::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_SNIVY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Tepig::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TEPIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Oshawott::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_OSHAWOTT, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- KALOS ----------
RustboroCity_EventScript_BattleMay_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Chespin
	case 1, RustboroCity_EventScript_BattleMay_Fennekin
	case 2, RustboroCity_EventScript_BattleMay_Froakie
	end

RustboroCity_EventScript_BattleMay_Chespin::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_CHESPIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Fennekin::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_FENNEKIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Froakie::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_FROAKIE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- ALOLA ----------
RustboroCity_EventScript_BattleMay_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Rowlet
	case 1, RustboroCity_EventScript_BattleMay_Litten
	case 2, RustboroCity_EventScript_BattleMay_Popplio
	end

RustboroCity_EventScript_BattleMay_Rowlet::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_ROWLET, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Litten::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_LITTEN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Popplio::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_POPPLIO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- GALAR ----------
RustboroCity_EventScript_BattleMay_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Grookey
	case 1, RustboroCity_EventScript_BattleMay_Scorbunny
	case 2, RustboroCity_EventScript_BattleMay_Sobble
	end

RustboroCity_EventScript_BattleMay_Grookey::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_GROOKEY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Scorbunny::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_SCORBUNNY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Sobble::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_SOBBLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- PALDEA ----------
RustboroCity_EventScript_BattleMay_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMay_Sprigatito
	case 1, RustboroCity_EventScript_BattleMay_Fuecoco
	case 2, RustboroCity_EventScript_BattleMay_Quaxly
	end

RustboroCity_EventScript_BattleMay_Sprigatito::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_SPRIGATITO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Fuecoco::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_FUECOCO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMay_Quaxly::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_QUAXLY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_Rival_BRENDAN::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleBrendan_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleBrendan_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleBrendan_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleBrendan_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleBrendan_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleBrendan_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleBrendan_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleBrendan_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleBrendan_Paldea
	end

RustboroCity_EventScript_BrendanBrineyHint::
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

@ --- KANTO ---
RustboroCity_EventScript_BattleBrendan_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanBulbasaur
	case 1, RustboroCity_EventScript_BattleBrendanCharmander
	case 2, RustboroCity_EventScript_BattleBrendanSquirtle
	end

RustboroCity_EventScript_BattleBrendanBulbasaur::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_BULBASAUR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanCharmander::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_CHARMANDER, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanSquirtle::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_SQUIRTLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- JOHTO ---
RustboroCity_EventScript_BattleBrendan_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanChikorita
	case 1, RustboroCity_EventScript_BattleBrendanCyndaquil
	case 2, RustboroCity_EventScript_BattleBrendanTotodile
	end

RustboroCity_EventScript_BattleBrendanChikorita::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_CHIKORITA, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanCyndaquil::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_CYNDAQUIL, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTotodile::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TOTODILE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- HOENN ---
RustboroCity_EventScript_BattleBrendan_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- SINNOH ---
RustboroCity_EventScript_BattleBrendan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTurtwig
	case 1, RustboroCity_EventScript_BattleBrendanChimchar
	case 2, RustboroCity_EventScript_BattleBrendanPiplup
	end

RustboroCity_EventScript_BattleBrendanTurtwig::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TURTWIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanChimchar::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_CHIMCHAR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanPiplup::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_PIPLUP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- UNOVA ---
RustboroCity_EventScript_BattleBrendan_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanSnivy
	case 1, RustboroCity_EventScript_BattleBrendanTepig
	case 2, RustboroCity_EventScript_BattleBrendanOshawott
	end

RustboroCity_EventScript_BattleBrendanSnivy::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_SNIVY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTepig::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TEPIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanOshawott::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_OSHAWOTT, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- KALOS ---
RustboroCity_EventScript_BattleBrendan_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanChespin
	case 1, RustboroCity_EventScript_BattleBrendanFennekin
	case 2, RustboroCity_EventScript_BattleBrendanFroakie
	end

RustboroCity_EventScript_BattleBrendanChespin::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_CHESPIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanFennekin::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_FENNEKIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanFroakie::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_FROAKIE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- ALOLA ---
RustboroCity_EventScript_BattleBrendan_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanRowlet
	case 1, RustboroCity_EventScript_BattleBrendanLitten
	case 2, RustboroCity_EventScript_BattleBrendanPopplio
	end

RustboroCity_EventScript_BattleBrendanRowlet::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_ROWLET, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanLitten::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_LITTEN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanPopplio::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_POPPLIO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- GALAR ---
RustboroCity_EventScript_BattleBrendan_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanGrookey
	case 1, RustboroCity_EventScript_BattleBrendanScorbunny
	case 2, RustboroCity_EventScript_BattleBrendanSobble
	end

RustboroCity_EventScript_BattleBrendanGrookey::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_GROOKEY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanScorbunny::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_SCORBUNNY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanSobble::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_SOBBLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ --- PALDEA ---
RustboroCity_EventScript_BattleBrendan_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanSprigatito
	case 1, RustboroCity_EventScript_BattleBrendanFuecoco
	case 2, RustboroCity_EventScript_BattleBrendanQuaxly
	end

RustboroCity_EventScript_BattleBrendanSprigatito::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_SPRIGATITO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanFuecoco::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_FUECOCO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanQuaxly::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_QUAXLY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_Rival_RED::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleRed
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleRed::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleRed_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleRed_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleRed_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleRed_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleRed_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleRed_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleRed_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleRed_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleRed_Paldea
	end

RustboroCity_EventScript_BattleRed_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedBulbasaur
	case 1, RustboroCity_EventScript_BattleRedCharmander
	case 2, RustboroCity_EventScript_BattleRedSquirtle
	end

RustboroCity_EventScript_BattleRedBulbasaur::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_BULBASAUR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedCharmander::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_CHARMANDER, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedSquirtle::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_SQUIRTLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedChikorita
	case 1, RustboroCity_EventScript_BattleRedCyndaquil
	case 2, RustboroCity_EventScript_BattleRedTotodile
	end

RustboroCity_EventScript_BattleRedChikorita::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_CHIKORITA, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedCyndaquil::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_CYNDAQUIL, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedTotodile::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_TOTODILE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedTreecko
	case 1, RustboroCity_EventScript_BattleRedTorchic
	case 2, RustboroCity_EventScript_BattleRedMudkip
	end

RustboroCity_EventScript_BattleRedTreecko::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedTorchic::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedMudkip::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedTurtwig
	case 1, RustboroCity_EventScript_BattleRedChimchar
	case 2, RustboroCity_EventScript_BattleRedPiplup
	end

RustboroCity_EventScript_BattleRedTurtwig::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_TURTWIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedChimchar::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_CHIMCHAR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedPiplup::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_PIPLUP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedSnivy
	case 1, RustboroCity_EventScript_BattleRedTepig
	case 2, RustboroCity_EventScript_BattleRedOshawott
	end

RustboroCity_EventScript_BattleRedSnivy::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_SNIVY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedTepig::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_TEPIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedOshawott::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_OSHAWOTT, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedChespin
	case 1, RustboroCity_EventScript_BattleRedFennekin
	case 2, RustboroCity_EventScript_BattleRedFroakie
	end

RustboroCity_EventScript_BattleRedChespin::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_CHESPIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedFennekin::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_FENNEKIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedFroakie::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_FROAKIE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedRowlet
	case 1, RustboroCity_EventScript_BattleRedLitten
	case 2, RustboroCity_EventScript_BattleRedPopplio
	end

RustboroCity_EventScript_BattleRedRowlet::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_ROWLET, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedLitten::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_LITTEN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedPopplio::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_POPPLIO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedGrookey
	case 1, RustboroCity_EventScript_BattleRedScorbunny
	case 2, RustboroCity_EventScript_BattleRedSobble
	end

RustboroCity_EventScript_BattleRedGrookey::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_GROOKEY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedScorbunny::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_SCORBUNNY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedSobble::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_SOBBLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRed_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleRedSprigatito
	case 1, RustboroCity_EventScript_BattleRedFuecoco
	case 2, RustboroCity_EventScript_BattleRedQuaxly
	end

RustboroCity_EventScript_BattleRedSprigatito::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_SPRIGATITO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedFuecoco::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_FUECOCO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleRedQuaxly::
	trainerbattle_no_intro TRAINER_RED_RUSTBORO_QUAXLY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_Rival_LEAF::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleLeaf
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleLeaf::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleLeaf_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleLeaf_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleLeaf_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleLeaf_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleLeaf_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleLeaf_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleLeaf_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleLeaf_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleLeaf_Paldea
	end

@ ---------- KANTO ----------
RustboroCity_EventScript_BattleLeaf_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafBulbasaur
	case 1, RustboroCity_EventScript_BattleLeafCharmander
	case 2, RustboroCity_EventScript_BattleLeafSquirtle
	end

RustboroCity_EventScript_BattleLeafBulbasaur::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_BULBASAUR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafCharmander::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_CHARMANDER, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafSquirtle::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_SQUIRTLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- JOHTO ----------
RustboroCity_EventScript_BattleLeaf_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafChikorita
	case 1, RustboroCity_EventScript_BattleLeafCyndaquil
	case 2, RustboroCity_EventScript_BattleLeafTotodile
	end

RustboroCity_EventScript_BattleLeafChikorita::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_CHIKORITA, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafCyndaquil::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_CYNDAQUIL, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafTotodile::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_TOTODILE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- HOENN ----------
RustboroCity_EventScript_BattleLeaf_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafTreecko
	case 1, RustboroCity_EventScript_BattleLeafTorchic
	case 2, RustboroCity_EventScript_BattleLeafMudkip
	end

RustboroCity_EventScript_BattleLeafTreecko::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafTorchic::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafMudkip::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- SINNOH ----------
RustboroCity_EventScript_BattleLeaf_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafTurtwig
	case 1, RustboroCity_EventScript_BattleLeafChimchar
	case 2, RustboroCity_EventScript_BattleLeafPiplup
	end

RustboroCity_EventScript_BattleLeafTurtwig::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_TURTWIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafChimchar::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_CHIMCHAR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafPiplup::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_PIPLUP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- UNOVA ----------
RustboroCity_EventScript_BattleLeaf_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafSnivy
	case 1, RustboroCity_EventScript_BattleLeafTepig
	case 2, RustboroCity_EventScript_BattleLeafOshawott
	end

RustboroCity_EventScript_BattleLeafSnivy::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_SNIVY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafTepig::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_TEPIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafOshawott::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_OSHAWOTT, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- KALOS ----------
RustboroCity_EventScript_BattleLeaf_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafChespin
	case 1, RustboroCity_EventScript_BattleLeafFennekin
	case 2, RustboroCity_EventScript_BattleLeafFroakie
	end

RustboroCity_EventScript_BattleLeafChespin::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_CHESPIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafFennekin::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_FENNEKIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafFroakie::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_FROAKIE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- ALOLA ----------
RustboroCity_EventScript_BattleLeaf_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafRowlet
	case 1, RustboroCity_EventScript_BattleLeafLitten
	case 2, RustboroCity_EventScript_BattleLeafPopplio
	end

RustboroCity_EventScript_BattleLeafRowlet::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_ROWLET, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafLitten::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_LITTEN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafPopplio::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_POPPLIO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- GALAR ----------
RustboroCity_EventScript_BattleLeaf_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafGrookey
	case 1, RustboroCity_EventScript_BattleLeafScorbunny
	case 2, RustboroCity_EventScript_BattleLeafSobble
	end

RustboroCity_EventScript_BattleLeafGrookey::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_GROOKEY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafScorbunny::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_SCORBUNNY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafSobble::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_SOBBLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ---------- PALDEA ----------
RustboroCity_EventScript_BattleLeaf_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLeafSprigatito
	case 1, RustboroCity_EventScript_BattleLeafFuecoco
	case 2, RustboroCity_EventScript_BattleLeafQuaxly
	end

RustboroCity_EventScript_BattleLeafSprigatito::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_SPRIGATITO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafFuecoco::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_FUECOCO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLeafQuaxly::
	trainerbattle_no_intro TRAINER_LEAF_RUSTBORO_QUAXLY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_Rival_ETHAN::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_EthanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleEthan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_EthanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleEthan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleEthan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleEthan_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleEthan_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleEthan_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleEthan_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleEthan_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleEthan_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleEthan_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleEthan_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleEthan_Paldea
	end

@ KANTO
RustboroCity_EventScript_BattleEthan_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanBulbasaur
	case 1, RustboroCity_EventScript_BattleEthanCharmander
	case 2, RustboroCity_EventScript_BattleEthanSquirtle
	end
RustboroCity_EventScript_BattleEthanBulbasaur::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_BULBASAUR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanCharmander::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_CHARMANDER, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanSquirtle::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_SQUIRTLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ JOHTO
RustboroCity_EventScript_BattleEthan_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanChikorita
	case 1, RustboroCity_EventScript_BattleEthanCyndaquil
	case 2, RustboroCity_EventScript_BattleEthanTotodile
	end
RustboroCity_EventScript_BattleEthanChikorita::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_CHIKORITA, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanCyndaquil::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_CYNDAQUIL, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanTotodile::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_TOTODILE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ HOENN
RustboroCity_EventScript_BattleEthan_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanTreecko
	case 1, RustboroCity_EventScript_BattleEthanTorchic
	case 2, RustboroCity_EventScript_BattleEthanMudkip
	end
RustboroCity_EventScript_BattleEthanTreecko::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanTorchic::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanMudkip::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ SINNOH
RustboroCity_EventScript_BattleEthan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanTurtwig
	case 1, RustboroCity_EventScript_BattleEthanChimchar
	case 2, RustboroCity_EventScript_BattleEthanPiplup
	end
RustboroCity_EventScript_BattleEthanTurtwig::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_TURTWIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanChimchar::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_CHIMCHAR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanPiplup::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_PIPLUP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ UNOVA
RustboroCity_EventScript_BattleEthan_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanSnivy
	case 1, RustboroCity_EventScript_BattleEthanTepig
	case 2, RustboroCity_EventScript_BattleEthanOshawott
	end
RustboroCity_EventScript_BattleEthanSnivy::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_SNIVY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanTepig::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_TEPIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanOshawott::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_OSHAWOTT, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ KALOS
RustboroCity_EventScript_BattleEthan_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanChespin
	case 1, RustboroCity_EventScript_BattleEthanFennekin
	case 2, RustboroCity_EventScript_BattleEthanFroakie
	end
RustboroCity_EventScript_BattleEthanChespin::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_CHESPIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanFennekin::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_FENNEKIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanFroakie::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_FROAKIE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ALOLA
RustboroCity_EventScript_BattleEthan_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanRowlet
	case 1, RustboroCity_EventScript_BattleEthanLitten
	case 2, RustboroCity_EventScript_BattleEthanPopplio
	end
RustboroCity_EventScript_BattleEthanRowlet::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_ROWLET, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanLitten::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_LITTEN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanPopplio::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_POPPLIO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ GALAR
RustboroCity_EventScript_BattleEthan_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanGrookey
	case 1, RustboroCity_EventScript_BattleEthanScorbunny
	case 2, RustboroCity_EventScript_BattleEthanSobble
	end
RustboroCity_EventScript_BattleEthanGrookey::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_GROOKEY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanScorbunny::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_SCORBUNNY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanSobble::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_SOBBLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ PALDEA
RustboroCity_EventScript_BattleEthan_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleEthanSprigatito
	case 1, RustboroCity_EventScript_BattleEthanFuecoco
	case 2, RustboroCity_EventScript_BattleEthanQuaxly
	end
RustboroCity_EventScript_BattleEthanSprigatito::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_SPRIGATITO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanFuecoco::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_FUECOCO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleEthanQuaxly::
	trainerbattle_no_intro TRAINER_ETHAN_RUSTBORO_QUAXLY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_Rival_LYRA::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_LyraAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleLyra
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_LyraAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleLyra
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleLyra::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleLyra_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleLyra_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleLyra_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleLyra_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleLyra_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleLyra_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleLyra_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleLyra_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleLyra_Paldea
	end

@ ================= KANTO =================
RustboroCity_EventScript_BattleLyra_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraBulbasaur
	case 1, RustboroCity_EventScript_BattleLyraCharmander
	case 2, RustboroCity_EventScript_BattleLyraSquirtle
	end
RustboroCity_EventScript_BattleLyraBulbasaur::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_BULBASAUR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraCharmander::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_CHARMANDER, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraSquirtle::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_SQUIRTLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= JOHTO =================
RustboroCity_EventScript_BattleLyra_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraChikorita
	case 1, RustboroCity_EventScript_BattleLyraCyndaquil
	case 2, RustboroCity_EventScript_BattleLyraTotodile
	end
RustboroCity_EventScript_BattleLyraChikorita::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_CHIKORITA, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraCyndaquil::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_CYNDAQUIL, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraTotodile::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_TOTODILE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= HOENN =================
RustboroCity_EventScript_BattleLyra_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraTreecko
	case 1, RustboroCity_EventScript_BattleLyraTorchic
	case 2, RustboroCity_EventScript_BattleLyraMudkip
	end
RustboroCity_EventScript_BattleLyraTreecko::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraTorchic::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraMudkip::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= SINNOH =================
RustboroCity_EventScript_BattleLyra_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraTurtwig
	case 1, RustboroCity_EventScript_BattleLyraChimchar
	case 2, RustboroCity_EventScript_BattleLyraPiplup
	end
RustboroCity_EventScript_BattleLyraTurtwig::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_TURTWIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraChimchar::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_CHIMCHAR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraPiplup::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_PIPLUP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= UNOVA =================
RustboroCity_EventScript_BattleLyra_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraSnivy
	case 1, RustboroCity_EventScript_BattleLyraTepig
	case 2, RustboroCity_EventScript_BattleLyraOshawott
	end
RustboroCity_EventScript_BattleLyraSnivy::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_SNIVY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraTepig::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_TEPIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraOshawott::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_OSHAWOTT, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= KALOS =================
RustboroCity_EventScript_BattleLyra_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraChespin
	case 1, RustboroCity_EventScript_BattleLyraFennekin
	case 2, RustboroCity_EventScript_BattleLyraFroakie
	end
RustboroCity_EventScript_BattleLyraChespin::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_CHESPIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraFennekin::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_FENNEKIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraFroakie::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_FROAKIE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= ALOLA =================
RustboroCity_EventScript_BattleLyra_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraRowlet
	case 1, RustboroCity_EventScript_BattleLyraLitten
	case 2, RustboroCity_EventScript_BattleLyraPopplio
	end
RustboroCity_EventScript_BattleLyraRowlet::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_ROWLET, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraLitten::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_LITTEN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraPopplio::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_POPPLIO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= GALAR =================
RustboroCity_EventScript_BattleLyra_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraGrookey
	case 1, RustboroCity_EventScript_BattleLyraScorbunny
	case 2, RustboroCity_EventScript_BattleLyraSobble
	end
RustboroCity_EventScript_BattleLyraGrookey::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_GROOKEY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraScorbunny::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_SCORBUNNY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraSobble::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_SOBBLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ================= PALDEA =================
RustboroCity_EventScript_BattleLyra_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLyraSprigatito
	case 1, RustboroCity_EventScript_BattleLyraFuecoco
	case 2, RustboroCity_EventScript_BattleLyraQuaxly
	end
RustboroCity_EventScript_BattleLyraSprigatito::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_SPRIGATITO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraFuecoco::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_FUECOCO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleLyraQuaxly::
	trainerbattle_no_intro TRAINER_LYRA_RUSTBORO_QUAXLY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_Rival_LUCAS::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_LucasAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleLucas
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_LucasAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleLucas
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleLucas::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleLucas_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleLucas_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleLucas_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleLucas_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleLucas_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleLucas_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleLucas_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleLucas_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleLucas_Paldea
	end

@ ================= KANTO =================
RustboroCity_EventScript_BattleLucas_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasBulbasaur
	case 1, RustboroCity_EventScript_BattleLucasCharmander
	case 2, RustboroCity_EventScript_BattleLucasSquirtle
	end
RustboroCity_EventScript_BattleLucasBulbasaur::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_BULBASAUR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasCharmander::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_CHARMANDER, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasSquirtle::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_SQUIRTLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= JOHTO =================
RustboroCity_EventScript_BattleLucas_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasChikorita
	case 1, RustboroCity_EventScript_BattleLucasCyndaquil
	case 2, RustboroCity_EventScript_BattleLucasTotodile
	end
RustboroCity_EventScript_BattleLucasChikorita::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_CHIKORITA, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasCyndaquil::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_CYNDAQUIL, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasTotodile::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_TOTODILE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= HOENN =================
RustboroCity_EventScript_BattleLucas_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasTreecko
	case 1, RustboroCity_EventScript_BattleLucasTorchic
	case 2, RustboroCity_EventScript_BattleLucasMudkip
	end
RustboroCity_EventScript_BattleLucasTreecko::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasTorchic::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasMudkip::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= SINNOH =================
RustboroCity_EventScript_BattleLucas_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasTurtwig
	case 1, RustboroCity_EventScript_BattleLucasChimchar
	case 2, RustboroCity_EventScript_BattleLucasPiplup
	end
RustboroCity_EventScript_BattleLucasTurtwig::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_TURTWIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasChimchar::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_CHIMCHAR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasPiplup::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_PIPLUP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= UNOVA =================
RustboroCity_EventScript_BattleLucas_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasSnivy
	case 1, RustboroCity_EventScript_BattleLucasTepig
	case 2, RustboroCity_EventScript_BattleLucasOshawott
	end
RustboroCity_EventScript_BattleLucasSnivy::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_SNIVY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasTepig::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_TEPIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasOshawott::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_OSHAWOTT, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= KALOS =================
RustboroCity_EventScript_BattleLucas_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasChespin
	case 1, RustboroCity_EventScript_BattleLucasFennekin
	case 2, RustboroCity_EventScript_BattleLucasFroakie
	end
RustboroCity_EventScript_BattleLucasChespin::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_CHESPIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasFennekin::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_FENNEKIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasFroakie::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_FROAKIE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= ALOLA =================
RustboroCity_EventScript_BattleLucas_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasRowlet
	case 1, RustboroCity_EventScript_BattleLucasLitten
	case 2, RustboroCity_EventScript_BattleLucasPopplio
	end
RustboroCity_EventScript_BattleLucasRowlet::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_ROWLET, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasLitten::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_LITTEN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasPopplio::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_POPPLIO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= GALAR =================
RustboroCity_EventScript_BattleLucas_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasGrookey
	case 1, RustboroCity_EventScript_BattleLucasScorbunny
	case 2, RustboroCity_EventScript_BattleLucasSobble
	end
RustboroCity_EventScript_BattleLucasGrookey::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_GROOKEY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasScorbunny::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_SCORBUNNY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasSobble::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_SOBBLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ================= PALDEA =================
RustboroCity_EventScript_BattleLucas_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleLucasSprigatito
	case 1, RustboroCity_EventScript_BattleLucasFuecoco
	case 2, RustboroCity_EventScript_BattleLucasQuaxly
	end
RustboroCity_EventScript_BattleLucasSprigatito::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_SPRIGATITO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasFuecoco::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_FUECOCO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleLucasQuaxly::
	trainerbattle_no_intro TRAINER_LUCAS_RUSTBORO_QUAXLY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_Rival_DAWN::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_DawnAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleDawn
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_DawnAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleDawn
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleDawn::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleDawn_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleDawn_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleDawn_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleDawn_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleDawn_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleDawn_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleDawn_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleDawn_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleDawn_Paldea
	end

@ ========== KANTO ==========
RustboroCity_EventScript_BattleDawn_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnBulbasaur
	case 1, RustboroCity_EventScript_BattleDawnCharmander
	case 2, RustboroCity_EventScript_BattleDawnSquirtle
	end
RustboroCity_EventScript_BattleDawnBulbasaur::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_BULBASAUR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnCharmander::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_CHARMANDER, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnSquirtle::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_SQUIRTLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== JOHTO ==========
RustboroCity_EventScript_BattleDawn_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnChikorita
	case 1, RustboroCity_EventScript_BattleDawnCyndaquil
	case 2, RustboroCity_EventScript_BattleDawnTotodile
	end
RustboroCity_EventScript_BattleDawnChikorita::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_CHIKORITA, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnCyndaquil::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_CYNDAQUIL, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnTotodile::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_TOTODILE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== HOENN ==========
RustboroCity_EventScript_BattleDawn_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnTreecko
	case 1, RustboroCity_EventScript_BattleDawnTorchic
	case 2, RustboroCity_EventScript_BattleDawnMudkip
	end
RustboroCity_EventScript_BattleDawnTreecko::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnTorchic::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnMudkip::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== SINNOH ==========
RustboroCity_EventScript_BattleDawn_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnTurtwig
	case 1, RustboroCity_EventScript_BattleDawnChimchar
	case 2, RustboroCity_EventScript_BattleDawnPiplup
	end
RustboroCity_EventScript_BattleDawnTurtwig::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_TURTWIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnChimchar::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_CHIMCHAR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnPiplup::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_PIPLUP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== UNOVA ==========
RustboroCity_EventScript_BattleDawn_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnSnivy
	case 1, RustboroCity_EventScript_BattleDawnTepig
	case 2, RustboroCity_EventScript_BattleDawnOshawott
	end
RustboroCity_EventScript_BattleDawnSnivy::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_SNIVY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnTepig::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_TEPIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnOshawott::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_OSHAWOTT, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== KALOS ==========
RustboroCity_EventScript_BattleDawn_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnChespin
	case 1, RustboroCity_EventScript_BattleDawnFennekin
	case 2, RustboroCity_EventScript_BattleDawnFroakie
	end
RustboroCity_EventScript_BattleDawnChespin::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_CHESPIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnFennekin::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_FENNEKIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnFroakie::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_FROAKIE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== ALOLA ==========
RustboroCity_EventScript_BattleDawn_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnRowlet
	case 1, RustboroCity_EventScript_BattleDawnLitten
	case 2, RustboroCity_EventScript_BattleDawnPopplio
	end
RustboroCity_EventScript_BattleDawnRowlet::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_ROWLET, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnLitten::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_LITTEN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnPopplio::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_POPPLIO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== GALAR ==========
RustboroCity_EventScript_BattleDawn_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnGrookey
	case 1, RustboroCity_EventScript_BattleDawnScorbunny
	case 2, RustboroCity_EventScript_BattleDawnSobble
	end
RustboroCity_EventScript_BattleDawnGrookey::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_GROOKEY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnScorbunny::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_SCORBUNNY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnSobble::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_SOBBLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ========== PALDEA ==========
RustboroCity_EventScript_BattleDawn_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleDawnSprigatito
	case 1, RustboroCity_EventScript_BattleDawnFuecoco
	case 2, RustboroCity_EventScript_BattleDawnQuaxly
	end
RustboroCity_EventScript_BattleDawnSprigatito::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_SPRIGATITO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnFuecoco::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_FUECOCO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleDawnQuaxly::
	trainerbattle_no_intro TRAINER_DAWN_RUSTBORO_QUAXLY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_Rival_HILBERT::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_HilbertAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleHilbert
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_HilbertAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleHilbert
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleHilbert::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleHilbert_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleHilbert_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleHilbert_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleHilbert_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleHilbert_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleHilbert_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleHilbert_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleHilbert_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleHilbert_Paldea
	end

@ ===== KANTO =====
RustboroCity_EventScript_BattleHilbert_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertBulbasaur
	case 1, RustboroCity_EventScript_BattleHilbertCharmander
	case 2, RustboroCity_EventScript_BattleHilbertSquirtle
	end
RustboroCity_EventScript_BattleHilbertBulbasaur::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_BULBASAUR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertCharmander::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_CHARMANDER, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertSquirtle::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_SQUIRTLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== JOHTO =====
RustboroCity_EventScript_BattleHilbert_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertChikorita
	case 1, RustboroCity_EventScript_BattleHilbertCyndaquil
	case 2, RustboroCity_EventScript_BattleHilbertTotodile
	end
RustboroCity_EventScript_BattleHilbertChikorita::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_CHIKORITA, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertCyndaquil::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_CYNDAQUIL, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertTotodile::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_TOTODILE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== HOENN =====
RustboroCity_EventScript_BattleHilbert_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertTreecko
	case 1, RustboroCity_EventScript_BattleHilbertTorchic
	case 2, RustboroCity_EventScript_BattleHilbertMudkip
	end
RustboroCity_EventScript_BattleHilbertTreecko::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertTorchic::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertMudkip::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== SINNOH =====
RustboroCity_EventScript_BattleHilbert_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertTurtwig
	case 1, RustboroCity_EventScript_BattleHilbertChimchar
	case 2, RustboroCity_EventScript_BattleHilbertPiplup
	end
RustboroCity_EventScript_BattleHilbertTurtwig::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_TURTWIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertChimchar::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_CHIMCHAR, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertPiplup::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_PIPLUP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== UNOVA =====
RustboroCity_EventScript_BattleHilbert_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertSnivy
	case 1, RustboroCity_EventScript_BattleHilbertTepig
	case 2, RustboroCity_EventScript_BattleHilbertOshawott
	end
RustboroCity_EventScript_BattleHilbertSnivy::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_SNIVY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertTepig::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_TEPIG, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertOshawott::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_OSHAWOTT, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== KALOS =====
RustboroCity_EventScript_BattleHilbert_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertChespin
	case 1, RustboroCity_EventScript_BattleHilbertFennekin
	case 2, RustboroCity_EventScript_BattleHilbertFroakie
	end
RustboroCity_EventScript_BattleHilbertChespin::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_CHESPIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertFennekin::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_FENNEKIN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertFroakie::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_FROAKIE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== ALOLA =====
RustboroCity_EventScript_BattleHilbert_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertRowlet
	case 1, RustboroCity_EventScript_BattleHilbertLitten
	case 2, RustboroCity_EventScript_BattleHilbertPopplio
	end
RustboroCity_EventScript_BattleHilbertRowlet::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_ROWLET, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertLitten::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_LITTEN, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertPopplio::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_POPPLIO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== GALAR =====
RustboroCity_EventScript_BattleHilbert_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertGrookey
	case 1, RustboroCity_EventScript_BattleHilbertScorbunny
	case 2, RustboroCity_EventScript_BattleHilbertSobble
	end
RustboroCity_EventScript_BattleHilbertGrookey::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_GROOKEY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertScorbunny::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_SCORBUNNY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertSobble::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_SOBBLE, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

@ ===== PALDEA =====
RustboroCity_EventScript_BattleHilbert_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHilbertSprigatito
	case 1, RustboroCity_EventScript_BattleHilbertFuecoco
	case 2, RustboroCity_EventScript_BattleHilbertQuaxly
	end
RustboroCity_EventScript_BattleHilbertSprigatito::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_SPRIGATITO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertFuecoco::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_FUECOCO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end
RustboroCity_EventScript_BattleHilbertQuaxly::
	trainerbattle_no_intro TRAINER_HILBERT_RUSTBORO_QUAXLY, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_Rival_HILDA::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_HildaAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleHilda
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_HildaAskToBattle::
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleHilda
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleHilda::
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, RustboroCity_EventScript_BattleHilda_Kanto
	case STARTER_REGION_JOHTO, RustboroCity_EventScript_BattleHilda_Johto
	case STARTER_REGION_HOENN, RustboroCity_EventScript_BattleHilda_Hoenn
	case STARTER_REGION_SINNOH, RustboroCity_EventScript_BattleHilda_Sinnoh
	case STARTER_REGION_UNOVA, RustboroCity_EventScript_BattleHilda_Unova
	case STARTER_REGION_KALOS, RustboroCity_EventScript_BattleHilda_Kalos
	case STARTER_REGION_ALOLA, RustboroCity_EventScript_BattleHilda_Alola
	case STARTER_REGION_GALAR, RustboroCity_EventScript_BattleHilda_Galar
	case STARTER_REGION_PALDEA, RustboroCity_EventScript_BattleHilda_Paldea
	end

@ ===== KANTO =====
RustboroCity_EventScript_BattleHilda_Kanto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaBulbasaur
	case 1, RustboroCity_EventScript_BattleHildaCharmander
	case 2, RustboroCity_EventScript_BattleHildaSquirtle
	end
RustboroCity_EventScript_BattleHildaBulbasaur::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_BULBASAUR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaCharmander::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_CHARMANDER, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaSquirtle::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_SQUIRTLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== JOHTO =====
RustboroCity_EventScript_BattleHilda_Johto::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaChikorita
	case 1, RustboroCity_EventScript_BattleHildaCyndaquil
	case 2, RustboroCity_EventScript_BattleHildaTotodile
	end
RustboroCity_EventScript_BattleHildaChikorita::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_CHIKORITA, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaCyndaquil::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_CYNDAQUIL, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaTotodile::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_TOTODILE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== HOENN =====
RustboroCity_EventScript_BattleHilda_Hoenn::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaTreecko
	case 1, RustboroCity_EventScript_BattleHildaTorchic
	case 2, RustboroCity_EventScript_BattleHildaMudkip
	end
RustboroCity_EventScript_BattleHildaTreecko::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaTorchic::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaMudkip::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== SINNOH =====
RustboroCity_EventScript_BattleHilda_Sinnoh::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaTurtwig
	case 1, RustboroCity_EventScript_BattleHildaChimchar
	case 2, RustboroCity_EventScript_BattleHildaPiplup
	end
RustboroCity_EventScript_BattleHildaTurtwig::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_TURTWIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaChimchar::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_CHIMCHAR, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaPiplup::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_PIPLUP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== UNOVA =====
RustboroCity_EventScript_BattleHilda_Unova::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaSnivy
	case 1, RustboroCity_EventScript_BattleHildaTepig
	case 2, RustboroCity_EventScript_BattleHildaOshawott
	end
RustboroCity_EventScript_BattleHildaSnivy::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_SNIVY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaTepig::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_TEPIG, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaOshawott::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_OSHAWOTT, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== KALOS =====
RustboroCity_EventScript_BattleHilda_Kalos::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaChespin
	case 1, RustboroCity_EventScript_BattleHildaFennekin
	case 2, RustboroCity_EventScript_BattleHildaFroakie
	end
RustboroCity_EventScript_BattleHildaChespin::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_CHESPIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaFennekin::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_FENNEKIN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaFroakie::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_FROAKIE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== ALOLA =====
RustboroCity_EventScript_BattleHilda_Alola::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaRowlet
	case 1, RustboroCity_EventScript_BattleHildaLitten
	case 2, RustboroCity_EventScript_BattleHildaPopplio
	end
RustboroCity_EventScript_BattleHildaRowlet::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_ROWLET, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaLitten::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_LITTEN, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaPopplio::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_POPPLIO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== GALAR =====
RustboroCity_EventScript_BattleHilda_Galar::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaGrookey
	case 1, RustboroCity_EventScript_BattleHildaScorbunny
	case 2, RustboroCity_EventScript_BattleHildaSobble
	end
RustboroCity_EventScript_BattleHildaGrookey::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_GROOKEY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaScorbunny::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_SCORBUNNY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaSobble::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_SOBBLE, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

@ ===== PALDEA =====
RustboroCity_EventScript_BattleHilda_Paldea::
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleHildaSprigatito
	case 1, RustboroCity_EventScript_BattleHildaFuecoco
	case 2, RustboroCity_EventScript_BattleHildaQuaxly
	end
RustboroCity_EventScript_BattleHildaSprigatito::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_SPRIGATITO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaFuecoco::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_FUECOCO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end
RustboroCity_EventScript_BattleHildaQuaxly::
	trainerbattle_no_intro TRAINER_HILDA_RUSTBORO_QUAXLY, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_Movement_RivalApproachPlayer0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3:
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4:
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5:
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_Boy1::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_Text_WeShortenItToDevon:
	.string "Die DEVON CORPORATION…\n"
	.string "Sagen alle einfach nur DEVON.\p"
	.string "Die bauen so ziemlich alles, was man\n"
	.string "irgendwie gebrauchen kann.$"

RustboroCity_Text_SneakyLookingManWentAroundCorner:
	.string "Was? Ein shady Typ?\p"
	.string "Jo, ich glaub, der ist eben da um die Ecke\n"
	.string "geschlichen. Sah nicht vertrauenswürdig aus.$"

RustboroCity_Text_HaveYouChallengedGym:
	.string "Hast du dich schon an der ARENA\n"
	.string "versucht?\p"
	.string "Wenn du diesen coolen ORDEN hast,\n"
	.string "wissen die anderen TRAINER:\l"
	.string "Du meinst es ernst.$"

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.string "Whoa! Das ist der ORDEN von METAROST!\p"
	.string "Kein Witz - der ist der stylischste von allen.$"

RustboroCity_Text_YoureNewAroundHere:
	.string "Hey… dich hab ich hier noch nie gesehen.\p"
	.string "Neu in der Gegend? Frisch in der\n"
	.string "TRAINERSCHULE?$"

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.string "Ich hab’s versucht… aber meine Feuer-\n"
	.string "Pokémon haben bei der ARENA\l"
	.string "gnadenlos verkackt…\p"
	.string "GESTEIN ist halt nicht gerade\n"
	.string "ihr Lieblingsgegner.$"

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.string "Der alte Mr. Brack wohnt an der Küste.\p"
	.string "Der spaziert manchmal einfach im\n"
	.string "Tunnel rum.\p"
	.string "Rentner-Life halt.$"

RustboroCity_Text_MrBrineyLovesPeeko:
	.string "Mr. Brack - Seebär mit Herz.\p"
	.string "Der war wohl shoppen für sein geliebtes PEEKO.\n"
	.string "In FALESIA. Ganz schön weit für Vogelfutter!$"

RustboroCity_Text_WowYouHavePokemon:
	.string "Whoa, du hast auch Pokémon?\p"
	.string "Wenn ich groß bin, will ich auch mit\n"
	.string "Pokémon durch die Welt ziehen!$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.string "TRAINERSCHULE…\p"
	.string "Wenn ich da hingehe, kann ich dann\n"
	.string "seltene Pokémon ganz easy fangen?$"

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.string "Wenn ein Pokémon viele Kämpfe macht,\n"
	.string "verändert es sich manchmal richtig krass.$"

RustboroCity_Text_PokemonChangeShape:
	.string "Ein Pokémon, das sich komplett\n"
	.string "verwandelt? Ich würd ausflippen!$"

RustboroCity_Text_TradePokemonGrowFast:
	.string "Tausch-Pokémon wachsen wie Unkraut.\p"
	.string "Aber ohne bestimmte ORDEN hören die\n"
	.string "einfach nicht auf dich… so frech!$"

RustboroCity_Text_OutOfTheWay:
	.string "Ey! Platz da!\n"
	.string "Aus dem Weg, Mann!$"

RustboroCity_Text_WaitDontTakeMyGoods:
	.string "Hey! HALT!\p"
	.string "Nicht meine WAREN!!$"

RustboroCity_Text_HelpMeIWasRobbed:
	.string "Oh hey, du bist’s!\p"
	.string "Du warst der Held im Wald, oder?\p"
	.string "Jetzt haben mich diese\n"
	.string "AQUA-Clowns ausgeraubt!\p"
	.string "Bitte hilf mir, die DEVON-WAREN\n"
	.string "zurückzuholen!\p"
	.string "Sonst… bin ich sowas von am Ar… äh, dran!$"

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
	.string "Der Typ? Der sah nicht ganz koscher aus.\n"
	.string "Ist in Richtung Tunnel abgehauen.$"

RustboroCity_Text_YouGotItThankYou:
	.string "Whoa! Du hast sie echt zurückgeholt?\p"
	.string "Die DEVON-WAREN? Hammer!\n"
	.string "Du bist der Wahnsinn!\p"
	.string "Hier, nimm das - ein\n"
	.string "zu gebrauchen!$"

RustboroCity_Text_YoureLoadedWithItems:
	.string "Äh… du bist randvoll mit Zeug.\n"
	.string "Ich kann dir nix mehr geben - räum mal auf.$"

RustboroCity_Text_PleaseComeWithMe:
	.string "Sorry, sorry!\n"
	.string "Komm schnell mit - das musst du sehen.$"

RustboroCity_Text_MayHiLetsRegister:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Heeeey, {PLAYER}{KUN}!\p"
	.string "Du hast jetzt MATCH CALL im POKéNAV!\p"
	.string "Komm, lass uns Nummern tauschen.\n"
	.string "Dann bleib ich dir auf den Fersen!{COLOR DARK_GRAY}$"

RustboroCity_Text_RegisteredMay:
	.string "{RIVAL} wurde ins POKéNAV eingetragen.$"

RustboroCity_Text_MayPassedBrineyWantToBattle:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Hab grad Mr. Brack im\n"
	.string "Wald getroffen…\p"
	.string "Der wackelt wohl zurück in seine\n"
	.string "Hütte am Meer.\p"
	.string "Und dein POKéDEX, {PLAYER}{KUN}?\n"
	.string "Meiner füllt sich super!\p"
	.string "Also, Bock auf 'nen schnellen Kampf?{COLOR DARK_GRAY}$"

RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Oh… echt jetzt?\p"
	.string "Noch keine Pokémon trainiert?\n"
	.string "Du enttäuschst mich!{COLOR DARK_GRAY}$"

RustboroCity_Text_MayWantToBattle:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Und? Lust auf einen kleinen Fight?{COLOR DARK_GRAY}$"

RustboroCity_Text_MayImNotGoingToLose:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Du bist neu, klar.\n"
	.string "Aber ich geh hier nicht unter!{COLOR DARK_GRAY}$"

RustboroCity_Text_MayDefeat:
	.string "Whoa!\n"
	.string "Du bist besser als ich dachte!$"

RustboroCity_Text_MayMrBrineyHint:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Ach ja, dieser Mr. Brack…\p"
	.string "Du bist neu in der Gegend, aber früher war\n"
	.string "der Typ ’ne echte Seefahrer-Legende.{COLOR DARK_GRAY}$"

RustboroCity_Text_BrendanHiLetsRegister:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Yo, {PLAYER}!\p"
	.string "MATCH CALL auf deinem POKéNAV? Nice!\p"
	.string "Lass Nummern tauschen, dann bleib ich\n"
	.string "up to date!{COLOR DARK_GRAY}$"

RustboroCity_Text_RegisteredBrendan:
	.string "{RIVAL} wurde im POKéNAV gespeichert.$"

RustboroCity_Text_BrendanPassedBrineyWantToBattle:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Hab grad Mr. Brack im\n"
	.string "Wald gesehen…\p"
	.string "Zieht’s wohl wieder an die\n"
	.string "Küste zurück.\p"
	.string "Wie läuft dein POKéDEX?\n"
	.string "Meiner? Voll nice!\p"
	.string "Komm, wir battlen kurz.\n"
	.string "Zeig, was du drauf hast!{COLOR DARK_GRAY}$"

RustboroCity_Text_BrendanNoConfidenceInPokemon:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Was los?\n"
	.string "Vertraust du deinen Pokémon nicht?{COLOR DARK_GRAY}$"

RustboroCity_Text_BrendanWantToBattle:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Na los - wie wär’s mit ’nem Battle?{COLOR DARK_GRAY}$"

RustboroCity_Text_BrendanIWontGoEasy:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Frischling hin oder her -\n"
	.string "ich nehm dich nicht auf die leichte Schulter!{COLOR DARK_GRAY}$"

RustboroCity_Text_BrendanDefeat:
	.string "Nicht schlecht!\n"
	.string "Da steckt was in dir.$"

RustboroCity_Text_BrendanMrBrineyHint:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Kennst du Mr. Brack?\n"
	.string "Der chillt irgendwo am Meer.\p"
	.string "Der war mal ein richtiger Seemann, kein Witz.{COLOR DARK_GRAY}$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "“Schneller Tunnel, fast fertig!“\p"
	.string "…steht da. Jemand hat ein riesiges\n"
	.string "rotes X drübergesprüht. Nice.$"

RustboroCity_Text_DevonCorpSign:
	.string "DEVON CORPORATION\p"
	.string "“Alles fürs Leben - wir bauen’s.“$"

RustboroCity_Text_GymSign:
	.string "Pokémon ARENA - METAROST CITY\n"
	.string "Leiterin: FELIZIA\p"
	.string "“Gestählt und gestochen\n"
	.string "scharf - Musterschülerin!“$"

RustboroCity_Text_DevonCorpBranchOfficeSign:
	.string "DEVON-NIEDERLASSUNG\p"
	.string "“Nur für Mitarbeiter\n"
	.string "kein Zutritt für Normalos!“$"

RustboroCity_Text_CitySign:
	.string "METAROST CITY\p"
	.string "“Natur trifft auf Wissenschaft.\l"
	.string "Ziemlich cool hier.“$"

RustboroCity_Text_TrainersSchoolSign:
	.string "TRAINERSCHULE\p"
	.string "“Hier wird’s ernst - alles über Pokémon!“$"

RustboroCity_Text_CuttersHouse:
	.string "HAUS DES SCHNEIDERS$"

RustboroCity_Text_DevelopedNewPokenavFeature:
	.string "Ich hab 'ne neue POKéNAV-Funktion\p"
	.string "gebastelt… Richtig gut geworden!\n"
	.string "Zeig mal her - das POKéNAV vom PRÄSI!$"

RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
	.string "Da, bitteschön!\p"
	.string "MATCH CALL ist jetzt am Start.\p"
	.string "Damit kannst du mit allen labern,\n"
	.string "die du eingespeichert hast.\p"
	.string "Probier’s direkt mal mit PRÄSIDENT STONE!\p"
	.string "Komm schon - call ihn an.$"

RustboroCity_Text_PleaseSelectPokenav:
	.string "Wähl einfach das POKéNAV aus.$"

RustboroCity_Text_IdBetterGetBackToWork:
	.string "Okay, zurück an die Arbeit.\n"
	.string "Viel Erfolg da draußen, {PLAYER}!$"

RustboroCity_Text_YouCanHave2On2Battle:
	.string "Schon gewusst?\p"
	.string "Du kannst 'nen 2vs2-Kampf machen,\n"
	.string "auch ohne zweiten TRAINER bei dir.\p"
	.string "Zwei Gegner spotten dich - zack, Doppel-\l"
	.string "duell!\p"
	.string "Ziemlich cool, wenn du beide alleine\n"
	.string "fertig machst!$"

RustboroCity_EventScript_TeamRocket::
	msgbox RustboroCity_Text_TeamRocket, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamAqua::
	msgbox RustboroCity_Text_TeamAqua, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamMagma::
	msgbox RustboroCity_Text_TeamMagma, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamGalactic::
	msgbox RustboroCity_Text_TeamGalactic, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamPlasma::
	msgbox RustboroCity_Text_TeamPlasma, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamNeoPlasma::
	msgbox RustboroCity_Text_TeamNeoPlasma, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamFlare::
	msgbox RustboroCity_Text_TeamFlare, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamSkull::
	msgbox RustboroCity_Text_TeamSkull, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamYell::
	msgbox RustboroCity_Text_TeamYell, MSGBOX_NPC
	end

RustboroCity_EventScript_TeamStar::
	msgbox RustboroCity_Text_TeamStar, MSGBOX_NPC
	end

RustboroCity_Text_TeamRocket:
	.string "Ich bin ein Mitglied von Team Rocket!$"

RustboroCity_Text_TeamAqua:
	.string "Ich bin ein Mitglied von Team Aqua!$"

RustboroCity_Text_TeamMagma:
	.string "Ich bin ein Mitglied von Team Magma!$"

RustboroCity_Text_TeamGalactic:
	.string "Ich bin ein Mitglied von Team Galactic!$"

RustboroCity_Text_TeamPlasma:
	.string "Ich bin ein Mitglied von Team Plasma!$"

RustboroCity_Text_TeamNeoPlasma:
	.string "Ich bin ein Mitglied von Team Neo Plasma!$"

RustboroCity_Text_TeamFlare:
	.string "Ich bin ein Mitglied von Team Flare!$"

RustboroCity_Text_TeamSkull:
	.string "Ich bin ein Mitglied von Team Skull!$"

RustboroCity_Text_TeamYell:
	.string "Ich bin ein Mitglied von Team Yell!$"

RustboroCity_Text_TeamStar:
	.string "Ich bin ein Mitglied von Team Star!$"

