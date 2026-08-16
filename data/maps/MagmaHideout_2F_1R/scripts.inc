MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Was, was, was?\p"
	.string "Hier dürfen nur TEAM-MAGMA-Mitglieder\n"
	.string "rein!\p"
	.string "Aber du trägst gar nicht die\n"
	.string "TEAM-MAGMA-Uniform…\p"
	.string "Du machst mich misstrauisch!\n"
	.string "Kämpf gegen mich!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Mein Stolz als TEAM-MAGMA-Mitglied…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Wenn dir ständig kalt ist, solltest du\n"
	.string "zu TEAM MAGMA kommen.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Stopp, keinen Schritt weiter!\p"
	.string "Du glaubst doch nicht ernsthaft, dass ich\n"
	.string "die Klappe halte und dich einfach durchwinke?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Oha wow!\n"
	.string "Ich gebe auf!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Vielleicht wär's besser gewesen,\n"
	.string "ich hätte dich einfach vorbeigelassen…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Aha!\n"
	.string "Ein Eindringling!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ich hab schon verloren.\p"
	.string "Muss ich jetzt echt weiter im Kreis\n"
	.string "rumrennen?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh!\n"
	.string "Ein Eindringling!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Mutter…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Ehrlich gesagt bin ich kein Profi im Kämpfen…$"

