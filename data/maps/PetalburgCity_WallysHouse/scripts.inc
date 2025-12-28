PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Du…\n"
	.string "Moment - du bist doch {PLAYER}{KUN}, oder?\p"
	.string "Danke, dass du Heiko geholfen hast.\p"
	.string "Er war schon als Baby ständig krank…\n"
	.string "sogar gegen Milch hatte er ’ne Allergie.\p"
	.string "Wir haben ihn zu Verwandten nach\n"
	.string "Wiesenflur geschickt - bessere Luft dort.\p"
	.string "Was? Er ist einfach weg?!\n"
	.string "Heiko?! Unser Heiko?!\p"
	.string "Oh Arceus… wo treibt der sich jetzt\n"
	.string "schon wieder rum?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Ich frag mich, was Heiko grad so macht…\n"
	.string "Hoffentlich hat er endlich gegessen.$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "Hi, {PLAYER}{KUN}! Sorry, dass du nochmal\n"
	.string "kommen musstest.\p"
	.string "Heiko ist viel stabiler geworden, seit\n"
	.string "er in Wiesenflur lebt.\p"
	.string "Und das verdanken wir wohl dir!\p"
	.string "Du warst dabei, als er sein erstes\n"
	.string "Pokémon gefangen hat, oder?\p"
	.string "Er war so glücklich - und ich auch.\n"
	.string "Mein Herz hat richtig gepiept.\p"
	.string "Das hier ist keine Bestechung!\n"
	.string "…Okay, vielleicht ein kleines Dankeschön.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Wenn dein Pokémon Surfer kann,\n"
	.string "öffnet sich dir gefühlt ganz Hoenn.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "Heiko kommt bald nach Hause!\n"
	.string "Ich putz schon seit drei Tagen nonstop.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Was?! Du hast Heiko in Prachtpolis City\n"
	.string "getroffen?\p"
	.string "Haha, klar. Und ich bin Cynthia.\n"
	.string "Er kommt doch nicht mal allein\n"
	.string "bis zur Bushaltestelle.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Heiko war SO glücklich, als er sagte:\n"
	.string "“Ich hab eins gefangen!”\p"
	.string "Ich hab ihn ewig nicht so strahlen sehen.\n"
	.string "Fast schon unheimlich.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Psst… Mein Mann weiß es noch nicht.\p"
	.string "Aber Heiko ist einfach abgehauen -\n"
	.string "ganz ohne was zu sagen!\p"
	.string "Er ist nicht kräftig, nein…\n"
	.string "Aber er ist stur wie ein Mampfaxo.\p"
	.string "Ich hoffe, er kommt heil zurück.\n"
	.string "Und ohne noch mehr Allergien.$"
