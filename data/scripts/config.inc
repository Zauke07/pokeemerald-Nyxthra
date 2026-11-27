Debug_FlagsAndVarNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsAndVarNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsAndVarNotSetBattleConfigMessage_Text:
	.string "Funktion nicht verfügbar! Bitte lege\n"
	.string "ein nutzbares Flag und eine nutzbare\l"
	.string "Variable fest in:\l"
	.string "'include/config/battle.h'!$"

Common_EventScript_ShowRivalId_Debug::
	special GetRivalStyleGraphicsIdAndSetVar
	special ShowFieldMessageVarObjGfxId0AndStyle
	waitbuttonpress
	return
