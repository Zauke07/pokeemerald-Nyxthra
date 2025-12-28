Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy::
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_RematchNob::
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy::
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear::
	.string "Höhlenforschung ist nichts für Weicheier,\n"
	.string "die sonst nur auf gepflasterten Wegen\l"
	.string "rumlungern.\p"
	.string "Du weißt nie, wann dir so ein Vieh aus\n"
	.string "der Dunkelheit ins Gesicht springt.\n"
	.string "Wer hier keine Nerven aus Stahl hat,\l"
	.string "sollte lieber zu Mutti gehen!$"

Route115_Text_RouteSignRustboro::
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} METAROST CITY (Zivilisation für Lappen)$"

Route115_Text_MeteorFallsSign::
	.string "METEORFÄLLE\n"
	.string "LAUBWECHSELFELD (Dreck & Steine) HIER ENTLANG$"

Route115_EventScript_RouteSignBabyBootCamp::
	msgbox Route115_Text_RouteSignBabyBootCamp, MSGBOX_SIGN
	end

Route115_Text_RouteSignBabyBootCamp:
	.string "{LEFT_ARROW} Komischer Baum\n"
	.string "{RIGHT_ARROW} Baby-Boot Camp$"

Route115_EventScript_Man::
	msgbox Route115_Text_ManIntro, MSGBOX_DEFAULT
	end

Route115_Text_ManNo:
	.string "Ok, dann nicht.$"

Route115_Text_ManIntro:
	.string "Wenn du ins Baby-Boot Camp willst, musst\n"
	.string "du mir 5k zahlen. Zur Info, dies musst\l"
	.string "du jedes mal wenn du ins Camp willst.$"

Route115_Text_ManYes:
	.string "Cool Danke.$"

Route115_Text_ManNoMoney:
	.string "Haha du bist Pleite! Was ein Pech kleiner.$"

Route115_Text_ManEnjoy:
	.string "Viel Spaß im Baby-Boot Camp!$"

Route115_EventScript_TriggerMan::
	lockall
	checkflag FLAG_ROUTE115_PAID
	goto_if_set FLAG_ROUTE115_PAID, Route115_EventScript_TriggerMan_AlreadyPaid
	showmoneybox 0, 0
	msgbox Route115_Text_ManIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Route115_EventScript_ManNo
	call Route115_EventScript_Man_Pay
	releaseall
	end

Route115_EventScript_TriggerMan_AlreadyPaid::
	releaseall
	end

Route115_EventScript_Man_Pay::
	checkmoney 5000
	goto_if_lt VAR_RESULT, 1, Route115_EventScript_ManNoMoney
	playse SE_SHOP
	msgbox Route115_Text_ManYes, MSGBOX_DEFAULT
	removemoney 5000
	updatemoneybox
	msgbox Route115_Text_ManEnjoy, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement 24, Route115_Movement_Man_MoveUp
	waitmovement 24
	setflag FLAG_ROUTE115_PAID
	goto Route115_EventScript_End

Route115_Movement_Man_MoveUp::
	walk_up
	face_down
	step_end

Route115_EventScript_ManNo::
	msgbox Route115_Text_ManNo, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route115_Movement_Player_MoveDown
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

Route115_EventScript_ManNoMoney::
	msgbox Route115_Text_ManNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route115_Movement_Player_MoveDown
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

Route115_Movement_Player_MoveDown::
	walk_down
	step_end

Route115_EventScript_End::
	releaseall
	end

Route115_Text_ClerkIntro:
	.string "Hi, mein Name ist Winnie und ich arbeite\n"
	.string "als selbstständiger Händler.\p"
	.string "Bei mir kannst du alle Bälle die es\n"
	.string "im Spiel gibt kaufen.\p"
	.string "Bis auf den Premierball, den Safariball\n"
	.string "und natürlich den Meisterball.$"

Route115_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route115_Text_ClerkIntro, MSGBOX_DEFAULT
	closemessage
	message gText_HowMayIServeYou
	waitmessage
	pokemart Route115_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
Route115_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FAST_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_DREAM_BALL
	.2byte ITEM_SPORT_BALL
	.2byte ITEM_PARK_BALL
	.2byte ITEM_BEAST_BALL
	.2byte ITEM_CHERISH_BALL
	.2byte ITEM_NONE
	release
	end

