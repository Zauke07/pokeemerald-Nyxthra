.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

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
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
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
	.string "MR. BRACK: Warte, Mädchen!\n"
	.string "Immer langsam, PECKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hm? Du bist {PLAYER}{KUN}!\n"
	.string "Du hast meine geliebte PEEKO gerettet!\l"
	.string "Wir sind dir so viel schuldig!\p"
	.string "Was ist das?\n"
	.string "Du willst mit mir segeln?\p"
	.string "Hmhm…\p"
	.string "Du hast einen BRIEF für WETTERAN auf\n"
	.string "FAULAENZERIN und ein Paket für FAULAENZERIN,\l"
	.string "stimmt's?\p"
	.string "Ein ziemlich geschäftiges Leben führst du!\p"
	.string "Aber natürlich ist das, was du fragst,\n"
	.string "kein Problem.\p"
	.string "Du bist hier an der richtigen Adresse!\n"
	.string "Wir segeln nach FAULAENZERIN.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "Mr. Brack: Dann geht es nach FAULAENZERIN!\p"
	.string "Leinen los!\n"
	.string "PEEKO, wir stechen in See, mein Liebling!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "Mr. Brack: Ist das so?\n"
	.string "Deine Lieferungen können warten?\p"
	.string "Sag mir einfach Bescheid, wann du\n"
	.string "segeln möchtest!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "Mr. Brack: Ahoi!\n"
	.string "Ich weiß genau, was du sagen willst!\p"
	.string "Du sollst einen BRIEF nach FAULAENZERIN\n"
	.string "und ein Paket nach FAULAENZERIN\l"
	.string "bringen.\p"
	.string "Was du von mir verlangst, ist kein\n"
	.string "Problem - ich bin der Richtige für den\l"
	.string "Job!\p"
	.string "Zuerst segeln wir nach FAULAENZERIN.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "Mr. Brack: Ahoi!\n"
	.string "Ich weiß genau, was du sagen willst!\p"
	.string "Du sollst ein Paket an\n"
	.string "KAPITÄN STERN in FAULAENZERIN\l"
	.string "überbringen.\p"
	.string "Was du von mir verlangst, ist kein\n"
	.string "Problem - ich bin der Richtige für den\l"
	.string "Job!\p"
	.string "Zuerst segeln wir nach FAULAENZERIN.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "Mr. Brack: Ahoi!\n"
	.string "Für dich gehe ich jederzeit aufs Meer!\p"
	.string "Also, mein Freund, wohin soll es gehen?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "Mr. Brack: Ist das so?\n"
	.string "Na, PEEKO verdankt dir ihr Leben.\p"
	.string "Sag mir einfach Bescheid, wann du\n"
	.string "segeln möchtest!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

