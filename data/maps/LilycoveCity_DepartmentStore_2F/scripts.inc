LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_POKE_DOLL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ADRENALINE_ORB
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_WAVE_MAIL
	pokemartlistend

@ Nyxthra: two extra clerks selling every Mega Stone / evolution stone in the
@ project, since neither used to be buyable anywhere in the game at all.
LilycoveCity_DepartmentStore_2F_EventScript_ClerkUp::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_PokemartMegaStones
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
LilycoveCity_DepartmentStore_2F_PokemartMegaStones:
	.2byte ITEM_ABOMASITE
	.2byte ITEM_ABSOLITE
	.2byte ITEM_ABSOLITE_Z
	.2byte ITEM_AERODACTYLITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_ALTARIANITE
	.2byte ITEM_AMPHAROSITE
	.2byte ITEM_AUDINITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_BARBARACITE
	.2byte ITEM_BAXCALIBRITE
	.2byte ITEM_BEEDRILLITE
	.2byte ITEM_BLASTOISINITE
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_CHANDELURITE
	.2byte ITEM_CHARIZARDITE_X
	.2byte ITEM_CHARIZARDITE_Y
	.2byte ITEM_CHESNAUGHTITE
	.2byte ITEM_CHIMECHITE
	.2byte ITEM_CLEFABLITE
	.2byte ITEM_CRABOMINITE
	.2byte ITEM_DARKRANITE
	.2byte ITEM_DELPHOXITE
	.2byte ITEM_DIANCITE
	.2byte ITEM_DRAGALGITE
	.2byte ITEM_DRAGONINITE
	.2byte ITEM_DRAMPANITE
	.2byte ITEM_EELEKTROSSITE
	.2byte ITEM_EMBOARITE
	.2byte ITEM_EXCADRITE
	.2byte ITEM_FALINKSITE
	.2byte ITEM_FERALIGITE
	.2byte ITEM_FLOETTITE
	.2byte ITEM_FROSLASSITE
	.2byte ITEM_GALLADITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_GARCHOMPITE_Z
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_GENGARITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_GLIMMORANITE
	.2byte ITEM_GOLISOPITE
	.2byte ITEM_GOLURKITE
	.2byte ITEM_GRENINJITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_HAWLUCHANITE
	.2byte ITEM_HEATRANITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_KANGASKHANITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_LUCARIONITE_Z
	.2byte ITEM_MAGEARNITE
	.2byte ITEM_MALAMARITE
	.2byte ITEM_MANECTITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_MEDICHAMITE
	.2byte ITEM_MEGANIUMITE
	.2byte ITEM_MEOWSTICITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_MEWTWONITE_X
	.2byte ITEM_MEWTWONITE_Y
	.2byte ITEM_PIDGEOTITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_PYROARITE
	.2byte ITEM_RAICHUNITE_X
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_SABLENITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_SCOLIPITE
	.2byte ITEM_SCOVILLAINITE
	.2byte ITEM_SCRAFTINITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_SKARMORITE
	.2byte ITEM_SLOWBRONITE
	.2byte ITEM_STARAPTITE
	.2byte ITEM_STARMINITE
	.2byte ITEM_STEELIXITE
	.2byte ITEM_SWAMPERTITE
	.2byte ITEM_TATSUGIRINITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_ZERAORITE
	.2byte ITEM_ZYGARDITE
	pokemartlistend

LilycoveCity_DepartmentStore_2F_EventScript_ClerkDown::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_PokemartEvolutionStones
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
LilycoveCity_DepartmentStore_2F_PokemartEvolutionStones:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	pokemartlistend

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly::
	.string "Lern erst mal, wie man Items richtig\n"
	.string "benutzt, bevor du hier auf dicke Hose\l"
	.string "machst. Das ist ja wohl das Mindeste!$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband::
	.string "Mein Alter hockt zu Hause und wartet.\n"
	.string "Was schenk ich dem bloß, damit er endlich\l"
	.string "mal die Klappe hält?$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems::
	.string "Ich verdufte bald auf 'ne lange Reise.\n"
	.string "Ich muss mich mit Zeug eindecken, damit\l"
	.string "ich da draußen nicht jämmerlich verrecke.$"

