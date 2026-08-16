SafariZone_Southwest_MapScripts::
	.byte 0

SafariZone_Southwest_EventScript_Woman::
	msgbox SafariZone_Southwest_Text_Woman, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_RestHouseSign::
	msgbox SafariZone_Southwest_Text_RestHouseSign, MSGBOX_SIGN
	end

SafariZone_Southwest_EventScript_Chimpep::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, SafariZone_Southwest_EventScript_Chimpep_RandomizerText
	msgbox SafariZone_Southwest_Text_Chimpep, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_Chimpep_RandomizerText::
	msgbox SafariZone_Southwest_Text_ChimpepRandomizer, MSGBOX_NPC
	end
