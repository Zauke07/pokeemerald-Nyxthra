MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy::
	.string "ONKEL: Ich glaub, die Viecher tun dem\n"
	.string "Jungen nicht gut. Der ist völlig\l"
	.string "aufgedreht und fängt an, mich massiv\l"
	.string "zu nerven…$"

MauvilleCity_Text_WallyWantToChallengeGym::
	.string "HEIKO: Alter, jetzt halt mal die Luft\n"
	.string "an, ONKEL! Ich will in diese ARENA!\p"
	.string "Ich will sehen, wie ich die Versager\n"
	.string "dort drin demütige. Lass mich jetzt\l"
	.string "einfach machen! Los!$"

MauvilleCity_Text_UncleYourePushingIt::
	.string "ONKEL: Jetzt komm mal runter, Bürschchen.\p"
	.string "Schön und gut, dass du nicht mehr\n"
	.string "alle zwei Meter umkippst.\p"
	.string "Aber du überschätzt dich maßlos, wenn\n"
	.string "du glaubst, du hättest in einer\l"
	.string "echten ARENA eine Chance.$"

MauvilleCity_Text_WallyWeCanBeatAnyone::
	.string "HEIKO: Du hast doch keine Ahnung!\p"
	.string "Wenn TRASLA und ich erst mal loslegen,\n"
	.string "wischen wir mit jedem den Boden auf!$"

MauvilleCity_Text_WallyWillYouBattleMe::
	.string "HEIKO: Oh! Guck mal an, {PLAYER}!\p"
	.string "Seit unserem letzten Treffen hab ich\n"
	.string "ordentlich Muckis aufgebaut.\p"
	.string "{PLAYER}, ich werd dir und diesem\n"
	.string "pessimistischen ONKEL jetzt zeigen,\l"
	.string "wer hier die Hosen anhat.\p"
	.string "{PLAYER}, zieh deine POKéBALLS, ich\n"
	.string "mach dich jetzt fertig!$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong::
	.string "HEIKO: Was is los? Hast du Schiss,\n"
	.string "{PLAYER}? Wenn du jetzt kneifst, denkt\l"
	.string "mein ONKEL ewig, ich wär ein Lappen!$"

MauvilleCity_Text_UncleCanYouBattleWally::
	.string "ONKEL: {PLAYER}{KUN}, oder?\n"
	.string "Tu mir den Gefallen und zieh dem\l"
	.string "Gören eins über die Rübe.\p"
	.string "Der hört mir eh nicht mehr zu und hält\n"
	.string "sich für den King von Hoenn…$"

MauvilleCity_Text_WallyPleaseBattleMe::
	.string "HEIKO: {PLAYER}, jetzt mach schon!\n"
	.string "Kämpf gegen mich! Oder hast du Sand\l"
	.string "im Getriebe?!$"

MauvilleCity_Text_WallyHereICome::
	.string "HEIKO: Na endlich! {PLAYER}, danke!\p"
	.string "Bereite dich auf deine Demütigung vor!\n"
	.string "Hier komme ich!$"

MauvilleCity_Text_WallyDefeat::
	.string "HEIKO: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Das darf doch nicht wahr sein…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf::
	.string "HEIKO: ONKEL…\n"
	.string "Ich verpiss mich wieder nach WIESENFLUR…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle::
	.string "{PLAYER}, krass rasiert! Ein echter\n"
	.string "TRAINER muss wohl ein ziemliches\l"
	.string "Arschloch sein, um zu gewinnen, was?\p"
	.string "Nur POKéMON im Beutel haben reicht\n"
	.string "nicht. Man muss sie wohl richtig\l"
	.string "knechten, um Erfolg zu haben.$"

MauvilleCity_Text_UncleNoNeedToBeDown::
	.string "ONKEL: HEIKO, jetzt flenn nicht rum.\p"
	.string "Trainier halt härter, statt nur dumm\n"
	.string "rumzulabern! Nichts hält dich auf.\p"
	.string "Komm, wir gehen heim.\n"
	.string "In WIESENFLUR kannst du wieder Baby sein.$"

MauvilleCity_Text_UncleVisitUsSometime::
	.string "ONKEL: {PLAYER}{KUN}, mir fällt's wieder ein.\n"
	.string "Du warst derjenige, der auf HEIKO\l"
	.string "aufgepasst hat, als er sein erstes\l"
	.string "Vieh gefangen hat.\p"
	.string "Komm ruhig mal in WIESENFLUR vorbei.\n"
	.string "Dann kann HEIKO dir zeigen, wie viel\l"
	.string "Wut er angestaut hat.$"

MauvilleCity_Text_WallyPokenavCall::
	.string "… … … … …\n"
	.string "…\p"
	.string "HEIKO: Ey, {PLAYER}!\p"
	.string "Pass auf! Mein Onkel hat mir so ein\n"
	.string "POKéNAV-Teil geschenkt.\p"
	.string "Jetzt kann ich dich nerven, wann immer\n"
	.string "ich Bock hab, {PLAYER}!\p"
	.string "… … … … …\n"
	.string "Klick!$"

