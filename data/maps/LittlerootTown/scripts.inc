LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@					and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex

LittlerootTown_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	setvar VAR_0x8004, LOCALID_LITTLEROOT_RIVAL
	spawnrival_style
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
	call_if_set FLAG_UNLOCKED_TESTLABOR_NPC, EventScript_Testlabor_SetGuardPos
	end

EventScript_Testlabor_SetGuardPos::
	checkflag FLAG_UNLOCKED_TESTLABOR_NPC
	call_if FALSE, EventScript_Testlabor_SetGuard_DefaultPos

EventScript_Testlabor_SetGuard_DefaultPos::
	setobjectxyperm LOCALID_LITTLEROOT_BRANDON, 25, 8
	return

LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_EventScript_SetRivalLeftForRoute103::
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_MoveRivalFromOldale::
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	return

LittlerootTown_EventScript_MoveMomToMaysDoor::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 8
	return

LittlerootTown_EventScript_SetTwinPos::
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 10, 1
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_SetTwinGuardingRoutePos::
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
	getplayerstyle
	call_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	call_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	call_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	call_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	call_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
@	call_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
@	call_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
@	call_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
@	call_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
@	call_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
@	call_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
@	call_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
@	call_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
@	call_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
@	call_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
	return

LittlerootTown_OnFrame:
@	map_script_1 LittlerootTown_EventScript_ApplyTruckGraphics
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
@	call_if_set FLAG_UNLOCKED_TESTLABOR_NPC, EventScript_FixTestlaborGuardPosition
	.2byte 0

@EventScript_FixTestlaborGuardPosition::
@	setobjectxyperm LOCALID_LITTLEROOT_BRANDON, 26, 8
@	end

@LittlerootTown_EventScript_ApplyTruckGraphics::
@	checkplayerstyle
@	compare VAR_RESULT, STYLE_BRENDAN
@	goto_if_eq .show_blue
@	compare VAR_RESULT, STYLE_RED
@	goto_if_eq .show_blue

@	@ Leaf oder May → roter Truck
@	hideobject 5	@ blauer Truck ausblenden
@	showobject 6	@ roten Truck anzeigen
@	end

@.show_blue:
@	hideobject 6	@ roter Truck ausblenden
@	showobject 5	@ blauen Truck anzeigen
@	end

LittlerootTown_EventScript_StepOffTruckMale::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_StepOffTruckFemale::
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_GoInsideWithMom::
	delay 15
	playse SE_LEDGE
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LOCALID_LITTLEROOT_MOM
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitHouse
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
	waitmovement 0
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachDoor
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomEnterHouse
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	hideplayer
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_Movement_MomExitHouse:
	walk_down
	step_end

LittlerootTown_Movement_MomApproachPlayerAtTruck:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_Movement_MomApproachDoor:
	delay_16
	delay_8
	walk_up
	step_end

LittlerootTown_Movement_MomEnterHouse:
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_PlayerApproachDoor:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_PlayerEnterHouse:
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
	lockall
	playse SE_PIN
	applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	releaseall
	end

LittlerootTown_OnWarp:
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
	addobject LOCALID_LITTLEROOT_BIRCH
	addobject LOCALID_LITTLEROOT_RIVAL
	getplayerstyle

	compare VAR_RESULT, STYLE_BRENDAN
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
	compare VAR_RESULT, STYLE_RED
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
	compare VAR_RESULT, STYLE_ETHAN
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
	compare VAR_RESULT, STYLE_LUCAS
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
	compare VAR_RESULT, STYLE_HILBERT
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
@	compare VAR_RESULT, STYLE_NATE
@	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
@	compare VAR_RESULT, STYLE_CALEM
@	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
@	compare VAR_RESULT, STYLE_ELIO
@	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
@	compare VAR_RESULT, STYLE_VICTOR
@	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight
@	compare VAR_RESULT, STYLE_FLORIAN
@	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight

	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeLeft


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeLeft:
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeRight:
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
	end

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoSaveBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	release
	end

LittlerootTown_EventScript_YouSavedBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_NeedPokemonTriggerLeft::
	lockall
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_DangerousWithoutPokemon::
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_Movement_TwinApproachPlayerLeft:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_TwinPushPlayerFromRoute:
	walk_down
	step_end

LittlerootTown_Movement_TwinReturnLeft:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_faster_down
	step_end

