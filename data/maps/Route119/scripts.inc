Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_RIVAL_ON_BIKE
	call Common_EventScript_SetupRivalMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL_ON_BIKE
	addobject LOCALID_RIVAL
	delay 30
	getplayerstyle
	copyvar VAR_TEMP_2, VAR_RESULT
	switch VAR_TEMP_2
	case STYLE_BRENDAN, Route119_EventScript_StartBattle_May
	case STYLE_MAY, Route119_EventScript_StartBattle_Brendan
	case STYLE_RED, Route119_EventScript_StartBattle_Leaf
	case STYLE_LEAF, Route119_EventScript_StartBattle_Red
	@call_if_eq VAR_RESULT, STYLE_ETHAN, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_LYRA, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_LUCAS, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_DAWN, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_HILBERT, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_HILDA, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_NATE, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_ROSA, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_CALEM, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_SERENA, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_ELIO, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_SELENE, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_VICTOR, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_GLORIA, Route119_EventScript_BattleBrendan
	@call_if_eq VAR_RESULT, STYLE_FLORIAN, Route119_EventScript_BattleMay
	@call_if_eq VAR_RESULT, STYLE_JULIANA, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_StartBattle_Brendan::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartBrendan_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartBrendan_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartBrendan_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartBrendan_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartBrendan_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartBrendan_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartBrendan_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartBrendan_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartBrendan_Paldea
	end

Route119_EventScript_StartBattle_May::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartMay_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartMay_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartMay_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartMay_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartMay_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartMay_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartMay_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartMay_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartMay_Paldea
	end

Route119_EventScript_StartBattle_Red::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartRed_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartRed_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartRed_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartRed_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartRed_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartRed_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartRed_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartRed_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartRed_Paldea
	end

Route119_EventScript_StartBattle_Leaf::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartLeaf_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartLeaf_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartLeaf_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartLeaf_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartLeaf_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartLeaf_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartLeaf_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartLeaf_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartLeaf_Paldea
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_ROUTE119_SCOTT
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_ROUTE119_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 25, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 26, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Where were you? I was looking for you!\p"
	.string "How much stronger have you gotten?\n"
	.string "Let me check for you!\p"
	.string "Ready with your POKéMON?\n"
	.string "Of course you are! Go!$"

Route119_Text_MayDefeat:
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, you're strong!\p"
	.string "I was worried that you might be\n"
	.string "struggling with your training.$"

Route119_Text_MayPresentForYou:
	.string "MAY: But I had absolutely nothing to\n"
	.string "worry about! Keep it up!\p"
	.string "And, here! I have a present for you.$"

Route119_Text_MayExplainFly:
	.string "MAY: Use FLY, and your POKéMON will\n"
	.string "instantly carry you to any town you've\l"
	.string "already visited.\p"
	.string "But, to use FLY, you have to get\n"
	.string "the GYM BADGE from FORTREE CITY.\l"
	.string "That's important, so don't forget.\p"
	.string "You should FLY home and visit\n"
	.string "LITTLEROOT for a change.\p"
	.string "I bet your mom's worried about you,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Well, let's meet again somewhere!$"

Route119_Text_BrendanIntro:
	.string "BRENDAN: {PLAYER}! So this is where\n"
	.string "you've been looking for POKéMON?\p"
	.string "Let me see how good you got.\n"
	.string "I'll test you!\p"
	.string "Now!\n"
	.string "It's a battle, so battle!$"

Route119_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "You've gotten pretty darn decent.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "BRENDAN: I'd say you're good enough\n"
	.string "to search for POKéMON anywhere.\p"
	.string "Here, I'll give you this.\n"
	.string "Try it out.$"

Route119_Text_BrendanExplainFly:
	.string "BRENDAN: Use FLY, and your POKéMON\n"
	.string "instantly carries you to any town\l"
	.string "you've already visited.\p"
	.string "But you need the FORTREE GYM BADGE \n"
	.string "to do that.\p"
	.string "Anyway, I have to move along.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "SCOTT: Hahahah!\n"
	.string "Way to go, {PLAYER}{KUN}!\p"
	.string "I just passed by a TRAINER riding\n"
	.string "a BIKE.\p"
	.string "You just beat that TRAINER, didn't you?\n"
	.string "It was pretty obvious that you did.\p"
	.string "The kid looked really upset with\n"
	.string "a face all red from anger.\p"
	.string "I sure seem to run into you often.\n"
	.string "Are you off to FORTREE GYM next?\p"
	.string "I expect that you'll do well at the GYM.\n"
	.string "Well, I'll be seeing you!$"


Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
	.string "Just as I thought, you won at\n"
	.string "the FORTREE GYM.\p"
	.string "Your strength…\n"
	.string "Perhaps you really are the TRAINER\l"
	.string "that I've been searching for.\p"
	.string "Remember, you have a fan in me.\n"
	.string "I'll be cheering from the sidelines.\l"
	.string "Keep up the great work!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "We're standing lookout here.\p"
	.string "Hey, you! Stay away from the WEATHER\n"
	.string "INSTITUTE. It's not safe.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Lookout duty is surprisingly boring.\p"
	.string "Hey, you! Please don't go near the\n"
	.string "WEATHER INSTITUTE.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "I thought you FLY by catching a whole\n"
	.string "flock of BIRD POKéMON, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares BIKE tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Can your POKéMON use its SECRET POWER\n"
	.string "on a big pile of grass and make a\l"
	.string "SECRET BASE?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_WeatherInstitute:
	.string "WEATHER INSTITUTE$"

