MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Ich verstehe alles, was unser Boss\n"
	.string "sagt. Aber weißt du was?\p"
	.string "Sachen wie ein uraltes POKéMON\n"
	.string "auszugraben und jemandem den\l"
	.string "METEORITEN zu klauen…\p"
	.string "Ich glaube, wir gehen ein bisschen zu weit.\n"
	.string "Was meinst du?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ja, ich glaube auch, dass hier\n"
	.string "irgendwas gewaltig schiefläuft.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Weißt du, die Niederlage gegen dich hat mir den Kopf klargemacht.\p"
	.string "Wenn ich unseren Boss das nächste Mal sehe,\n"
	.string "frage ich ihn, was wir hier eigentlich tun.$"

