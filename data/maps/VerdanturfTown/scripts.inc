VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel::
	.string "Mein Alter hat mir den Mist erzählt.\p"
	.string "Er meint, im Tunnel hocken nur feige\n"
	.string "Mist-POKéMON rum.\p"
	.string "Die heulen sofort rum, wenn’s mal laut\n"
	.string "wird. Voll die Pussys!\p"
	.string "Deswegen haben die den Bau gestoppt.\n"
	.string "Lächerlich, oder?\p"
	.string "Aber da ist so ein Irrer, der meint,\n"
	.string "er müsste den Tunnel alleine graben.$"

VerdanturfTown_Text_ManDugTunnelForLove::
	.string "Da war so ein Simp, der hat den Tunnel\n"
	.string "alleine für seine Alte gegraben.\p"
	.string "Stell dir das mal vor. Wie dumm kann\n"
	.string "man eigentlich sein?\l"
	.string "Aber hey, wenigstens hat er Muckis.$"

VerdanturfTown_Text_AirCleanHere::
	.string "Der Wind steht hier so, dass wir den\n"
	.string "ganzen Vulkan-Dreck nicht abkriegen.\p"
	.string "Die Luft ist hier so ekelhaft sauber,\n"
	.string "dass das ganze Dorf voll mit kranken\l"
	.string "Schwächlingen und Heulsusen ist.$"

VerdanturfTown_Text_MakeBattleTentDebut::
	.string "Meine POKéMON und ich haben gerade\n"
	.string "alles weggemoscht.\p"
	.string "Jetzt geh ich ins KAMPFCAMP und zeig\n"
	.string "den Versagern dort, wo der Hammer hängt.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave::
	.string "Siehst du das Loch neben dem Laden?\p"
	.string "Da drin ist ein Psycho, der Felsen mit\n"
	.string "bloßen Händen zerlegen will, um auf die\l"
	.string "andere Seite zu kommen.\p"
	.string "Wär das geil, wenn der mal fertig wird…\n"
	.string "Dann müsste ich nicht ewig laufen, um\l"
	.string "in METAROST CITY Leute abzuziehen.$"

VerdanturfTown_Text_EasyToGetToRustboroNow::
	.string "Der Tunnel neben dem Supermarkt ist\n"
	.string "endlich offen. Gott sei Dank!\p"
	.string "Jetzt kommt man ruckzuck nach\n"
	.string "METAROST CITY, um bei DEVON die\l"
	.string "Regale leerzuräumen.$"

VerdanturfTown_Text_TownSign::
	.string "WIESENFLUR\p"
	.string "“Ein snobistisches Kaff voller sauberer\n"
	.string "Luft und kranker Lappen.”$"

VerdanturfTown_Text_WandasHouse::
	.string "HEIKES BRUCHBUDE$"

VerdanturfTown_Text_BattleTentSign::
	.string "KAMPFCAMP WIESENFLUR\n"
	.string "“Wo du lernst, wie man richtig aufgibt!”$"

VerdanturfTown_Text_RusturfTunnelSign::
	.string "METAFLURTUNNEL\n"
	.string "“Verbindung für Leute, die zu faul zum\p"
	.string "Laufen sind.\n"
	.string "Baustopp wegen Heul-Attacken.”$"


