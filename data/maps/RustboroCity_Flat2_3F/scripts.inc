RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "Der PRÄSIDENT von DEVON sammelt\n"
	.string "leidenschaftlich seltene Steine.\p"
	.string "Sein Büro sieht aus wie ein halbes\n"
    .string "Museum!$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Der Sohn des PRÄSIDENTEN ist wohl\n"
	.string "ähnlich. Auch er sammelt seltene Steine.\p"
	.string "Scheint in der Familie zu liegen, was?$"

