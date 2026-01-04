AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething::
	.string "Häh? Was? Was willst du hier bei\n"
	.string "TEAM AQUA rumlungern?\p"
	.string "Unser BOSS ist nicht da! Er zieht gerade\n"
	.string "ein ganz dickes Ding durch!\p"
	.string "…… ……\n"
	.string "Wo er hin ist?\p"
	.string "Wahaha! Glaubst du echt, ich bin so hohl\n"
	.string "und erzähl dir Spion das einfach so?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe::
	.string "Was? Wie?\n"
	.string "Bist du etwa so'ne TEAM MAGMA-Wurst?\p"
	.string "Ich hab gehört, TEAM MAGMA will in\n"
	.string "ihrem Loch irgendein krasses POKéMON\l"
	.string "aus dem Schlaf prügeln.\p"
	.string "Aber wo verstecken sich diese Penner\n"
	.string "überhaupt?$"

AquaHideout_1F_Text_BossWentToJackASubmarine::
	.string "Häh? Was? Was glotzt du so?\n"
	.string "Willst du Ärger mit TEAM AQUA?\p"
	.string "Unser BOSS ist gerade beschäftigt!\n"
	.string "Er zockt sich gerade ein U-Boot!\p"
	.string "…… ……\n"
	.string "Wohin er damit tuckert?\p"
	.string "Wahaha! Als ob ich dir das verraten\n"
	.string "würde, du Witzfigur!$"

AquaHideout_1F_Text_BossIsOnRoute122::
	.string "Was? Wie? Was willst du Vogel hier im\n"
	.string "Versteck von TEAM AQUA?\p"
	.string "Unser BOSS ist weg! Der ist gerade auf\n"
	.string "dem Weg zum PYROBERG auf ROUTE 122!\p"
	.string "…… ……\n"
	.string "Warum er da ist?\p"
	.string "Wahaha! Träum weiter! Ich erzähl dir\n"
	.string "gar nix!$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney::
	.string "Häh? Was?\n"
	.string "Bist du einer von den MAGMA-Spacken?\p"
	.string "Man sagt, TEAM MAGMA ist am SCHLOTBERG\n"
	.string "hinter 'nem legendären Viech her.\p"
	.string "Aber was ist das für 'ne hässliche\n"
	.string "Kreatur?$"

AquaHideout_1F_Text_BossIsInSlateportCity::
	.string "Was? Wie? Was willst du hier im\n"
	.string "Hauptquartier von TEAM AQUA?\p"
	.string "Der BOSS ist ausgeflogen!\n"
	.string "Er macht gerade GRAPHITPORT CITY unsicher!\p"
	.string "…… ……\n"
	.string "Was er da will?\p"
	.string "Wahaha! Ich bin doch nicht bekloppt und\n"
	.string "plapper hier unsere Geheimnisse aus!$"

AquaHideout_1F_Text_Grunt1Intro::
	.string "Ayiyiyi!\n"
	.string "Verdächtiges Subjekt gesichtet!$"

AquaHideout_1F_Text_Grunt1Defeat::
	.string "Grrrrr……\n"
	.string "Voll verkackt!$"

AquaHideout_1F_Text_Grunt1PostBattle::
	.string "Ich hab zwar geloost, aber ich hab dich\n"
	.string "wenigstens aufgehalten…… Job erledigt!$"
