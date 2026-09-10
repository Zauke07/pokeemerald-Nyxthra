GraniteCave_B6F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B6F_OnTransition
	.byte 0

GraniteCave_B6F_OnTransition:
	setflag FLAG_HIDE_GRANITE_CAVE_METAGROSS
	goto_if_set FLAG_CAUGHT_SHINY_METAGROSS, GraniteCave_B6F_OnTransition_Done
	goto_if_unset FLAG_BADGE06_GET, GraniteCave_B6F_OnTransition_Done
	clearflag FLAG_HIDE_GRANITE_CAVE_METAGROSS
GraniteCave_B6F_OnTransition_Done:
	end

GraniteCave_B6F_EventScript_Metagross::
	lock
	faceplayer
	waitse
	msgbox GraniteCave_B6F_Text_MetagrossIntro, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_METAGROSS, 50
	special ForceShinyScriptedWildMon
	playmoncry SPECIES_METAGROSS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playbgm MUS_DP_VS_LEGEND, TRUE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, GraniteCave_B6F_EventScript_MetagrossCaught
	removeobject LOCALID_GRANITE_CAVE_B6F_METAGROSS
	msgbox GraniteCave_B6F_Text_MetagrossGone, MSGBOX_DEFAULT
	release
	end

GraniteCave_B6F_EventScript_MetagrossCaught::
	setflag FLAG_CAUGHT_SHINY_METAGROSS
	removeobject LOCALID_GRANITE_CAVE_B6F_METAGROSS
	release
	end

GraniteCave_B6F_Text_MetagrossIntro:
	.string "Ein schillerndes METAGROSS versperrt\n"
	.string "dir den Weg!$"

GraniteCave_B6F_Text_MetagrossGone:
	.string "METAGROSS verschwindet in der\n"
	.string "Dunkelheit der Höhle...$"
