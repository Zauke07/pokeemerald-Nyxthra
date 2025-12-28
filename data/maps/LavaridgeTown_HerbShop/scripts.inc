LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop::
	.string "Willkommen in der Giftmischerei!\n"
	.string "Hier gibt's Zeug, das wirkt - auch wenn\l"
	.string "dein POKéMON danach schreit!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine::
	.string "Du willst dich also mit Kräuter-Dreck\n"
	.string "eindecken, hier in BAD LAVASTADT?\p"
	.string "Ziemlich skrupellos von dir.\p"
	.string "Gefällt mir! Nimm den Müll hier mit!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal::
	.string "Diese HOLZKOHLE ist eigentlich zum\n"
	.string "Medizin mischen da.\p"
	.string "Aber wenn du sie einem POKéMON zum\n"
	.string "Festhalten gibst, brennen seine Feuer-\l"
	.string "Attacken dem Gegner Löcher in die Haut.\p"
	.string "Ziemlich fies, oder?$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike::
	.string "Die Kräuter ziehen ordentlich durch.\n"
	.string "Aber dein POKéMON wird dich dafür\l"
	.string "abgrundtief hassen.\p"
	.string "Das Zeug ist so bitter, da zieht's\n"
	.string "einem alles zusammen!$"

