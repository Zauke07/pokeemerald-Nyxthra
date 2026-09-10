#ifndef GUARD_CONFIG_BATTLE_H
#define GUARD_CONFIG_BATTLE_H

// Berechnungs-Einstellungen
#define B_CRIT_CHANCE               GEN_LATEST // Chance, dass ein Volltreffer landet. Siehe CalcCritChanceStage. In Gen6+ treffen Porenta/Silvarro mit Lauch und hohen-Crit-Moves garantiert kritisch.
#define B_CRIT_MULTIPLIER           GEN_LATEST // In Gen6+ multiplizieren Volltreffer den Schaden mit 1.5 statt 2.
#define B_PARALYSIS_SPEED           GEN_LATEST // In Gen7+ wird Initiative um 50% statt 75% gesenkt.
#define B_CONFUSION_SELF_DMG_CHANCE GEN_LATEST // In Gen7+ hat Verwirrung eine 33,3%-Chance auf Selbstschaden statt 50%.
#define B_MULTI_HIT_CHANCE          GEN_LATEST // In Gen5+ haben Mehrfachtreffer-Moves andere Wahrscheinlichkeiten. Werte siehe SetRandomMultiHitCounter.
#define B_WHITEOUT_MONEY            GEN_LATEST // In Gen4+ hängt Geldverlust bei Niederlage von der Anzahl Orden ab. Zuvor wurde das Geld halbiert. (FRLG weicht leicht ab; GEN_3 ergibt RSE-Verhalten.)
#define B_LIGHT_BALL_ATTACK_BOOST   GEN_LATEST // In Gen4+ verdoppelt Kugelblitz zusätzlich auch physische Moves, nicht nur spezielle.

// Erfahrung-Einstellungen
#define B_EXP_CATCH                 GEN_LATEST // In Gen6+ gibt es EP fürs Fangen.
#define B_TRAINER_EXP_MULTIPLIER    GEN_LATEST // In Gen7+ geben Trainerkämpfe keinen 1,5x-EP-Bonus mehr.
#define B_SPLIT_EXP                 GEN_LATEST // In Gen6+ erhalten alle Teilnehmenden die vollen EP.
#define B_SCALED_EXP                GEN_3      // In Gen5 und Gen7+ werden EP anhand der Leveldifferenz gewichtet.
#define B_UNEVOLVED_EXP_MULTIPLIER  GEN_LATEST // In Gen6+: Wenn das Pokémon sich per Level entwickeln könnte, es aber nicht hat, erhält es ~1,2x EP. Gilt nur für EVO_LEVEL.
#define B_LEVEL_UP_NOTIFICATION     GEN_LATEST // In Gen9+: Bei mehreren Level-Ups wird die Meldung nur einmal angezeigt.

// Statuswert-Einstellungen
#define B_BADGE_BOOST               GEN_LATEST // In Gen4+ erhöhen Orden keine Statuswerte mehr.
#define B_FRIENDSHIP_BOOST          FALSE      // Nur in LGPE: Alle Stats außer KP werden je nach Freundschaft bis zu 10% geboostet. Diese Boosts fließen in die Basisstats-Berechnung ein.
#define B_MAX_LEVEL_EV_GAINS        GEN_LATEST // In Gen5+ können Pokémon auf Lv. 100 regulär Fleißpunkte erhalten.
#define B_RECALCULATE_STATS         GEN_LATEST // In Gen5+ werden Stats der am Kampf beteiligten Pokémon am Kampfende neu berechnet.

// Schadens-Einstellungen
#define B_BURN_DAMAGE               GEN_LATEST // In Gen7+ verursacht Verbrennung 1/16 KP statt 1/8. Gilt auch für Erfrierung.
#define B_BURN_FACADE_DMG           GEN_LATEST // In Gen6+ senkt Verbrennung nicht mehr den Angriff für Fassade.
#define B_BINDING_DAMAGE            GEN_LATEST // In Gen6+ fesseln-Schaden 1/8 KP statt 1/16. (Mit Haftband 1/6 bzw. 1/8.)
#define B_PSYWAVE_DMG               GEN_LATEST // Psywellen-Schadensformel. Details in DoFixedDamageMoveCalc.
#define B_PAYBACK_SWITCH_BOOST      GEN_LATEST // In Gen5+ verdoppelt Gnadenstoß nicht mehr den Schaden, wenn Gegner wechselt.
#define B_HIDDEN_POWER_DMG          GEN_LATEST // In Gen6+ hat Kraftreserve immer 60 Stärke. Davor abhängig von DVs.
#define B_ROUGH_SKIN_DMG            GEN_LATEST // In Gen4+ rauhe Schale 1/8 KP statt 1/16. Gilt auch für Eisenstachel.
#define B_KNOCK_OFF_DMG             GEN_LATEST // In Gen6+ macht Abschlag 50% mehr Schaden, wenn Item entfernt wird.
#define B_SPORT_DMG_REDUCTION       GEN_LATEST // In Gen5+ reduzieren Wassersport/Lehmschelle Feuer/Elektro um 67% statt 50%.
#define B_EXPLOSION_DEFENSE         GEN_LATEST // In Gen5+ halbieren Finale/Selbstzerstörung nicht mehr die Verteidigung des Ziels.
#define B_PARENTAL_BOND_DMG         GEN_LATEST // In Gen7+ macht Elternteilliebe beim zweiten Treffer 25% statt 50% des ersten.
#define B_MULTIPLE_TARGETS_DMG      GEN_LATEST // In Gen4+ Schaden von Flächenmoves auf 75% reduziert. Zuvor 50%.

// Typ-Einstellungen
#define B_GHOSTS_ESCAPE             GEN_LATEST // In Gen6+ wirken Wegsperre/Standpauke-Effekte nicht auf Geist. Geister entkommen immer wilden Kämpfen.
#define B_PARALYZE_ELECTRIC         GEN_LATEST // In Gen6+ können Elektro-Pokémon nicht paralysiert werden.
#define B_POWDER_GRASS              GEN_LATEST // In Gen6+ sind Pflanze-Pokémon immun gegen Puder/Sporen.
#define B_UPDATED_TYPE_MATCHUPS     GEN_LATEST // Aktualisiert Typen-Matchups. Details in src/data/types_info.h.
#define B_PRANKSTER_DARK_TYPES      GEN_LATEST // In Gen7+ treffen Strolch-Statusmoves Unlicht-Pokémon nicht.
#define B_SHEER_COLD_IMMUNITY       GEN_LATEST // In Gen7+ sind Eis-Pokémon immun gegen Eiseskälte.
#define B_ROOST_PURE_FLYING         GEN_LATEST // In Gen5+ macht Ruheort reine Flug-Pokémon zu Normal-Typ.
#define B_STATUS_TYPE_IMMUNITY      GEN_LATEST // In Gen1 waren Nebenwirkungen Paral./Frost/Brand immun, wenn der Move denselben Typ wie das Ziel hatte.

// Runden-Einstellungen
#define B_BINDING_TURNS             GEN_LATEST // In Gen5+ dauern Fessel-Moves 4-5 statt 2-5 Runden. (Mit Griffigklaue 7 bzw. 5.)
#define B_UPROAR_TURNS              GEN_LATEST // In Gen5+ dauert Aufruhr 3 Runden statt 2-5.
#define B_UPROAR_IGNORE_SOUNDPROOF  GEN_LATEST // In Gen5+ ignoriert Aufruhr Lärmschutz.
#define B_DISABLE_TURNS             GEN_LATEST // Dauer von Aussetzer. Siehe Cmd_disablelastusedattack.
#define B_TAILWIND_TURNS            GEN_LATEST // In Gen5+ Rückenwind 4 statt 3 Runden.
#define B_SLEEP_TURNS               GEN_LATEST // In Gen5+ dauert Schlaf 2-4 Runden statt 2-5.
#define B_TAUNT_TURNS               GEN_LATEST // In Gen5+: Verhöhner 3 Runden, wenn Nutzer schneller; 4, wenn Ziel zuerst handelte. Gen3: 2 Runden; Gen4: 3-5.
#define B_ENCORE_TURNS              GEN_LATEST // Gen 5+: Zugabe hält 3 Runden (wenn Ziel diese Runde noch nicht dran war) oder 4 Runden (wenn es schon agiert hat). Gen 4: 3-7 Runden. Gen 2-3: 2-6 Runden.
#define B_SPORT_TURNS               GEN_LATEST // In Gen6+ halten Wasser/Schlammsport 5 Runden, auch nach Wechsel.
#define B_MEGA_EVO_TURN_ORDER       GEN_LATEST // In Gen7 bestimmt Initiative nach Mega-Entwicklung die Reihenfolge, nicht davor.
#define B_RECALC_TURN_AFTER_ACTIONS GEN_LATEST // In Gen8 beeinflusst Wechsel/Move die aktuelle Rundenreihenfolge (dynamische Initiative).
#define B_FAINT_SWITCH_IN           GEN_LATEST // In Gen4+ kommen neue Pokémon nach K.O. am Rundenende hinein. Zuvor nach jeder Aktion.

