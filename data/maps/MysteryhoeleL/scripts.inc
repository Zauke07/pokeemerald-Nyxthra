MysteryhoeleL_MapScripts::
	.byte 0



MysteryhoeleL_EventScript_Krokel::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, MysteryhoeleL_EventScript_Krokel_RandomizerText
	msgbox MysteryhoeleL_Text_Krokel, MSGBOX_NPC
	end

MysteryhoeleL_EventScript_Krokel_RandomizerText::
	msgbox MysteryhoeleL_Text_KrokelRandomizer, MSGBOX_NPC
	end

MysteryhoeleL_Text_Krokel:
	.string "Hey {PLAYER}, ich bin ein\n"
	.string "Bote von diesem Rom Entwickler.\l"
	.string "Sein Name ist Zauke07!\p"
	.string "Immer wenn du mich am Ende einer\n"
	.string "Route siehst, sprich mich an, denn\l"
	.string "ich habe einen heißen Tipp für dich!\p"
	.string "Tipp:\p"
	.string "In dieser Höhle versteckt sich ein\n"
	.string "Starter aus der 9 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

MysteryhoeleL_Text_KrokelRandomizer:
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"
