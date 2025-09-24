RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Willkommen bei DEVON CORPORATION!\n"
	.string "Die Firma für alles, was das\l"
	.string "Leben besser macht.\p"
    .string "Medizin, Items, Technik - wir ent-\n"
	.string "wickeln, was dein Abenteuer beflügelt.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Puh... Eines unserer Forscherteams wurde\n"
	.string "tatsächlich beklaut.\p"
    .string "Voll peinlich, ehrlich gesagt.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Whoa, du hast die TURBOTRETER an?!\n"
	.string "Die stammen aus unserem Labor!\p"
	.string "Es ist immer cool zu sehen, wenn\n"
	.string "unsere Erfindungen im Einsatz sind.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Das geklaute Paket?\p"
	.string "Klar, das war wichtig - aber damit anfangen\n"
	.string "kann der Dieb nix ohne die Anleitung.\p"
	.string "Ehrlich gesagt... der war nicht gerade\n"
	.string "die hellste Kerze auf der Torte.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Na das klingt doch gut!\n"
	.string "Unsere DEVON-WAREN sind wieder zurück.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Sorry, hier ist Schluss.\n"
	.string "Zutritt nur mit DEVON-Ausweis.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Echt jetzt… Wie konnte das passieren?\n"
	.string "Wir bauen Hightech, aber werden beklaut.$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hey, schön dich wiederzusehen!\n"
	.string "Komm jederzeit vorbei!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "In der Vitrine funkeln alte Gesteins- und\n"
	.string "Metallproben. Eine Tafel erklärt alles…\p"
	.string "“DEVON startete klein - mit Steinen aus\n"
	.string "Steinbrüchen und Metall aus\l"
    .string "Sandfeilspänen.\p"
	.string "“Heute liefern wir alles: von Hightech-Zeug\n"
	.string "bis zu coolen Tools für Trainer.$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Die Glasvitrine ist voll mit Geräten,\n"
	.string "die nach Zukunft aussehen.\p"
	.string "Eine Infotafel erklärt:\p"
	.string "“Neben Industrieprodukten stellt DEVON\n"
	.string "jetzt auch Trainer-Gadgets her.\p"
	.string "“Zum Beispiel POKéBÄLLE und POKéNAVs -\n"
	.string "alles, was dein Abenteuer braucht.”$"

