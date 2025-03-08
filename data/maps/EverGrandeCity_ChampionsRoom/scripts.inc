.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	lockall
    call Common_EventScript_SetupRivalMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_MAY, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_RED, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_LEAF, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_ETHAN, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_LYRA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_LUCAS, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_DAWN, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_HILBERT, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_HILDA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_NATE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_ROSA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_CALEM, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_SERENA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_ELIO, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_SELENE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_VICTOR, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_GLORIA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	goto_if_eq VAR_RESULT, STYLE_FLORIAN, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, STYLE_JULIANA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end
    getplayerstyle
	call_if_eq VAR_RESULT, STYLE_BRENDAN, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_MAY, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_RED, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_LEAF, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_ETHAN, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_LYRA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_LUCAS, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_DAWN, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_HILBERT, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_HILDA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_NATE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_ROSA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_CALEM, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_SERENA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_ELIO, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_SELENE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_VICTOR, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_GLORIA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	call_if_eq VAR_RESULT, STYLE_FLORIAN, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	call_if_eq VAR_RESULT, STYLE_JULIANA, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	
	call_if_eq VAR_RESULT, STYLE_BRENDAN, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_MAY, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_RED, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_LEAF, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_ETHAN, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_LYRA, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_LUCAS, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_DAWN, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_HILBERT, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_HILDA, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_NATE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_ROSA, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_CALEM, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_SERENA, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_ELIO, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_SELENE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_VICTOR, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_GLORIA, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	call_if_eq VAR_RESULT, STYLE_FLORIAN, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, STYLE_JULIANA, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "Wallace: Willkommen, {PLAYER}{KUN}.\p"
	.string "Dieses Ereignis in SEEGRASULB CITY…\n"
	.string "Du hast die Krise ganz allein beendet.\p"
	.string "Ups!\p"
	.string "Es wäre nicht fair zu sagen, dass du\n"
	.string "es allein geschafft hast.\p"
	.string "Du hast diese schwierige Situation\n"
	.string "überwunden, indem du mit deinen\l"
	.string "POKéMON zusammengearbeitet hast.\p"
	.string "Wir TRAINER stärken unsere POKéMON,\n"
	.string "geben ihnen Items und bringen ihnen\l"
	.string "neue Techniken bei.\p"
	.string "Doch auch wir lernen viel von\n"
	.string "unseren POKéMON.\p"
	.string "Und hier werden deine Erfolge\n"
	.string "gegen die anderer TRAINER gemessen.\p"
	.string "Nun!\p"
	.string "Wer kann am elegantesten mit seinen\n"
	.string "POKéMON tanzen in HOENN?\p"
	.string "Zeige es mir hier und jetzt!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Ich, der CHAMPION, wurde besiegt…\p"
	.string "Das war eine unglaubliche Leistung.\n"
	.string "Du warst elegant, fast schon\l"
	.string "frustrierend gut.\p"
	.string "Und doch war es absolut grandios!\p"
	.string "Gratulation, {PLAYER}{KUN}!\p"
	.string "Du bist ein wahrhaft edler POKéMON-\n"
	.string "TRAINER!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "Wallace: Die POKéMON, die du in den\n"
	.string "Kampf geschickt hast…\p"
	.string "Mal bewegten sie sich anmutig wie\n"
	.string "eine Frühlingsbrise, mal schlugen sie\l"
	.string "ein wie ein Blitz.\p"
	.string "Mit Leichtigkeit und doch sicherem\n"
	.string "Schritt hast du sie angeführt.\p"
	.string "Selbst ich war geblendet von deiner\n"
	.string "meisterhaften Performance!\p"
	.string "Nun stehst du auf dem höchsten Gipfel\n"
	.string "der POKéMON-LIGA.\p"
	.string "Ich erkläre dich hiermit zum neuen\n"
	.string "CHAMPION von HOENN!$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "Prof. Birk: Siehst du?\n"
	.string "Was habe ich dir gesagt, {RIVAL}?\p"
	.string "Hab ich dir nicht gesagt, dass du\n"
	.string "dir keine Sorgen um {PLAYER}{KUN}\l"
	.string "machen musst?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, du hast es wirklich geschafft.\p"
	.string "Als ich hörte, dass du deinen eigenen\n"
	.string "Vater in der ARENA von BLÜTENBURG\l"
	.string "besiegt hast, hatte ich Hoffnung…\p"
	.string "Aber dass du es wirklich zum\n"
	.string "CHAMPION geschafft hast!\p"
	.string "Ach ja!\p"
	.string "Wie steht es um deinen POKéDEX?\n"
	.string "Lass mich mal sehen.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "Prof. Birk: Wie auch immer…\n"
	.string "herzlichen Glückwunsch!\p"
	.string "Nun geh mit Stolz in den letzten Raum!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "Wallace: {PLAYER}{KUN}…\p"
	.string "Nein, lass mich das richtig sagen.\p"
	.string "Der neue CHAMPION!\p"
	.string "Komm mit mir.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "Wallace: Es tut mir leid, aber…\p"
	.string "Von hier an dürfen nur TRAINER, die\n"
	.string "CHAMPIONS geworden sind, eintreten.\p"
	.string "Du musst draußen mit Prof. Birk\n"
	.string "warten.$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "{RIVAL}: {PLAYER}!\p"
	.string "Wie wäre es mit einem Tipp, bevor du\n"
	.string "den CHAMPION herausforderst?…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "{RIVAL}: Hä?\n"
	.string "Was, was, was?\p"
	.string "{PLAYER}…\n"
	.string "Soll das heißen…\l"
	.string "Es ist schon vorbei?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "{RIVAL}: {PLAYER}!\p"
	.string "Wie wäre es mit einem Tipp, bevor du\n"
	.string "den CHAMPION herausforderst?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "{RIVAL}: {PLAYER}…\p"
	.string "Willst du mir sagen…\n"
	.string "Du hast den CHAMPION besiegt?$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "{RIVAL}: Hm…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ich mache nur Spaß! Ist schon okay!\n"
	.string "Das sind nun mal die Regeln!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Ganz ehrlich, herzlichen Glückwunsch!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "{RIVAL}: Waaas?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Es lässt sich nicht ändern,\n"
	.string "so sind die Regeln.\p"
	.string "{PLAYER}, das hast du gut gemacht!\n"
	.string "Glückwunsch!$"


