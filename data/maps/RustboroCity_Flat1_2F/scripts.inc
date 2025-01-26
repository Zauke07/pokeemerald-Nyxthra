.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
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
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, jeden Tag wird es schwerer...\p"
	.string "Was so schwer ist?\n"
	.string "Das fragst du noch?\p"
	.string "Herauszufinden, was ich jeden Tag\n"
	.string "kochen soll, natürlich!\p"
	.string "Es ist nicht einfach, jeden Tag eine\n"
	.string "Mahlzeit auf den Tisch zu bringen.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, hallo!\n"
	.string "Willkommen im Haushalt der PEPPER.\p"
	.string "Ich habe eine Frage an dich.\n"
	.string "Hast du jemals auf ein Baby aufgepasst?\p"
	.string "Siehst du, ich bin ein neuer Vater, also ist es\n"
	.string "für mich ganz neu, ein Kind großzuziehen.\p"
	.string "Und ich habe ein Problem. Meine Tochter WALDA\n"
	.string "lacht nicht genug.\p"
	.string "Ich denke, sie würde für mich lachen, wenn ich\n"
	.string "ihr etwas Lustiges erzähle.\p"
	.string "Kennst du ein lustiges Wort oder eine\n"
	.string "Redewendung, die du mir sagen könntest?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ich habe in letzter Zeit “{STR_VAR_1}” gesagt,\n"
	.string "um sie zu amüsieren.\p"
	.string "Kennst du ein besseres Wort oder eine bessere\n"
	.string "Redewendung, die funktionieren könnte?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, das ist wunderbar.\n"
	.string "Also, lass es uns hören, deine Vorschläge.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, ist das so?\p"
	.string "Nun, wenn du einen guten Vorschlag hast,\n"
	.string "bin ich ganz Ohr.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, verstehe.\n"
	.string "Nun, lass es uns versuchen, sollen wir?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, ja! Sie lacht!\n"
	.string "Oh, ich bin genauso begeistert wie sie!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, verstehe.\n"
	.string "Nun, lass es uns versuchen, sollen wir?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Sie lächelt überhaupt nicht.\n"
	.string "Vielleicht ist WALDA ein sehr ernstes Kind…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, also kennst du keine guten Worte.\n"
	.string "Dann sollte ich wohl selbst nachdenken.\p"
	.string "Hmm…\n"
	.string "Wie wäre es mit “{STR_VAR_1}”?\l"
	.string "Lass uns sehen, ob das funktioniert.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Sie lächelt überhaupt nicht.\n"
	.string "Vielleicht ist WALDA ein sehr ernstes Kind…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, also kennst du keine guten Worte.\n"
	.string "Ich denke, ich werde versuchen, sie mit\n"
	.string "dem Spruch zu amüsieren, den ich vorher\n"
	.string "verwendet habe.\p"
	.string "Übrigens, wenn du einen guten Vorschlag hast,\n"
	.string "zöger nicht, ihn mir mitzuteilen, okay?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Danke!\p"
	.string "Dank dir hat meine liebste WALDA für mich\n"
	.string "gelacht!\p"
	.string "Eigentlich sehe ich vielleicht nicht besonders\n"
	.string "aus, aber ich bin einer der Top-Forscher von\n"
	.string "DEVON CORPORATION.\p"
	.string "Also, wie wäre es, wenn ich dir etwas im\n"
	.string "Gegenzug gebe?\p"
	.string "Ich weiß, ich werde einige neue Tapetenmuster\n"
	.string "für die BOXEN im PC-POKéMON-Aufbewahrungssystem\n"
	.string "hinzufügen.\p"
	.string "Im Tapetenmuster-Menü wähle “FREUNDE.”\p"
	.string "Dann hast du Zugriff auf die neuen\n"
	.string "Tapetenmuster.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Es ist eine POKéMON-Stoffpuppe!$"
