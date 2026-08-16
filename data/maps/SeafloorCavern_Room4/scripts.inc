SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Wer bist du, Lappen?\n"
	.string "Wo bist du reingeglitcht?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Komplett reingetrollt…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Ich find den Exit nicht!\p"
	.string "Aber ich hab null Schiss,\n"
	.string "also halt bloß dein Maul!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Wer bist du, Opfer?\n"
	.string "Wo willst du überhaupt hin?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Richtig mieser Lose!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Mein Mate hat die Minimap\n"
	.string "im U-Boot liegen lassen!\p"
	.string "Wie absolut useless kann\n"
	.string "man eigentlich sein, Bro?$"

