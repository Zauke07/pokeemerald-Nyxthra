InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP

	getplayerstyle
	isstylemale

	goto_if_eq VAR_RESULT, 1, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_ETHAN, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_LYRA, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_LUCAS, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_DAWN, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_HILBERT, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_HILDA, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_NATE, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_ROSA, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_CALEM, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_SERENA, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_ELIO, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_SELENE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_VICTOR, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_GLORIA, InsideOfTruck_EventScript_SetIntroFlagsFemale
	@goto_if_eq VAR_RESULT, STYLE_FLORIAN, InsideOfTruck_EventScript_SetIntroFlagsMale
	@goto_if_eq VAR_RESULT, STYLE_JULIANA, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "Auf der Kiste ist ein Pokémon-Logo.\p"
	.string "Es ist ein Umzugs- und Lieferservice\n"
	.string "einer Pokémon-Firma.$"

