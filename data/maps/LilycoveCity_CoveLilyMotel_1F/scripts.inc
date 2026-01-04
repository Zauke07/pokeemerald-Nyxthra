LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot::
	.string "Hm, die haben die Gästezahlen verdoppelt,\n"
	.string "nur weil sie Viecher als Köder nutzen?\p"
	.string "Vielleicht sollte ich mir auch so ein\n"
	.string "süßes POKéMON als Maskottchen zulegen.\p"
	.string "Ob die Leute uns dann die Bude einrennen\n"
	.string "und ihre Kohle hierlassen?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua::
	.string "Oh, verdammt! Sorry!\n"
	.string "Die Glotze war gerade viel spannender!\p"
	.string "Seit dieses Pack von TEAM AQUA hier rum-\n"
	.string "lungert, traut sich kein Tourist mehr in\l"
	.string "diese Absteige. Mies fürs Geschäft!$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV::
	.string "He, nimm dein Haupt aus der Sonne!\n"
	.string "Ich seh nix vom TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem::
	.string "Krass! Du willst mir sagen, ein POKéMON\n"
	.string "hat verlorenen Kram wiedergefunden?\p"
	.string "Nicht schlecht. Wenn wir auch so ein\n"
	.string "schlaues Viech hätten……\p"
	.string "Dann könnten wir den Müll einsammeln,\n"
	.string "den die Gäste ständig liegen lassen.$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted::
	.string "Oh, Ups! Sorry!\n"
	.string "Ich war voll im TV-Modus gefangen!\p"
	.string "Hab gehört, irgendwer hat das Versteck\n"
	.string "von TEAM AQUA hochgenommen.\p"
	.string "Dank dieser Aktion haben wir direkt 'ne\n"
	.string "fette Buchung von 'ner großen Gruppe.\p"
	.string "Die Firma hieß irgendwie……\n"
	.string "GAME irgendwas……$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar::
	.string "Abgefahren! Ein POKéMON hat als Sitter\n"
	.string "einen Einbrecher gestellt?\p"
	.string "Nicht übel. Wenn wir so ein brutales\n"
	.string "Viech als Türsteher hätten……\p"
	.string "Dann müssten wir uns hier nicht mehr mit\n"
	.string "diesem kriminellen Gesindel rumärgern.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner::
	.string "Oh, Mist! Sorry!\n"
	.string "Ich bin schon wieder vor der Glotze\l"
	.string "verklebt.\p"
	.string "Stimmt ja, vorhin ist ein ganzer Haufen\n"
	.string "Gäste hier aufgeschlagen.\p"
	.string "Die haben unter dem Namen GAME FREAK\n"
	.string "gebucht. Machen wohl Videospiele.\p"
	.string "Oh-ha, ich sollte wohl mal langsam an\n"
	.string "ihrem Fraß arbeiten!$"
