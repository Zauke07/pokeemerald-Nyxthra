EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	@ Nyxthra story: whoever isn't the player's own gender (May or Brendan -
	@ see IsChampionMay()) is the reigning Champion of Hoenn and stands here
	@ in Wallace's old spot, fixed regardless of the player's chosen style.
	specialvar VAR_RESULT, IsChampionMay
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_SetChampionGfxMay
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	end
EverGrandeCity_ChampionsRoom_EventScript_SetChampionGfxMay:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
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
	specialvar VAR_RESULT, IsChampionMay
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_ChampionsRoom_EventScript_FightMay
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeechBrendan, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRENDAN_CHAMPION, EverGrandeCity_ChampionsRoom_Text_DefeatBrendan
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
EverGrandeCity_ChampionsRoom_EventScript_FightMay:
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeechMay, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAY_CHAMPION, EverGrandeCity_ChampionsRoom_Text_DefeatMay
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	@ Nyxthra story: the CHAMPION you just fought is fixed to May or Brendan
	@ (IsChampionMay, independent of your own style) and reacts right where
	@ they stand. Your own actual rival - still fully per-style/dynamic via
	@ spawnrival_style, same as always - bursts in separately afterward.
	specialvar VAR_RESULT, IsChampionMay
	goto_if_eq VAR_RESULT, TRUE, EverGrandeCity_ChampionsRoom_EventScript_MayChampionReacts
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeechBrendan, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_RivalArrives
EverGrandeCity_ChampionsRoom_EventScript_MayChampionReacts:
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeechMay, MSGBOX_DEFAULT
EverGrandeCity_ChampionsRoom_EventScript_RivalArrives:
	closemessage
	playse SE_DOOR
	lockall
	call Common_EventScript_SetupRivalMusic
	setvar VAR_0x8004, LOCALID_CHAMPIONS_ROOM_RIVAL
	spawnrival_style
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	specialvar VAR_RESULT, IsChampionMay
	goto_if_eq VAR_RESULT, TRUE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	specialvar VAR_RESULT, IsChampionMay
	call_if_eq VAR_RESULT, TRUE, EverGrandeCity_ChampionsRoom_EventScript_ComeWithMeMay
	call_if_eq VAR_RESULT, FALSE, EverGrandeCity_ChampionsRoom_EventScript_ComeWithMeBrendan
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	specialvar VAR_RESULT, IsChampionMay
	call_if_eq VAR_RESULT, TRUE, EverGrandeCity_ChampionsRoom_EventScript_WaitOutsideMay
	call_if_eq VAR_RESULT, FALSE, EverGrandeCity_ChampionsRoom_EventScript_WaitOutsideBrendan
	specialvar VAR_RESULT, IsChampionMay
	call_if_eq VAR_RESULT, TRUE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FALSE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
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

EverGrandeCity_ChampionsRoom_EventScript_ComeWithMeMay::
	msgbox EverGrandeCity_ChampionsRoom_Text_ComeWithMeMay, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_ComeWithMeBrendan::
	msgbox EverGrandeCity_ChampionsRoom_Text_ComeWithMeBrendan, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_WaitOutsideMay::
	msgbox EverGrandeCity_ChampionsRoom_Text_WaitOutsideMay, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_WaitOutsideBrendan::
	msgbox EverGrandeCity_ChampionsRoom_Text_WaitOutsideBrendan, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
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

EverGrandeCity_ChampionsRoom_Text_IntroSpeechMay:
	.string "Mai: Na, sieh mal einer an.\p"
	.string "Ich hab schon gedacht, du traust dich\n"
	.string "gar nicht mehr her.\p"
	.string "Weißt du noch, wie du in LITTLEROOT\n"
	.string "nicht mal wusstest, wie rum man einen\l"
	.string "POKéBALL hält?\p"
	.string "Und jetzt stehst du hier. Vor der\n"
	.string "amtierenden CHAMPION von HOENN.\p"
	.string "Das bin übrigens ich, falls das noch\n"
	.string "nicht ganz angekommen ist.\p"
	.string "Ich hab nicht die ganze Liga\n"
	.string "durchgeboxt, um dir das jetzt einfach\l"
	.string "so zu überlassen, {PLAYER}.\p"
	.string "Zeig mir, was du drauf hast!$"

EverGrandeCity_ChampionsRoom_Text_IntroSpeechBrendan:
	.string "Brix: Da bist du ja endlich.\p"
	.string "Ich dachte schon, du hast dich\n"
	.string "irgendwo verlaufen.\p"
	.string "Erinnerst du dich noch an LITTLEROOT?\n"
	.string "Du konntest kaum deinen RUCKSACK\l"
	.string "richtig tragen.\p"
	.string "Und jetzt stehst du vor mir. Dem\n"
	.string "amtierenden CHAMPION von HOENN.\p"
	.string "Klingt verrückt, oder? Mir kommt's\n"
	.string "manchmal selbst so vor.\p"
	.string "Aber glaub bloß nicht, ich mach's dir\n"
	.string "leicht, nur weil wir uns kennen,\l"
	.string "{PLAYER}.\p"
	.string "Los, zeig mir, was in dir steckt!$"

