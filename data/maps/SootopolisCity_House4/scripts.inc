SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Hör gut zu, ich leak dir\n"
	.string "jetzt mal krasse Infos.\p"
	.string "Hier unten im Meer soll es\n"
	.string "richtig alte Ruinen geben.\p"
	.string "Da wartet safe richtig fetter\n"
	.string "Loot auf geile Tryharder.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Uralter Loot…\p"
	.string "Wäre schon geil, aber selbst\n"
	.string "wenn das alles Fake-News sind…\p"
	.string "Ich will eigentlich eh nur mit\n"
	.string "meinen Viechern unten chillen.$"

SootopolisCity_House4_Text_Azumarill:
	.string "Azumarill: Bluuuuub…$"
