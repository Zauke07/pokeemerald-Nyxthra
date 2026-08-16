SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Bist ein Trainer, oder?\p"
	.string "Juan aus Xeneroville hat\n"
	.string "echt unnormal viele Simps.\l"
	.string "Mehr als sein Schüler Wassili!\p"
	.string "Hast du eigentlich auch Simps,\n"
	.string "oder bist du ein Nobody?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, dann bist du wohl echt\n"
	.string "ein krasser Tryharder.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh Mann…\n"
	.string "Das ist echt erbärmlich.\p"
	.string "Schwitz mal ein bisschen mehr\n"
	.string "rein, damit dich wer feiert.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Seine krassesten Simps reisen\n"
	.string "sogar von außerhalb Hoenns an.\p"
	.string "Der Trainer-Fanclub drüben in\n"
	.string "Seegrasulb ist 'ne Freakshow.$"
