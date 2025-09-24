RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_TwixsDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferTwixPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_TwixsDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_TwixsDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoTwixNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithTwixPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_TwixLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_TwixDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_TwixsDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_TwixsDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_TwixsDadFaceTwix
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_TwixLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_TwixsDadFaceTwix
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_TWIX_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_TwixDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_TwixsDadFaceTwix
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_TwixsDadFaceTwix::
	turnobject LOCALID_TWIX_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_TwixsMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Du willst wissen, was wirklich schwer ist?\p"
	.string "Nein, nicht die Liga. Nicht TEAM ROCKET.\n"
	.string "Das tägliche KOCHEN.\p"
	.string "Was soll ich denn heute wieder machen?\n"
	.string "PokéNudeln? Glumanda-Gratin?\l"
	.string "Glibunkelgulasch?\p"
	.string "Sag du's mir. Ich bin kurz davor,\n"
	.string "einfach Chips mit TM-Geschmack\l"
	.string "zu servieren.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Willkommen im Pepper-Haushalt!\n"
	.string "Hier leben Schlafmangel und Babywindeln.\p"
	.string "Ich bin frischgebackener Vater…\n"
	.string "Und ja, ich bin VÖLLIG überfordert.\p"
	.string "Meine Tochter Twix? Lacht nie.\n"
	.string "So ernst wie ein Onix im Stau.\p"
	.string "Vielleicht kennst du ja einen Spruch,\n"
	.string "der ihr ein Lächeln entlockt?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ich hab in letzter Zeit immer\n"
	.string "“{STR_VAR_1}” gesagt, aber\l"
	.string "Twix schaut nur wie\n"
	.string "Rocko bei Sonnenlicht.\p"
	.string "Kennst du was Besseres? Was mit Wumms?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, das klingt super!\n"
	.string "Lass hören, was du auf Lager hast.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh? Wirklich?\p"
	.string "Na gut - wenn du was Geniales hast,\n"
	.string "bin ich ganz Ohr (und leicht verzweifelt).$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Okay, dann probieren wir deinen Spruch.\p"
	.string "Er kann ja kaum schlechter sein\n"
	.string "als meiner.$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}?!\p"
	.string "Haha! Oh wow - sie lacht!\n"
	.string "Sie kann nicht mehr aufhören!\p"
	.string "Ich... ich auch nicht... danke!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Alles klar.\n"
	.string "Dann mal los. Twix, hör gut zu...$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}...\p"
	.string "Nichts.\n"
	.string "Kein Zucken, kein Blinzeln.\p"
	.string "Ich glaube, Twix ist auf innerem\l"
	.string "Zen-Urlaub.$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Also hast du keinen?\n"
	.string "Dann denke ich halt selbst nach.\p"
	.string "Wie wär's mit “Karpador-Karate”?\l"
	.string "......\n"
	.string "Ja, okay. Vergessen wir das.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}...\p"
	.string "Nope. Keine Reaktion.\n"
	.string "Vielleicht ist Twix einfach ein kleiner Boss.$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Also hast du keinen?\n"
	.string "Dann muss ich eben weiterraten…\p"
	.string "Wenn dir doch mal was einfällt,\n"
	.string "komm einfach wieder vorbei, okay?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Du hast’s geschafft!\n"
	.string "Twix hat gelacht - ein echtes Lachen!\p"
	.string "Ich… ich glaub, ich wein gleich.\n"
	.string "Du bist mein Held!\p"
	.string "Wusstest du, dass ich bei DEVON arbeite?\n"
	.string "Ich bin der Typ für Tapeten. Kein Witz.\p"
	.string "Ich hab dir neue Box-Designs\n"
	.string "freigeschaltet: Wähl “FREUNDE” im\l"
	.string "PC-Menü.\p"
	.string "Und denk dran: Humor rettet Leben -\n"
	.string "oder zumindest Väter mit Schlafmangel.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Das ist eine POKéMON-Stoffpuppe!\n"
	.string "Und ja, sie wurde schon vollgesabbert.$"

RustboroCity_Flat1_2F_EventScript_QuestBoard::
	msgbox RustboroCity_Flat1_2F_Text_QuestBoard, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_QuestBoard:
	.string "Auf dem Brett steht ein Hinweis:\p"
	.string "Du kannst ein eigenes Geheimwort\n"
	.string "für das Kind generieren,\l"
	.string "damit es wieder lacht.\p"
	.string "Google dazu einfach:\n"
	.string "“Pokémon Emerald geheimwort\l"
	.string "-generator”\p"
    .string "und öffne den ersten Link.$"

