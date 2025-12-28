MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_HARBOR_MAIL
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport::
	.string "Wenn ich doch nur ein verdammtes RAD\n"
	.string "hätte… Dann könnte ich endlich aus\l"
	.string "diesem Loch abhaun und einkaufen.\p"
	.string "In GRAPHITPORT CITY gibt es diesen\n"
	.string "HAFENBRIEF im Supermarkt… den brauche\l"
	.string " ich unbedingt für meine Geschäfte.$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase::
	.string "Oh! Du hast einen HAFENBRIEF dabei?!\n"
	.string "Rück ihn raus! Ich geb dir auch diesen\l"
	.string "MÜNZKORB dafür. Der bringt mir hier\l"
	.string "eh nur Unglück! Deal?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase::
	.string "Na endlich! Her mit dem Ding!\n"
	.string "Hier, nimm den MÜNZKORB und verspiel\l"
	.string "dein Hab und Gut in der Absteige\l"
	.string "nebenan!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner::
	.string "Ohne diesen MÜNZKORB lassen dich die\n"
	.string "Schlägertypen in der SPIELHALLE nicht\l"
	.string "mal an die Automaten.$"

MauvilleCity_House2_Text_ThatsDisappointing::
	.string "Tzz, dann eben nicht.\p"
	.string "Viel Spaß beim Zugucken in der\n"
	.string "SPIELHALLE, ohne Korb kriegst du\l"
	.string "da nämlich gar nichts!$"

