ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Hey, du da! Trainer, richtig?\n"
	.string "Du siehst aus, als hättest du was drauf.\p"
	.string "Ich habe ein kleines Hobby: Ich sammle\n"
	.string "die Profile von Pokémon-Trainern.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Also, was sagst du?\n"
	.string "Verrätst du mir dein Profil?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Dein Profil besteht aus genau vier\n"
	.string "Wörtern oder kurzen Phrasen.\p"
	.string "Ich zeig dir mal ein kleines Beispiel,\n"
	.string "wie so etwas aussehen kann.\p"
	.string "Du kannst diese vier Textbausteine\n"
	.string "völlig frei mischen, bis es perfekt\l"
	.string "zu dir passt.\p"
	.string "Die Auswahl an Wörtern ist riesig.\p"
	.string "Damit du nicht den Überblick verlierst,\n"
	.string "sind sie in Kategorien wie Pokémon oder\l"
	.string "Hobbys sortiert.\p"
	.string "Wähle einfach eine Kategorie aus, um\n"
	.string "die Wörter darin zu sehen.\p"
	.string "Such dir deinen Favoriten aus.\p"
	.string "Mach das viermal, und dein ganz\n"
	.string "persönliches Profil steht!$"

ProfileMan_Text_LetsSeeItThen:
	.string "Perfekt! Danke dir!\n"
	.string "Dann leg mal los.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Schade, wirklich.\p"
	.string "Dabei hätte dein Profil bestimmt\n"
	.string "echt interessant geklungen…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Keine Lust im Moment?\p"
	.string "Alles klar, ich bin ja hier, falls\n"
	.string "du später doch noch willst!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Hey, Trainer!\n"
	.string "Du siehst heute echt gut gelaunt aus.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Willst du mir dein neues Profil zeigen?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Perfekt! Danke dir!\p"
	.string "Bin gespannt, ob es dein altes Profil\n"
	.string "noch übertreffen kann.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Alles klar, es bleibt beim alten Profil.\p"
	.string "Warum auch ändern? Es passt doch\n"
	.string "bereits perfekt zu dir.$"

ProfileMan_Text_FantasticProfile:
	.string "W-Wahnsinn!\p"
	.string "Dieses Profil ist der Hammer!\n"
	.string "Es bringt deinen Charakter auf den Punkt.\p"
	.string "Das wird den anderen Trainern da\n"
	.string "draußen definitiv im Gedächtnis bleiben!\p"
	.string "Danke dir!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the MYSTERY EVENT CLUB!$"
