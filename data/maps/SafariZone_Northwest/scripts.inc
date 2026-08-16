SafariZone_Northwest_MapScripts::
	.byte 0

SafariZone_Northwest_EventScript_Man::
	msgbox SafariZone_Northwest_Text_Man, MSGBOX_NPC
	end

SafariZone_Northwest_EventScript_Hopplo::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, SafariZone_Northwest_EventScript_Hopplo_RandomizerText
	msgbox SafariZone_Northwest_Text_Hopplo, MSGBOX_NPC
	end

SafariZone_Northwest_EventScript_Hopplo_RandomizerText::
	msgbox SafariZone_Northwest_Text_HopploRandomizer, MSGBOX_NPC
	end
