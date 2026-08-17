Route119_Mistery_MapScripts::
	.byte 0

MewtwoStatue_EventScript::
	goto_if_set FLAG_CAUGHT_MEWTWO_STATUE, MewtwoStatue_EventScript_EndSilent
	goto_if_eq VAR_TEMP_0, 1, MewtwoStatue_EventScript_EndSilent

	lockall

	seteventmon SPECIES_MEWTWO, 70

	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30

	special BattleSetup_StartLegendaryBattle
	waitstate

	specialvar VAR_RESULT, GetBattleOutcome

	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MewtwoStatue_EventScript_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MewtwoStatue_EventScript_Vanished
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MewtwoStatue_EventScript_Vanished
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MewtwoStatue_EventScript_Vanished

	releaseall
	end


MewtwoStatue_EventScript_Caught::
	setflag FLAG_CAUGHT_MEWTWO_STATUE
	setvar VAR_TEMP_0, 1
	releaseall
	end


MewtwoStatue_EventScript_Vanished::
	setvar VAR_TEMP_0, 1
	msgbox MewtwoStatue_Text_Vanished, MSGBOX_DEFAULT
	releaseall
	end


MewtwoStatue_EventScript_EndSilent::
	end


MewtwoStatue_Text_Vanished:
	.string "Für einen Moment scheint die\n"
	.string "Zeit stillzustehen…\p"
	.string "Dann verschwindet Mewtu ohne\n"
	.string "jede Spur.$"
