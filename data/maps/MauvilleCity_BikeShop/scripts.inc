MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_AlreadyHaveAcro
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_BikeShop_EventScript_TellGetMachBikeFromTroy
	goto_if_unset FLAG_CYCLING_ROAD_PASSED_FOR_ACRO, MauvilleCity_BikeShop_EventScript_TellBeatCyclingRoad
	goto MauvilleCity_BikeShop_EventScript_GiveAcroBike
	end

MauvilleCity_BikeShop_EventScript_AlreadyHaveAcro::
	msgbox MauvilleCity_BikeShop_Text_AlreadyHaveAcroBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_TellGetMachBikeFromTroy::
	msgbox MauvilleCity_BikeShop_Text_GetMachBikeFromTroy, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_TellBeatCyclingRoad::
	msgbox MauvilleCity_BikeShop_Text_BeatCyclingRoadFirst, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_GiveAcroBike::
	msgbox MauvilleCity_BikeShop_Text_GiveAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BIKE
	release
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	msgbox MauvilleCity_BikeShop_Text_HandbookDisabled, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	msgbox MauvilleCity_BikeShop_Text_HandbookDisabled, MSGBOX_NPC
	end

MauvilleCity_BikeShop_Text_HandbookDisabled:
	.string "Die Handbücher sind gerade nicht verfügbar.$"

MauvilleCity_BikeShop_Text_AlreadyHaveAcroBike:
	.string "RADLA: Na sieh mal einer an!\p"
	.string "Du hast ja schon ein KUNSTRAD.\n"
	.string "Viel Spaß damit!$"

MauvilleCity_BikeShop_Text_GetMachBikeFromTroy:
	.string "RADLA: Hm? Du hast ja gar kein\n"
	.string "EILRAD!\p"
	.string "Hol dir zuerst das EILRAD von TROY.\n"
	.string "Dann können wir weiterreden!$"

MauvilleCity_BikeShop_Text_BeatCyclingRoadFirst:
	.string "RADLA: Ein KUNSTRAD bekommst du\n"
	.string "nicht einfach so!\p"
	.string "Beweise dich zuerst auf dem RADWEG.\n"
	.string "Fahr sauber und zeig mir dein Können!\p"
	.string "Dann gebe ich dir ein KUNSTRAD.$"

MauvilleCity_BikeShop_Text_GiveAcroBike:
	.string "RADLA: Aha! Das war nicht schlecht!\p"
	.string "Wie versprochen:\n"
	.string "Hier ist dein KUNSTRAD!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Ich lerne etwas über RÄDER,\n"
	.string "während ich hier arbeite.\p"
	.string "Die Handbücher stehen dort hinten.$"
