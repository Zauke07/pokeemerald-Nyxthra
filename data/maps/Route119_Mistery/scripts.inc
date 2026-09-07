Route119_Mistery_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_Mistery_OnTransition
	.byte 0

Route119_Mistery_OnTransition:
	call_if_unset FLAG_CAUGHT_MEWTWO_STATUE, Route119_Mistery_EventScript_SetMysteryFog
	end

Route119_Mistery_EventScript_SetMysteryFog::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	return


MewtwoStatue_EventScript::
	goto_if_set FLAG_CAUGHT_MEWTWO_STATUE, MewtwoStatue_EventScript_AfterCaught
	goto_if_eq VAR_TEMP_0, 1, MewtwoStatue_EventScript_EndSilent

	lockall

	msgbox MewtwoStatue_Text_Intro, MSGBOX_DEFAULT
	closemessage

	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 6
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate

	msgbox MewtwoStatue_Text_Awakening, MSGBOX_DEFAULT
	closemessage

	seteventmon SPECIES_MEWTWO, 70

	waitse
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry

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

	msgbox MewtwoStatue_Text_CaughtFlash, MSGBOX_DEFAULT
	closemessage

	fadeoutbgm 4
	resetweather
	doweather

	msgbox MewtwoStatue_Text_CaughtSilence, MSGBOX_DEFAULT
	closemessage

	releaseall
	end


MewtwoStatue_EventScript_Vanished::
	setvar VAR_TEMP_0, 1
	msgbox MewtwoStatue_Text_Vanished, MSGBOX_DEFAULT
	releaseall
	end


MewtwoStatue_EventScript_AfterCaught::
	lock
	msgbox MewtwoStatue_Text_AfterCaught, MSGBOX_DEFAULT
	release
	end


MewtwoStatue_EventScript_EndSilent::
	end


MewtwoStatue_Text_Intro:
	.string "Ein kalter Schauer läuft dir über\n"
	.string "den Rücken, als deine Hand den\l"
	.string "kalten Stein berührt.\p"
	.string "Für einen Moment ist alles\n"
	.string "vollkommen still…\p"
	.string "Dann beginnt der Boden unter\n"
	.string "deinen Füßen zu vibrieren!$"

MewtwoStatue_Text_Awakening:
	.string "Die Augen der Statue beginnen\n"
	.string "unheimlich zu leuchten…\p"
	.string "Eine gewaltige Präsenz erwacht\n"
	.string "vor dir!$"

MewtwoStatue_Text_CaughtFlash:
	.string "Ein greller Lichtblitz durchzuckt\n"
	.string "den Raum -$"

MewtwoStatue_Text_CaughtSilence:
	.string "und dann kehrt nur noch Stille\n"
	.string "ein.\p"
	.string "Die Statue ist zu gewöhnlichem\n"
	.string "Stein erstarrt.$"

MewtwoStatue_Text_AfterCaught:
	.string "Die Statue ist nur noch ein\n"
	.string "gewöhnlicher Steinblock.\p"
	.string "Von der geheimnisvollen Präsenz,\n"
	.string "die einst hier war, ist nichts\l"
	.string "mehr zu spüren.$"

MewtwoStatue_Text_Vanished:
	.string "Für einen Moment scheint die\n"
	.string "Zeit stillzustehen…\p"
	.string "Dann verschwindet Mewtu ohne\n"
	.string "jede Spur.$"
