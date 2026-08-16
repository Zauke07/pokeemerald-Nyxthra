SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Hey! Endlich mal wieder ein\n"
	.string "Gast hier.\p"
	.string "Du rettest meinen Tag, also\n"
	.string "gönn dir diese Wailmer-Puppe.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Pass gut auf das Teil auf!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, du hast grad keinen Platz?\n"
	.string "Dann heb ich den Stuff auf.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Bist du sicher?\n"
	.string "Du lehnst Free Loot ab?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Ich liebe diese Plüsch-Teile!$"

