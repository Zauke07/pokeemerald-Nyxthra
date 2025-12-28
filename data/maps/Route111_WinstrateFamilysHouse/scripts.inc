Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou::
	.string "Ich hab ja schon viele Glückspilze gesehen,\n"
	.string "aber du scheinst deine Viecher ja halbwegs\l"
	.string "im Griff zu haben.\p"
	.string "Aber bild dir bloß nichts drauf ein… mein\n"
	.string "Sohn würde mit dir den Boden aufwischen.\p"
	.string "Der ist gerade bei der POKéMON LIGA und\n"
	.string "zeigt denen mal, wie man richtig kämpft.\l"
	.string "Dagegen bist du gar nichts!$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace::
	.string "Wir benutzen dieses MACHOBAND, um unsere\n"
	.string "POKéMON mal so richtig ranzunehmen.\p"
	.string "Du hast zwar meine ganze Sippe besiegt,\n"
	.string "aber du siehst aus, als könntest du\l"
	.string "ein bisschen extra Training gebrauchen.\l"
	.string "Nimm das MACHOBAND und werd endlich\l"
	.string "ein echter Mann (oder ’ne Frau)!$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles::
	.string "Wenn’s ums Boxen geht, kennt meine\n"
	.string "Familie keine Freunde. Wir leben für\l"
	.string "den Stress!$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers::
	.string "Mami klatscht Papi.\p"
	.string "Ich klatsch Mami.\p"
	.string "Und Omi klatscht mich!\p"
	.string "Aber mein großer Bruder klatscht sie\n"
	.string "einfach alle weg!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong::
	.string "Ja ja, du bist stark, bla bla.\p"
	.string "Aber wenn du gegen meinen Enkel antrittst,\n"
	.string "wirst du heulend zu deiner Mami rennen.\l"
	.string "Der zerlegt Typen wie dich zum Frühstück!\p"
	.string "Der ist gerade dabei, die POKéMON LIGA\n"
	.string "auseinanderzunehmen.\p"
	.string "So wie ich den kenne, ist er mittlerweile\n"
	.string "schon der Boss der Bosse!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort::
	.string "Mein Enkel ist gerade dabei, die\n"
	.string "POKéMON LIGA zu demütigen.\p"
	.string "Der ist bestimmt schon CHAMP und lacht\n"
	.string "über Versager wie dich!$"