MauvilleCity_Text_RegisteredWally::
	.string "Der nervige HEIKO wurde in dein\n"
	.string "POKéNAV-Verzeichnis geschmiert.$"

MauvilleCity_Text_ScottYouDidntHoldBack::
	.string "SCOTT: Hehe…\n"
	.string "Geiles Gemetzel gerade!\p"
	.string "Du bist doch ein Kumpel von diesem\n"
	.string "HEIKO, oder?\p"
	.string "Aber du hast ihn eiskalt abserviert.\n"
	.string "Keine Gnade, kein Mitleid. Beeindruckend!\p"
	.string "Yeah! Genau so müssen Kämpfe sein!\n"
	.string "Wer schwach ist, fliegt raus!\p"
	.string "Solche eiskalten TRAINER feier ich!\p"
	.string "Hau weiter so rein!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey::
	.string "WALTER: Oh, {PLAYER}{KUN}!\n"
	.string "Du hast ja echt Eier in der Hose!\l"
	.string "Das gefällt mir, wahahahahahaha…\p"
	.string "Pass auf! Ich hab ’nen Job für dich,\n"
	.string "{PLAYER}{KUN}! Eine echte Drecksarbeit!\p"
	.string "Hier unter der Stadt gibt's ’ne Ruine,\n"
	.string "die wir NEU MALVENFROH nennen.\p"
	.string "Dort läuft ein GENERATOR heiß.\n"
	.string "Geh da runter und schalt das Teil aus,\l"
	.string "bevor uns die ganze Bude um die\l"
	.string "Ohren fliegt!\p"
	.string "Hier ist der SCHLÜSSEL. Verlier ihn nicht!$"

MauvilleCity_Text_WattsonWontBeChallenge::
	.string "WALTER: Keine Sorge. Das ist keine\n"
	.string "Herausforderung, das ist ein Spaziergang.\p"
	.string "Der Eingang ist bei ROUTE 110.\n"
	.string "Einfach ein bisschen surfen und fertig.\p"
	.string "Vertrau mir einfach! Wenn du's überlebst,\n"
	.string "gibt's ’ne Belohnung! Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM::
	.string "WALTER: Wahahahahaha!\p"
	.string "Ich wusste es, {PLAYER}{KUN}! Du bist genau\n"
	.string "das richtige Arbeitstier für sowas!\p"
	.string "Hier, nimm das als Lohn - die TM mit\n"
	.string "DONNERBLITZ!\p"
	.string "Zieh's dir rein! Du hast es dir verdient!$"

MauvilleCity_Text_WattsonYoungTakeCharge::
	.string "WALTER: Wahahahahaha!\p"
	.string "Geil zu sehen, dass die Jugend heutzutage\n"
	.string "noch richtig zupacken kann!$"

MauvilleCity_Text_NurseHurtMonBackToHealth::
	.string "Kämpfe sind ja ganz lustig und so,\n"
	.string "aber wenn dein Vieh halb tot ist,\l"
	.string "musst du es wohl oder übel hier\l"
	.string "wieder zusammenflicken lassen.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough::
	.string "Hier kreuzen sich alle Wege.\n"
	.string "Deshalb rennen hier auch so viele\l"
	.string "seltsame Gestalten rum.$"

MauvilleCity_Text_RydelVeryGenerous::
	.string "Warst du schon bei RADLA?\p"
	.string "Der Typ verschenkt Fahrräder.\n"
	.string "Entweder ist er dumm oder stinkreich.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike::
	.string "Selbst auf deinem Drahtesel bist du\n"
	.string "vor wilden Viechern nicht sicher.$"

MauvilleCity_Text_CitySign::
	.string "MALVENFROH CITY\n"
	.string "“Die Stadt, die niemals schläft und\l"
	.string "immer unter Strom steht!”$"

MauvilleCity_Text_GymSign::
	.string "ARENA von MALVENFROH CITY\n"
	.string "LEITER: WALTER\l"
	.string "“Vorsicht: Hochspannung für Amateure!”$"

MauvilleCity_Text_BikeShopSign::
	.string "RADLAS RÄDER\n"
	.string "“Friss Staub oder fahr im Kies!”$"

MauvilleCity_Text_GameCornerSign::
	.string "MALVENFROH CITY SPIELHALLE\n"
	.string "“Wir nehmen dir jeden Cent ab!”$"

MauvilleCity_Text_ExplainTV::
	.string "Ey, guckst du eigentlich TV?\p"
	.string "Da läuft mittlerweile echt kranker\n"
	.string "Scheiß.\p"
	.string "Manchmal seh ich meine Saufkumpane\n"
	.string "im Fernsehen ausrasten.\p"
	.string "Und oft wirst du gefilmt, ohne dass\n"
	.string "du es merkst. Also benimm dich!\p"
	.string "Ich will auch mal berühmt werden.\p"
	.string "Schalt die Kiste öfter mal ein…$"

MauvilleCity_Text_BeenCheckingOutTV::
	.string "Na, wieder nur vor der Glotze gehangen?$"
