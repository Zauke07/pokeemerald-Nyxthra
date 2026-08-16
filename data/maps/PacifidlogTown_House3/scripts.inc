PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Guck dir dieses {STR_VAR_2} an!\p"
	.string "Hab ich mir gestern zum Geburtstag\n"
	.string "gegönnt, frisch gefangen!\p"
	.string "Ey, sabber nicht, ich seh doch, dass\n"
	.string "du's willst. Ist halt 'n krasses Teil.\p"
	.string "Weißt du was? Besorg mir 'n {STR_VAR_1},\n"
	.string "dann machen wir den Deal.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, das ist echt 'n {STR_VAR_1}?\p"
	.string "Hat irgendwie krasse {STR_VAR_2}-Vibes,\n"
	.string "sieht aber trotzdem anders aus.\p"
	.string "Ehrenaktion, danke dir!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Willst du mich komplett verarschen?!\n"
	.string "Ich hab klipp und klar gesagt:\p"
	.string "Ein {STR_VAR_1}! Komm mir bloß nicht\n"
	.string "mit so 'nem Schmutz!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Kneifst du jetzt oder was?\p"
	.string "Mir doch scheißegal. Ich muss mein\n"
	.string "Monster hier nicht zwingend loswerden.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Klar könnte ich meinen Arsch\n"
	.string "hochkriegen und selbst eins suchen...\p"
	.string "Aber ich wollte halt unbedingt ein\n"
	.string "KINDWURM von 'nem anderen TRAINER.\p"
	.string "Bin halt faul, okay?$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Ist das 'n original POKéDEX?\p"
	.string "Bist du echt draußen unterwegs und\n"
	.string "triffst die ganzen kranken POKéMON?\p"
	.string "Boah, dein Leben will ich haben.$"