// Move-Daten-Einstellungen
#define B_UPDATED_MOVE_DATA         GEN_LATEST // Aktualisiert gMovesInfo: Stärke, Genauigkeit, AP, Stat-Änderungen, Ziele, Nebenwirkungs-Chancen.
#define B_UPDATED_MOVE_TYPES        GEN_LATEST // Aktualisiert Move-Typen.
#define B_UPDATED_MOVE_FLAGS        GEN_LATEST // Aktualisiert Move-Flags.
#define B_PHYSICAL_SPECIAL_SPLIT    GEN_LATEST // In Gen3 bestimmt der Typ, ob physisch/spezial. Das Icon in der Übersicht spiegelt das wider.
#define B_RECOIL_IF_MISS_DMG        GEN_LATEST // In Gen5+ macht (Hoch) Sprung-Kick bei Fehlschlag immer 1/2 Max-KP Schaden.
#define B_KLUTZ_FLING_INTERACTION   GEN_LATEST // In Gen5+ kann Tollpatsch Schleuder nicht einsetzen.
#define B_UPDATED_CONVERSION        GEN_LATEST // In Gen6+ nimmt Umwandlung den Typ des ersten Moves. Zuvor zufälliger Move.
#define B_UPDATED_CONVERSION_2      GEN_LATEST // In Gen5+ wählt Umwandlung2 einen Typ, der den letzten Move des Ziels resistet. Struggle gilt vor Gen5 als Normal.
#define B_PP_REDUCED_BY_SPITE       GEN_LATEST // In Gen4+ senkt Groll die AP des letzten Moves um 4 statt 2-5.
#define B_EXTRAPOLATED_MOVE_FLAGS   TRUE       // Fügt Moves plausible Flags hinzu, die sie in den neuesten Spielen wahrscheinlich hätten.
#define B_HIDDEN_POWER_COUNTER      GEN_LATEST // Vor Gen4 behandeln Konter und Spiegelcape Kraftreserve unabhängig vom Typ immer als physische Attacke.
#define B_MODERN_TRICK_CHOICE_LOCK  GEN_LATEST // In Gen5+ kann der Anwender nach Trickbetrug/Wechseldich erneut eine Attacke wählen, wenn ein Wahl-Item gegen ein anderes Wahl-Item getauscht wurde; danach wird er wieder darauf festgelegt.
#define B_PROTECT_FAILURE_RATE      GEN_LATEST // In Gen5+ sinkt die Erfolgsrate bei wiederholtem Einsatz von Schutz-Attacken um den Faktor 1/3 statt 1/2.

// Fähigkeits-Daten
#define B_UPDATED_ABILITY_DATA      GEN_LATEST // Beeinflusst Fähigkeits-Flags

// Move-Genauigkeit
#define B_TOXIC_NEVER_MISS          GEN_LATEST // In Gen6+ verfehlt Toxin nie, wenn Nutzer Gift-Typ ist.
#define B_MINIMIZE_DMG_ACC          GEN_LATEST // In Gen6+ überspringen Anti-Minimize-Moves die Genauigkeitsprüfung.
#define B_BLIZZARD_HAIL             GEN_LATEST // In Gen4+ trifft Blizzard bei Hagel immer.
#define B_SHEER_COLD_ACC            GEN_LATEST // In Gen7+ nur 20% Basis-Treffer, wenn Nutzer kein Eis-Typ ist.

// Stat-Änderungs-Moves
#define B_FELL_STINGER_STAT_RAISE   GEN_LATEST // In Gen7+ erhöht Schlitzerklinge bei K.O. Angriff um 3 statt 2 Stufen.
#define B_KINGS_SHIELD_LOWER_ATK    GEN_LATEST // In Gen8+ senkt Königsschild Angriff um 1 statt 2 Stufen.
#define B_SPEED_BUFFING_RAPID_SPIN  GEN_LATEST // In Gen8 erhöht Turbodreher die Initiative um 1 Stufe.
#define B_CHARGE_SPDEF_RAISE        GEN_LATEST // In Gen5+ erhöht Ladevorgang die Sp.-Vert. um 1 Stufe.
#define B_MINIMIZE_EVASION          GEN_LATEST // In Gen5+ erhöht Komprimator die Fluchtwert um 2 statt 1 Stufe.
#define B_GROWTH_STAT_RAISE         GEN_LATEST // In Gen5+ erhöht Wachstum bei Sonne Angriff und Sp.-Angriff um je 2 Stufen statt 1.
#define B_FOCUS_ENERGY_CRIT_RATIO   GEN_2      // Fokus-Energie erhöht die Crit-Stufe nur um 1 statt um 2. Reduziert die Kritrate deutlich.
#define B_PSYCH_UP_CRIT_RATIO       GEN_LATEST // In Gen6+: Psych Up kopiert auch das Kritische-Treffer-Verhältnis des Ziels.

// Weitere Attacken-Einstellungen
#define B_INCINERATE_GEMS           GEN_LATEST // In Gen6+: Verbrennung kann Juwelen zerstören.
#define B_CAN_SPITE_FAIL            GEN_LATEST // In Gen4+: Groll schlägt nicht fehl, wenn der gegnerische letzte Move nur noch 1 AP hat.
#define B_CRASH_IF_TARGET_IMMUNE    GEN_LATEST // In Gen4+: Moves mit Crash-Schaden treffen ihr Ziel und crashen, wenn das Ziel immun ist.
#define B_MEMENTO_FAIL              GEN_LATEST // In Gen4+: Memento schlägt nicht fehl, wenn Ziel bereits -6 Atk/SpA hat. Gen5+: Schlägt fehl, wenn kein Ziel, oder geschützt/Delegation.
#define B_PARTING_SHOT_SWITCH       GEN_LATEST // In Gen7+: Nutzer wechselt nicht, wenn Gnadenstoß fehlschlägt.
#define B_BATON_PASS_TRAPPING       GEN_LATEST // In Gen5+: Staffette behält keine Trapping-Effekte (Festhalte-Effekte) auf anderen Kämpfern bei, wenn der Anwender auswechselt.
#define B_GLARE_GHOST               GEN_LATEST // In Gen4+: Augenblick trifft Geist-Pokémon normal.
#define B_SKILL_SWAP                GEN_LATEST // In Gen4+: Fähigkeitentausch triggert Switch-in-Fähigkeiten nach Einsatz.
#define B_BRICK_BREAK               GEN_LATEST // In Gen4+: Kann eigene Seiten-Bildschirme zerstören. Gen5+: Bildschirme werden nicht entfernt, wenn Ziel immun.
#define B_WISH_HP_SOURCE            GEN_LATEST // In Gen5+: Wunsch heilt 50% von Nutzer-KP statt Ziel-KP.
#define B_RAMPAGE_CONFUSION         GEN_LATEST // In Gen5+ wird der Wutanfall direkt nach der Attacke statt erst am Rundenende beendet; ein fehlgeschlagener Wutanfall beendet den Zähler, außer es ist die letzte Runde.
#define B_HEAL_BLOCKING             GEN_LATEST // In Gen5+: Heilsperre blockiert Black Sludge, Überreste, Glocke. KP-Beeren nicht verbraucht.
                                               // Drain-Fähigkeiten heilen nicht, verhindern aber Schaden. Gen6+: Blockiert meiste HP-Drain-Moves.
