SafariZone_North_MapScripts::
	.byte 0

SafariZone_North_EventScript_Fisherman::
	msgbox SafariZone_North_Text_Fisherman, MSGBOX_NPC
	end

SafariZone_North_EventScript_Man::
	msgbox SafariZone_North_Text_Man, MSGBOX_NPC
	end

SafariZone_North_EventScript_Memmeon::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, SafariZone_North_EventScript_Memmeon_RandomizerText
	msgbox SafariZone_North_Text_Memmeon, MSGBOX_NPC
	end

SafariZone_North_EventScript_Memmeon_RandomizerText::
	msgbox SafariZone_North_Text_MemmeonRandomizer, MSGBOX_NPC
	end
