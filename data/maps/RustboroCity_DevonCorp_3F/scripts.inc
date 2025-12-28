RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	goto_if_eq VAR_ROCKET_STATE, 2, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterRocketReveal
	goto_if_eq VAR_ROCKET_STATE, 1, RustboroCity_DevonCorp_3F_EventScript_MrStoneMentionsRocket
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneMentionsRocket::
	msgbox RustboroCity_DevonCorp_3F_Text_TrummMentionsRocket, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterRocketReveal::
	msgbox RustboroCity_DevonCorp_3F_Text_TrummAfterRocketReveal, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Ich bin MR. TRUMM - CEO, Visionär,\n"
	.string "Patriarch der DEVON CORPORATION.\p"
	.string "Wir müssen reden.\n"
	.string "Wichtig. Weltrettung vielleicht.\p"
	.string "Du hast unseren Angestellten gleich\n"
	.string "zweimal aus der Patsche geholfen -\l"
	.string "und das ohne Bonuszahlung!\p"
	.string "Deshalb: Ich hab da ein Jobangebot für\n"
	.string "dich. Nein - eine Mission!\p"
	.string "Du willst ja sowieso zur WERFT nach\n"
	.string "GRAPHITPORT CITY, korrekt?\p"
	.string "Mach doch 'nen Zwischenstopp in\n"
	.string "FAUSTAUHAVEN und übergib TROY diesen\l"
	.string "handgeschriebenen, offiziellen BRIEF.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. TRUMM: Ich bin reich, mächtig und\n"
	.string "unglaublich großzügig.\p"
	.string "Natürlich bekommst du auch was für\n"
	.string "deinen Dienst am Fortschritt.\p"
	.string "Hier, fang - bevor meine Assistentin\n"
	.string "merkt, dass ich Dinge verschenke.$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} erhält den POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. TRUMM: Dieses Gerät…\p"
	.string "Es ist ein POKéMON NAVIGATOR - oder kurz:\n"
	.string "POKéNAV. Entwickelt hier bei DEVON.\p"
	.string "Ich denke, du wirst ihn brauchen.\n"
	.string "Die Dinge draußen sind… unruhig.\p"
	.string "Nicht nur MAGMA oder AQUA treiben sich\n"
	.string "herum. Es gibt… andere Gruppen.\p"
	.string "Namenlose, oder solche, die man besser\n"
	.string "nicht laut ausspricht.\p"
	.string "Du wirst verstehen, was ich meine,\n"
	.string "wenn du weiter reist.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. TRUMM: Geh mit Bedacht, {PLAYER}{KUN}.\n"
	.string "Und versau mein Firmenimage nicht!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. TRUMM: Ich zähle auf dich.\n"
	.string "Oder wie wir hier sagen:\l"
	.string "Du wurdest gerade outsourced.$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. TRUMM: Der BRIEF kam an?\n"
	.string "Du bist echt der Amazon Prime unter den\l"
	.string "TRAINERN.\p"
	.string "Hier, ein kleines Dankeschön von mir.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. TRUMM: Das hier ist der EP-TEILER.\n"
	.string "Ein Gamechanger.\p"
	.string "Damit kann dein faules POKéMON XP farmen,\n"
	.string "ohne einen Finger zu krümmen.\p"
	.string "Wie Homeoffice, aber für Monster.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. TRUMM: Ich hab früher nur gearbeitet.\n"
	.string "Keine Ahnung von TikTok oder Trends.\p"
	.string "Alle Kids wollen wohl Liga-Champ werden?\n"
	.string "Oder Influencer. Weiß man ja nicht.$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Das hier ist der heilige Boden: Etage 2\n"
	.string "- das Büro des großen MR. TRUMM.\p"
	.string "Er will dir persönlich danken, also…\n"
	.string "Zeig Respekt. Oder tu zumindest so.\p"
	.string "Ach ja, das Paket, das du uns\n"
	.string "zurückgebracht hast - kannst du\l"
	.string "das bitte nach GRAPHITPORT CITY bringen?\p"
	.string "Falls es nochmal geklaut wird, war alles\n"
	.string "umsonst. Und das geht gar nicht!\p"
	.string "Äh… Moment bitte, ich leite dich weiter.$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Unser PRÄSIDENT erwartet dich.\n"
	.string "Zieh dir was Ordentliches an. Nur Spaß.\p"
	.string "Komm mit.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Bitte, geh voran.\n"
	.string "Er steht drauf, wenn Leute\n"
    .string "ehrfürchtig wirken.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Wenn du in GRAPHITPORT CITY bist,\n"
	.string "such KAPT. BRIGG in der WERFT.\p"
	.string "Großer Typ. Riecht nach Motoröl und Ehre.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "WIEDERBALL und TIMERBALL - unsere\n"
	.string "neusten Hits.\p"
	.string "Beliebt bei TRAINERN, Sammlern und\n"
	.string "Leuten, die zu oft verlieren.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Vitrine mit seltenen Steinen und\n"
	.string "Mineralien.\p"
	.string "Privatsammlung von MR. TRUMM.\n"
	.string "(Er redet auch mit ihnen.)$"

RustboroCity_DevonCorp_3F_Text_TrummMentionsRocket:
	.string "In FAUSTAUHAVEN… Hast du dort etwas\n"
	.string "gesehen? Schwarze Uniformen vielleicht?\p"
	.string "Ich dachte, sie wären verschwunden. Aber\n"
	.string "manche Schatten kehren immer zurück.\p"
	.string "Wenn du mehr erfährst, komm zurück.\n"
	.string "Und sei vorsichtig - Team ROCKET\l"
	.string "spielt nach eigenen Regeln.$"

RustboroCity_DevonCorp_3F_Text_TrummAfterRocketReveal:
	.string "MR. TRUMM: Also stimmt es… Team ROCKET\n"
	.string "ist wieder aktiv.\p"
	.string "Ich hätte es wissen müssen - die Angriffe\n"
	.string "auf unsere Transportschiffe…\p"
	.string "Wenn du gegen sie kämpfen willst, brauchst\n"
	.string "du mehr als Mut. Du brauchst Wissen.\p"
	.string "Und du wirst es nicht von mir bekommen…\n"
	.string "noch nicht.$"