LittlerootTown_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_NeedPokemonTriggerRight::
	lockall
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
	waitmovement 0
	releaseall
	end

LittlerootTown_Movement_TwinApproachPlayerRight:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end

LittlerootTown_Movement_TwinReturnRight:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
	lockall
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	releaseall
	end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	getplayerstyle
	isstylemale
	call_if_eq VAR_RESULT, TRUE, LittlerootTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouseM, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign::
	lockall
	getplayerstyle
	isstylemale
	call_if_eq VAR_RESULT, TRUE, LittlerootTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouseF, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_GiveRunningShoesTrigger0::
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 10, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_LITTLEROOT_MOM, 11, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger3::
	lockall
	setvar VAR_0x8008, 3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger4::
	lockall
	setvar VAR_0x8008, 4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger5::
	lockall
	setvar VAR_0x8008, 5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger::
	getplayerstyle
	call_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_EventScript_MomNoticePlayerFemale
	call_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_EventScript_MomNoticePlayerFemale
	call_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_EventScript_MomNoticePlayerFemale
	call_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_EventScript_MomNoticePlayerFemale
	call_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_EventScript_MomNoticePlayerFemale
@	call_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_EventScript_MomNoticePlayerMale
@	call_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_EventScript_MomNoticePlayerFemale
@	call_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_EventScript_MomNoticePlayerMale
@	call_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_EventScript_MomNoticePlayerFemale
@	call_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_EventScript_MomNoticePlayerMale
@	call_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_EventScript_MomNoticePlayerFemale
@	call_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_EventScript_MomNoticePlayerMale
@	call_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_EventScript_MomNoticePlayerFemale
@	call_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_EventScript_MomNoticePlayerMale
@	call_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_EventScript_MomNoticePlayerFemale

	call_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale

	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_EventScript_MomApproachPlayerFemale
	call_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_EventScript_MomApproachPlayerFemale
	call_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_EventScript_MomApproachPlayerFemale
	call_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_EventScript_MomApproachPlayerFemale
	call_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_EventScript_MomApproachPlayerFemale
@	call_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_EventScript_MomApproachPlayerMale
@	call_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_EventScript_MomApproachPlayerFemale
@	call_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_EventScript_MomApproachPlayerMale
@	call_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_EventScript_MomApproachPlayerFemale
@	call_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_EventScript_MomApproachPlayerMale
@	call_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_EventScript_MomApproachPlayerFemale
@	call_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_EventScript_MomApproachPlayerMale
@	call_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_EventScript_MomApproachPlayerFemale
@	call_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_EventScript_MomApproachPlayerMale
@	call_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_EventScript_MomApproachPlayerFemale
	call LittlerootTown_EventScript_GiveRunningShoes
	call_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_EventScript_MomReturnHomeFemale
	call_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_EventScript_MomReturnHomeFemale
	call_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_EventScript_MomReturnHomeFemale
	call_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_EventScript_MomReturnHomeFemale
	call_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_EventScript_MomReturnHomeFemale
@	call_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_EventScript_MomReturnHomeMale
@	call_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_EventScript_MomReturnHomeFemale
@	call_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_EventScript_MomReturnHomeMale
@	call_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_EventScript_MomReturnHomeFemale
@	call_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_EventScript_MomReturnHomeMale
@	call_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_EventScript_MomReturnHomeFemale
@	call_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_EventScript_MomReturnHomeMale
@	call_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_EventScript_MomReturnHomeFemale
@	call_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_EventScript_MomReturnHomeMale
@	call_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_EventScript_MomReturnHomeFemale

	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetHomeDoorCoordsMale::
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_MomNoticePlayerMale::
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LittlerootTown_EventScript_MomNoticePlayerFemale::
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
	return

LittlerootTown_EventScript_MomApproachPlayerFemale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
	return

LittlerootTown_EventScript_MomApproachPlayer0::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayer1::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale3::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale4::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerMale5::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale3::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale4::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayerFemale5::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHomeMale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
	return

LittlerootTown_EventScript_MomReturnHomeFemale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
	return

LittlerootTown_EventScript_MomReturnHome0::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHome1::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHomeMale2::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale2
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale3::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale3
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale4::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale4
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale5::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale5
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale2::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale3::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale4::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale5::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_Movement_MomApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayerMale2:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale4:
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale5:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale2:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale3:
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale5:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomReturnHome0:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHome1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHomeMale2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale4:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale5:
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale2:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale3:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomExitThroughDoor:
	walk_up
	step_end