#define B_ROOTED_GROUNDING          GEN_LATEST // In Gen4+: Verwurzelung lässt Pokémon am Boden haften.
#define B_METRONOME_MOVES           GEN_LATEST // Bestimmt bis zu welcher Gen. Metronom Moves zieht.
#define B_TELEPORT_BEHAVIOR         GEN_LATEST // LGPE+ (Gen8+ hier): Teleport erlaubt Wechsel mit anderem Team-Mitglied.
#define B_BEAT_UP                   GEN_LATEST // In Gen5+: Beat Up nutzt andere Schadensformel, Unlicht-Typ. Gen5-: Kündigt Party-Mitglieder an.
#define B_DARK_VOID_FAIL            GEN_LATEST // In Gen7+: Nur Darkrai kann Schlummerort nutzen.
#define B_HIT_THAW                  GEN_LATEST // In Gen6+: Schaden verursachende Attacken, die den Anwender auftauen, tauen auch das Ziel auf. Gen3+: Feuer-Attacken tauen das Ziel auf. Gen1-2: Attacken mit Brand-Chance tauen Ziel auf, egal ob es brennen kann oder nicht.
#define B_HEALING_WISH_SWITCH       GEN_LATEST // In Gen5+: Empfänger von Heilwunsch kommt am Rundenende rein.
                                               // Gen8+: Heilwunsch-Effekt speichert sich bis Nutzer in Status/verletztes Mon wechselt.
#define B_DEFOG_EFFECT_CLEARING     GEN_LATEST // Gen5+: Auflockern senkt nicht Fluchtwert hinter Delegation. Gen6+: Löscht Stachler, Giftspitzen, Tarnsteine, Klebenetz. Gen8+: Löscht Terrain.
#define B_STOCKPILE_RAISES_DEFS     GEN_LATEST // ACHTUNG: Diese Config funktioniert derzeit nicht! In Gen4+ erhöht Horten auch Vert. und Sp.-Vert.; bei Entfessler/Verzehrer gehen diese Erhöhungen verloren.
#define B_TRANSFORM_SEMI_INV_FAIL   GEN_LATEST // In Gen2+: Verwandlung schlägt fehl, wenn das Ziel halbunverwundbar ist.
#define B_TRANSFORM_TARGET_FAIL     GEN_LATEST // In Gen2+: Verwandlung schlägt fehl, wenn das Ziel bereits verwandelt ist.
#define B_TRANSFORM_USER_FAIL       GEN_LATEST // In Gen5+: Verwandlung schlägt fehl, wenn der Anwender bereits verwandelt ist.
#define B_TRANSFORM_SUBSTITUTE_FAIL GEN_LATEST // In Gen5+: Verwandlung schlägt fehl, wenn sich das Ziel hinter einem Delegator befindet.
#define B_TRANSFORM_SHINY           GEN_LATEST // In Gen4+: Verwandlung kopiert Glitzer-Zustand statt ihn beizubehalten.
#define B_TRANSFORM_CATCH_RATE      GEN_LATEST // In Gen3 und Gen4 übernimmt ein verwandeltes Pokémon die Fangrate der kopierten Spezies; in anderen Generationen behält es seine ursprüngliche Fangrate.
#define B_TRANSFORM_BATTLE_REWARDS  GEN_LATEST // In Gen3 und Gen4 gibt ein verwandeltes Pokémon EP und Fleißpunkte der kopierten Spezies; in anderen Generationen die der ursprünglichen Spezies.
#define B_TRANSFORM_FORM_CHANGES    GEN_LATEST // In Gen5+: Verwandelte Pokémon können Formen nicht wechseln.
#define B_WIDE_GUARD                GEN_LATEST // Gen5 nur: Rundumschutz kaum fehl bei wiederholtem Einsatz.
#define B_QUICK_GUARD               GEN_LATEST // Gen5 nur: Rapidschutz kaum fehl bei wiederholtem Einsatz.
#define B_IMPRISON                  GEN_LATEST // In Gen5+: Begrenzer schlägt nicht fehl, wenn Gegner keine Moves des Nutzers kennen.
#define B_TAUNT_ME_FIRST            GEN_LATEST // In Gen5+: Verhöhner blockiert Egotrip (Me First) nicht.
#define B_ALLY_SWITCH_FAIL_CHANCE   GEN_LATEST // In Gen9+: Wiederholter Seitentausch senkt Erfolgs-Chance.
#define B_SKETCH_BANS               GEN_LATEST // In Gen9+: Nachahmer kopiert weniger Moves als frühere Gen.
#define B_KNOCK_OFF_REMOVAL         GEN_LATEST // In Gen5+: Abschlag entfernt Item statt macht es nutzlos.
#define B_HEAL_BELL_SOUNDPROOF      GEN_LATEST // Gen5: Vitalglocke heilt alle mit Lärmschutz. Gen6-8: Inaktive, nicht Kämpfer. Gen9: Nutzer immer.
#define B_CHARGE                    GEN_LATEST // In Gen9+: Ladevorgang-Status geht verloren, unabhängig vom Typ der nächsten Attacke.
#define B_POWDER_STATUS_HEAVY_RAIN  GEN_LATEST // In Gen7+: Pulverschleuder fügt dem Anwender einer Feuer-Attacke bei Starkregen keinen Schaden zu.
#define B_AFTER_YOU_TURN_ORDER      GEN_LATEST // In Gen8+: Verzögerung schlägt nicht fehl, wenn Reihenfolge gleich bleibt.
#define B_QUASH_TURN_ORDER          GEN_LATEST // Gen8+: Verzögerer-Nutzer nach Geschwindigkeit. Gen7-: In Verzögerer-Reihenfolge.
#define B_DESTINY_BOND_FAIL         GEN_LATEST // In Gen7+: Abgangsbund schlägt bei Wiederholung fehl.
#define B_FORESIGHT_FAIL            GEN_LATEST // Gen2 und Gen5+: Gesichte schlägt gegen Ziel unter Effekt fehl.
#define B_MIRACLE_EYE_FAIL          GEN_LATEST // In Gen5+: Wunderauge schlägt gegen Ziel unter Effekt fehl.
#define B_PURSUIT_TARGET            GEN_LATEST // Gen4+: Verfolgung greift Wechsel-Gegner an, auch nicht gezielt. Gen3-: Nur gezielt.
#define B_SKIP_RECHARGE             GEN_LATEST // Gen1: Auflade-Moves überspringen Aufladung, wenn Ziel K.O.
#define B_ENCORE_TARGET             GEN_LATEST // In Gen5+: Zugabe-Moves dürfen Ziel wählen.
#define B_TIME_OF_DAY_HEALING_MOVES GEN_LATEST // Gen2: Morgengrauen/Mondschein/Synthese heilen 2x bei Tageszeit. Abend hilft Mondschein.
                                               // OW_TIMES_OF_DAY Gen3+: Morgengrauen geht bei Tag.
#define B_DREAM_EATER_LIQUID_OOZE   GEN_LATEST // In Gen5+: Traumfresser betroffen von Kloakensoße.
#define B_DREAM_EATER_SUBSTITUTE    GEN_LATEST // In Gen5+: Traumfresser trifft und drainiert Delegation.
#define B_SNATCH                    GEN_LATEST // In Gen5+ stiehlt Übernahme keine Attacken mehr, die bereits im selben Zug von einem anderen Pokémon durch Übernahme gestohlen wurden.
#define B_FOCUS_PUNCH_FAILURE       GEN_LATEST // Um zu bestimmen, ob der Fokus verloren geht, wird in Gen4- geprüft, ob die aktuelle Attacke Power-Punch ist.
                                               // In Gen5-6 wird geprüft, ob die ausgewählte Attacke Power-Punch ist.
                                               // In Gen7+ wird geprüft, ob sowohl die aktuelle als auch die ausgewählte Attacke Power-Punch ist.
                                               // In Gen4- passiert die Prüfung auf Fehlschlag von Power-Punch nach Effekten wie AP-Verbrauch oder Zurückschrecken, während sie in Gen5+ davor stattfindet.
