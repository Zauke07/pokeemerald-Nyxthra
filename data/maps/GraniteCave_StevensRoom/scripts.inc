GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lockall
	faceplayer
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, GraniteCave_StevensRoom_EventScript_StevenAfterLetter
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	setvar VAR_ROCKET_STATE, 1
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	checkflag FLAG_BADGE02_GET
	goto_if TRUE, GraniteCave_StevensRoom_EventScript_GiveBike
	goto_if FALSE, GraniteCave_StevensRoom_EventScript_BikeLocked

GraniteCave_StevensRoom_EventScript_StevenAfterLetter:
	checkflag FLAG_BADGE02_GET
	goto_if TRUE, GraniteCave_StevensRoom_EventScript_GiveBike
	msgbox GraniteCave_StevensRoom_Text_BeatBrawlyFirst, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

GraniteCave_StevensRoom_EventScript_AfterGift:
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	setflag FLAG_DELIVERED_STEVEN_LETTER
	releaseall
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_EventScript_BikeLocked:
	msgbox GraniteCave_StevensRoom_Text_BeatBrawlyFirst, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

GraniteCave_StevensRoom_EventScript_GiveBike:
    msgbox GraniteCave_StevensRoom_Text_GiveBike, MSGBOX_DEFAULT
    giveitem ITEM_MACH_BIKE
    call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
    goto GraniteCave_StevensRoom_EventScript_AfterGift


GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "Mein Name ist TROY.\p"
	.string "Ich sammle seltene Steine, daher reise\n"
	.string "ich durch ganz HOENN.\p"
	.string "Oh?\n"
	.string "Ein BRIEF? Für mich?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "TROY: Ich danke dir wirklich.\p"
	.string "Du bist für diesen Brief so weit gegangen.\n"
	.string "Hier - diese TM enthält STAHLFLÜGEL,\l"
	.string "eine meiner Lieblingsattacken.\p"
	.string "Sie ist nützlich gegen viele Typen,\n"
	.string "besonders in gefährlichen Höhlen.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "TROY: Deine Pokémon wirken stark\n"
	.string "und gut trainiert.\p"
	.string "Ich bin sicher, du könntest eines Tages\n"
	.string "die LIGA herausfordern.\p"
	.string "Sag…\n"
	.string "Hast du jemals KYOGRE gesehen?\p"
	.string "Ich glaube, ich habe es aus der Ferne\n"
	.string "beobachtet… aber es war nicht blau.\p"
	.string "Auch kein rosa Schimmer wie bei\n"
	.string "einem schillernden Exemplar…\p"
	.string "Es war… anders. Irgendwie anders.\p"
	.string "Ich kann es nicht erklären…\n"
	.string "aber es sah mächtig aus.\p"
	.string "Vor Kurzem habe ich außerdem ein\n"
	.string "U-Boot gesehen -\l"
	.string "es fuhr Richtung GRAPHITPORT.\p"
	.string "Darauf prangte ein großes rotes R…\n"
	.string "Das verheißt nichts Gutes.\p"
	.string "Ich habe ein ungutes Gefühl dabei…\n"
	.string "kannst du das untersuchen?\p"
	.string "Aber vorher solltest du zurück zu dem\n"
	.string "Mann, der dir den Brief gab.\p"
	.string "Er wartet bestimmt schon.\n"
	.string "Wir sehen uns.$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "TROY wurde im POKéNAV-Verzeichnis\n"
	.string "eingetragen.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Ich muss weiter - es gibt noch viele\n"
	.string "seltene Steine zu entdecken.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh… dein BEUTEL ist voll?\n"
	.string "Dann kann ich dir die TM leider\n"
	.string "nicht geben. Schade.$"


GraniteCave_StevensRoom_Text_BeatBrawlyFirst:
	.string "TROY: Ach übrigens…\p"
	.string "Ich hätte da noch ein Geschenk für\n"
	.string "dich - aber erst, wenn du die Arena\l"
	.string "hier geschafft hast.\p"
	.string "Besieg erst Kamillo in FAUSTAUHAVEN,\n"
	.string "dann reden wir weiter.$"

GraniteCave_StevensRoom_Text_GiveBike:
	.string "TROY: Ah, ich sehe, du hast den ORDEN\n"
	.string "von FAUSTAUHAVEN. Sehr gut!\p"
	.string "Hier, nimm das - ein echtes\n"
	.string "EILRAD. Schnell und wendig!$"
