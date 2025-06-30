EverGrandeCity_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
	.byte 0

EverGrandeCity_HallOfFame_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_HallOfFame_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame::
	lockall
	applymovement LOCALID_HALL_OF_FAME_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	waitmovement 0
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HALL_OF_FAME_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
	waitmovement 0
	delay 20
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HALL_OF_FAME_WALLACE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, EverGrandeCity_HallOfFame_EventScript_GameClearMale
	goto_if_eq VAR_RESULT, STYLE_RED, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_ETHAN, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_LUCAS, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_HILBERT, EverGrandeCity_HallOfFame_EventScript_GameClearMale
@     goto_if_eq VAR_RESULT, STYLE_NATE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_CALEM, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_ELIO, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_VICTOR, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_FLORIAN, EverGrandeCity_HallOfFame_EventScript_GameClearMale
    goto_if_eq VAR_RESULT, STYLE_MAY, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_LEAF, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_LYRA, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_DAWN, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_HILDA, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
@     goto_if_eq VAR_RESULT, STYLE_ROSA, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_SERENA, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_SELENE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_GLORIA, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
    goto_if_eq VAR_RESULT, STYLE_JULIANA, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
	end

EverGrandeCity_HallOfFame_EventScript_GameClearMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_GameClearFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions:
	.string "Wallace: Dieser Raum…\p"
	.string "Hier bewahren wir die Aufzeichnungen\n"
	.string "der POKéMON auf, die sich durch harte\l"
	.string "Kämpfe durchgesetzt haben.\p"
	.string "Hier werden die CHAMPIONS DER LIGA\n"
	.string "geehrt.$"

EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames:
	.string "Wallace: Komm, lass uns deinen Namen\n"
	.string "als TRAINER verewigen, der die POKéMON-\l"
	.string "LIGA bezwungen hat, sowie die Namen\l"
	.string "der Partner, die an deiner Seite kämpften.$"
