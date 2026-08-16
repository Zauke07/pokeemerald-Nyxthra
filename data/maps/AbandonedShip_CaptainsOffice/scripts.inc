AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Ich untersuche dieses Schiff im Auftrag\n"
	.string "von KAPITÄN BRIGGS.\p"
	.string "Er hat mich auch gebeten, einen SCANNER\n"
	.string "zu finden, aber bisher ohne Erfolg…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh! Das ist ein SCANNER!\p"
	.string "Kannst du den bitte zu KAPITÄN BRIGGS\n"
	.string "bringen?\p"
	.string "Ich möchte das Schiff hier noch\n"
	.string "etwas weiter untersuchen.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Dieses Schiff heißt S.S. KAKTEI.\n"
	.string "Es scheint aus einer früheren Zeit zu stammen.$"

