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
	.string "Hallo und Willkommen in der\n"
	.string "DEVON CORPORATION.\p"
	.string "Wir sind die stolzen Entwickler von\n"
	.string "Medizin und Items, die das Leben\l"
	.string "bereichern.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Einem Mitglied unseres Forschungsteams\n"
	.string "ist blöderweise ein wichtiges Paket\l"
	.string "gestohlen worden.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hey, diese TURBOTRETER!\n"
	.string "Die haben wir auch entwickelt!\p"
	.string "Ich freue mich immer, wenn ich jemanden\n"
	.string "treffe, der eines unserer Produkte\l"
	.string "benutzt.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Das gestohlene Paket...\p"
	.string "Nun, es ist natürlich sehr wichtig, aber\n"
	.string "mit dem Inhalt kann niemand etwas\l"
	.string "anfangen.\p"
	.string "Meiner Einschätzung nach ist der Dieb\n"
	.string "wirklich nicht sehr schlau gewesen...$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Klingt, als hätten wir die gestohlenen\n"
	.string "DEVON-WAREN zurückerhalten.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Tut mir Leid, aber nur autorisierte\n"
	.string "Personen haben hier Zutritt.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Das ist mehr als blöd.\n"
	.string "Wie konnten wir nur ausgeraubt werden?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hi, du da!\n"
	.string "Du bist hier jederzeit willkommen!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Proben von Steinen und Metall sind\n"
	.string "in der Glasvitrine ausgestellt.\p"
	.string "Es gibt eine Tafel mit einigen\n"
	.string "Schriftzeichen darauf…\p"
	.string "“Die DEVON CORPORATION begann als\n"
	.string "Hersteller von Steinen aus Steinbrüchen.\p"
	.string "“Das Unternehmen stellte auch Eisen aus\n"
	.string "Feilspänen im Sand her.\p"
	.string "“Von diesem bescheidenen Beginn als\n"
	.string "Hersteller von Rohstoffen hat sich DEVON\l"
	.string "entwickelt.\p"
	.string "“DEVON ist heute ein Hersteller einer\n"
	.string "breiten Palette von Industrieprodukten.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototypen und Testprodukte füllen\n"
	.string "die Glasvitrine.\p"
	.string "Es gibt eine Tafel mit einer Beschreibung darauf…\p"
	.string "“Zusätzlich zu Industrieprodukten vertreibt\n"
	.string "DEVON jetzt auch Kleinigkeiten und\l"
	.string "Pharmazeutika für ein besseres Leben.\p"
	.string "“In letzter Zeit hat DEVON begonnen, Werkzeuge\n"
	.string "für POKéMON-TRAINER zu vermarkten,\l"
	.string "darunter POKéBÄLLE und POKéNAV-Systeme.”$"

