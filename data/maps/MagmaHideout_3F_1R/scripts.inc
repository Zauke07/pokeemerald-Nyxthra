MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Was hab ich getan, dass ich auf diesem\n"
	.string "Wachposten gelandet bin?\p"
	.string "Mein linkes Ohr brennt schon!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Ich kipp gleich wegen der Hitze um…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Findest du es nicht auch komisch, dass wir\n"
	.string "in diesem Magma-Vulkan Kapuzen tragen?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Wir sind beigetreten, um unserem Boss\n"
	.string "bei seiner großen Vision zu helfen.\p"
	.string "Ist mir egal, ob du zu TEAM AQUA gehörst\n"
	.string "oder nur irgendein Kind auf Durchreise bist.\p"
	.string "Niemand funkt uns dazwischen und kommt\n"
	.string "ungestraft davon!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh nein!\n"
	.string "Dir kann man ja gar nicht trauen!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Hör mir zu.\n"
	.string "TEAM MAGMA hat recht!\p"
	.string "Hör nicht auf TEAM AQUA.\n"
	.string "Glaub deren Lügen nicht!$"

