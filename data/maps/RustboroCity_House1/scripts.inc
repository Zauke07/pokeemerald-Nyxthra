RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Gibst du deinen POKéMON eigentlich\n"
	.string "Spitznamen? Ich hab meinem 'nen\l"
    .string "richtig coolen Namen gegeben.\p"
	.string "Aber immer wenn ich's rufe, lachen\n"
	.string "sich alle Leute schlapp…\p"
	.string "Wie wär’s? Willst du dein {STR_VAR_1}\n"
	.string "gegen mein {STR_VAR_2} tauschen?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hihihi… oh Mann, das ist so aufregend!$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hm? Das sieht nicht nach nem {STR_VAR_1} aus.\n"
	.string "Na toll… wie enttäuschend.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Schade… das ist echt ein gutes POKéMON.$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Willst du nicht wissen, welche verrückten\n"
	.string "Namen andere Leute ihren POKéMON geben?$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Überall leben ganz unterschiedliche\n"
	.string "Leute mit unterschiedlichen POKéMON.\p"
	.string "Ich find das mega spannend, deswegen\n"
	.string "reise ich gerne rum.$"