#define B_COUNTER_MIRROR_COAT_ALLY  GEN_LATEST // In Gen5+ zählt die Attacke eines Verbündeten nicht für den Einsatz von Konter/Spiegelcape/Metallstoß. In Gen4- schlagen Konter/Spiegelcape/Metallstoß fehl, wenn der letzte erlittene Treffer von einem Verbündeten stammte.
#define B_COUNTER_TRY_HIT_PARTNER   GEN_LATEST // In Gen5+ wird der Angriff auf den Partner umgeleitet, wenn das Pokémon, das den letzten Angriff ausgeführt hat, nicht mehr auf dem Feld ist. In Gen4- würden Konter/Spiegelcape/Metallstoß in diesem Fall fehlschlagen.
#define B_RAGE_BUILDS               GEN_LATEST // In Gen4+ tritt der Effekt von Raserei nur ein, wenn die Attacke erfolgreich trifft. In Gen3 tritt der Effekt ein, egal ob sie trifft, danebengeht oder fehlschlägt.
#define B_CHECK_USER_FAILURE        GEN_LATEST // In Gen5+ prüft der Anwender nicht mehr auf eigenes Fehlschlagen, z.B. blockiert Lärmschutz nicht mehr den eigenen Abgesang.
#define B_ABSORB_MESSAGE            GEN_LATEST // In Gen5+: Keine Absorber-Nachricht wird angezeigt, wenn der Anwender bereits volle KP hat.
#define B_UPROAR                    GEN_LATEST // In Gen5+ weckt Aufruhr beim ersten erfolgreichen Einsatz alle Kämpfer. In Gen3-4 können Kämpfer vor ihrer Aktion oder am Rundenende aufwachen.

// Fähigkeits-Einstellungen
#define B_GALE_WINGS                GEN_LATEST // In Gen7+ nur bei vollen KP aktiv.
#define B_STANCE_CHANGE_FAIL        GEN_LATEST // In Gen7+ scheitert Taktikwechsel bei Status wie Paralyse/Verwirrung. In Gen6 nicht.
#define B_SHADOW_TAG_ESCAPE         GEN_LATEST // In Gen4+ können alle entkommen, wenn beide Seiten Wegsperre haben. Zuvor niemand.
#define B_MOODY_ACC_EVASION         GEN_LATEST // In Gen8 kann Gefühlswippe Genauigkeit/Fluchtwert nicht mehr erhöhen.
#define B_FLASH_FIRE_FROZEN         GEN_LATEST // In Gen5+ kann Feuerfänger auch eingefroren triggern.
#define B_SYNCHRONIZE_TOXIC         GEN_LATEST // In Gen5+ spiegelt Synchro Toxin als Toxin; zuvor nur normal vergiftet.
#define B_UPDATED_INTIMIDATE        GEN_LATEST // In Gen8 wirkt Bedroher nicht auf Innerer Fokus, Tollpatsch, Eigenwille, Dösigkeit; aktiviert Hasenfuß.
#define B_OBLIVIOUS_TAUNT           GEN_LATEST // In Gen6+ schützt Dösigkeit vor Verhöhner.
#define B_STURDY                    GEN_LATEST // In Gen5+ lässt Robustheit mit 1 KP überleben, auch bei Selbstschaden durch Verwirrung.
#define B_PLUS_MINUS_INTERACTION    GEN_LATEST // In Gen5+ aktivieren Plus/Minus sich selbst und gegenseitig; zuvor nur gegnerische Fähigkeit.
#define B_WEATHER_FORMS             GEN_LATEST // In Gen5+ formenwechseln Formeo/Kinoso zurück, wenn Fähigkeit weg ist. Kinoso braucht Floraschild.
#define B_SYMBIOSIS_GEMS            GEN_LATEST // In Gen7+ reicht Mitnahme Item nach Juwelen-Boost erst nach dem Treffer weiter; zuvor davor, wodurch der Boost verloren gehen konnte.
#define B_REDIRECT_ABILITY_IMMUNITY GEN_LATEST // In Gen5+ machen Blitzfänger/Sturmsog immun und erhöhen Sp.-Angr. um 1, zusätzlich zur Umleitung.
#define B_REDIRECT_ABILITY_ALLIES   GEN_LATEST // In Gen4+ leiten Blitzfänger/Sturmsog auch Verbündeten-Moves um.
#define B_LEAF_GUARD_PREVENTS_REST  GEN_LATEST // In Gen5+ verhindert Floraschild Erholung bei starker Sonne.
#define B_TRANSISTOR_BOOST          GEN_LATEST // In Gen9+ verstärkt Transistor Elektro-Moves nur 1.3x statt 1.5x.
#define B_ILLUMINATE_EFFECT         GEN_LATEST // In Gen9+ verhindert Erleuchtung Genauigkeitssenken und ignoriert Fluchtwert.
#define B_WEAK_ARMOR_SPEED          GEN_LATEST // In Gen7+ erhöht Schwächenschutz Initiative um 2 statt 1 bei physischem Treffer.
#define B_PROTEAN_LIBERO            GEN_LATEST // In Gen9+ wechseln Wandlungskunst/Torwächter nur einmal pro Kampf den Typ.
#define B_INTREPID_SWORD            GEN_LATEST // In Gen9+ hebt Wackeres Schwert Angriff nur einmal pro Kampf um 1 Stufe.
#define B_DAUNTLESS_SHIELD          GEN_LATEST // In Gen9+ hebt Kühnes Schild Verteidigung nur einmal pro Kampf um 1 Stufe.
#define B_DISGUISE_HP_LOSS          GEN_LATEST // In Gen8+ verliert Mimigmas Verkleidung beim Bruch 1/8 Max-KP.
#define B_ABILITY_TRIGGER_CHANCE    GEN_LATEST // Gen3: Häutungsblätter/Reize/Hitzekörper/Statik/Giftstachel 1/3 Chance. Gen4+: 30%. Effektspore Gen3: 10% Schlaf/Gift/Para gleich verteilt; Gen4: 30%; Gen5+: 11% Schlaf, 9% Gift, 10% Para.
#define B_PICKUP_WILD               GEN_LATEST // In Gen9+ kann Mitnahme im Wildkampf am Rundenende das eigene verbrauchte Item aufnehmen.
#define B_MAGIC_GUARD               GEN_LATEST // Nur Gen4: Magieschild ignoriert Lähmungs-Unbeweglichkeit.
#define B_BATTLE_BOND               GEN_LATEST // In Gen9+ erhöht Band des Kampfes Atk/SpA/Init um je 1 Stufe, einmal pro Kampf.
#define B_ATE_MULTIPLIER            GEN_LATEST // In Gen7+ multiplizieren die -wandler-Fähigkeiten 1.2x, sonst 1.3x, außer Variabilität ohne Multiplikator.
#define B_DEFIANT_STICKY_WEB        GEN_LATEST // In Gen9+ triggert Siegeswille durch Klebenetz unabhängig vom Urheber...
#define B_MIRROR_ARMOR_STICKY_WEB   GEN_LATEST // In Gen9+ reflektiert Spiegelrüstung die Statussenkung durch Klebenetz nicht, selbst wenn dessen ursprünglicher Anwender noch auf dem Feld ist.
#define B_POWDER_OVERCOAT           GEN_LATEST // In Gen6+ blockt Wetterfest Puder- und Sporen-Moves.
#define B_INFILTRATOR_SUBSTITUTE    GEN_LATEST // In Gen6+ ignoriert Schwebedurch den gegnerischen Delegator.
#define B_DANCER_ORDER              GEN_LATEST // In Gen8+ werden Tänzer-Aktivierungen nach Initiative inklusive Modifikatoren abgearbeitet. In Gen7 erfolgt die Reihenfolge von langsam nach schnell anhand der unveränderten Initiative.
// Neu in 1.17.0 (Kommentare noch nicht uebersetzt)
#define B_PARALYSIS_CHANCE          GEN_LATEST // In Champions, paralysis has a 12.5% chance of not moving, instead of 25%.
#define B_MEGA_EVO_SPEED_SWAP       GEN_LATEST // In Champions, Mega Evolution does not overwrite the speed stat swapped via Speed Swap.
#define B_FREEZE_TURNS              GEN_LATEST // Prior to Champions, freeze has a 20% chance of being thawed out.
#define B_FIRST_TURN_MOVE               GEN_LATEST // In Champions, Fake Out and First Impression cannot be selected past the user's first turn.
#define B_SALT_CURE_DAMAGE              GEN_LATEST // In Gen9, Salt Cure deals 1/8 max HP (1/4 max HP to Steel and Water)
#define B_BELCH_SELECTABLE              GEN_LATEST // In Gen6-9, Belch cannot be selected unless the user has eaten a Berry
#define B_STUFF_CHEEKS_SELECTABLE       GEN_LATEST // In Gen8-9, Stuff Cheeks cannot be selected unless the user is holding a Berry
#define B_SPIT_UP_SELECTABLE            GEN_LATEST // In Champions, Spit Up cannot be selected unless the user has Stockpile stacks
#define B_MOVES_THAT_REMOVE_TYPE        GEN_LATEST // In Champions, Burn Up cannot be selected if the user is not Fire-type
#define B_LAST_RESORT_SELECTABLE        GEN_LATEST // In Champions, Last Resort cannot be selected if the user hasn't used all its other moves
#define B_FAINT_MOVE_EFFECT_TIMING      GEN_LATEST // In Champions, some move effects now apply even if the user faints from Rough Skin, Iron Barbs, etc.
#define B_SHEER_FORCE_AGAINST_ABILITIES GEN_LATEST // As of Champions, Sheer Force no longer prevents the activation of Berserk and Pickpocket
#define B_ENCORE_PRIORITY               GEN_LATEST // In Champions, Encore uses the priority of the Encored move instead of the selected move
#define B_RAGE_FIST                     GEN_LATEST // In Champions, Rage Fist stacks reset upon switching out or fainting
#define B_MOVE_EFFECTS_BEFORE_MOVES     GEN_LATEST // In Champions, Beak Blast will work when Encored into from a different move
#define B_UNSEEN_FIST_PIERCING_DRILL    GEN_LATEST // In Gen8-9, Unseen Fist/Piercing Drill deals 100% of the damage dealt to protected targets while also bypassing the contact effects of protect moves.

