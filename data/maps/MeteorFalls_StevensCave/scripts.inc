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
	.string "TROY: Da bist du ja, {PLAYER}{KUN}.\n"
	.string "Ich hoffte, du findest hierher.\p"
	.string "Hältst du mich nur für jemanden,\n"
	.string "der gerne schöne Steine sammelt?\p"
	.string "Dann hast du im Raumfahrtzentrum\n"
	.string "in Moosbach nicht gut aufgepasst.\p"
	.string "Du weißt genau, was ich kann.\n"
	.string "Und ich weiß, was du kannst.\p"
	.string "Also gut, {PLAYER}{KUN}.\n"
	.string "Kämpfen wir ohne Zurückhaltung!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Du…\n"
	.string "Dass du so stark werden würdest…\p"
	.string "Ich hatte wirklich keine Ahnung.$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "TROY: Seit unserem ersten Treffen\n"
	.string "in der Granithöhle ahnte ich es.\p"
	.string "Du wirst am Ende der Champion.\n"
	.string "Da war ich mir stets sicher.\p"
	.string "Meine Vorhersagen liegen fast\n"
	.string "niemals daneben.\p"
	.string "Und wohin führt dein Weg jetzt?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Selbst ich kann das nicht mehr\n"
	.string "mit Gewissheit vorhersagen.$"

