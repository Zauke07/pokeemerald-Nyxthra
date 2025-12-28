Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition:
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing::
	.string "Ey, meinst du der Boss zieht das echt\n"
	.string "durch und weckt dieses Riesenvieh auf?$"

Route112_Text_YeahWeNeedMeteorite::
	.string "Logisch, Mann. Aber ohne diesen\n"
	.string "METEORITen läuft hier gar nix.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor::
	.string "Ach so! Deswegen sind die anderen\n"
	.string "Spasten nach LAUBWECHSELFELD abgehauen.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack::
	.string "Ganz genau! Und solange die weg sind,\n"
	.string "polieren wir jedem die Fresse, der\l"
	.string "hier durchwill!$"

Route112_Text_NotEasyToGetBackToLavaridge::
	.string "Ich hab Bock auf Zocken in MALVENFROH,\n"
	.string "aber wenn ich diese Stufen runterspringe,\l"
	.string "muss ich den ganzen Weg zurück nach\l"
	.string "BAD LAVASTADT latschen. Kotzt mich an!$"

Route112_Text_MtChimneyCableCarSign::
	.string "SEILBAHN ZUM SCHLOTBERG\n"
	.string "“Hochfahren oder runterfallen! {UP_ARROW}”$"

Route112_Text_MtChimneySign::
	.string "SCHLOTBERG\p"
	.string "“Entweder nach BAD LAVASTADT oder\n"
	.string "hoch auf den Gipfel. Nerv nicht!”$"

Route112_Text_RouteSignLavaridge::
	.string "ROUTE 112\n"
	.string "{LEFT_ARROW} BAD LAVASTADT (Heißes Pflaster)$"

Route112_EventScript_Plinfa::
	msgbox Route112_Text_Plinfa, MSGBOX_NPC
	end

Route112_Text_Plinfa:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 4 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"