// Verschiedene temporäre Timer (Statusveränderungen)
#define B_CONFUSION_TURNS    5
#define B_UPROAR_TURN_COUNT  5
#define B_RAMPAGE_TURNS      3
#define B_DISABLE_TIMER      4
#define B_ENCORE_TIMER       4
#define B_PERISH_SONG_TIMER  3
#define B_TAUNT_TIMER        5
#define B_SLOW_START_TIMER   5
#define B_EMBARGO_TIMER      5
#define B_MAGNET_RISE_TIMER  5
#define B_TELEKINESIS_TIMER  3
#define B_HEAL_BLOCK_TIMER   5
#define B_LASER_FOCUS_TIMER  2
#define B_THROAT_CHOP_TIMER  2
#define B_WRAP_TURNS         7 // Maximale Anzahl an Runden mit Griffklaue
#define B_SYRUP_BOMB_TIMER   3
#define B_TORMENT_TIMER      3

// Item-Einstellungen
#define B_CONFUSE_BERRIES_HEAL      GEN_LATEST // In Gen3-6 stellen Tsitrubeere und ähnliche Beeren 1/8 der KP wieder her und wirken bei halben KP. In Gen7 stellen sie die Hälfte der KP wieder her und wirken bei 25% KP. In Gen8 heilen sie 1/3 der KP.
#define B_X_ITEMS_BUFF              GEN_LATEST // In Gen7+ erhöhen X-Items einen Statuswert um 2 Stufen statt 1.
#define B_X_ITEMS_CROSSUSE          TRUE       // In Gen3 kann man X-Items nur auf das aktive Pokémon anwenden. In Gen7+ kann man sie im Doppelkampf auf jeden verbündeten Kämpfer anwenden (genaue Generation der Änderung unklar).
#define B_MENTAL_HERB               GEN_LATEST // In Gen5+ heilt das Mentalkraut zusätzlich zur Betörung auch Verhöhner, Zugabe, Folterknecht, Heilsperre und Aussetzer.
#define B_TRAINERS_KNOCK_OFF_ITEMS  TRUE       // Wenn TRUE, können Trainer deine Items stehlen/tauschen (Nicht-Beeren werden nach dem Kampf zurückgegeben). In den Original-Spielen können Trainer keine Items außerhalb von Facilities stehlen.
#define B_RETURN_STOLEN_NPC_ITEMS   GEN_LATEST // In Gen5+ stehlen Raub und Bezirzer keine Items mehr von NPCs.
#define B_STEAL_WILD_ITEMS          GEN_LATEST // In Gen9+ stehlen Raub und Bezirzer das Item eines wilden Pokémon und schicken es in die Tasche. In Gen2-8 wurde das gestohlene Item vom Raub/Bezirzer-Nutzer gehalten.
#define B_RESTORE_HELD_BATTLE_ITEMS GEN_LATEST // In Gen9+ werden alle Nicht-Beeren-Items nach dem Kampf wiederhergestellt.
#define B_SOUL_DEW_BOOST            GEN_LATEST // In Gen3-6 erhöht Seelentau den Spezial-Angriff und die Spezial-Verteidigung von Latias und Latios. In Gen7+ verstärkt es stattdessen ihre Psycho- und Drachen-Attacken.
#define B_NET_BALL_MODIFIER         GEN_LATEST // In Gen7+ beträgt der Fang-Multiplikator des Netzballs x5 statt x3.
#define B_DIVE_BALL_MODIFIER        GEN_LATEST // In Gen4+ steigt die Effektivität des Tauchballs beim Surfen oder Angeln um x3,5.
#define B_NEST_BALL_MODIFIER        GEN_LATEST // Die Formel des Nestballs variiert je nach Generation. Siehe Cmd_handleballthrow.
#define B_REPEAT_BALL_MODIFIER      GEN_LATEST // In Gen7+ beträgt der Fang-Multiplikator des Wiederballs x3,5 statt x3.
#define B_TIMER_BALL_MODIFIER       GEN_LATEST // In Gen5+ steigt die Effektivität des Timerballs um x0,3 pro Runde statt x0,1.
#define B_DUSK_BALL_MODIFIER        GEN_LATEST // In Gen7+ beträgt der Fang-Multiplikator des Finsterballs x3 statt x3,5.
#define B_QUICK_BALL_MODIFIER       GEN_LATEST // In Gen5+ beträgt der Fang-Multiplikator des Flottballs x5 statt x4.
#define B_LURE_BALL_MODIFIER        GEN_LATEST // In Gen8+ beträgt der Fang-Multiplikator des Köderballs x4. In Gen7 ist er x5. In Gen6 und älter ist er x3.
#define B_HEAVY_BALL_MODIFIER       GEN_LATEST // In Gen7+ ändern sich die Wertebereiche des Schwerballs. Siehe Cmd_handleballthrow.
#define B_DREAM_BALL_MODIFIER       GEN_LATEST // In Gen8+ beträgt der Fang-Multiplikator des Traumballs x4, wenn das Ziel schläft oder die Fähigkeit Dauerschlaf hat.
#define B_SPORT_BALL_MODIFIER       GEN_LATEST // In Gen8+ wurde der Fang-Multiplikator des Turnierballs von x1,5 auf x1 reduziert.
#define B_SAFARI_BALL_MODIFIER      GEN_LATEST // In Gen8+ wurde der Fang-Multiplikator des Safariballs von x1,5 auf x1 reduziert.
#define B_FRIEND_BALL_MODIFIER      GEN_LATEST // In Gen8+ wurde der Freundschafts-Boost des Freundesballs von 200 auf 150 reduziert.
#define B_SERENE_GRACE_BOOST        GEN_LATEST // In Gen5+ erhöht Edelmut die zusätzliche Zurückschreck-Chance von King-Stein und Scharfzahn.
#define B_IRON_BALL                 GEN_LATEST // In Gen5+ erleiden Flug-Pokémon, die eine Eisenkugel tragen, x1 Schaden durch Boden-Attacken unabhängig von ihren anderen Typen, außer in Umkehrkämpfen oder wenn das Pokémon durch einen anderen Effekt am Boden gehalten wird.

// Flag-Einstellungen
// Um die folgenden Features zu nutzen, ersetze 0 durch ein Flag in include/constants/flags.h, idealerweise ein ungenutztes.
// Beispiel: FLAG_UNUSED_0x264 umbenennen und unten verwenden.