LittlerootTown_EventScript_Mom::
	lock
	getplayerstyle
	faceplayer
	call_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
	call_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
@	call_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_EventScript_SetHomeDoorCoordsMale
@	call_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_EventScript_SetHomeDoorCoordsFemale

	call LittlerootTown_EventScript_GiveRunningShoes
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetReceivedRunningShoes::
	removeobject LOCALID_LITTLEROOT_MOM
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_GiveRunningShoes::
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_EventScript_Boy::
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_Text_BirchSpendsDaysInLab:
	.string "PROF. BIRK hockt den ganzen Tag\n"
	.string "in seinem Labor… oder rennt wie'n Irrer\l"
	.string "durchs Gras, als wär er besessen…\p"
	.string "Manchmal glaub ich, der hat zu viel\n"
	.string "Sonderbonbon geschnupft.$"

LittlerootTown_Text_OurNewHomeLetsGoInside:
	.string "Mom: {PLAYER}, wir sind da, Schatz!\p"
	.string "15 Jahre alt und schon im Umzugswagen\n"
	.string "zwischen Kisten eingepfercht… herrlich!\p"
	.string "Dank dieser endlosen Quarantäne\n"
	.string "mussten wir aus der alten Stadt raus.\p"
	.string "Aber hey - willkommen in WURZELHEIM!\p"
	.string "Klein, friedlich,\n"
	.string "kaum Empfang - perfekt!\p"
	.string "Und… du bekommst dein eigenes Zimmer.\n"
	.string "Lass uns mal reinschauen!$"

LittlerootTown_Text_WaitPlayer:
	.string "Mom: Warte, {PLAYER}!$"
	.string "Mom: Warte, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes:
	.string "Mom: {PLAYER}, schon mit PROF. BIRK\n"
	.string "gequatscht? Hat er dich adoptiert?\p"
	.string "Oh! Das POKéMON steht dir gut.\n"
	.string "Wusste gar nicht, dass du so\l"
	.string " heldenhaft bist!\p"
	.string "Hier, zieh das an - TURBOTRETER!\n"
	.string "Sind besser als deine alten\l"
	.string "Quarantänelatschen.$"

LittlerootTown_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} zieht die TURBOTRETER an.$"
	.string "{PLAYER} zieht die TURBOTRETER an.$"

LittlerootTown_Text_ExplainRunningShoes:
	.string "Mom: Und bevor du losrennst…\n"
	.string "gibt’s auch ’ne Anleitung!\p"
	.string "“Halte den B-Knopf gedrückt,\n"
	.string "wenn du die TURBOTRETER trägst,\l"
	.string "und flitz los wie der Blitz!”\p"
	.string "Jetzt hast du keine Ausrede mehr.\n"
	.string "Ab in die große, gefährliche Welt!$"

LittlerootTown_Text_ComeHomeIfAnythingHappens:
	.string "…\n"
	.string "…\p"
	.string "Mein kleines Quarantäne-Kind zieht\n"
	.string "los mit POKéMON… wie die Zeit vergeht!\p"
	.string "Dein Vater würde platzen vor Stolz.\n"
	.string "Oder Sorge. Oder beidem.\p"
	.string "Aber im Ernst:\n"
	.string "Wenn was schiefläuft, komm heim.\p"
	.string "Bis dahin: Sei frech, wild und wunderbar!$"

LittlerootTown_Text_CanUsePCToStoreItems:
	.string "Jo, das da is’n PC.\n"
	.string "Kein TikTok-Terminal, du Opfer.\p"
	.string "Hier speicherst du Items.\n"
	.string "Nicht deine Fortnite-Skins, klar?\p"
	.string "Und Cloud? Die is nicht hier,\n"
	.string "also heul woanders, Kevin.$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "Äh… Ähm… Hihi…\p"
	.string "Im hohen Gras lauern wilde POKéMON.\n"
	.string "Wie Tinder, nur mit mehr Kratzern.$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon:
	.string "Wenn du kein POKéMON hast,\n"
	.string "bist du basically Futter.\p"
	.string "Geh nicht rein. Du wurdest gewarnt.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
	.string "Uhm… Hallo?\p"
	.string "Da ist ein creepy POKéMON irgendwo da\n"
	.string "drüben. Macht üble Geräusche!\p"
	.string "Ich würd ja nachsehen, aber ich bin\n"
	.string "absolut nicht versichert.\p"
	.string "Hilfst du mir? Vielleicht stirbt ja wer.$"

