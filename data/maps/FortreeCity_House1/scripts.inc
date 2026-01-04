FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou::
	.string "Wroooaaar! Ich brauch das Teil!\n"
	.string "Ich muss unbedingt ein {STR_VAR_1} haben!\l"
	.string "Ich würd' fast alles dafür tun!\p"
	.string "Äh…… Hast du das gehört?\n"
	.string "Das war mein gieriger Schrei nach Blut!\p"
	.string "Jetzt, wo du weißt, wie verzweifelt ich\n"
	.string "bin, tauschst du doch sicher dein\l"
	.string "{STR_VAR_1} gegen mein {STR_VAR_2}?!?$"

FortreeCity_House1_Text_MonYouTakeCare::
	.string "Geil! Her mit dem Teil!\p"
	.string "Willkommen in der Hölle, {STR_VAR_1}!\n"
	.string "Zisch ab und nerv wen anders, {STR_VAR_2}!$"

FortreeCity_House1_Text_ThisIsntAMon::
	.string "Willst du mich verarschen?\n"
	.string "Das ist doch gar kein {STR_VAR_1}!$"

FortreeCity_House1_Text_YouWontTradeMe::
	.string "Was? Nein? Willst du mich leiden sehen?\n"
	.string "Obwohl ich mich hier so zum Affen\l"
	.string "gemacht habe? Asozial!$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong::
	.string "Ich werd' dafür sorgen, dass VOLBEAT\n"
	.string "so richtig fies und stark wird!\p"
	.string "Sieh zu, dass du PLUSLE nicht sofort\n"
	.string "schrottest!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers::
	.string "Mit anderen POKéMON tauschen……\p"
	.string "Das ist, als ob man seinen Müll mit\n"
	.string "anderen Leuten teilt. Irgendwie eklig.$"

FortreeCity_House1_Text_Zigzagoon::
	.string "ZIGZACHS: Gumomoh? (Was glotzt du?)$"

