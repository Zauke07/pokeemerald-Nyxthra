RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Diese Entschlossenheit...\n"
	.string "Diese Moves...\l"
	.string "Du bist kein 08/15-TRAINER, das seh ich\p"
	.string "sofort! Sag nix, dein Style spricht Bände.\n"
	.string "Und du hast diesen Blick - gefährlich \l"
    .string "motiviert.\p"
	.string "Ich drück dir einfach das in die Hand.\n"
	.string "Keine Widerrede, Bruder - du packst das!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Das hier ist VM01 - ZERSCHNEIDER.\p"
	.string "Mit der kannst du nicht nur im Kampf\n"
	.string "was reißen, sondern auch draußen Bäume\l"
    .string "fällen.\p"
	.string "Aber nur, wenn du den\n"
    .string "ersten ORDEN hast.\p"
	.string "Sonst sagt dein POKéMON: nö.\p"
	.string "Und im Gegensatz zu einer TM - die hier\n"
	.string "kannst du so oft einsetzen, wie du willst.\p"
	.string "Fast wie TikTok: einfach immer wieder.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Mein Dad hat damals geholfen, als sie\n"
	.string "METAROST CITY erweitern wollten.\p"
	.string "Er hat einfach seine POKéMON genommen,\n"
	.string "und zack - Baum weg, Baum weg, Baum weg.\p"
	.string "Der Typ war wie ein\n"
    .string "lebender Rasentrimmer.$"