// Orden-Boost-Flags
#define B_FLAG_BADGE_BOOST_ATTACK   FLAG_BADGE01_GET // Wenn gesetzt und B_BADGE_BOOST == GEN_3: Angriff x1.1
#define B_FLAG_BADGE_BOOST_DEFENSE  FLAG_BADGE05_GET // Wenn gesetzt und B_BADGE_BOOST == GEN_3: Verteidigung x1.1
#define B_FLAG_BADGE_BOOST_SPEED    FLAG_BADGE03_GET // Wenn gesetzt und B_BADGE_BOOST == GEN_3: Initiative
#define B_FLAG_BADGE_BOOST_SPATK    FLAG_BADGE07_GET // Wenn gesetzt und B_BADGE_BOOST == GEN_3: Sp.-Angriff x1.1
#define B_FLAG_BADGE_BOOST_SPDEF    FLAG_BADGE07_GET // Wenn gesetzt und B_BADGE_BOOST == GEN_3: Sp.-Verteidigung x1.1
// Neu in 1.17.0 (Kommentare noch nicht uebersetzt)
#define B_FLAG_INVERSE_BATTLE       0     // If this flag is set, the battle's type chart inverted. For example, Fire is super effective against Water.
#define B_FLAG_AI_VS_AI_BATTLE      0     // If this flag is set, the player's Pokémon will be controlled by the AI in the next battle.
#define B_FLAG_DYNAMAX_BATTLE       0     // If this flag is set, the ability to Dynamax in battle is enabled for all Trainers.
#define B_FLAG_TERA_ORB_CHARGED     0     // If this flag is set, the Tera Orb is charged. It is automatically set upon healing and cleared upon Terastallizing once configured.
#define B_FLAG_TERA_ORB_NO_COST     0     // If this flag is set, the Tera Orb does not use up its charge upon Terastallization. In SV, this occurs after an event with Terapagos.
#define B_FLAG_SLEEP_CLAUSE         0     // If this flag is set, sleep clause is enabled; if a Pokémon on the one side of the field is asleep, another one on that side cannot be put to sleep. AI requires AI_FLAG_CHECK_BAD_MOVE to understand.
#define B_FLAG_NO_WHITEOUT          0     // If this flag is set, the player can not white out against Trainers. Please note that the party is not healed automatically!

// Weitere Kampf-Flags
#define B_FLAG_INVERSE_BATTLE       0     // Wenn gesetzt, werden Typ-Effektivität invertiert. Feuer ist z. B. sehr effektiv gegen Wasser.
#define B_FLAG_AI_VS_AI_BATTLE      0     // Wenn gesetzt, steuert die KI in den nächsten Kämpfen die Pokémon des Spielers.
#define B_FLAG_DYNAMAX_BATTLE       0     // Wenn gesetzt, ist Dynamaxen für alle Trainerkämpfe aktiviert.
#define B_FLAG_TERA_ORB_CHARGED     0     // Wenn gesetzt, ist der Tera-Orb geladen. Wird nach Heilen automatisch gesetzt und nach Terakristallisieren geleert, sobald konfiguriert.
#define B_FLAG_TERA_ORB_NO_COST     0     // Wenn gesetzt, verbraucht der Tera-Orb seine Ladung nicht beim Terakristallisieren. In S/V nach Ereignis mit Terapagos.
#define B_FLAG_SLEEP_CLAUSE         0     // Wenn gesetzt, Schlafklausel aktiv: Hat die Seite bereits ein gegnerisches Pokémon eingeschläfert, darf kein weiteres eingeschläfert werden. KI benötigt AI_FLAG_CHECK_BAD_MOVE.
#define B_FLAG_NO_WHITEOUT          0     // Wenn gesetzt, kann der Spieler gegen Trainer nicht ohnmächtig werden. Hinweis: Team wird nicht automatisch geheilt!

// Variablen-Einstellungen
// Um die folgenden Funktionen zu nutzen, ersetze 0 durch eine Variable aus include/constants/vars.h, am besten eine ungenutzte.
// Beispiel: VAR_UNUSED_0x404E passend umbenennen und anschließend unten verwenden.
#define B_VAR_WILD_AI_FLAGS         0     // Wenn nicht 0, können hier zusätzliche Wild-AI-Flags gesetzt werden. WICHTIG: Nicht mit obigen Flags (1 << 15) nutzbar.
                                          // Diese Var darf nie lange genug ungleich 0 bleiben, um gespeichert zu werden.
                                          // Für bessere Wild-AI siehe GetWildAiFlags() in src/battle_ai_main.c

#define B_VAR_DIFFICULTY            0     // Wenn nicht 0, steuert diese Var, welche Trainer-Schwierigkeit geladen wird. Per Script_SetDifficulty NACH NewGameInitData setzen.

// Taschen-Einstellungen
#define NO_BAG_RESTRICTION       0    // Keine Taschenbeschränkung
#define NO_BAG_AGAINST_TRAINER   1    // Keine Tasche gegen Trainer
#define NO_BAG_IN_BATTLE         2    // Keine Tasche im Kampf
#define NO_BAG_INVALID_VALUE     3

#define B_VAR_NO_BAG_USE         0     // Wenn 1, ist die Fähigkeit, die Tasche im Kampf zu verwenden, in Trainerkämpfen deaktiviert. Wenn 2, ist sie auch in Wildkämpfen deaktiviert.

// Himmelskämpfe
#define B_FLAG_SKY_BATTLE                 0     // Wenn gesetzt, kann der Spieler in geskriptete Himmelskämpfe gehen.
#define B_VAR_SKY_BATTLE                  0     // Wenn gesetzt, merkt sich das Spiel die Positionen der im Himmelskampf eingesetzten Pokémon.
#define B_SKY_BATTLE_STRICT_ELIGIBILITY   FALSE // TRUE: Teilnahmebedingungen wie in X/Y. FALSE: Alle Flug-Pokémon oder Pokémon mit Schwebe sind erlaubt.

// Flag/Var-Reset
#define B_RESET_FLAGS_VARS_AFTER_WHITEOUT TRUE // TRUE: Overworld_ResetBattleFlagsAndVars setzt Kampf-Flags/Vars bei Ohnmacht zurück.

// Ingame-Partner-Zielanzeige
#define B_SHOW_PARTNER_TARGET             FALSE // Zeigt das Ziel, das der Partner anvisiert.

// Move-Beschreibung im Kampfbildschirm
#define B_SHOW_MOVE_DESCRIPTION     TRUE       // Zeigt Move-Infos im Kampf an.

// Wetter-Einstellungen
// Suche nach 'rain', 'sunny day' und 'hail' für move-/spezies-spezifische Wetterinteraktionen.
#define B_ICE_WEATHER_BOTH              0
#define B_ICE_WEATHER_HAIL              1
#define B_ICE_WEATHER_SNOW              2

#define B_ABILITY_WEATHER               GEN_LATEST // In Gen6+ halten Fähigkeits-Wetter 5 Runden. Zuvor bis Kampfende oder Wechsel des Wetters.
#define B_SANDSTORM_SPDEF_BOOST         GEN_LATEST // In Gen4+ Sandsturm: Sp.-Vert. von Gestein x1.5.
#define B_SANDSTORM_SOLAR_BEAM          GEN_LATEST // In Gen3+ verringert Sandsturm die Stärke von Solarstrahl, was vorher nicht der Fall war.
#define B_OVERWORLD_FOG                 GEN_LATEST // In Gen8+ erzeugt OW-Nebel Feen-Terrain im Kampf. Nur Gen4: spezielles Nebel-Wetter.
#define B_OVERWORLD_SNOW                GEN_LATEST // In Gen9+ erzeugt OW-Schnee im Kampf Schnee statt Hagel.
#define B_SNOW_WARNING                  GEN_LATEST // In Gen9+ ruft Schneewalzer Schnee statt Hagel hervor.
#define B_PREFERRED_ICE_WEATHER         B_ICE_WEATHER_BOTH // Schaltet Hagel-Effekte auf Schnee um und umgekehrt.

