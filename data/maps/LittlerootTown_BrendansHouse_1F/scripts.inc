LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
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
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
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
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
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
	.string "MOM: Siehst du, {PLAYER}?\n"
	.string "Ist es hier drinnen nicht auch schön?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Die POKéMON machen die ganze Arbeit\n"
	.string "des Einziehens und Aufräumens.\l"
	.string "Das ist so praktisch!\p"
	.string "{PLAYER}, dein Zimmer ist oben.\n"
	.string "Geh und sieh es dir an, Schatz!\p"
	.string "DAD hat dir eine neue Uhr gekauft.\p"
	.string "Vergiss nicht, sie zu stellen!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MOM: Nun, {PLAYER}?\p"
	.string "Bist du nicht neugierig, dein\n"
	.string "neues Zimmer zu sehen?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Stell bitte die Uhr in deinem Zimmer ein.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Schnell! Komm schnell!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Schau mal, das ist Blütenburg Arena!\n"
	.string "Ich glaube, DAD ist im Fernsehen!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Oh... Es ist vorbei.\p"
	.string "Ich glaube, DAD war dabei, wir haben\n"
	.string "ihn verpasst. Schade.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ach ja.\n"
	.string "Einer von Dad's Freunden lebt hier.\p"
	.string "PROF. BIRK ist sein Name.\p"
	.string "Er lebt gleich nebenan, daher solltest\n"
	.string "du hinübergehen und dich vorstellen.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: Siehst du, Schatz!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MOM: Hast du dich bei PROF. BIRK\n"
	.string "vorgestellt?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: Wie geht es dir, {PLAYER}?\n"
	.string "Du siehst ein wenig müde aus.\p"
	.string "Ich denke, du solltest dich etwas\n"
	.string "ausruhen.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Pass auf dich auf, Schatz!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MOM: Oh? Hat DAD dir den Orden gegeben?\p"
	.string "Dann ist hier etwas von deiner MOM!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Streng dich nicht zu sehr an, Schatz.\n"
	.string "Du kannst jederzeit nach Hause kommen.\p"
	.string "Pass auf dich auf, Schatz!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: Was ist das, Schatz? Ein POKéNAV?\n"
	.string "Jemand aus DEVON hat es dir gegeben?\p"
	.string "Nun, Schatz, wie wäre es mit einer\n"
	.string "Registrierung deiner Mutter?\p"
	.string "... ... ...$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registriert MOM\n"
	.string "in den POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo...$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: Das haben wir mitgebracht\n"
	.string "Bericht von vor der Blütenburg Arena.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Da läuft gerade ein Film.\p"
	.string "Zwei Männer tanzen auf riesengroßen\n"
	.string "Klaviertasten.\p"
	.string "Aber es wird Zeit aufzubrechen!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Das ist die Gebrauchsanweisung für die\n"
	.string "Turbotreter.\p"
	.string "“Halte den B-Knopf gedrückt um zu\n"
	.string "rennen, während du die Turbotreter an\n"
	.string "hast.“$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, hier ist {PLAYER}!\p"
	.string "Es ist schon eine Weile her, dass ich\n"
	.string "dich gesehen habe,\n"
	.string "aber du siehst irgendwie...stärker aus.\p"
	.string "Das ist der Eindruck, den ich habe.\n"
	.string "Aber dein alter Herr hat noch nicht aufgegeben!\p"
	.string "Oh, ja, ich habe etwas für dich.\n"
	.string "Das kam für dich von jemandem namens\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, ein TICKET für eine Fähre?\p"
	.string "Ich weiß, dass es in GRAPHITPORT CITY\n"
	.string "und SEEGRASULB CITY Anlegestellen für\l"
	.string "Fähren gibt.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Ich gehe besser zurück zur Blütenburg Arena.\p"
	.string "MOM, danke, dass du auf das Haus\n"
	.string "aufpasst, während ich weg bin.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: Dein DAD...\p"
	.string "Er kommt zum ersten Mal seit einer halben\n"
	.string "ewigkeit, aber alles worüber er spricht\n"
	.string "ist POKéMON.\p"
	.string "Er sollte sich entspannen und ein bisschen\n"
	.string "länger bleiben.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Ist das eine Eilmeldung?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Hier sind die Sondernachrichten.\p"
	.string "Wir haben die Meldung erhalten, dass in\n"
	.string "der HOENN-Region ein GRSSSS…\l"
	.string "farbiges POKéMON gesichtet wurde.\p"
	.string "Die Identität des POKéMON konnte\n"
	.string "bisher nicht festgestellt werden.\p"
	.string "Und damit schalten wir wieder um in\n"
	.string "unser laufendes Programm.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, hast du das gesehen?\p"
	.string "Welche Farbe hat der Ansager gesagt?\n"
	.string "welche Farbe hatte das POKéMON?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Na, das ist doch was!"
	.string "Es gibt noch unbekannte POKéMON.$"
