OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_Joke::
    setvar VAR_JOKE_NPC_INDEX, 0
    call JokeNpc_EventScript_Main
    end


OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "Toll… Alles ausverkauft.\n"
	.string "Wie soll ich denn so das Mysterium\l"
	.string "dort in der Höhle erforschen?$"


OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "Ich kaufe mir gleich einen ganzen Stapel\n"
	.string "POKéBÄLLE…\p"
	.string "Man weiß nie, was einem im hohen Gras\n"
	.string "oder dunklen Höhlen begegnet.$"


OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "Wenn dein POKéMON alle KP verliert,\n"
	.string "wird es kampfunfähig.\p"
	.string "Ein TRANK kann entscheidend sein -\n"
	.string "gerade wenn du dich ins Ungewisse wagst.$"
