MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Yo, du kleines Trainer-Opfer!\n"
	.string "Die Superangel ist der absolute Boss!\p"
	.string "Digga, das Ding zieht dir die krassesten\n"
	.string "Viecher vom Meeresgrund hoch, no cap!\p"
	.string "Was guckst du so lost?\n"
	.string "Willst du den fetten Loot haben oder was?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Dacht ich mir doch, du Geringverdiener!\n"
	.string "Wer sagt schon nein zu free Stuff?\p"
	.string "Die Superangel ist einfach komplett OP!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Schmeiß das Ding einfach in jede\n"
	.string "Pfütze rein und guck, was anbeißt.\p"
	.string "Aber heul mir nachher nicht die Ohren\n"
	.string "voll, wenn du nur Trash-Mobs ziehst!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hä? Angeln ist dir nicht wild genug?\n"
	.string "Bist du komplett cringe oder was?\p"
	.string "Geh mal lieber Gras berühren, du NPC.$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Flex einfach 'ne Runde mit der\n"
	.string "Superangel auf dem Meeresgrund.\p"
	.string "Und jetzt mach 'nen Abflug, du nervst.$"
