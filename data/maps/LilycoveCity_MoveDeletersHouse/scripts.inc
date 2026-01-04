LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove::
	.string "Äh……\n"
	.string "Oh, ja, ich bin der ATTACKEN-VERLERNER.\p"
	.string "Ich kann dafür sorgen, dass deine\n"
	.string "POKéMON alles vergessen.\p"
	.string "Soll ich mal ordentlich in ihrem Hirn\n"
	.string "rumwühlen?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget::
	.string "Welches POKéMON soll sein Gedächtnis\n"
	.string "verlieren?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten::
	.string "Welche Attacke soll ich auslöschen?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove::
	.string "{STR_VAR_1} weiß nur noch eine einzige\n"
	.string "Sache…… das kann ich nicht auch noch\l"
	.string "löschen, sonst ist es komplett hohl.$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten::
	.string "Hm! {STR_VAR_1}s {STR_VAR_2}?\n"
	.string "Dieser Move soll für immer weg?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove::
	.string "Perfekt gelaufen!\p"
	.string "{STR_VAR_1} hat keine Ahnung mehr,\n"
	.string "was {STR_VAR_2} überhaupt war.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain::
	.string "Komm wieder, wenn ich noch mehr\n"
	.string "Erinnerungen ausradieren soll.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves::
	.string "Was?\n"
	.string "Ein EI hat noch gar kein Hirn zum\l"
	.string "Löschen. Nerv mich nicht!$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf::
	.string "Hm!\p"
	.string "Dein {STR_VAR_1} klammert sich regelrecht\n"
	.string "an SURFER. Das krieg ich nicht raus.$"
