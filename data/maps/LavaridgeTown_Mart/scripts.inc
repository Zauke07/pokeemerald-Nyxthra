LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike::
	.string "Zieh dir X-TEMPO rein, wenn dein\n"
	.string "POKéMON zu lahmarschig ist.\p"
	.string "Damit schlägst du vielleicht mal zuerst\n"
	.string "zu - ein massiver Vorteil für Leute,\l"
	.string "die sonst nix hinkriegen!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney::
	.string "Oben auf dem Schlotberg gibt’s so ’nen\n"
	.string "Spezial-Fraß, den man nur da kriegt.\p"
	.string "Stopf das in dein POKéMON rein - das\n"
	.string "Vieh wird vor Freude fast ausrasten.$"

