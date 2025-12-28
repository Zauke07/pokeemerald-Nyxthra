VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech::
	.string "HEIKO: Tja, du hast zwar gewonnen,\n"
	.string "{PLAYER}, aber bild dir bloß nichts ein!\p"
	.string "Ich hab jetzt einen Masterplan.\n"
	.string "Mein TRASLA und ich werden die ARENen\p"
	.string "komplett rasieren. Ich werd der Boss,\n"
	.string "während du noch im Matsch spielst.\p"
	.string "Zitter schon mal, {PLAYER}.\n"
	.string "Bald zieh ich dir die Ohren lang!\p"
	.string "Und dann zeig ich dir mal, wie man\n"
	.string "richtig kämpft, du Amateur!$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort::
	.string "HEIKO: Putz schon mal deine Orden,\n"
	.string "{PLAYER}. Bald gehör'n sie mir!\p"
	.string "Dann polier ich dir die Fresse,\n"
	.string "dass du Sterne siehst!$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor::
	.string "ONKEL: Oh! {PLAYER}{KUN}!\n"
	.string "Der nervige Bengel hockt nebenan.\p"
	.string "Aber pass mal auf:\p"
	.string "Die Luft hier ist so gut, dass HEIKO\n"
	.string "endlich aufgehört hat, rumzuheulen.\p"
	.string "Oder er hat gemerkt, dass er mit seiner\n"
	.string "Mitleids-Tour hier nicht weit kommt.\l"
	.string "Sein POKéMON tut mir echt leid…$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff::
	.string "HEIKO hat sich endlich verpisst…\n"
	.string "Soll er doch woanders nerven…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar::
	.string "ONKEL: Ernsthaft?\n"
	.string "HEIKO ist ganz alleine abgehauen?\p"
	.string "Na endlich! Ich dachte schon, ich\n"
	.string "muss den Kerl bis zur Rente füttern…$"

VerdanturfTown_WandasHouse_Text_MeetWanda::
	.string "HEIKE: Wer zur Hölle bist du?\n"
	.string "Ach, warte mal…\p"
	.string "Du bist {PLAYER}. HEIKO hat ständig\n"
	.string "von dir gelabert, echt nervig.\p"
	.string "Ich bin seine Cousine.\n"
	.string "Guck nicht so blöd!\p"
	.string "Seit er hier ist, hat er zumindest\n"
	.string "aufgehört, das Bad vollzukotzen.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally::
	.string "HEIKE: Mach dir keinen Kopf um HEIKO.\n"
	.string "Unkraut vergeht nicht.\p"
	.string "Der Kleine ist zäher als er aussieht.\n"
	.string "Und wenn nicht - sein POKéMON regelt.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay::
	.string "Dank dir kann ich meine Olle jetzt\n"
	.string "jeden Tag sehen. Ob ich happy bin?\l"
	.string "Klar, jetzt kann ich sie endlich\l"
	.string "kontrollieren!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven::
	.string "Der Typ meiner Tochter ist ein echter\n"
	.string "Psycho.\p"
	.string "Er gräbt wie ein Besessener diesen\n"
	.string "Tunnel, nur um sie zu stalken.\p"
	.string "Meine Tochter kriegt langsam Panik und\n"
	.string "schaut jeden Tag, ob er schon durch ist.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging::
	.string "Unfassbar! Der Freak hat den Tunnel\n"
	.string "tatsächlich mit den Händen gegraben!\p"
	.string "Vollkommen geisteskrank!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally::
	.string "Wenn HEIKO abkratzt, krieg ich Stress\n"
	.string "mit seinen Eltern in BLÜTENBURG.\l"
	.string "Darauf hab ich echt keinen Bock…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande::
	.string "HEIKO ist in PRACHTPOLIS CITY?\p"
	.string "Sein Vater in BLÜTENBURG kriegt bestimmt\n"
	.string "’nen Herzinfarkt, wenn er das hört.$"

