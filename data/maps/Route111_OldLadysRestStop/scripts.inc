Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_NowYouAreFit, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Du siehst fertig aus, ey.\n"
	.string "Soll ich deine Mon's kurz fit machen?\p"
	.string "Komm, leg dich kurz hin.\n"
	.string "Ich beiß nicht - meistens.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "So gehört sich das.\n"
	.string "Kurz chillen, dann\l"
    .string "wieder klatschen gehen.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Pff, dann verpuff halt.\n"
	.string "Meine Couch hat eh Besseres verdient.$"

Route111_OldLadysRestStop_Text_NowYouAreFit:
	.string "So, deine Mon's sind wieder fresh.\l"
	.string "Verklopp jetzt ein paar Noobs, klar?\p"
	.string "Was denn, noch'n Keks?\l"
	.string "Tsss... die Jugend von heute...$"
