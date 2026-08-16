SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Wir brauchen hier keine Noobs!\n"
	.string "Verpiss dich nach Hause!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Ich will zu Mama heulen gehen…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Ich will endlich aufsteigen,\n"
	.string "damit ich die anderen Lappen\l"
	.string "rumkommandieren kann…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Das U-Boot ist so verfickt eng.\n"
	.string "Mir tut alles weh, Digga!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Dieser Lose tut noch mehr weh!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Das U-Boot, das wir abgezogen\n"
	.string "haben, ist ein absoluter Scam.\l"
	.string "Man hat da drin einfach null\n"
	.string "Platz zum Chillen!$"

