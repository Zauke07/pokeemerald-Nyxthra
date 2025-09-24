Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "Mr. Brack: Chill mal, Mädel!\n"
	.string "PECKO, renn nicht wieder los\n"
    .string "wie auf Red Bull!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Oh, du bist das!\n"
	.string "{PLAYER}{KUN}, mein Retter - PECKO\l"
    .string "schuldet dir ihr Leben!\p"
	.string "Also willst du auf große Reise?\n"
	.string "BRIEF nach FAUSTAUHAVEN, Paket\l"
    .string "nach GRAPHITPORT?\p"
	.string "Uff, Amazon-Express oder was?\p"
	.string "Aber hey - ich bin dabei.\n"
	.string "Kapitän BRACK bringt dich überall hin.\p"
	.string "Pack die Badehose ein - auf\n"
    .string "nach FAUSTAUHAVEN!$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "Mr. Brack: Und los geht’s!\n"
    .string "FAUSTAUHAVEN, wir kommen!\p"
	.string "Anker hoch!\n"
	.string "PECKO, Navi an - Kurs Südwest!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "Mr. Brack: Echt jetzt? Du lässt mich\n"
	.string "hier einfach stehen?\p"
	.string "Na gut. Wenn du wieder Bock hast -\n"
	.string "einfach Bescheid geben.$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "Mr. Brack: Aha! Ich weiß, was anliegt.\p"
	.string "Brief nach FAUSTAUHAVEN, Paket\n"
	.string "nach GRAPHITPORT? Klassiker!\p"
	.string "Ich bin dein Uber-Boat - los geht’s\n"
	.string "erstmal nach FAUSTAUHAVEN!$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "Mr. Brack: Ich kenn den Blick.\n"
    .string "Du willst liefern.\p"
	.string "KAPT. BRIGG wartet in GRAPHITPORT…\n"
	.string "Und du bringst’s ihm, wie DHL mit Style!\p"
	.string "Aber wir starten wie immer mit dem\n"
	.string "nassen Abenteuer: FAUSTAUHAVEN!$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "Mr. Brack: Hey, für dich spring ich\n"
	.string "jederzeit in die Fluten!\p"
	.string "Sag Bescheid - FAUSTAUHAVEN oder GRAPHITPORT?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "Mr. Brack: Noch nicht bereit?\n"
	.string "Kein Ding.\p"
	.string "PECKO schuldet dir eh - ruf einfach,\n"
	.string "wenn’s losgehen soll.$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PECKO: Pii piihyoro!\n"
	.string "(“heftiges Möwengeschrei auf Koffein”)$"

