FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting::
	.string "Oh, hi.\n"
	.string "Wer bist du denn?\p"
	.string "Aha, {PLAYER}{KUN} also.\n"
	.string "Ein TRAINER, wie originell.\p"
	.string "Das heißt, du benutzt mein POKéMON-\n"
	.string "Lagerungssystem. Sei gefälligst dankbar.\p"
	.string "Wie ich darauf komme? Einfache Logik.\n"
	.string "Wer so planlos vor einem PC steht wie\l"
	.string "du, braucht Hilfe von Experten.\p"
	.string "Oh, ich bin übrigens LANETTE.\p"
	.string "Eigentlich ist es mir egal, wen ich hier\n"
	.string "treffe, aber immerhin benutzt du meine\l"
	.string "Software ohne sie kaputtzumachen.\p"
	.string "Falls du mal echte Unordnung sehen\n"
	.string "willst: Mein Haus ist auf ROUTE 114.\l"
	.string "Aber fass bloß nichts an!$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown::
	.string "Ich frag mich echt, wie hässlich die\n"
	.string "POKéMON früher ausgesehen haben.\p"
	.string "Vielleicht weiß der FOSSIL-MANIAC am\n"
	.string "Stadtrand mehr. Der Typ ist so verrückt,\l"
	.string "der ist selbst fast ein Fossil.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees::
	.string "Hier in LAUBWECHSELFELD pflanzen wir\n"
	.string "Bäume, die so zäh sind, dass ihnen sogar\l"
	.string "dieser Asche-Dreck nichts ausmacht.\l"
	.string "Müsste man mal mit Menschen versuchen…$"

