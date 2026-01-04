Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
	givemon SPECIES_CASTFORM_NORMAL, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro::
	.string "Diese Eierköpfe haben ein POKéMON\n"
	.string "gezüchtet, das am Wetter rumfummelt.\l"
	.string "Das gehört jetzt uns, verstanden?!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat::
	.string "Willst du mich rollen? Ein Kind macht\n"
	.string "hier den dicken Max?!$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle::
	.string "Wenn dieses Wetter-Vieh echt existiert,\n"
	.string "wird TEAM AQUA damit die Welt fluten!\l"
	.string "Und du kannst nix dagegen tun!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro::
	.string "Wir sind TEAM AQUA!\n"
	.string "Wir krallen uns alles, was selten ist!\l"
	.string "Und jetzt kriegst du erst mal eins aufs Maul!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat::
	.string "Toll…… das war's wohl.$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle::
	.string "Du hast doch keinen Plan, was wir hier\n"
	.string "vorbereiten! Zisch ab und spiel im\l"
	.string "hohen Gras Verstecken!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro::
	.string "Sag nicht, du willst das Wetter-Vieh\n"
	.string "auch klauen? Schwing deinen Arsch\l"
	.string "wieder raus, wir waren zuerst hier!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat::
	.string "Na toll, schau dir meine POKéMON an……\n"
	.string "Alles Trümmerhaufen.$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle::
	.string "Hmpf…… Scheiß drauf!\n"
	.string "Das, was wir eigentlich suchen……\p"
	.string "ist hier sowieso nicht zu finden……\n"
	.string "Hihihihihihihiiiii……$"

Route119_WeatherInstitute_2F_Text_ShellyIntro::
	.string "Ahahahahaha!!!\p"
	.string "Du willst dich echt mit TEAM AQUA\n"
	.string "anlegen? Mutig oder einfach nur hohl?\p"
	.string "Du bist ja so niedlich…… zum Kotzen!\n"
	.string "Ich polier dir jetzt die Fresse, Baby!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat::
	.string "Ahahahahaha!!!!!\n"
	.string "Du bist widerlich…… widerlich stark!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle::
	.string "Als ob der Stress mit TEAM MAGMA nicht\n"
	.string "schon reichen würde, jetzt kommst du\l"
	.string "auch noch aus deinem Loch gekrochen!\p"
	.string "Warum steckst du deine Nase in Dinge,\n"
	.string "die dich einen feuchten Dreck angehen?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy::
	.string "Leute, wir haben hier 'nen Notfall!\p"
	.string "Ein Trupp von TEAM MAGMA ist gerade am\n"
	.string "INSTITUT vorbeigerannt!\p"
	.string "Die ziehen voll Richtung PYROBERG durch!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre::
	.string "Was?!?\n"
	.string "Dann lassen wir den Schrott hier liegen!\p"
	.string "Abflug! Wir müssen zum PYROBERG, bevor\n"
	.string "die MAGMA-Spacken alles einsacken!\p"
	.string "Ahahahahahaha!\n"
	.string "TEAM MAGMA, zieht euch warm an!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon::
	.string "Danke!\n"
	.string "Echt jetzt, danke! Wir sind gerettet!\p"
	.string "Nimm das Vieh hier als Belohnung.\n"
	.string "Wir haben davon eh zu viele rumliegen!$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform::
	.string "{PLAYER} erhält FORMEO (den Wetter-Fritzen)!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather::
	.string "Das Teil ändert seine Form, je nachdem\n"
	.string "wie das Wetter gerade drauf ist.\p"
	.string "Nimm es ruhig mit, wir haben hier im\n"
	.string "Lager noch genug davon rumstehen.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous::
	.string "Ich glotz seit Jahren auf den Regen.\n"
	.string "Zu glauben, dass Menschen das Wetter\l"
	.string "kontrollieren können, ist totaler Bullshit.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather::
	.string "Ich protokollier hier das Chaos in HOENN.\p"
	.string "Momentan brennt die Luft auf\n"
	.string "der {STR_VAR_1} richtig weg!\p"
	.string "Das heißt wohl, dass dort……$"

Route119_WeatherInstitute_2F_Text_KyogreWeather::
	.string "Ich schau mir die Katastrophen an.\p"
	.string "Im Moment säuft die {STR_VAR_1}\n"
	.string "regelrecht ab!\p"
	.string "Ob das bedeutet, dass auf der {STR_VAR_1}……$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather::
	.string "Alles wieder ruhig. Keine Weltuntergänge\n"
	.string "in Sicht.\p"
	.string "Ein bisschen Regen ab und zu ist okay,\n"
	.string "dann muss ich meinen Garten nicht gießen.$"

