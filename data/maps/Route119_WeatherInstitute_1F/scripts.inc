Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro::
	.string "Der BOSS will die Forschungsdaten haben,\n"
	.string "also ziehen wir das hier durch.\p"
	.string "Verpiss dich, Kleiner, oder du fängst\n"
	.string "dir eine!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat::
	.string "Was zum……?\n"
	.string "Abgezogen von 'ner halben Portion!$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle::
	.string "Der BOSS hat den Plan, ich bin nur für's\n"
	.string "Grobe hier.\p"
	.string "Glaubst du echt, ich krieg als RÜPEL\n"
	.string "erzählt, was in seinem Kopf abgeht?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro::
	.string "Häh?\n"
	.string "Was stolpert denn hier für 'ne Blage rum?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat::
	.string "Wie jetzt?\n"
	.string "Ich hab echt geloost?!?$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle::
	.string "Oh Mann. Der Boss macht mich zur Sau,\n"
	.string "weil ich gegen ein Kind verloren hab……\p"
	.string "Ich leg mich jetzt erst mal hin und\n"
	.string "heul 'ne Runde.$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs::
	.string "Während ich hier gepennt hab, sind die\n"
	.string "anderen nach oben abgezischt!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong::
	.string "Boah! Du hast die ja voll plattgemacht!\p"
	.string "Ich wünschte, ich wär auch so'n krasser\n"
	.string "TRAINER und kein Schreibtischtäter!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain::
	.string "Der PROFESSOR ist total besessen vom\n"
	.string "Regen. Der Typ ist echt schräg.\p"
	.string "Aber wenn es weiter so schifft, saufen\n"
	.string "wir hier alle ab. Das ist die Kacke dabei.\p"
	.string "Deswegen versucht er rauszufinden, ob\n"
	.string "der Regen für irgendwas gut ist.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather::
	.string "Hier im ersten Stock glotzen wir auf\n"
	.string "die Klimawerte von ganz HOENN.\p"
	.string "Momentan gibt's entweder extreme\n"
	.string "Dürre oder totale Sintfluten. Echt übel!$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo::
	.string "Tagchen! Danke, dass du die Spinner\n"
	.string "hier rausgeprügelt hast!\p"
	.string "Keine Ahnung, was Team AQUA von uns\n"
	.string "wollte…… wir haben doch nur Daten!$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed::
	.string "Da steht 'ne Gammel-Pritsche……\n"
	.string "Bock auf 'ne Runde pennen?$"