LittlerootTown_Text_YouSavedBirch:
	.string "Du hast PROF. BIRK gerettet!\n"
	.string "Krass, dachte echt, der ist fällig!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
	.string "Pokébälle check? Zielwasser check?\n"
	.string "Na dann - viel Glück beim Fangen!$"

LittlerootTown_Text_TownSign:
	.string "WURZELHEIM\n"
	.string "“Wo WLAN stirbt und Träume beginnen.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "LABOR von PROF. BIRK\n"
	.string "Betreten auf eigene Gefahr.$"

LittlerootTown_Text_PlayersHouseM:
	.string "Wohnsitz von {PLAYER}\n"
	.string "Schuhe bitte anlassen.$"

LittlerootTown_Text_PlayersHouseF:
	.string "Wohnsitz von {PLAYER}\n"
	.string "Schuhe bitte ausziehen.$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "PROF. BIRKS HAUS\n"
	.string "Kein Eintritt ohne Laborkittel.$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. BIRK: Na, {PLAYER}{KUN}!\n"
	.string "Das war wilde Action da draußen!\p"
	.string "Ich hab sofort gesehen, du bist kein\n"
	.string "Durchschnitts-Kid. Respekt!\p"
	.string "Übrigens… du hast noch meinen POKéDEX,\n"
	.string "oder? Ich will dir was zeigen.\p"
	.string "Komm rüber ins Labor.\n"
	.string "Und keine Panik - keine Experimente.$"

LittlerootTown_EventScript_RotNochKeinChamp::
	msgbox LittlerootTown_Text_RotNochKeinChamp, MSGBOX_NPC
	end

LittlerootTown_Text_RotNochKeinChamp:
	.string "Hallo {PLAYER}!\p"
	.string "Leider wird das Haus noch\n"
	.string "Renoviert.\p"
	.string "Bitte komm doch Später wieder,\n"
	.string "wenn du Champ geworden bist!$"

LittlerootTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox LittlerootTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_Text_Azurill:
	.string "Azurrill..$"

LittlerootTown_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LittlerootTown_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_Text_Azumarill:
	.string "Azumarill..$"

LittlerootTown_EventScript_Champhaus::
	msgbox LittlerootTown_Text_Champhaus, MSGBOX_SIGN
	end

LittlerootTown_Text_Champhaus:
	.string "Haus der Champion's!$"

LittlerootTown_EventScript_Testlabor::
	msgbox LittlerootTown_Text_Testlabor, MSGBOX_SIGN
	end

LittlerootTown_Text_Testlabor:
	.string "Testlabor für Scripts!$"

EventScript_TestlaborGuard::
	lockall
	faceplayer
	checkflag FLAG_UNLOCKED_TESTLABOR_NPC
	goto_if TRUE, EventScript_TestlaborGuard_AlreadyUnlocked

	msgbox TestlaborGuard_AskPassword, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ShowTestPasswordMenu
	waitstate
	compare VAR_RESULT, 1337 @ ← dein echtes Passwort hier!
	goto_if_eq EventScript_TestlaborGuard_Correct

	msgbox TestlaborGuard_WrongPassword, MSGBOX_DEFAULT
	releaseall
	end

EventScript_TestlaborGuard_Correct::
	msgbox TestlaborGuard_CorrectPassword, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLEROOT_BRANDON, Movement_TestlaborGuard_StepAside
	waitmovement 0
	setflag FLAG_UNLOCKED_TESTLABOR_NPC
	releaseall
	end

EventScript_TestlaborGuard_AlreadyUnlocked::
	msgbox TestlaborGuard_WelcomeBack, MSGBOX_DEFAULT
	releaseall
	end

Movement_TestlaborGuard_StepAside:
	walk_in_place_right
	walk_right
	walk_in_place_down
	step_end

TestlaborGuard_AskPassword:
	.string "Zutritt nur für Entwickler!\nBitte nenne das Passwort:$"

TestlaborGuard_CorrectPassword:
	.string "Zugang bestätigt.\nTritt ein.$"

TestlaborGuard_WrongPassword:
	.string "Falsches Passwort.\nZutritt verweigert.$"

TestlaborGuard_WelcomeBack:
	.string "Du bist berechtigt.\nGeh ruhig rein.$"

