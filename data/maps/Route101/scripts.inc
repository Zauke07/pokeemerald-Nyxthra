Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	goto Route101_EventScript_ChooseStarterRegion

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "H-help me!$"

Route101_Text_PleaseHelp:
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe:
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} ROSALTSTADT$"

Route101_EventScript_Glumanda::
	msgbox Route101_Text_Glumanda, MSGBOX_NPC
	end

Route101_Text_Glumanda:
	.string "Hey {PLAYER}, ich bin ein\n"
	.string "Bote von diesem Rom Entwickler.\l"
	.string "Sein name ist Zauke07!\p"
	.string "Immer wenn du mich am ende einer\n"
	.string "Route Siehst, sprich mich an, denn\l"
	.string "ich habe einen Heißen Tipp für dich!\p"
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 1 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

Route101_EventScript_ChooseStarterRegion::
    msgbox Route101_Text_WhichStarterRegion, MSGBOX_DEFAULT
    closemessage
    special ShowStarterRegionMulti
    waitstate
    switch VAR_RESULT
    case 0, SetStarterRegion_Kanto
    case 1, SetStarterRegion_Johto
    case 2, SetStarterRegion_Hoenn
    case 3, SetStarterRegion_Sinnoh
    case 4, SetStarterRegion_Unova
    case 5, SetStarterRegion_Kalos
    case 6, SetStarterRegion_Alola
    case 7, SetStarterRegion_Galar
    case 8, SetStarterRegion_Paldea
    end

SetStarterRegion_Kanto::
    setvar VAR_STARTER_REGION, STARTER_REGION_KANTO
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Johto::
    setvar VAR_STARTER_REGION, STARTER_REGION_JOHTO
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Hoenn::
    setvar VAR_STARTER_REGION, STARTER_REGION_HOENN
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Sinnoh::
    setvar VAR_STARTER_REGION, STARTER_REGION_SINNOH
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Unova::
    setvar VAR_STARTER_REGION, STARTER_REGION_UNOVA
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Kalos::
    setvar VAR_STARTER_REGION, STARTER_REGION_KALOS
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Alola::
    setvar VAR_STARTER_REGION, STARTER_REGION_ALOLA
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Galar::
    setvar VAR_STARTER_REGION, STARTER_REGION_GALAR
    goto Route101_EventScript_BirchsBag_Continued

SetStarterRegion_Paldea::
    setvar VAR_STARTER_REGION, STARTER_REGION_PALDEA
    goto Route101_EventScript_BirchsBag_Continued

Route101_EventScript_BirchsBag_Continued::
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_ZIGZAGOON
    setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
    setflag FLAG_RESCUED_BIRCH
    special ChooseStarter
    waitstate
    applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
    waitmovement 0
    msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
    special HealPlayerParty
    setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
    clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
    setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
    setvar VAR_BIRCH_LAB_STATE, 2
    setvar VAR_ROUTE101_STATE, 3
    clearflag FLAG_HIDE_MAP_NAME_POPUP
    getplayerstyle
    call_if_eq VAR_RESULT, STYLE_BRENDAN, Route101_EventScript_HideMayInBedroom
    call_if_eq VAR_RESULT, STYLE_MAY, Route101_EventScript_HideBrendanInBedroom
    call_if_eq VAR_RESULT, STYLE_RED, Route101_EventScript_HideMayInBedroom
    call_if_eq VAR_RESULT, STYLE_LEAF, Route101_EventScript_HideBrendanInBedroom
    warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
    waitstate
    release
    end

Route101_Text_WhichStarterRegion:
    .string "Wähle die Region des Starters:\n"
    .string "{COLOR RED}Kanto{COLOR WHITE}, {COLOR GREEN}Johto{COLOR WHITE}, {COLOR BLUE}Hoenn{COLOR WHITE}, {COLOR LIGHT_BLUE}Sinnoh{COLOR WHITE},\l"
    .string "{COLOR LIGHT_RED}Einall{COLOR WHITE}, {COLOR LIGHT_GREEN}Kalos{COLOR WHITE}, {COLOR DYNAMIC_COLOR4}Alola{COLOR WHITE}, {COLOR DYNAMIC_COLOR5}Galar{COLOR WHITE},\p"
    .string "{COLOR DYNAMIC_COLOR6}Paldea{COLOR WHITE}.$"

Route101_Text_DebugKantoReached:
    .string "Kanto-Auswahl erkannt.$"

Route101_Text_DebugCompareKanto:
    .string "Vergleich mit 0 erreicht.$"

Route101_Text_DebugStarterRegion:
    .string "Starter-Region = {STR_VAR_1}$"

Route101_Text_DebugStarterVarResult:
    .string "Starterwahl = {STR_VAR_1}$"

