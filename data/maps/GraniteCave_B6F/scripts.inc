GraniteCave_B6F_MapScripts::
	.byte 0

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
