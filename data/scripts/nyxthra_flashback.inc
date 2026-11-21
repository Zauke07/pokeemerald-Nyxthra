@ Nyxthra: Rückblick-Clip 1 — Brix wählt 2005 auf der originalen Route 101 Hydropi.
@ Karte und Tilesets sind Kopien aus pret/pokeemerald (Smaragd 2005).
@ Texte im offiziellen deutschen Stil (PokéWiki, 3. Generation).

NyxthraFlashback_Text_HelpMe:
	.string "HI… HIIIILFE!!!\n"
	.string "HILFE!!!$"

NyxthraFlashback_Text_PleaseHelp:
	.string "Du dort drüben!\n"
	.string "Bitte! HILFE!!!\p"
	.string "In meinem BEUTEL…\n"
	.string "Da findest du einen POKéBALL!$"

NyxthraFlashback_EventScript_Clip1::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	playbgm MUS_HELP, TRUE
	msgbox NyxthraFlashback_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_FLASHBACK_BIRCH, 0, 15
	setobjectxy LOCALID_FLASHBACK_ZIGZAGOON, 0, 16
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_FLASHBACK_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_FLASHBACK_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_FLASHBACK_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_FLASHBACK_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_FLASHBACK_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_FLASHBACK_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_FLASHBACK_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox NyxthraFlashback_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FLASHBACK_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PlayerFaceLeft
	waitmovement 0
	special ChooseStarter
	delay 40
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end
