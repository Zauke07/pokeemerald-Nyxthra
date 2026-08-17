LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex::
	.string "Ich bin der GAME DESIGNER.\p"
	.string "Ach was? Du arbeitest echt an diesem\n"
	.string "POKéDEX-Dingsbums?\p"
	.string "Ist 'ne miese Plackerei, das Ding vollzu-\n"
	.string "kriegen, also heul nicht rum.\p"
	.string "Falls du es wider Erwarten doch schaffst,\n"
	.string "kannst du's mir ja mal zeigen.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis::
	.string "Oha! Das ist ja mal fett!\n"
	.string "Echt jetzt, absolut krank!\p"
	.string "Der POKéDEX ist komplett voll!\n"
	.string "Du hast doch echt kein Leben, oder?!\p"
	.string "Ich bin fast schon beeindruckt……\p"
	.string "Hier, nimm das als Anerkennung dafür,\n"
	.string "dass du so'n krasser Nerd bist!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer::
	.string "Häh? Du laberst mich an?\n"
	.string "Ich bin hier der PROGRAMMIERER.\p"
	.string "Ich frag mich eher, ob die EINARMIGEN\n"
	.string "BANDITEN hier gut programmiert sind.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist::
	.string "Ich bin der GRAFIKER! Sind die POKéMON\n"
	.string "in HOENN nicht ein optischer Genuss?\l"
	.string "Hab ich schließlich hingepinselt!$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute::
	.string "Die kleinen GÖREN am Strand sind ja\n"
	.string "ganz niedlich, was?\l"
	.string "Gegen so'ne süße Maus zu kämpfen……\p"
	.string "Boah, das macht so richtig Laune!\p"
	.string "Und die ZWILLINGE! Sind die nicht goldig?\n"
	.string "Ein 2-gegen-2 mit ZWILLINGEN……\p"
	.string "Einfach unschlagbar gut!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart::
	.string "Die Seebrise kitzelt meine Nerven.\n"
	.string "Echt herrlich hier oben!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy::
	.string "Man weiß nie, welcher Vollpfosten einen\n"
	.string "als Nächstes herausfordert.\p"
	.string "Deswegen geh ich ohne meinen GAME BOY\n"
	.string "ADVANCE nicht mal kacken.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles::
	.string "SCOTT: …… …… …… …… ……\n"
	.string "…… …… …… …… …… Chrr……\p"
	.string "…… …… …… …… …… Häh?!\n"
	.string "Oh, sorry! Ich hab gepennt!\p"
	.string "Ich wollte mir mal diesen POKéMON-\n"
	.string "WETTBEWERB-Quatsch ansehen.\p"
	.string "Ganz ehrlich, ist ja ganz nett zur\n"
	.string "Unterhaltung, aber……\p"
	.string "Nenn mich altmodisch, aber ich steh auf\n"
	.string "echte Kämpfe und brutale TRAINER.\p"
	.string "Aber das ist nur mein Ding.\p"
	.string "{PLAYER}{KUN}, zieh dir ruhig den ganzen Rest\n"
	.string "rein: ARENEN, WETTBEWERBE, KAMPFCAMP……\l"
	.string "wenn du auf sowas stehst.$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy::
	.string "SCOTT: Ich schätze, man braucht schon\n"
	.string "ein bisschen Hirn für die WETTBEWERBE.\p"
	.string "Wer da Strategien austüftelt, ist am\n"
	.string "Ende vielleicht ein weniger mieser\l"
	.string "TRAINER, schätze ich mal.$"
