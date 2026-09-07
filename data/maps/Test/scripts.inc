Test_MapScripts::
	.byte 0

@ Nyxthra debug tool: assign this SAME script (via Porymap's object script
@ field) to any NPC you want to check - gSpecialVar_LastTalked gets set
@ automatically to whichever object you just talked to, so this works for
@ all of them without any per-NPC copy.
Test_EventScript_CheckPalette::
	lock
	faceplayer
	special Nyxthra_DebugShowObjectIdentity
	msgbox Test_Text_ObjectIdentity, MSGBOX_DEFAULT
	special Nyxthra_DebugShowWatchdogGentleman
	msgbox Test_Text_WatchdogGentleman, MSGBOX_DEFAULT
	special Nyxthra_DebugShowTableEntryCheck
	msgbox Test_Text_TableEntryCheck, MSGBOX_DEFAULT
	release
	end

Test_Text_ObjectIdentity:
	.string "ObjEvt: {STR_VAR_1}\n"
	.string "Graphics: {STR_VAR_2}\l"
	.string "Spieler ObjEvt: {STR_VAR_3}$"

Test_Text_WatchdogGentleman:
	.string "Gentleman Fixe: {STR_VAR_1}\n"
	.string "Slot danach: {STR_VAR_2}\l"
	.string "F/U/R: {STR_VAR_3}$"

Test_Text_TableEntryCheck:
	.string "Index: {STR_VAR_1}\n"
	.string "Tag an Index: {STR_VAR_2}\l"
	.string "Farbe/Match: {STR_VAR_3}$"