Route119_Text_TrainerTipsDecoration:
	.string "TIPPS für TRAINER\p"
	.string "In der GEHEIMBASIS können bis zu 16\n"
	.string "Dekorationen und Möbel untergebracht\l"
	.string "werden.\p"
	.string "Nimm deine Lieblingsitems und richte dir\n"
	.string "deine GEHEIMBASIS ganz nach deinem\l"
	.string "Geschmack ein.$"

Route119_EventScript_Froxy::
	msgbox Route119_Text_Froxy, MSGBOX_NPC
	end

Route119_Text_Froxy:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 6 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

Route119_EventScript_StartBrendan_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleBULBASAUR
	case 1, Route119_EventScript_StartBrendanBattleCHARMANDER
	case 2, Route119_EventScript_StartBrendanBattleSQUIRTLE
	end

Route119_EventScript_StartBrendanBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleCHIKORITA
	case 1, Route119_EventScript_StartBrendanBattleCYNDAQUIL
	case 2, Route119_EventScript_StartBrendanBattleTOTODILE
	end

Route119_EventScript_StartBrendanBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleTOTODILE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleTREECKO
	case 1, Route119_EventScript_StartBrendanBattleTORCHIC
	case 2, Route119_EventScript_StartBrendanBattleMUDKIP
	end

Route119_EventScript_StartBrendanBattleTREECKO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleTORCHIC::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleMUDKIP::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleTURTWIG
	case 1, Route119_EventScript_StartBrendanBattleCHIMCHAR
	case 2, Route119_EventScript_StartBrendanBattlePIPLUP
	end

Route119_EventScript_StartBrendanBattleTURTWIG::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattlePIPLUP::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleSNIVY
	case 1, Route119_EventScript_StartBrendanBattleTEPIG
	case 2, Route119_EventScript_StartBrendanBattleOSHAWOTT
	end

Route119_EventScript_StartBrendanBattleSNIVY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleTEPIG::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleCHESPIN
	case 1, Route119_EventScript_StartBrendanBattleFENNEKIN
	case 2, Route119_EventScript_StartBrendanBattleFROAKIE
	end

Route119_EventScript_StartBrendanBattleCHESPIN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleFROAKIE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleROWLET
	case 1, Route119_EventScript_StartBrendanBattleLITTEN
	case 2, Route119_EventScript_StartBrendanBattlePOPPLIO
	end

Route119_EventScript_StartBrendanBattleROWLET::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleLITTEN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleGROOKEY
	case 1, Route119_EventScript_StartBrendanBattleSCORBUNNY
	case 2, Route119_EventScript_StartBrendanBattleSOBBLE
	end

Route119_EventScript_StartBrendanBattleGROOKEY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleSOBBLE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleSPRIGATITO
	case 1, Route119_EventScript_StartBrendanBattleFUECOCO
	case 2, Route119_EventScript_StartBrendanBattleQUAXLY
	end

Route119_EventScript_StartBrendanBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleFUECOCO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleQUAXLY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartMay_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleBULBASAUR
	case 1, Route119_EventScript_StartMayBattleCHARMANDER
	case 2, Route119_EventScript_StartMayBattleSQUIRTLE
	end

Route119_EventScript_StartMayBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleCHIKORITA
	case 1, Route119_EventScript_StartMayBattleCYNDAQUIL
	case 2, Route119_EventScript_StartMayBattleTOTODILE
	end

Route119_EventScript_StartMayBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleTOTODILE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleTREECKO
	case 1, Route119_EventScript_StartMayBattleTORCHIC
	case 2, Route119_EventScript_StartMayBattleMUDKIP
	end

Route119_EventScript_StartMayBattleTREECKO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleTORCHIC::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleMUDKIP::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleTURTWIG
	case 1, Route119_EventScript_StartMayBattleCHIMCHAR
	case 2, Route119_EventScript_StartMayBattlePIPLUP
	end

Route119_EventScript_StartMayBattleTURTWIG::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattlePIPLUP::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleSNIVY
	case 1, Route119_EventScript_StartMayBattleTEPIG
	case 2, Route119_EventScript_StartMayBattleOSHAWOTT
	end

Route119_EventScript_StartMayBattleSNIVY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleTEPIG::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleCHESPIN
	case 1, Route119_EventScript_StartMayBattleFENNEKIN
	case 2, Route119_EventScript_StartMayBattleFROAKIE
	end

Route119_EventScript_StartMayBattleCHESPIN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleFROAKIE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleROWLET
	case 1, Route119_EventScript_StartMayBattleLITTEN
	case 2, Route119_EventScript_StartMayBattlePOPPLIO
	end

