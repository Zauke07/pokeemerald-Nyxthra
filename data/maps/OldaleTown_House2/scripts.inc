OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "POKéMON wachsen durch Kämpfe.\n"
	.string "Manche verändern sich sogar komplett!\p"
	.string "Einige Forscher glauben, es gäbe noch\n"
	.string "weit seltenere Formen als Entwicklungen…$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Wenn dein Team stark genug ist,\n"
	.string "öffnen sich neue Wege.\p"
	.string "Sogar abgelegene Orte wie die neue\n"
	.string "Höhle nördlich von hier auf Route 103…$"