// Terrain-Einstellungen
#define B_TERRAIN_BG_CHANGE         TRUE       // TRUE: Terrain-Moves ändern den Standard-Battle-Hintergrund temporär bis zum Ablauf.
#define B_THUNDERSTORM_TERRAIN      TRUE       // TRUE: OW-Gewitter erzeugt Regen + Elektro-Terrain wie in Gen8.
#define B_TERRAIN_TYPE_BOOST        GEN_LATEST // In Gen8: 30% Schaden statt 50%.
#define B_SECRET_POWER_EFFECT       GEN_LATEST // Effekte von Geheimpower variieren nach Terrain/Gen. Siehe MOVE_EFFECT_SECRET_POWER in SetMoveEffect.
#define B_SECRET_POWER_ANIMATION    GEN_LATEST // Animationen von Geheimpower variieren nach Terrain/Gen.
#define B_NATURE_POWER_MOVES        GEN_LATEST // Natur-Kraft ruft je nach Terrain/Gen andere Moves. Siehe gBattleEnvironmentInfo.
#define B_CAMOUFLAGE_TYPES          GEN_LATEST // Camouflage ändert Typ je nach Terrain/Gen. Siehe sTerrainToType.
#define B_NEW_TERRAIN_BACKGROUNDS   TRUE       // TRUE: Neue Hintergründe für Elektro/Feen/Gras/Psycho-Terrain.

// Interface-Einstellungen
#define B_FAST_INTRO_PKMN_TEXT              TRUE  // TRUE: Kampfintro-Texte laufen parallel zur Einlauf-Animation.
#define B_FAST_INTRO_NO_SLIDE               FALSE // TRUE: Überspringt die Anfangs-Slide-Animation.
#define B_FAST_HP_DRAIN                     TRUE  // TRUE: KP-Balken bewegen sich schneller.
#define B_FAST_EXP_GROW                     TRUE  // TRUE: EP-Balken bewegen sich schneller.
#define B_SHOW_TARGETS                      TRUE  // TRUE: Zeigt mögliche Ziele an, bevor man Moves auswählt, die 2-3 Pokémon treffen.
#define B_SHOW_CATEGORY_ICON                TRUE  // TRUE: Zeigt Kategorien-Icon in Übersicht und Move-Lehrer.
#define B_HIDE_HEALTHBOX_IN_ANIMS           TRUE  // TRUE: Versteckt KP-Boxen während Move-Animationen.
#define B_WAIT_TIME_MULTIPLIER              16    // Dauer von Textpausen im Kampf. Vanilla 16. Niedriger = schneller.
#define B_QUICK_MOVE_CURSOR_TO_RUN          TRUE // TRUE: B in Kampfoptionen gegen Wilde verschiebt Cursor auf „Flucht“.
#define B_RUN_TRAINER_BATTLE                TRUE  // TRUE: Flucht aus Trainerkämpfen möglich, gilt als Ohnmacht.
#define B_MOVE_DESCRIPTION_BUTTON           L_BUTTON // Taste, um Move-Beschreibung zu öffnen (nicht B_LAST_USED_BALL_BUTTON).
#define B_SHOW_USELESS_Z_MOVE_INFO          FALSE // TRUE: Z-Moves ohne Zusatzeffekt zeigen „kein Zusatzeffekt“.
#define B_ANIMATE_MON_AFTER_KO              TRUE // TRUE: Nach K.O. des Gegners zeigt eigenes Mon Sieges-Animation.
#define B_ANIMATE_MON_AFTER_FAILED_POKEBALL TRUE  // TRUE: Bricht ein Ball, zeigt wildes Mon seine Animation.
#define B_SHOW_DYNAMAX_MESSAGE              FALSE // TRUE: Zusätzliche Meldung nach abgeschlossener Dynamax/Gigadynamax.
#define B_HPBAR_COLOR_THRESHOLD             GEN_LATEST // In Gen5+ richten sich die Farbgrenzen des KP-Balkens nach den tatsächlichen KP statt nach der Pixellänge des Balkens; dadurch sind die Farben genauer.

// Fang-Einstellungen
#define B_SEMI_INVULNERABLE_CATCH       GEN_LATEST // In Gen4+ kann man keine Bälle auf halb-unverwundbare Ziele (Schaufler/Flieger/etc.) werfen.
#define B_CATCHING_CHARM_BOOST          100         // %-Bonus auf Krit-Fang mit Fang-Amulett.
#define B_INCAPACITATED_CATCH_BONUS     GEN_LATEST // In Gen5+ beträgt der Fangbonus bei Schlaf oder Gefrieren x2,5. In Gen4 und älter beträgt er nur x2.
#define B_LOW_LEVEL_CATCH_BONUS         GEN_3       // In Gen8 wird ein Bonus auf die Fangchance gewährt, wenn das Pokémon unter Level 20 ist. In Gen9 gilt der Bonus nur für Pokémon unter Level 13.
#define B_MISSING_BADGE_CATCH_MALUS     GEN_LATEST // In Gen9 wird ein Malus auf die Fangchance angewendet, wenn das Pokémon mehr als 5 Level über dem aktuellen Gehorsamslevel liegt, basierend auf der Anzahl der erhaltenen Orden.
#define B_CRITICAL_CAPTURE              TRUE       // Aktiviert Kritische Fangchance.
#define B_CRITICAL_CAPTURE_LOCAL_DEX    TRUE       // FALSE: Krit-Fang basierend auf Nationaldex (per aktivierten Generationen geschätzt).
#define B_CRITICAL_CAPTURE_IF_OWNED     GEN_LATEST // In Gen9+ erscheint ein Fang als kritisch, wenn das Pokémon bereits einen Pokédex-Eintrag hat (bereits gefangen wurde).

#define B_LAST_USED_BALL            TRUE       // TRUE: „Zuletzt benutzter Ball“ aus Gen7.
#define B_LAST_USED_BALL_BUTTON     R_BUTTON   // Taste/Kombination zum Werfen des letzten Balls.
#define B_LAST_USED_BALL_CYCLE      TRUE       // TRUE: Halte B_LAST_USED_BALL_BUTTON und nutze Steuerkreuz zum Durchschalten der Bälle.
#define B_CATCH_SWAP_INTO_PARTY     GEN_LATEST // In Gen7+: Nach Fang Auswahl, das neue Mon ins Team zu nehmen und ein anderes in die Box zu senden.
#define B_CATCH_SWAP_CHECK_HMS      TRUE       // TRUE: Verhindert, dass HM-Träger in die Box geschickt werden.

// Sonstiges
#define B_MULTI_BATTLE_WHITEOUT         GEN_LATEST // In Gen4+ enden Multi-Kämpfe, wenn Spieler UND Partner keine kampffähigen Pokémon mehr haben.
#define B_EVOLUTION_AFTER_WHITEOUT      GEN_LATEST // In Gen6+ entwickeln sich Pokémon nach Kampf auch bei Niederlage.
#define B_AFFECTION_MECHANICS           TRUE       // In Gen6+: Zuneigung kann Effekte im Kampf auslösen. Ab LGPE nutzen diese Effekte stattdessen Freundschaft.
#define B_TRAINER_CLASS_POKE_BALLS      GEN_LATEST // In Gen7+ benutzen Trainer je nach Klasse bestimmte Pokébälle.
#define B_TRAINER_MON_RANDOM_ABILITY    0          // If this is set to 0, trainers mons with no set ability only use the first ability of a mon. If set to 1 it will roll a random non-hidden ability. If set to 2, it will roll any ability (including hidden ability) with equal chance
#define B_OBEDIENCE_MECHANICS           GEN_LATEST // In PLA+ (hier Gen8+): Gehorsam gilt auch für Nicht-Tausch-Pokémon, basierend auf Fang-Level statt aktuellem Level.
#define B_USE_FROSTBITE                 FALSE      // In PLA ersetzt Erfrierung den Gefrier-Zustand. Aktiviert dies hier. Moves können einzeln auf Freeze/Erfrierung gestellt werden. Frost-/Geheimkraft/Triplette hängen davon ab.
#define B_TOXIC_REVERSAL                GEN_LATEST // In Gen5+ wird Toxin am Kampfende zu normaler Vergiftung.
#define B_TRY_CATCH_TRAINER_BALL        GEN_LATEST // In Gen4+ verbraucht der Versuch, ein Trainer-Mon zu fangen, keinen Ball.
#define B_SLEEP_CLAUSE                  FALSE      // Aktiviert Schlafklausel immer und überall, überschreibt B_FLAG_SLEEP_CLAUSE. Nutze Flag für Modularität.
#define B_PARTNER_MONS_MARKED_SEEN      TRUE      // TRUE: Partner-Pokémon im Doppelkampf werden als GESEHEN im Pokédex markiert, falls noch nicht begegnet.
#define B_MULTI_HALF_TEAMS              FALSE      // TRUE: Bei zwei Trainern auf einer Seite sind beide Teams auf je 3 Pokémon begrenzt. Bei FALSE kann die Begrenzung weiterhin pro Kampf über „Multi Party: Half“ in trainers.party gesetzt werden.

