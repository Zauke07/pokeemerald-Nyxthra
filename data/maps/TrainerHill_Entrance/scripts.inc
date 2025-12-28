TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady::
	.string "Das hier ist der TRAINERBERG.\n"
	.string "Hier werden Amateure wie du am\l"
	.string "laufenden Band aussortiert.\p"
	.string "Leider ist die Arena noch nicht bereit.\n"
	.string "Zieh Leine und komm später wieder!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill::
	.string "Willkommen!\p"
	.string "Das hier ist der TRAINERBERG.\n"
	.string "Der Ort, an dem du lernst, dass deine\l"
	.string "POKéMON eigentlich gar nichts draufhaben!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter::
	.string "Bist du zum ersten Mal hier?\p"
	.string "Bevor du reingehst und dich blamierst,\n"
	.string "speichere gefälligst dein Spiel.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX::
	.string "Mal sehen…\n"
	.string "Die TRAINER, die gerade Zeit haben…\p"
	.string "Hocken bis Stockwerk Nr. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom::
	.string "Mal sehen…\n"
	.string "Die Hütte ist voll.\p"
	.string "In jedem verdammten Zimmer wartet\n"
	.string "jemand darauf, dich fertigzumachen.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers::
	.string "Willst du dich wirklich mit denen\n"
	.string "anlegen, oder hast du schon Schiss?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo::
	.string "Ich stoppe die Zeit, damit jeder sieht,\n"
	.string "wie lange du für deine Niederlage brauchst!\p"
	.string "Auf die Plätze…\p"
	.string "Fertig…\p"
	.string "Und jetzt beweg deinen Hintern! GO!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain::
	.string "Komm bloß wieder, wir brauchen Opfer!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort::
	.string "Tja, das war wohl nichts.\p"
	.string "Du hast dich zwar bemüht, aber\n"
	.string "Mitleidspunkte gibt es hier nicht.\p"
	.string "Üb mal weiter und komm wieder!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest::
	.string "Gib dein Bestes, sonst wird’s peinlich.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch::
	.string "Wenn die TRAINER die Plätze tauschen,\n"
	.string "geht’s hier zu wie im Taubenschlag.\p"
	.string "Damit du nicht unter die Hufe kommst,\n"
	.string "steht der Tresen jetzt hier.\p"
	.string "Stell dich nicht so an wegen der Unannehmlichkeit.$"

TrainerHill_Entrance_Text_ThankYouForPlaying::
	.string "Danke für’s Mitspielen, Kleiner!$"

TrainerHill_Entrance_Text_ExplainTrainerHill::
	.string "Hier am TRAINERBERG machen wir den\n"
	.string "sogenannten Time Attack.\p"
	.string "Das ist ein Rennen vom Tresen bis zum\n"
	.string "Dach, wo der größenwahnsinnige Besitzer\l"
	.string "auf dich wartet.\p"
	.string "Die Rekorde stehen am Board - versuch\n"
	.string "wenigstens, nicht als Letzter draufzustehen.\p"
	.string "Übrigens: In den Kämpfen hier gibt es\n"
	.string "weder EP noch Kohle. Wir sind hier nicht\l"
	.string "beim Wohlfahrtsamt!$"

TrainerHill_Roof_Text_YouFinallyCameBravo::
	.string "Hm! Hm!\p"
	.string "Du hast es tatsächlich geschafft!\n"
	.string "Du bist oben angekommen!\p"
	.string "Halt! Sag nichts!\n"
	.string "Ich weiß genau, warum du dich hier\l"
	.string "hochgequält hast!\p"
	.string "Du wolltest MICH sehen, den Gott des\n"
	.string "TRAINERBERGS, weil…\p"
	.string "Du mein persönlicher Wasserträger sein\n"
	.string "willst! Wa-hoo!\p"
	.string "…Wie?\n"
	.string "Das ist es nicht?\p"
	.string "Egal, ich hab dich beobachtet.\n"
	.string "War ganz okay, für ’nen Anfänger! Bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift::
	.string "Für jemanden, der so viel Glück hatte\n"
	.string "wie du, hab ich ein fettes Geschenk!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis::
	.string "Deine Taschen sind voll mit Schrott!\n"
	.string "Komm wieder, wenn du Platz gemacht hast!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly::
	.string "Oh, Moment mal! Bist du etwa so\n"
	.string "verdammt schnell hier hochgerannt?\p"
	.string "Hättest dich gar nicht so beeilen\n"
	.string "müssen, um meine Visage zu sehen!\p"
	.string "Egal, ich lass das Time Board unten\n"
	.string "direkt mal aktualisieren!$"

TrainerHill_Roof_Text_YouWerentVeryQuick::
	.string "Aber, oh…\n"
	.string "Du warst ja mal echt lahmarschig unterwegs.$"

TrainerHill_Roof_Text_ArriveZippierNextTime::
	.string "Vielleicht beeindruckst du mich mehr,\n"
	.string "wenn du nächstes Mal den Turbo zündest.\p"
	.string "Dann überleg ich mir das vielleicht\n"
	.string "mit dem Tag-Team!\p"
	.string "Man riecht sich, Amigo!$"

TrainerHill_Entrance_Text_ChallengeTime::
	.string "{STR_VAR_1} Min. {STR_VAR_2}.{STR_VAR_3} Sek. (Echt jetzt?)$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead::
	.string "Wer weiß schon, was für Gestalten da\n"
	.string "oben lauern?\p"
	.string "Mir egal, ich hau einfach jedem die\n"
	.string "Zähne raus, der im Weg steht!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters::
	.string "Ich hab gehört, hier kommen die härtesten\n"
	.string "Säue von ganz Hoenn her.\p"
	.string "Endlich mal ein paar Leute zum Boxen!\p"
	.string "Ich mach jeden platt, der meint,\n"
	.string "er wäre was Besseres!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop::
	.string "Siehst du das Board da drüben?\p"
	.string "Meine Kumpels und ich wetten darum, wer\n"
	.string "als Erster oben ist, ohne zu kotzen.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen::
	.string "Wann machen die hier endlich auf?\p"
	.string "Ich warte hier schon ewig, um der erste\n"
	.string "Herausforderer überhaupt zu sein!$"

TrainerHill_Elevator_Text_ReturnToReception::
	.string "Willst du aufgeben und zurück zum\n"
	.string "Tresen kriechen?$"
