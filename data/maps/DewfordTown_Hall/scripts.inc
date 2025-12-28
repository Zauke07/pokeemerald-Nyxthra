DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Was gerade voll im Trend ist?\n"
	.string "Na klar - “{STR_VAR_1}”!\p"
	.string "Ohne “{STR_VAR_1}” wäre das Leben\n"
	.string "nur halb so aufregend!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "“{STR_VAR_1}” ist zwar noch in,\n"
	.string "aber irgendwie… meh.\p"
	.string "Zeit für was Neues!$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Ich versuche meinen Pokémon was über\n"
	.string "“{STR_VAR_1}” beizubringen…\p"
	.string "Aber sie checken's einfach nicht.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Ich beschäftige mich gerade intensiv\n"
	.string "mit “{STR_VAR_1}”.\p"
	.string "Gibt’s da vielleicht nen geheimen Link\n"
	.string "zu “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Yes! Ich wusste, dass “{STR_VAR_1}”\n"
	.string "das nächste große Ding wird!\p"
	.string "Trendradar: 100%!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Was?! Das ist jetzt angesagt?!\p"
	.string "Boah… Für uns Oldies ist das echt\n"
	.string "schwer, mitzuhalten.$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Dieses “{STR_VAR_1}”…\n"
	.string "Gab’s da nicht ne Doku auf Pokéflix?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Sag mal, ist “{STR_VAR_1}” drüben\n"
	.string "auf dem Festland noch angesagter?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Ich sammel alles zu “{STR_VAR_1}”!\p"
	.string "Plüschis? Check.\n"
	.string "Klamotten? Check.\n"
	.string "Poster und Bücher? Alles meins!\p"
	.string "Aber nix davon bekommst du! Hehe!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "“GUTE {STR_VAR_1}”\n"
	.string "und “SCHLECHTE {STR_VAR_1}”…\p"
	.string "“{STR_VAR_1} & Pokémon”…\p"
	.string "Dieses Regal ist VOLL mit Büchern\n"
	.string "über “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“DER RUF VON {STR_VAR_1}”\n"
	.string "ist der Titel.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“DAS LÄCHELN VON {STR_VAR_1}”\n"
	.string "ist der Titel.$"

DewfordTown_Hall_Text_LastTrend:
	.string "“DAS LETZTE {STR_VAR_1}”…\n"
	.string "klingt mysteriös, oder?$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "“DIE GEBURT EINES {STR_VAR_1}”…\n"
	.string "Da fängt alles an!$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Ich hab letztens “{STR_VAR_1}” gesehen!\n"
	.string "Und wow - das war der Wahnsinn!\p"
	.string "Einfach das Coolste überhaupt!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Hmpf…\n"
	.string "Das war kein echtes “{STR_VAR_1}”.\p"
	.string "Das echte sieht viel stylischer aus!\p"
	.string "Aber hey - du hast’s versucht!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ich hab nen Song über “{STR_VAR_1}”\n"
	.string "geschrieben.\p"
	.string "Willst du hören?\n"
	.string "Okay, los geht’s!\p"
	.string "{STR_VAR_1}\n"
	.string "Schönes {STR_VAR_1}$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "…\n"
	.string "Ähm… Vielleicht nimmst du erst ein paar\n"
	.string "Gesangsstunden, bevor du performst.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Wir sollten ne\n"
	.string "“{STR_VAR_1}”-Party schmeißen!\p"
	.string "Die Insel braucht das!$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Das ist genial!\p"
	.string "Wir machen “{STR_VAR_1}” zum\l"
	.string "größten Trend ever!\p"
	.string "Von jetzt an dreht sich alles darum!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Ich denke, “{STR_VAR_1}” ist\n"
	.string "nicht nur Trend - es ist ein Lifestyle.$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Was? Zu dominant?\p"
	.string "Naja, “{STR_VAR_1}” hat halt\n"
	.string "Kultstatus erreicht!\p"
	.string "Du bist echt ein “{STR_VAR_1}”-GURU!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Du und ich - gemeinsam sind wir\n"
	.string "unschlagbar gegen alles “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Licht an - wir sind das\n"
	.string "“{STR_VAR_1}”-Dreamteam!\p"
	.string "Klingt verrückt? Find ich super!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Ich steh total auf MATSCHBOMBE!\p"
	.string "Kennst du das etwa nicht?!\n"
	.string "Hier, nimm eine!$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "MATSCHBOMBE ist top,\n"
	.string "aber “{STR_VAR_1}” ist auch\n"
	.string "gerade mächtig im Kommen.$"


