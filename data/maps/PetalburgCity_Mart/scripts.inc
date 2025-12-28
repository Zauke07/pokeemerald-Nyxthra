PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_ExpandedItems::
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_Woman::
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_JokeNpc::
    setvar VAR_JOKE_NPC_INDEX, 1
    call JokeNpc_EventScript_Main
    end


PetalburgCity_Mart_Text_WeakWillGrowStronger:
	.string "Jedes Pokémon wird mal stärker…\n"
	.string "Wenn du's nicht vorher aus Versehen\l"
	.string "tauschst, vergisst oder abspeicherst.\p"
	.string "Ich sag nur: “Level 5 mit Liebe”…\n"
	.string "Aber wenn’s schwach bleibt, ist halt Müll.$"

PetalburgCity_Mart_Text_RepelIsUseful:
	.string "Schutz? Klar benutz ich den.\n"
	.string "Wie soll ich sonst den ganzen Zickzacks\l"
	.string "aus dem Weg gehen?!\p"
	.string "Aber gestern… wurde mein Schutz\n"
	.string "geklaut. Von so nem Typ in Schwarz.\p"
	.string "Der hat einfach gelacht und war weg.\n"
	.string "Ich sag nur: komische Zeiten.$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
	.string "Ich nehm immer Gegengift mit.\n"
	.string "Weil ich weiß: Das Leben vergiftet dich.\p"
	.string "Oder dein Pikachu. Kommt drauf an.\n"
	.string "Beides tut weh, Bro.$"

