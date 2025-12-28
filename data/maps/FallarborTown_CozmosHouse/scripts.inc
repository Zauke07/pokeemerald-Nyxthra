FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow::
	.string "PROF. KOSMO: Oh Mann…\n"
	.string "Ich bin so ein Vollidiot. Warum hab ich\l"
	.string "diesem TEAM MAGMA nur geglaubt?\l"
	.string "Die haben mich abgezogen wie ’nen\l"
	.string "Schuljungen…\p"
	.string "Mein schöner METEORIT aus den\n"
	.string "METEORFÄLLEN… Den krieg ich nie wieder.\l"
	.string "Mein Leben ist so unfair! Mimimi…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt::
	.string "Oh!\n"
	.string "Häh?\p"
	.string "Dieses Ding da…\p"
	.string "Ist das etwa…?\p"
	.string "Ist das der METEORIT, den diese\n"
	.string "Halbstarken von TEAM MAGMA geklaut\l"
	.string "haben?\p"
	.string "Bitte, gib ihn mir! Ich brauch den!\p"
	.string "Ich bin auch kein Schnorrer.\n"
	.string "Hier, nimm diese TM und rück das\l"
	.string "Teil endlich raus!$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM::
	.string "PROF. KOSMO: Diese TM ist quasi mein\n"
	.string "Schweigegeld. Nimm sie und lass mich\l"
	.string "endlich mit meinem Stein allein!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch::
	.string "PROF. KOSMO: Oh, ich fass es nicht.\n"
	.string "Geil, einfach nur geil!\p"
	.string "Jetzt kann ich endlich wieder so tun,\n"
	.string "als würde ich hier wichtig forschen!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment::
	.string "PROF. KOSMO: Ernsthaft?\n"
	.string "Du willst mich echt so hängen lassen?\l"
	.string "Du bist so ein mieser Typ…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite::
	.string "PROF. KOSMO: Bitte, gib mir den Stein!\p"
	.string "Ich geb dir auch diesen TM-Müll dafür.\n"
	.string "Komm schon, sei kein Arsch!$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls::
	.string "PROF. KOSMO ist mit ein paar Typen von\n"
	.string "TEAM MAGMA zu den METEORFÄLLEN\l"
	.string "abgehauen. Der lässt sich auch von\l"
	.string "jedem Honk einladen.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo::
	.string "Der arme Professor…\n"
	.string "Der hockt nur noch in der Ecke und\l"
	.string "flennt. Das hält man im Kopf nicht aus.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy::
	.string "Guck dir den KOSMO an…\n"
	.string "Der freut sich wie ’n Schnitzel über\l"
	.string "diesen dämlichen Stein. Peinlich.$"

