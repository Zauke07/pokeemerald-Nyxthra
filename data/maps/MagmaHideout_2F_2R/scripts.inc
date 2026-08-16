MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Ich hab eigentlich nichts gegen dich.\n"
	.string "Ich befolge nur Befehle!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Ich habe vielleicht verloren, aber…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Wir haben etwas ausgegraben, das jenseits von allem ist!\n"
	.string "Und wir haben den BLAUEN ORB!\p"
	.string "Jetzt muss unser Boss nur noch…\n"
	.string "Fufufu… Fwahahaha!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Ich kann Hitze nicht ab. Vielleicht hätte ich\n"
	.string "eher zu TEAM AQUA gehen sollen…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ja, ich bin vielleicht wirklich nicht\n"
	.string "für TEAM MAGMA gemacht…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Vermisst du nicht auch das Meer,\n"
	.string "wenn du an so einem Ort bist?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Man hört hier manchmal Erdstöße.\p"
	.string "Ist das der Vulkan…\n"
	.string "oder ist das GROU…\p"
	.string "Ups!\n"
	.string "Nein, nein, vergiss es!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Du kämpfst richtig feurig.\n"
	.string "Wie ein Vulkan!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Dieses eine Mal hast du halt gewonnen,\n"
	.string "aber das ist egal.\p"
	.string "TEAM MAGMA steht kurz vor dem\n"
	.string "großen Ziel!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Einer von uns hat komplett Panik geschoben,\n"
	.string "weil er sein MAGMA-EMBLEM verloren hat…\p"
	.string "Moment mal!\n"
	.string "Warst du das, der es gefunden hat?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Ich kann das kaum glauben…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Ich hab langsam das Gefühl, dass unser Plan\n"
	.string "am Ende komplett scheitert…$"