#define NUM_BEEPS_GEN_LATEST            4                    // Läuft 4 Schleifen
#define NUM_BEEPS_GEN_3                 -1                   // Läuft unendlich
#define NUM_BEEPS_OFF                   0                    // Spielt gar nicht
#define B_NUM_LOW_HEALTH_BEEPS          NUM_BEEPS_GEN_LATEST // Anzahl der „wenig KP“-Piepser. NUM_BEEPS_OFF deaktiviert, NUM_BEEPS_GEN_3 unendlich. Jeder beliebige Wert möglich, die Defines sind nur Bequemlichkeit.

// Animations-Einstellungen
#define B_NEW_SWORD_PARTICLE            TRUE     // TRUE: Aktualisiert Schwerttanz-Partikel.
#define B_NEW_LEECH_SEED_PARTICLE       TRUE     // TRUE: Aktualisiert Egelsamen-Partikel.
#define B_NEW_HORN_ATTACK_PARTICLE      TRUE     // TRUE: Aktualisiert Hornattacke-Partikel.
#define B_NEW_ROCKS_PARTICLE            TRUE     // TRUE: Aktualisiert Stein-Partikel.
#define B_NEW_LEAF_PARTICLE             TRUE     // TRUE: Aktualisiert Blatt-Partikel.
#define B_NEW_EMBER_PARTICLES           TRUE     // TRUE: Aktualisiert Glut-Partikel.
#define B_NEW_MEAN_LOOK_PARTICLE        TRUE     // TRUE: Aktualisiert Horrorblick-Auge.
#define B_NEW_TEETH_PARTICLE            TRUE     // TRUE: Aktualisiert Zähne-Partikel für Biss/Knirscher.
#define B_NEW_HANDS_FEET_PARTICLE       TRUE     // TRUE: Aktualisiert Hieb/Tritt/Schlag-Partikel.
#define B_NEW_SPIKES_PARTICLE           TRUE     // TRUE: Aktualisiert Stachler-Partikel.
#define B_NEW_FLY_BUBBLE_PARTICLE       TRUE     // TRUE: Aktualisiert Flug-„Blase“.
#define B_NEW_CURSE_NAIL_PARTICLE       TRUE     // TRUE: Aktualisiert Fluch-Nagel.
#define B_NEW_BATON_PASS_BALL_PARTICLE  TRUE     // TRUE: Aktualisiert Staffette-Pokéball-Sprite.
#define B_NEW_MORNING_SUN_STAR_PARTICLE TRUE     // TRUE: Aktualisiert Morgengrauen-Sterne.
#define B_NEW_IMPACT_PALETTE            TRUE     // TRUE: Aktualisiert Grund-Treffer-Palette.
#define B_NEW_SURF_PARTICLE_PALETTE     TRUE     // TRUE: Aktualisiert Surfer-Wellen-Palette.

// Pokéball-Animationen und -Sounds
#define B_ENEMY_THROW_BALLS          GEN_LATEST  // In Gen6+ werfen gegnerische Trainer Pokébälle statt „erscheinen und öffnen“.
#define B_ENEMY_THROW_BALLS_SOUND    GEN_LATEST  // In Gen5+ machen gegnerische Bälle beim Wurf einen Sound. Nur nutzbar, wenn B_ENEMY_THROW_BALLS >= Gen6.
#define B_PLAYER_THROW_BALLS_SOUND   GEN_LATEST  // In Gen5+ machen Spieler-Bälle beim Wurf einen Sound.

#define SHOW_TYPES_NEVER    0                    // Zeigt Typen im Kampf nie
#define SHOW_TYPES_ALWAYS   1                    // Zeigt Typen immer
#define SHOW_TYPES_CAUGHT   2                    // Zeigt Typen nur, wenn die Spezies gefangen wurde
#define SHOW_TYPES_SEEN     3                    // Zeigt Typen nur, wenn die Spezies gesehen wurde
#define B_SHOW_TYPES        SHOW_TYPES_SEEN     // Wann Typ-Indikatoren neben KP-Balken angezeigt werden, beim Move-Ziel-Auswählen.

#define SHOW_EFFECTIVENESS_NEVER    0           // Zeigt Effektivität beim Move-Wählen nie.
#define SHOW_EFFECTIVENESS_ALWAYS   1           // Zeigt Effektivität immer.
#define SHOW_EFFECTIVENESS_CAUGHT   2           // Nur wenn Spezies gefangen.
#define SHOW_EFFECTIVENESS_SEEN     3           // Nur wenn Spezies gesehen.
#define B_SHOW_EFFECTIVENESS        SHOW_EFFECTIVENESS_SEEN // Falls nicht NEVER: Ersetzt PP-String durch Effektivitäts-Hinweis basierend auf Moves und Gegenseite.

// Pokémon-Kampfsprite-Einstellungen
#define B_ENEMY_MON_SHADOW_STYLE        GEN_LATEST // In Gen4+ haben gegnerische Pokémon einen Schatten unter sich.

// Battle-UI-Einstellungen
#define B_MOVE_REARRANGEMENT_IN_BATTLE  GEN_3  // In Gen4+ können Moves im Kampf nicht umsortiert werden.

#define B_POOL_SETTING_CONSISTENT_RNG       FALSE    // TRUE: Derselbe Trainer erzeugt auf demselben Save immer denselben Pool.
#define B_POOL_SETTING_USE_FIXED_SEED       FALSE    // TRUE: Nutzt den festen Seed in B_POOL_SETTING_FIXED_SEED.
#define B_POOL_SETTING_FIXED_SEED           0x1D4127 // „Zufalls“-Zahl; in Emerald-Charmap へだら („he-da-ra“).
#define B_POOL_RULE_SPECIES_CLAUSE          FALSE    // Nur eine Spezies je Nationaldex-Nr.
#define B_POOL_RULE_EXCLUDE_FORMS           FALSE    // Schließt verschiedene Formen bei Species Clause aus.
#define B_POOL_RULE_ITEM_CLAUSE             FALSE    // Jedes Item nur einmal.
#define B_POOL_RULES_USE_ITEM_EXCLUSIONS    FALSE    // Items aus poolItemClauseExclusions ausschließen.
#define B_POOL_RULE_MEGA_STONE_CLAUSE       FALSE    // Nur ein Mon mit Mega-Stein auswählen.
#define B_POOL_RULE_Z_CRYSTAL_CLAUSE        FALSE    // Nur ein Mon mit Z-Kristall auswählen.
// Neu in 1.17.0 (Kommentare noch nicht uebersetzt)
#define B_OVERWORLD_WEATHER_OVERRIDE    GEN_LATEST // In Gen9+, overworld weather cannot be overridden.
#define B_HP_PERCENTAGE_DISPLAY             FALSE      // If set to TRUE, Pokémon on the opposing side's HP will be displayed in percentage alongside the HP bar. In single battles, this extends the healthbox to add the percentage below the HP bar. In double battles, the same input used to toggle your side's HP values will also toggle the opposing side's percentage display.
#define B_FLAG_VICTORY_CATCH_RANDOM     0          // If set, you will be prompted to throw a ball after the encounter has been defeated, catch rate is random. You can't capture the encounter in any other way.
#define B_FLAG_VICTORY_CATCH_GUARANTEED 0          // If set, you will be prompted to throw a ball after the encounter has been defeated, guaranteed to catch. You can't capture the encounter in any other way.
#define B_TERA_ORB_ALWAYS_CHARGED       FALSE      // If TRUE, causes the Tera Orb to always be charged all the time in every case, overriding B_FLAG_TERA_ORB_CHARGED. Use that for modularity.

#endif
