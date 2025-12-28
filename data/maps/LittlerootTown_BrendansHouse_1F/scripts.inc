LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_1F_EventScript_SetReadyToMeetBrendan
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetReadyToMeetBrendan::
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_BrendansHouse_1F_EventScript_Ready
	goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_BrendansHouse_1F_EventScript_Ready
	goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_BrendansHouse_1F_EventScript_Ready
	goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_BrendansHouse_1F_EventScript_Ready
	goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_BrendansHouse_1F_EventScript_Ready
@	goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_BrendansHouse_1F_EventScript_Ready
@	goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_BrendansHouse_1F_EventScript_Ready
@	goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_BrendansHouse_1F_EventScript_Ready
@	goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_BrendansHouse_1F_EventScript_Ready
@	goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_BrendansHouse_1F_EventScript_Ready
	return

LittlerootTown_BrendansHouse_1F_EventScript_Ready::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
@	getplayerstyle
@	compare VAR_RESULT, STYLE_BRENDAN
@	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_SkipNeighbor
@	compare VAR_RESULT, STYLE_RED
@	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_SkipNeighbor
@	compare VAR_RESULT, STYLE_ETHAN
@	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_SkipNeighbor
@	compare VAR_RESULT, STYLE_HILBERT
@	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_SkipNeighbor
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

@LittlerootTown_BrendansHouse_1F_EventScript_SkipNeighbor:
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	lockall
	setvar VAR_0x8004, LOCALID_BRENDANSHOUSE_1F_RIVAL
	getplayerstyle
	goto LittlerootTown_BrendansHouse_1F_ContinueMeetRival

LittlerootTown_BrendansHouse_1F_ContinueMeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_BRENDANSHOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2

	@ HIER NEU:
	setflag FLAG_FIX_RIVAL_DOOR_RAN_BRENDAN

	playse SE_EXIT
	removeobject LOCALID_BRENDANSHOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_BRENDANSHOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MOM: Naja, immerhin kein Schimmel an der\n"
	.string "Wand.\p"
    .string "Willkommen in deinem neuen Loch, {PLAYER}.$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Die Pokémon haben geschuftet, ich\n"
    .string "hab’s gefilmt.\p"
	.string "Wird bei Insta gut laufen.\p"
	.string "{PLAYER}, dein Zimmer ist oben.\n"
	.string "Ich hab sogar deine Uhr aufgehängt.\p"
	.string "Stell sie aber selbst ein.\n"
    .string "ich bin doch nicht dein Butler.$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MOM: Echt jetzt, {PLAYER}?\p"
	.string "Nicht mal neugierig auf dein neues Reich?\n"
	.string "Oben - wenn du’s findest.$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Stell deine scheiß Uhr in deinem Zimmer!$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: {PLAYER}! Schneller als dein\n"
    .string "letztes Date!\p"
	.string "Du verpasst was!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Da! Das ist Blütenburgs Arena!\n"
	.string "Vielleicht siehst du ja deinen alten mal.$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Na toll… Zu langsam wie immer.\p"
	.string "DAD war grad im TV und du warst nicht da.\n"
	.string "Schon fast wie früher.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "MOM: Nebenan wohnt dieser irre Professor.\n"
	.string "Geh hin und sag hallo. Oder tu so.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: So, ich chill jetzt.\p"
	.string "Mach was du willst.$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MOM: Warst du schon beim bekloppten Prof?\n"
	.string "Oder hast du dich wieder verlaufen?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: Du siehst aus wie durchgekaut.\p"
	.string "Leg dich kurz hin oder trink\l"
    .string "wenigstens Wasser.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Pass auf dich auf.\n"
    .string "Und bring nix mit Flöhen.$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MOM: Whoa, DAD hat dir echt 'nen Orden gegeben?\p"
	.string "Hier, nimm das. Hab’s beim Flohmarkt geklaut.$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Mach dich nicht kaputt da draußen.\n"
	.string "Aber wenn doch, ruf halt an.\p"
	.string "Oder nicht. Deine Entscheidung.$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: Ist das dieses fancy Ding?\n"
	.string "Hat dir jemand aus DEVON geschenkt?\p"
	.string "Na komm, speicher wenigstens meine Nummer,\n"
	.string "falls du mal Geld brauchst.$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MOM wurde in den Pokénav eingespeichert.\n"
	.string "jetzt bist du offiziell verloren.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: Das haben wir mitgebracht\n"
	.string "Bericht von vor der Blütenburg Arena.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Da läuft gerade Prosieben.\p"
	.string "Krass wiederholung von Circus HalliGalli!\p"
	.string "Aber egal, muss los!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Das ist die Gebrauchsanweisung für die\n"
	.string "Turbotreter.\p"
	.string "“Halte den B-Knopf gedrückt um zu\n"
	.string "rennen, während du die Turbotreter an\n"
	.string "hast.“$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm? Da ist ja mein Kind.\p"
	.string "Schon groß geworden, oder hab ich Alzheimer?\p"
	.string "Hier - irgendso'n alter Typ hat dir\n"
    .string "das zugeschickt.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Ticket für 'ne Fähre?\p"
	.string "Versuch’s in GRAPHITPORT oder SEEGRASULB.\n"
	.string "Wenn du's findest, bist du gut.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Ich bin dann wieder in der Arena.\p"
	.string "MOM passt auf die Bude auf. Hoffentlich.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: DAD war kurz da - hat kaum Hallo gesagt.\p"
	.string "Redet nur über Pokémon. Will kein Sex.\n"
    .string "Typisch.$"


PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Ist das eine Eilmeldung?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Hier sind die Sondernachrichten.\p"
	.string "Wir haben die Meldung erhalten, dass in\n"
	.string "der HOENN-Region ein GRSSSS…\l"
	.string "farbiges Pokémon gesichtet wurde.\p"
	.string "Die Identität des Pokémon konnte\n"
	.string "bisher nicht festgestellt werden.\p"
	.string "Und damit schalten wir wieder um in\n"
	.string "unser laufendes Programm.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: Hast du’s gesehen, {PLAYER}?\p"
	.string "Welche Farbe hatte das Pokémon?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Na, das ist doch was!"
	.string "Es gibt noch unbekannte Pokémon.$"
