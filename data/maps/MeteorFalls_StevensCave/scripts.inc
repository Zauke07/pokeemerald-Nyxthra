MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "Ich bin erstaunt, dass du weißt, wo du mich findest.\p"
	.string "Denkst du, äh… vielleicht an mich als\n"
	.string "nur einen Steinverrückten?\p"
	.string "Nein, das kann nicht stimmen.\p"
	.string "Wir kämpften zusammen im\n"
	.string "Moosbach City Raumfahrtzentrum.\p"
	.string "Du solltest eine sehr gute Vorstellung\n"
	.string "davon haben, wie gut ich bin.\p"
	.string "Okay, {PLAYER}{KUN}, wenn du eine\n"
	.string "ernsthafte Herausforderung wagst, erwarte das Schlimmste!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Du…\n"
	.string "Ich hatte keine Ahnung, dass du so stark wirst…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Wenn ich so darüber nachdenke, seit\n"
	.string "sich unsere Wege zum ersten Mal in der GRANITHÖHLE\l"
	.string "in BLÜTENBURG kreuzten, habe ich dieses Gefühl.\p"
	.string "Ich denke, dass du schließlich\n"
	.string "der CHAMP wirst.\p"
	.string "Meine Vorhersagen treffen normalerweise zu.\p"
	.string "Und wohin gehst du von hier aus?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hihihi, selbst ich kann dir das nicht sagen.$"

