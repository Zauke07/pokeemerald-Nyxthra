MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood::
	.string "Hier am Berg treiben sich alle möglichen\n"
	.string "schrägen Gestalten rum…\p"
	.string "Wer weiß, welcher Geist dich als Nächstes\n"
	.string "anspringen will. Nimm das hier gefälligst.\l"
	.string "Ist zu deinem eigenen Schutz, Kleiner.$"

MtPyre_1F_Text_ExplainCleanseTag::
	.string "Gib das SCHUTZBAND einem deiner\n"
	.string "POKéMON zum Halten.\p"
	.string "Es hält dir die wilden Viecher vom Hals,\n"
	.string "damit du hier in Ruhe wandern kannst.$"

MtPyre_1F_Text_ComeToPayRespects::
	.string "Bist du hier, um den POKéMON-Geistern\n"
	.string "die letzte Ehre zu erweisen?\p"
	.string "Du scheinst deine Viecher ja echt zu\n"
	.string "mögen. Hoffentlich krepieren sie nicht\l"
	.string "so bald wie die hier…$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon::
	.string "Hier vergammelt mein ZIGZACHS.\n"
	.string "Ich hab das kleine Ding echt geliebt……\l"
	.string "Jetzt ist es nur noch Dünger.$"