EverGrandeCity_ChampionsRoom_Text_DefeatMay:
	.string "Verdammt, hab ich tatsächlich\n"
	.string "verloren? Als CHAMPION?!\p"
	.string "Respekt, {PLAYER}. Richtig stark!$"

EverGrandeCity_ChampionsRoom_Text_DefeatBrendan:
	.string "Ha, kaum zu glauben…\n"
	.string "Der CHAMPION, geschlagen von dir!\p"
	.string "Nicht schlecht, {PLAYER}. Gar nicht\n"
	.string "schlecht!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeechMay:
	.string "Mai: …\p"
	.string "Okay, wow.\p"
	.string "Ich meine… wow.\p"
	.string "Ich hab mich wirklich, wirklich auf\n"
	.string "diesen Kampf vorbereitet, {PLAYER}.\p"
	.string "Und du hast mich einfach so vom\n"
	.string "Thron gefegt.$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeechBrendan:
	.string "Brix: …\p"
	.string "Also gut.\p"
	.string "Das musste ich mir jetzt erstmal\n"
	.string "setzen lassen.\p"
	.string "Monatelang hab ich für diesen einen\n"
	.string "Moment trainiert, {PLAYER}.\p"
	.string "Und du rauschst einfach so rein\n"
	.string "und räumst ab.$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "Prof. Birk: Siehst du?\n"
	.string "Was habe ich dir gesagt, {RIVAL}?\p"
	.string "Hab ich dir nicht gesagt, dass du\n"
	.string "dir keine Sorgen um {PLAYER}{KUN}\l"
	.string "machen musst?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, du hast es wirklich geschafft.\p"
	.string "Als ich hörte, dass du sogar den\n"
	.string "Arenaleiter von BLÜTENBURG besiegt\l"
	.string "hast, hatte ich Hoffnung…\p"
	.string "Aber dass du es wirklich zum\n"
	.string "CHAMPION geschafft hast!\p"
	.string "Ach ja!\p"
	.string "Wie steht es um deinen POKéDEX?\n"
	.string "Lass mich mal sehen.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "Prof. Birk: Wie auch immer…\n"
	.string "herzlichen Glückwunsch!\p"
	.string "Nun geh mit Stolz in den letzten Raum!$"

EverGrandeCity_ChampionsRoom_Text_ComeWithMeMay:
	.string "Mai: {PLAYER}…\p"
	.string "Nee, warte, lass mich das nochmal\n"
	.string "richtig sagen.\p"
	.string "Der neue CHAMPION von HOENN!\p"
	.string "Komm mit mir.$"

EverGrandeCity_ChampionsRoom_Text_ComeWithMeBrendan:
	.string "Brix: {PLAYER}…\p"
	.string "Nee, warte, lass mich das nochmal\n"
	.string "richtig sagen.\p"
	.string "Der neue CHAMPION von HOENN!\p"
	.string "Komm mit mir.$"

EverGrandeCity_ChampionsRoom_Text_WaitOutsideMay:
	.string "Mai: Tut mir leid, Professor…\p"
	.string "Aber ab hier kommen nur noch\n"
	.string "TRAINER rein, die CHAMPION\l"
	.string "geworden sind.\p"
	.string "Regeln sind Regeln. Auch wenn ich\n"
	.string "sie gerade selbst mache.\p"
	.string "Du wartest hier draußen mit Prof.\n"
	.string "Birk.$"

EverGrandeCity_ChampionsRoom_Text_WaitOutsideBrendan:
	.string "Brix: Tut mir leid, Professor…\p"
	.string "Aber ab hier kommen nur noch\n"
	.string "TRAINER rein, die CHAMPION\l"
	.string "geworden sind.\p"
	.string "Regeln sind Regeln. Auch wenn ich\n"
	.string "sie gerade selbst mache.\p"
	.string "Du wartest hier draußen mit Prof.\n"
	.string "Birk.$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "{COLOR RIVAL_CLR}{RIVAL}: {PLAYER}!\p"
	.string "Wie wäre es mit einem Tipp, bevor du\n"
	.string "den CHAMPION herausforderst?…{COLOR DARK_GRAY}$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Hä?\n"
	.string "Was, was, was?\p"
	.string "{PLAYER}…\n"
	.string "Soll das heißen…\l"
	.string "Es ist schon vorbei?{COLOR DARK_GRAY}$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "{COLOR RIVAL_CLR}{RIVAL}: {PLAYER}!\p"
	.string "Wie wäre es mit einem Tipp, bevor du\n"
	.string "den CHAMPION herausforderst?…{COLOR DARK_GRAY}$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "{COLOR RIVAL_CLR}{RIVAL}: {PLAYER}…\p"
	.string "Willst du mir sagen…\n"
	.string "Du hast den CHAMPION besiegt?{COLOR DARK_GRAY}$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Hm…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ich mache nur Spaß! Ist schon okay!\n"
	.string "Das sind nun mal die Regeln!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Ganz ehrlich, herzlichen Glückwunsch!{COLOR DARK_GRAY}$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Waaas?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Es lässt sich nicht ändern,\n"
	.string "so sind die Regeln.\p"
	.string "{PLAYER}, das hast du gut gemacht!\n"
	.string "Glückwunsch!{COLOR DARK_GRAY}$"

