LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_POKE_DOLL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ADRENALINE_ORB
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_WAVE_MAIL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly::
	.string "Lern erst mal, wie man Items richtig\n"
	.string "benutzt, bevor du hier auf dicke Hose\l"
	.string "machst. Das ist ja wohl das Mindeste!$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband::
	.string "Mein Alter hockt zu Hause und wartet.\n"
	.string "Was schenk ich dem bloß, damit er endlich\l"
	.string "mal die Klappe hält?$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems::
	.string "Ich verdufte bald auf 'ne lange Reise.\n"
	.string "Ich muss mich mit Zeug eindecken, damit\l"
	.string "ich da draußen nicht jämmerlich verrecke.$"

