Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis::
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Glotz nicht so blöd, ja, hier sieht’s\n"
	.string "aus wie bei Hempels unterm Sofa.\l"
	.string "Ich hab Wichtigeres zu tun als zu\l"
	.string "putzen, während ich die Welt rette!\p"
	.string "Echt peinlich… Wenn du das rumtratschst,\n"
	.string "lösch ich dein Konto! Hier, nimm das\l"
	.string "Schweigegeld und halt die Klappe!$"

Route114_LanettesHouse_Text_OrganizeYourBoxes::
	.string "Soll ich dir erklären, wie man den PC\n"
	.string "bedient, oder bist du zu hohl dafür?\p"
	.string "Sortier deine BOXen gefälligst ordentlich,\n"
	.string "sonst suchst du deine Viecher ewig,\l"
	.string "du Daten-Messie!$"

Route114_LanettesHouse_Text_ResearchNotesPage1::
	.string "LANETTEs Nerd-Notizen.\n"
	.string "Hier geht’s um den digitalen Knast.\p"
	.string "Ich hab BOXen gebaut, in die 30\n"
	.string "POKéMON reingequetscht werden.\p"
	.string "Das macht Platz für 420 Viecher.\n"
	.string "Wer mehr fängt, hat echt Probleme.\p"
	.string "Weiterlesen?$"

Route114_LanettesHouse_Text_ResearchNotesPage2::
	.string "Man kann die Viecher markieren,\n"
	.string "damit man sie im Chaos wiederfindet.\p"
	.string "Namen und Hintergründe kann man auch\n"
	.string "ändern. Den POKéMON ist das egal,\n"
	.string "die merken eh nix in ihrer Datenstarre.\p"
	.string "Weiterlesen?$"

Route114_LanettesHouse_Text_ResearchNotesPage3::
	.string "Das System schiebt das POKéMON immer\n"
	.string "in die BOX, in der du zuletzt rumgefummelt\l"
	.string "hast.\p"
	.string "Ist die Bude voll, geht’s in die nächste.\n"
	.string "Ist doch logisch, oder?\p"
	.string "Also merk dir einfach, wo du zuletzt\n"
	.string "geklickt hast. Ist nicht so schwer!$"

Route114_LanettesHouse_Text_ClosedTheNotebook::
	.string "{PLAYER} knallt das Notizbuch zu.$"

Route114_LanettesHouse_Text_EmailFromBill::
	.string "Da schleimt jemand per E-Mail rum.\p"
	.string "“… … … … … … …\p"
	.string "Ey Lanette, dein System ist viel geiler\n"
	.string "als mein alter Schrott aus Kanto.\p"
	.string "Es ist fast so, als hätten die User\n"
	.string "jetzt endlich mal Spaß am PC.\p"
	.string "Ich bin dein größter Fan, echt jetzt.\n"
	.string "Mach weiter so, du IT-Göttin!\p"
	.string "BILL (dein ergebener Fanboy)\n"
	.string "… … … … … … … …”$"

