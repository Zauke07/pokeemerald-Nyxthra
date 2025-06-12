Debug_FlagsAndVarNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsAndVarNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsAndVarNotSetBattleConfigMessage_Text:
	.string "Feature unavailable! Please define a\n"
	.string "usable flag and a usable var in:\l"
	.string "'include/config/battle.h'!$"

Common_EventScript_ShowRivalId_Debug::
	special GetRivalStyleGraphicsIdAndSetVar
	special ShowFieldMessageVarObjGfxId0AndStyle
	waitbuttonpress
	return
