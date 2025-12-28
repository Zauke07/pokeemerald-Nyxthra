RustboroCity_Mart_MapScripts::
	.byte 0

RustboroCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartBasic
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartExpanded
	end

RustboroCity_Mart_EventScript_PokemartBasic::
	pokemart RustboroCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

RustboroCity_Mart_EventScript_PokemartExpanded::
	pokemart RustboroCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

RustboroCity_Mart_EventScript_PokefanF::
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_Boy::
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_BugCatcher::
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_JokeNpc::
    setvar VAR_JOKE_NPC_INDEX, 2
    call JokeNpc_EventScript_Main
    end

RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish:
	.string "Ich wollte nur einen PARA-HEILER,\n"
	.string "aber dann hab ich Booster gesehen…\p"
	.string "Jetzt bin ich 20.000¥ ärmer\n"
	.string "und hab nur 3 Bisasam-Sticker.$"

RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead:
	.string "Kennst du den?\n"
	.string "Was sagt ein PIEPI im Supermarkt?\p"
	.string "“Pii, wo ist die Milchstraße?“\p"
	.string "…Ich lach jedes Mal wieder.$"

RustboroCity_Mart_Text_GettingEscapeRopeJustInCase:
	.string "Neulich an der Kasse:\n"
	.string "Blondine: Hier steht: “Hier öffnen…”\p"
	.string "…und reißt die Supertrank-Packung auf.\n"
	.string "Jetzt darf sie hier nicht mehr einkaufen.$"

