MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Ich bin der GESCHICHTENERZÄHLER.\n"
	.string "Ich laber dich mit alten Storys über\l"
	.string "legendäre TRAINER voll.\p"
	.string "Willst du dir das echt antun?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Pff...\n"
	.string "Lass mich halt alleine versauern...$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Hab da 'n paar krasse Legenden auf Lager.\n"
	.string "Welche Story soll ich raushauen?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Tja, dumm gelaufen. Ich kenn grad\n"
	.string "keine geilen TRAINER.\p"
	.string "Wo findet man heutzutage noch Leute,\n"
	.string "über die man krass ablästern... ähm,\l"
	.string "reden kann?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Ey, was geht ab?!\n"
	.string "Du... Du hast...\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} Mal durchgezogen?!\p"
	.string "Kranker Scheiß, das ist ja der Hammer!\n"
	.string "Da wird gleich 'ne Legende draus gestrickt!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Da frag ich mich glatt, ob da draußen\n"
	.string "noch andere kaputte TRAINER mit noch\l"
	.string "krasseren Storys rumrennen?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Bist du 'n TRAINER?\p"
	.string "Dann spuck's aus, hast du irgendwelche\n"
	.string "Storys, die wenigstens 'n bisschen ballern?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Nebenbei gefragt... Hast du Bock dir\n"
	.string "noch so 'ne fette Legende reinzuziehen?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm...\n"
	.string "Langweilig...\p"
	.string "Komm wieder, wenn du was gemacht hast,\n"
	.string "das nicht komplett zum Einschlafen ist.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Echt traurig, dass sich niemand für\n"
	.string "meinen geilen Scheiß über legendäre\l"
	.string "TRAINER interessiert.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "Der Speicher-Junkie$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Gespeichert wie 'n Verrückter$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser Typ hat einfach {STR_VAR_1} Mal\n"
	.string "gespeichert!\p"
	.string "So viel Schiss wie {STR_VAR_3} muss\n"
	.string "man erstmal haben!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "Der Trendhure-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Trends gestartet$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "irgendwelche neuen Trends gestartet!\p"
	.string "{STR_VAR_3} meint wohl, ganz HOENN\n"
	.string "tanzt nach seiner Pfeife!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "Der BEEREN-Bauer$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "BEEREN in den Dreck gesteckt$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "BEEREN gepflanzt!\p"
	.string "{STR_VAR_3} hat wohl 'nen krassen\n"
	.string "Fetisch für Grünzeug!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "Der RAD-Rowdy$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "RÄDER getauscht$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "sein RAD getauscht!\p"
	.string "{STR_VAR_3} kann sich wohl nie\n"
	.string "verdammt nochmal entscheiden!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "Die Rampensau$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Sich interviewen lassen$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat sich {STR_VAR_1} Mal\n"
	.string "das Mikro in die Fresse halten lassen!\p"
	.string "{STR_VAR_3} ist echt so geil auf\n"
	.string "Aufmerksamkeit, unglaublich!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "Der Kampf-Asi$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Leute weggeklatscht$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal gekämpft!\p"
	.string "{STR_VAR_3} sucht wohl echt hinter\n"
	.string "jeder Ecke Beef!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "Der POKéMON-Messie$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "POKéMON in Bälle gestopft$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat\n"
	.string "{STR_VAR_1} POKéMON gefangen!\p"
	.string "{STR_VAR_3} fängt wohl echt jeden\n"
	.string "Dreck, der nicht bei drei auf'm Baum ist!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "Der Angel-Proll$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Fische an Land gezogen$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat beim Angeln\n"
	.string "{STR_VAR_1} POKéMON aus dem Wasser gezerrt!\p"
	.string "{STR_VAR_3} hat wohl sonst\n"
	.string "keine Hobbys!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "Die EIER-Mutti$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "EIER ausgebrütet$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} POKéMON\n"
	.string "aus EIERN schlüpfen lassen!\p"
	.string "{STR_VAR_3} hockt wohl den halben\n"
	.string "Tag nur auf Eiern rum!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "Der Evolutions-Junkie$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "POKéMON mutieren lassen$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} POKéMON\n"
	.string "zur Entwicklung gezwungen!\p"
	.string "{STR_VAR_3} kriegt wohl nie\n"
	.string "den Hals voll!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "Der CENTER-Schnorrer$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Gratisheilung abgestaubt$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal seine\n"
	.string "POKéMON im CENTER heilen lassen!\p"
	.string "Niemand schnorrt sich so hart durchs\n"
	.string "Leben wie {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "Der Muttersöhnchen-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Bei Mutti gepennt$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "bei sich zuhause gepennt!\p"
	.string "So'n richtiges Muttersöhnchen wie\n"
	.string "{STR_VAR_3} findet man selten!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "Der SAFARI-Nerd$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "In der SAFARI-ZONE rumgelungert$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER war {STR_VAR_1} Mal\n"
	.string "in der SAFARI-ZONE!\p"
	.string "{STR_VAR_3} hat wohl draußen\n"
	.string "Schiss vor echten Kämpfen!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "Der Busch-Hacker$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "ZERTSCHNEIDER missbraucht$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "ZERTSCHNEIDER benutzt!\p"
	.string "{STR_VAR_3} rasiert echt jeden\n"
	.string "Büschel weg, der im Weg steht!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "Der Stein-Zertrümmerer$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Steine zu Staub gemacht$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "ZERTRÜMMERER benutzt!\p"
	.string "{STR_VAR_3} muss wohl echt miese\n"
	.string "Aggressionen abbauen!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "Der Obdachlosen-TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "GEHEIMBASIS umgezogen$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist mit seiner GEHEIMBASIS\n"
	.string "{STR_VAR_1} Mal umgezogen!\p"
	.string "{STR_VAR_3} flieht wohl vor den\n"
	.string "Steuerfahndern oder so!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "Der PLATSCHER-Trottel$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Sinnlos gePLATSCHERt$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "PLATSCHER eingesetzt!\p"
	.string "Wie dumm muss man sein? {STR_VAR_3}\n"
	.string "liebt es wohl, Zeit zu verschwenden!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "Der VERZWEIFLER$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Total abgefuckt VERZWEIFLER benutzt$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER musste {STR_VAR_1} Mal auf\n"
	.string "VERZWEIFLER zurückgreifen!\p"
	.string "{STR_VAR_3} hat wohl absolut keine\n"
	.string "Ahnung von Ressourcen-Management!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Der Spielotheken-King$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Den Jackpot geknackt$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat an den Automaten\n"
	.string "{STR_VAR_1} Mal den Jackpot abgeräumt.\p"
	.string "{STR_VAR_3} hat wohl mehr Glück\n"
	.string "als Verstand in der Spielo!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Der ROULETTE-Hustler$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "ROULETTE am Stück gewonnen$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat beim ROULETTE\n"
	.string "{STR_VAR_1} Mal in Folge gewonnen.\p"
	.string "{STR_VAR_3} hat die Kugel wohl\n"
	.string "irgendwie bestochen!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Das DUELLTURM-Opfer$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Sich im DUELLTURM blamiert$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat sich {STR_VAR_1} Mal\n"
	.string "in den DUELLTURM getraut!\p"
	.string "{STR_VAR_3} ist wohl scharf drauf,\n"
	.string "richtig auf die Fresse zu fliegen!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "Der Riegel-Panscher$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{POKEBLOCK} zusammengepampt$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "{POKEBLOCK} gemacht!\p"
	.string "Niemand manscht so viel ekliges\n"
	.string "Zeug zusammen wie {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "Die WETTBEWERBS-Diva$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Bei WETTBEWERBEN aufgedonnert$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "bei WETTBEWERBEN mitgemacht!\p"
	.string "{STR_VAR_3} hat's wohl echt nötig,\n"
	.string "sich vor anderen aufzuspielen!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Der Show-Abzieher$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "WETTBEWERBE rasiert$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal bei\n"
	.string "WETTBEWERBEN gewonnen!\p"
	.string "{STR_VAR_3} ist echt 'n arroganter\n"
	.string "WETTBEWERBS-Snob!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Das Konsum-Opfer$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Kohle rausgehauen$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal im\n"
	.string "Markt eingekauft!\p"
	.string "{STR_VAR_3} schmeißt die Kohle wohl\n"
	.string "echt mit beiden Händen aus'm Fenster.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "Der Pfandsammler$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Mit dem DETEKTOR Müll gesucht$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat den DETEKTOR\n"
	.string "{STR_VAR_1} Mal benutzt!\p"
	.string "{STR_VAR_3} kriecht wohl echt gerne\n"
	.string "im Dreck nach weggeworfenem Zeug!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "Der Pechvogel$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Vom Regen angepisst worden$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER wurde {STR_VAR_1} Mal vom\n"
	.string "Regen klatschnass gemacht!\p"
	.string "{STR_VAR_3} zieht das miese Wetter\n"
	.string "wohl magisch an!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Der POKéDEX-Streber$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Im POKéDEX rumgeschnüffelt$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal den\n"
	.string "POKéDEX gecheckt!\p"
	.string "{STR_VAR_3} hat wohl echt ein\n"
	.string "Gedächtnis wie ein Sieb!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Der BAND-Poser$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "BÄNDER abgestaubt$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "BÄNDER gekriegt!\p"
	.string "{STR_VAR_3} hängt seinen POKéMON\n"
	.string "wohl jeden billigen Fetzen um!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "Der Parkour-Trottel$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Von Klippen gesprungen$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist {STR_VAR_1} Mal\n"
	.string "über Stufen gesprungen!\p"
	.string "Wenn's da runter geht, kann\n"
	.string "{STR_VAR_3} sein Hirn wohl ausschalten!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Der Couch-Potato$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Sich vor die Glotze gehängt$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal\n"
	.string "Fernsehen geglotzt!\p"
	.string "{STR_VAR_3} sollte echt mal\n"
	.string "an die frische Luft gehen!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "Der Uhren-Spast$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Nach der Uhrzeit geguckt$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal auf\n"
	.string "die verdammte Uhr geschaut!\p"
	.string "{STR_VAR_3} hat wohl ordentlich\n"
	.string "Panik, was zu verpassen!$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Der LOTTERIE-Lucker$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "In der POKéMON-LOTTERIE gewonnen$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal in\n"
	.string "der POKéMON-LOTTERIE gewonnen!\p"
	.string "{STR_VAR_3} schleimt sich wohl bei\n"
	.string "allen zum Tauschen ein!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "Der Rabenvater$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "POKéMON in der PENSION abgeschoben$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal seine\n"
	.string "POKéMON in der PENSION abgeladen!\p"
	.string "{STR_VAR_3} hat wohl keinen Bock,\n"
	.string "seine Biester selber großzuziehen!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "Der SEILBAHN-Tourist$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Mit der SEILBAHN gegurkt$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER ist {STR_VAR_1} Mal mit\n"
	.string "der dämlichen SEILBAHN gefahren!\p"
	.string "{STR_VAR_3} ist wohl echt zu faul,\n"
	.string "den Berg mal selber hochzulaufen!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "Der Sauna-Gänger$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "In den Heißen Quellen rumgebadet$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Das ist die Story von 'nem TRAINER\n"
	.string "namens {STR_VAR_3}.\p"
	.string "Dieser TRAINER hat {STR_VAR_1} Mal in\n"
	.string "den Heißen Quellen abgepimmelt!\p"
	.string "{STR_VAR_3} wird langsam wohl echt\n"
	.string "weich in der Birne!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Hi, ich bin SCHNACKER!\n"
	.string "Ich hab 'ne krasse Story für dich!\p"
	.string "Bock, dir den Quatsch reinzuziehen?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh...\n"
	.string "Lass mich halt alleine versauern...$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Ach, mir fällt da noch was ein...$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Das wär's dann wohl fürs Erste...\p"
	.string "Lass mal wieder quatschen, ja?\n"
	.string "Hau rein!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hi, ich bin der BARDE.\n"
	.string "Willst du dir meinen Track gönnen?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh...\n"
	.string "Lass mich halt alleine versauern...$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Echt ein tiefgründiger Song...\n"
	.string "Würd den gern noch anderen aufzwingen...$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Und?\n"
	.string "Fetzt der Track, oder was?\p"
	.string "Aber der Text bockt mich irgendwie\n"
	.string "noch nicht so richtig an.\p"
	.string "Willst du mir nicht 'n paar\n"
	.string "krasse neue Zeilen schreiben?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh...\n"
	.string "Lass mich halt alleine versauern...$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Korrekt von dir!\n"
	.string "Dann hau ich das Teil mal raus.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "War das so in etwa der Vibe, den\n"
	.string "du für deinen Song im Kopf hattest?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Alles klar! Dann machen wir das so.\n"
	.string "Den Shit singe ich jetzt erstmal.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Yo, yo! Ich bin der HIPSTER.\n"
	.string "Ich zeig dir den krassesten neuen Scheiß.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Ey, ich hab dir doch schon erzählt,\n"
	.string "was gerade mega angesagt ist.\p"
	.string "Ich muss jetzt los, mein Wissen\n"
	.string "unter die anderen Loser bringen.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Yo, du weißt ja eh schon fast alles\n"
	.string "über den neuesten heißen Shit.\p"
	.string "Dir kann ich gar nichts mehr beibringen!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Yo, hast du schon von\n"
	.string "“{STR_VAR_1}“ gehört?\p"
	.string "Was das heißt? Ähm...\n"
	.string "Frag am besten Mutti oder Vati, ja?$"
