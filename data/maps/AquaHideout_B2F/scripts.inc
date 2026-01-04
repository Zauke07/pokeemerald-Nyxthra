AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro::
	.string "Hehehe……\p"
	.string "Schon hier angekommen? Wir haben dich\n"
	.string "wohl echt unterschätzt, du kleiner Wurm!\p"
	.string "Aber hier ist Endstation!\p"
	.string "Ich spiel in einer ganz anderen Liga als\n"
	.string "die Versager, die du bisher besiegt hast.\p"
	.string "Ich schinde keine Zeit.\n"
	.string "Ich werd dich einfach pulverisieren!$"

AquaHideout_B2F_Text_MattDefeat::
	.string "Hehehe……\n"
	.string "Na toll, jetzt hab ich auch abgekackt……$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations::
	.string "Hehehe!\p"
	.string "Während ich dich ein bisschen verprügelt\n"
	.string "habe, ist unser BOSS fertig geworden!$"

AquaHideout_B2F_Text_MattPostBattle::
	.string "Hehehe!\p"
	.string "Der BOSS ist schon längst auf dem Weg\n"
	.string "zu einer Höhle tief unter dem Meer!\p"
	.string "Wenn du ihn jagen willst, musst du die\n"
	.string "ganze verdammte See vor SEEGRASULB\l"
	.string "CITY absuchen.\p"
	.string "Aber ob du da was findest?\n"
	.string "Hehehe! Träum weiter!$"

AquaHideout_B2F_Text_Grunt4Intro::
	.string "Wahaha! Ich hab mir schon den Arsch\n"
	.string "abgewartet! Du schuldest mir auch\l"
	.string "einen Kampf, du Nervensäge!$"

AquaHideout_B2F_Text_Grunt4Defeat::
	.string "Erst ewig gewartet……\n"
	.string "Und dann direkt kassiert……$"

AquaHideout_B2F_Text_Grunt4PostBattle::
	.string "BOSS……\n"
	.string "Reicht das als Ablenkung?$"

AquaHideout_B2F_Text_Grunt6Intro::
	.string "Teleporter-Felder! Der ganze Stolz\n"
	.string "unseres Verstecks!\p"
	.string "Du hast doch keinen Plan mehr, wo\n"
	.string "oben und unten ist, oder?\p"
	.string "Den Gegner verwirren und mürbe machen,\n"
	.string "und dann bumm! Das ist unser Plan!$"

AquaHideout_B2F_Text_Grunt6Defeat::
	.string "Was ist los mit dir?\n"
	.string "Du bist ja gar nicht am Ende!$"

AquaHideout_B2F_Text_Grunt6PostBattle::
	.string "Wo du es sagst…… Ich weiß nicht mal\n"
	.string "mehr, wo ich den MEISTERBALL hingepfeffert\l"
	.string "habe.\p"
	.string "Wenn ich den verliere, reißt mir der BOSS\n"
	.string "den Arsch bis zu den Ohren auf……$"

AquaHideout_B2F_Text_Grunt8Intro::
	.string "Als ich bei TEAM AQUA angefangen habe,\n"
	.string "musste ich erst mal diesen Mist mit den\l"
	.string "Teleportern auswendig lernen.$"

AquaHideout_B2F_Text_Grunt8Defeat::
	.string "Ich war zu sehr damit beschäftigt, über\n"
	.string "diese blöden Felder nachzudenken……$"

AquaHideout_B2F_Text_Grunt8PostBattle::
	.string "Ich sollte wohl eher mal lernen, wie man\n"
	.string "richtig kämpft und nicht nur doof in der\l"
	.string "Gegend rumsteht……$"