Route119_EventScript_StartMayBattleROWLET::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleLITTEN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleGROOKEY
	case 1, Route119_EventScript_StartMayBattleSCORBUNNY
	case 2, Route119_EventScript_StartMayBattleSOBBLE
	end

Route119_EventScript_StartMayBattleGROOKEY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleSOBBLE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleSPRIGATITO
	case 1, Route119_EventScript_StartMayBattleFUECOCO
	case 2, Route119_EventScript_StartMayBattleQUAXLY
	end

Route119_EventScript_StartMayBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleFUECOCO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleQUAXLY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRed_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleBULBASAUR
	case 1, Route119_EventScript_StartRedBattleCHARMANDER
	case 2, Route119_EventScript_StartRedBattleSQUIRTLE
	end

Route119_EventScript_StartRedBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleCHIKORITA
	case 1, Route119_EventScript_StartRedBattleCYNDAQUIL
	case 2, Route119_EventScript_StartRedBattleTOTODILE
	end

Route119_EventScript_StartRedBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleTOTODILE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleTREECKO
	case 1, Route119_EventScript_StartRedBattleTORCHIC
	case 2, Route119_EventScript_StartRedBattleMUDKIP
	end

Route119_EventScript_StartRedBattleTREECKO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleTORCHIC::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleMUDKIP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleTURTWIG
	case 1, Route119_EventScript_StartRedBattleCHIMCHAR
	case 2, Route119_EventScript_StartRedBattlePIPLUP
	end

Route119_EventScript_StartRedBattleTURTWIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattlePIPLUP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleSNIVY
	case 1, Route119_EventScript_StartRedBattleTEPIG
	case 2, Route119_EventScript_StartRedBattleOSHAWOTT
	end

Route119_EventScript_StartRedBattleSNIVY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleTEPIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleCHESPIN
	case 1, Route119_EventScript_StartRedBattleFENNEKIN
	case 2, Route119_EventScript_StartRedBattleFROAKIE
	end

Route119_EventScript_StartRedBattleCHESPIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleFROAKIE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleROWLET
	case 1, Route119_EventScript_StartRedBattleLITTEN
	case 2, Route119_EventScript_StartRedBattlePOPPLIO
	end

Route119_EventScript_StartRedBattleROWLET::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleLITTEN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleGROOKEY
	case 1, Route119_EventScript_StartRedBattleSCORBUNNY
	case 2, Route119_EventScript_StartRedBattleSOBBLE
	end

Route119_EventScript_StartRedBattleGROOKEY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleSOBBLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleSPRIGATITO
	case 1, Route119_EventScript_StartRedBattleFUECOCO
	case 2, Route119_EventScript_StartRedBattleQUAXLY
	end

Route119_EventScript_StartRedBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleFUECOCO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleQUAXLY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLeaf_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleBULBASAUR
	case 1, Route119_EventScript_StartLeafBattleCHARMANDER
	case 2, Route119_EventScript_StartLeafBattleSQUIRTLE
	end

Route119_EventScript_StartLeafBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end
Route119_EventScript_StartLeaf_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleCHIKORITA
	case 1, Route119_EventScript_StartLeafBattleCYNDAQUIL
	case 2, Route119_EventScript_StartLeafBattleTOTODILE
	end

Route119_EventScript_StartLeafBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleTREECKO
	case 1, Route119_EventScript_StartLeafBattleTORCHIC
	case 2, Route119_EventScript_StartLeafBattleMUDKIP
	end

Route119_EventScript_StartLeafBattleTREECKO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleTURTWIG
	case 1, Route119_EventScript_StartLeafBattleCHIMCHAR
	case 2, Route119_EventScript_StartLeafBattlePIPLUP
	end

Route119_EventScript_StartLeafBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleSNIVY
	case 1, Route119_EventScript_StartLeafBattleTEPIG
	case 2, Route119_EventScript_StartLeafBattleOSHAWOTT
	end

Route119_EventScript_StartLeafBattleSNIVY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleTEPIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleCHESPIN
	case 1, Route119_EventScript_StartLeafBattleFENNEKIN
	case 2, Route119_EventScript_StartLeafBattleFROAKIE
	end

Route119_EventScript_StartLeafBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleROWLET
	case 1, Route119_EventScript_StartLeafBattleLITTEN
	case 2, Route119_EventScript_StartLeafBattlePOPPLIO
	end

Route119_EventScript_StartLeafBattleROWLET::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleLITTEN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleGROOKEY
	case 1, Route119_EventScript_StartLeafBattleSCORBUNNY
	case 2, Route119_EventScript_StartLeafBattleSOBBLE
	end

Route119_EventScript_StartLeafBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleSPRIGATITO
	case 1, Route119_EventScript_StartLeafBattleFUECOCO
	case 2, Route119_EventScript_StartLeafBattleQUAXLY
	end

Route119_EventScript_StartLeafBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedBrendan:
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	end

Route119_EventScript_DefeatedMay:
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	end

