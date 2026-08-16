AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Während wir nach Schätzen gesucht haben,\n"
	.string "haben wir einen TRAINER entdeckt!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Wir konnten nicht gewinnen, obwohl\n"
	.string "wir zusammen gekämpft haben…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: Wir finden einfach keine Schätze…\n"
	.string "Vielleicht hat sie schon jemand eingesackt?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Du hast nicht mal zwei POKéMON.\n"
	.string "So kannst du uns nicht besiegen.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Oh?\n"
	.string "Wir waren auf Schatzsuche.\l"
	.string "Und stattdessen finden wir einen TRAINER!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Oha, ganz schön stark!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Wo sind diese Schätze bloß?\p"
	.string "Ich weiß schon genau, was ich kaufe,\n"
	.string "sobald wir sie finden!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Oh, du hast keine zwei POKéMON?\n"
	.string "Dann kämpfen wir ein andermal!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Boah, du nervst ja mal komplett!\n"
	.string "Dafür landest du jetzt in meinem POKéNAV!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Wir suchen die ganze Zeit schon\n"
	.string "nach Schätzen.\p"
	.string "Unsere POKéMON sind dabei auch stärker geworden.\n"
	.string "Zeigen wir dir, was wir draufhaben, okay?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Du bist wie immer stark!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: Keine Schätze,\n"
	.string "bei POKéMON verlieren wir auch…\p"
	.string "Ich will eigentlich nach Hause… Aber wenn ich das sage,\n"
	.string "macht sie mich direkt zur Schnecke…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Du hast nicht mal zwei POKéMON.\n"
	.string "So kannst du uns nicht besiegen.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Oh? Wir treffen uns wieder!\p"
	.string "Genau wie wir hast du die Schatzsuche\n"
	.string "auch noch nicht aufgegeben, oder?\p"
	.string "Wie wär's: Wer verliert,\n"
	.string "gibt die Suche auf?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Oh nein, schon wieder verloren…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Wir gehen erst, wenn unsere\n"
	.string "POKéMON noch stärker sind und wir hier\l"
	.string "die Schätze gefunden haben!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Oh, du hast keine zwei POKéMON?\n"
	.string "Dann kämpfen wir ein andermal!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Ich bin kein Ass im Schwimmen,\n"
	.string "aber im Kampf kann ich was!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ups.\n"
	.string "Das lief nicht so gut.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Hier barfuß durch das Schiff zu laufen\n"
	.string "ist schon ziemlich eklig.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Stärke und Mitgefühl…\n"
	.string "Das sind die wahren Schätze eines TRAINERS!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, irgendetwas an dir\n"
	.string "strahlt richtig.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "In irgendeiner Kabine hier an Bord\n"
	.string "habe ich etwas glitzern sehen.$"
