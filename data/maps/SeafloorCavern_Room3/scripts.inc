SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Wie bist du ohne U-Boot hier\n"
	.string "reingekommen, du Tryhard?\l"
	.string "Echt krankes Movement!\p"
	.string "Aber… wir können dich hier\n"
	.string "echt nicht gebrauchen, Noob.\p"
	.string "Und für die Scheiße im\n"
	.string "Klima-Institut kassierst du!\p"
	.string "Ich mach dich jetzt komplett\n"
	.string "nass! Bereit für den Lose?$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Uff, mies kassiert!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Du bist einfach viel zu OP.\p"
	.string "Richtiger Abfuck, dass du\n"
	.string "nicht in Team Aqua bist.\p"
	.string "Du hättest die geile Map\n"
	.string "von unserem Boss direkt\l"
	.string "mit uns abstauben können…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Für unseren Masterplan\n"
	.string "brauchen wir OP-Pokémon.\p"
	.string "Aber Schwitzer wie du nutzen\n"
	.string "ihr Team, um uns sogar hier\l"
	.string "unten komplett abzufucken!\p"
	.string "Das Game ist echt so unfair!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah! Totaler Bullshit!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Wir würden die Meta von\n"
	.string "unserem Boss nie infrage\l"
	.string "stellen, keine Chance.\p"
	.string "Aber du Noob pushst einfach\n"
	.string "direkt auf unseren Boss.\p"
	.string "Vielleicht…\n"
	.string "hast du echt krasse Skills…$"

