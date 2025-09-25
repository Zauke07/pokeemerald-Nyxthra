#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Bewegungs-Konfiguration
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+ kann der Spieler auch in Gebäuden rennen.
#define SLOW_MOVEMENT_ON_STAIRS     FALSE       // Wenn aktiviert, bewegt sich der Spieler auf Treppen langsamer wie in FR.

// Weitere Einstellungen
#define OW_POISON_DAMAGE                GEN_LATEST // In Gen4 können Pokémon durch Gift im Overworld nicht mehr ohnmächtig werden. In Gen5+ nehmen sie gar keinen Schaden mehr.
#define OW_DOUBLE_APPROACH_WITH_ONE_MON TRUE       // Wenn aktiviert, können dich zwei Trainer gleichzeitig sehen, auch wenn du nur ein kampffähiges Pokémon hast.
#define OW_HIDE_REPEAT_MAP_POPUP        TRUE       // Wenn aktiviert, erscheinen Karten-Popups nicht, wenn man eine Karte mit derselben Map Section Id wie zuvor betritt.
#define OW_WHITEOUT_CUTSCENE            GEN_LATEST // In Gen4+ zeigt das Whiteout eine zusätzliche Nachricht und eine Cutscene mit einem heilenden NPC nach dem Whiteout-Event. (Obwohl diese Änderung auch in FRLG vorhanden war, führt die Einstellung auf GEN_3 der Einfachheit halber zum RSE-Verhalten.)
#define OW_DEFOG_FIELD_MOVE             TRUE       // Wenn aktiviert, kann Entnebel als Feldattacke wie in DPPt verwendet werden.
#define OW_ROCK_CLIMB_FIELD_MOVE        TRUE      // Wenn aktiviert, kann Kletterer als Feldattacke wie in DPPt verwendet werden.

// Item-Beschreibungsbox
#define OW_ITEM_DESCRIPTIONS_OFF        0   // Nie Beschreibungen anzeigen
#define OW_ITEM_DESCRIPTIONS_FIRST_TIME 1   // Nur beim ersten Mal anzeigen (** SAVE-BREAKING - siehe struct SaveBlock3 **)
#define OW_ITEM_DESCRIPTIONS_ALWAYS     2   // Immer Beschreibung anzeigen
#define OW_SHOW_ITEM_DESCRIPTIONS       OW_ITEM_DESCRIPTIONS_FIRST_TIME    // Wenn aktiviert, werden Item-Beschreibungen/Bilder beim Finden von Items angezeigt.

// Diese Generation-Defines unterscheiden nur bei Beeren und OW_PC_MOVE_ORDER
#define GEN_6_XY GEN_6
#define GEN_6_ORAS GEN_LATEST + 1

// PC-Einstellungen
#define OW_PC_PRESS_B               GEN_LATEST // In Gen4 entspricht das Drücken von B beim Halten eines Pokémon dem Ablegen. In Gen3 gibt es eine Fehlermeldung.
#define OW_PC_JAPAN_WALDA_ICONS     TRUE       // In der US-Version von Smaragd wurden bestimmte Icons für Waldas Wallpaper entfernt. TRUE stellt sie wieder her.
#define OW_PC_HEAL                  GEN_LATEST // In Gen8+ werden Pokémon beim Ablegen im PC nicht mehr geheilt.
#define OW_PC_MOVE_ORDER            GEN_LATEST // Ab Gen4 ändert sich die Reihenfolge der Optionen im PC-Menü.
#define OW_PC_RELEASE_ITEM          GEN_LATEST // In Gen8+ erhält man Items von freigelassenen Pokémon zurück in die Tasche.

#define OW_BERRY_MUTATIONS             TRUE      // Wenn aktiviert, können Beerenpflanzen mutieren, abhängig von benachbarten Beeren.
#define OW_BERRY_MUTATION_CHANCE       25         // Gibt die % Wahrscheinlichkeit einer Mutation an.
#define OW_BERRY_MOISTURE              FALSE      // Wenn aktiviert, muss der Boden feucht gehalten werden, nicht nur einmal pro Wachstumsstufe gießen.
#define OW_BERRY_ALWAYS_WATERABLE      FALSE      // Wenn OW_BERRY_MOISTURE aktiviert ist, kann man den Boden immer gießen; trockener Boden verringert die Ausbeute (wie Gen4). Aus, nur bei trockenem Boden gießen (wie Gen6).
#define OW_BERRY_MULCH_USAGE           FALSE      // Wenn aktiviert, kann Mulch zum Düngen verwendet werden. Feuchtigkeitseffekte funktionieren nur mit OW_BERRY_MOISTURE!
#define OW_BERRY_WEEDS                 FALSE      // Wenn aktiviert, können Unkraut auf Beerenpflanzen wachsen, das entfernt werden muss. Ohne OW_BERRY_MOISTURE werden Boni abgerundet.
#define OW_BERRY_PESTS                 FALSE      // Wenn aktiviert, können Schädlinge Beerenpflanzen befallen, die entfernt werden müssen. Ohne OW_BERRY_MOISTURE werden Boni abgerundet.
#define OW_BERRY_SIX_STAGES            FALSE      // In XY durchlaufen Beeren sechs statt vier Stadien. Ohne OW_BERRY_MOISTURE zählen die zwei extra Stadien als BERRY_STAGE_TALLER.

#define OW_BERRY_GROWTH_RATE           GEN_3      // Voreinstellungen, wie lange Beeren zum Wachsen brauchen.
#define OW_BERRY_YIELD_RATE            GEN_3      // Voreinstellungen, wie viele Beeren eine Pflanze tragen kann.
#define OW_BERRY_DRAIN_RATE            GEN_6_ORAS // Wenn OW_BERRY_MOISTURE aktiviert ist, bestimmt dies, wie schnell der Boden austrocknet. Andere Werte sind illegal.
#define OW_BERRY_IMMORTAL              TRUE      // Wenn aktiviert, verschwindet ein Beerenbaum mit Beeren nicht, bis sie gepflückt wurden.

// Overworld-Pokémon
#define OW_POKEMON_OBJECT_EVENTS       TRUE       // Fügt für jede Spezies ein Object Event hinzu. Kann für NPCs mit dem Makro OBJ_EVENT_GFX_SPECIES verwendet werden.
#define OW_SUBSTITUTE_PLACEHOLDER      TRUE       // Nutzt ein Ersatz-Overworld-Sprite für Pokémon ohne Overworld-Sprite.
#define OW_LARGE_OW_SUPPORT            TRUE       // Fügt Unterstützung für große Overworld-Sprites (z.B. 48x48, 64x64) hinzu.
#define OW_PKMN_OBJECTS_SHARE_PALETTES FALSE      // [WIP!! NICHT ALLE PALETTEN SIND ANGEPASST!!] Wenn TRUE, werden Paletten von Kampfsprites übernommen.
#define OW_GFX_COMPRESS                TRUE       // Fügt Unterstützung für komprimierte Overworld-Grafiken hinzu. Spart VRAM, aber inkompatibel mit nicht-potenzierten Spritegrößen.
#define OW_MON_WANDER_WALK             TRUE       // Wenn aktiviert, laufen Overworld-Pokémon mit MOVEMENT_TYPE_WANDER auf der Stelle zwischen den Schritten.
// Begleiter-Pokémon
#define OW_FOLLOWERS_ENABLED           TRUE      // Aktiviert Begleiter-Pokémon im HGSS-Stil. Benötigt OW_POKEMON_OBJECT_EVENTS. Zusätzliche Skripte nötig!
#define OW_FOLLOWERS_BOBBING           TRUE       // Wenn TRUE, wippen Begleiter-Pokémon bei Idle- und Laufanimationen.
#define OW_FOLLOWERS_POKEBALLS         TRUE       // Wenn TRUE, erscheinen Begleiter-Pokémon aus dem Ball, in dem sie sind, statt aus einem normalen Pokéball.
#define OW_FOLLOWERS_WEATHER_FORMS     TRUE      // Wenn TRUE, ändern Formwandler wie Formeo und Kinoso ihre Form je nach Wetter.
#define OW_FOLLOWERS_COPY_WILD_PKMN    TRUE      // Wenn TRUE, kopieren Begleiter mit Transform/Illusion/Imposter zufällige wilde Pokémon.
#define OW_BATTLE_ONLY_FORMS           TRUE       // Wenn TRUE, werden Overworld-Sprites für kampfexklusive Formen wie Mega-Entwicklungen geladen.
#define B_FLAG_FOLLOWERS_DISABLED      0          // Aktiviert/Deaktiviert Begleiter per Flag. Nützlich, um Begleiter temporär zu deaktivieren.
#define OW_FOLLOWERS_SCRIPT_MOVEMENT   TRUE       // Wenn TRUE, kehren Begleiter nur dann in den Ball zurück, wenn ein Nicht-Spieler mit ihnen kollidiert (per Flag).

// Einschränkungen für Begleiter-Pokémon
// Nur Pokémon, die Spezies, Fundort und/oder Level entsprechen, dürfen folgen; akzeptiert auch Variablen wie VAR_TEMP_1 usw.
#define OW_FOLLOWERS_ALLOWED_SPECIES (0)
#define OW_FOLLOWERS_ALLOWED_MET_LVL (0)
#define OW_FOLLOWERS_ALLOWED_MET_LOC (0)

// Fähigkeitseffekte außerhalb des Kampfes
#define OW_SYNCHRONIZE_NATURE       GEN_LATEST // In Gen8+ übernimmt ein wildes Pokémon immer das Wesen des ersten Team-Pokémon mit Synchro. Geschenk-Pokémon ausgenommen.
#define OW_SUPER_LUCK               GEN_LATEST // In Gen8+ erhöht Erstes Team-Pokémon mit Glückspilz die Rate für wilde Items auf 60%/20%.
#define OW_INFILTRATOR              GEN_LATEST // In Gen8+ halbiert Erstes Team-Pokémon mit Siegeswille die Begegnungsrate.
#define OW_HARVEST                  GEN_LATEST // In Gen8+ erhöht Erstes Team-Pokémon mit Reiche Ernte die Chance auf wilde Pflanzen-Pokémon auf 50%.
#define OW_LIGHTNING_ROD            GEN_LATEST // In Gen8+ erhöht Erstes Team-Pokémon mit Blitzfänger die Chance auf wilde Elektro-Pokémon auf 50%.
#define OW_STORM_DRAIN              GEN_LATEST // In Gen8+ erhöht Erstes Team-Pokémon mit Sturmsog die Chance auf wilde Wasser-Pokémon auf 50%.
#define OW_FLASH_FIRE               GEN_LATEST // In Gen8+ erhöht Erstes Team-Pokémon mit Feuerfänger die Chance auf wilde Feuer-Pokémon auf 50%.

// Diese Defines unterscheiden nur bei OW_ALTERED_TIME_RATIO
#define GEN_8_PLA                       GEN_LATEST + 2
#define TIME_DEBUG                      GEN_LATEST + 3

// Zeit
#define OW_TIMES_OF_DAY                 GEN_LATEST   // Verschiedene Generationen wechseln zu unterschiedlichen Zeiten die Tageszeit.
#define OW_USE_FAKE_RTC                 TRUE        // Wenn TRUE, vergeht eine Sekunde im Spiel nur alle 60 Frames.
#define OW_ALTERED_TIME_RATIO           GEN_LATEST   // In GEN_8_PLA vergeht im Spiel 1 Minute pro RTC-Sekunde. In GEN_9 sind es 20 Sekunden. TIME_DEBUG ist 1:1.
#define OW_TIME_OF_DAY_ENCOUNTERS       FALSE        // Wenn TRUE, können verschiedene Begegnungstabellen je nach Tageszeit definiert werden.
#define OW_TIME_OF_DAY_DISABLE_FALLBACK FALSE        // Wenn TRUE, gibt es keine Begegnungen, wenn die Tabelle für eine Tageszeit leer ist, statt auf die Standardtabelle zurückzufallen.
#define OW_TIME_OF_DAY_FALLBACK         TIME_MORNING // Tageszeit, auf die Begegnungstabellen zurückfallen.

// Beleuchtung
#define OW_SHADOW_INTENSITY             4       // Werte von 0 bis 16, wobei 0 durchsichtig und 16 schwarz ist.
#define OW_OBJECT_SUBPRIORITY           148     // Je höher der Wert, desto weiter hinten im Vergleich zu anderen Sprites. Schatten sollten hinter Objekten sein.
#define OW_ENABLE_DNS                   TRUE    // Wenn TRUE, wird die Overworld je nach Tageszeit eingefärbt.

// Schatten für Object Events
#define OW_OBJECT_VANILLA_SHADOWS      TRUE    // In Vanilla werden Schatten nur beim Springen angezeigt.

// Overworld-Flags
// Um die folgenden Features in Skripten zu nutzen, ersetze die 0 durch die gewünschte Flag-ID.
// Beispiel: Ersetze durch FLAG_UNUSED_0x264, um das Feature per Flag zu steuern.
#define OW_FLAG_PAUSE_TIME          FLAG_UNUSED_0x264  // Wenn gesetzt und OW_USE_FAKE_RTC aktiviert ist, bleibt die Zeit im Spiel stehen.
#define OW_FLAG_NO_ENCOUNTER        FLAG_UNUSED_0x266  // Wenn gesetzt, gibt es keine wilden Begegnungen.
#define OW_FLAG_NO_TRAINER_SEE      FLAG_UNUSED_0x267  // Wenn gesetzt, kämpfen Trainer nur nach Ansprache, nicht beim Sehen.
#define OW_FLAG_NO_COLLISION        FLAG_UNUSED_0x268  // Wenn gesetzt, kann der Spieler über Kollisionstiles laufen. Hauptsächlich für Debugging.
#define OW_FLAG_POKE_RIDER          0  // Wenn gesetzt, kann man per Pokenav oder Town Map mit 'R' fliegen.

// Battle-Pyramide
#define BATTLE_PYRAMID_RANDOM_ENCOUNTERS    FALSE    // Wenn TRUE, werden Pokémon in der Battle-Pyramide zufällig generiert statt festgelegt.

// Map-Popup-Konfiguration
#define OW_POPUP_GENERATION        GEN_3    // Verschiedene Generationen zeigen Ortsnamen unterschiedlich an. Nur GEN_3 und GEN_5 werden unterstützt.

// Gen5 Map-Popup-Konfiguration
// Konstanten
#define OW_POPUP_BW_TIME_NONE      0   // Keine Zeit anzeigen
#define OW_POPUP_BW_TIME_12_HR     1   // 12-Stunden-Anzeige (AM/PM)
#define OW_POPUP_BW_TIME_24_HR     2   // 24-Stunden-Anzeige

#define OW_POPUP_BW_COLOR_BLACK    0   // Schwarzes Popup wie in B2
#define OW_POPUP_BW_COLOR_WHITE    1   // Weißes Popup wie in W2

// Konfiguration
#define OW_POPUP_BW_COLOR          OW_POPUP_BW_COLOR_BLACK  // B2W2 nutzen unterschiedliche Farben für Map-Popups.
#define OW_POPUP_BW_TIME_MODE      OW_POPUP_BW_TIME_24_HR   // Bestimmt, welche Zeit angezeigt wird.
#define OW_POPUP_BW_ALPHA_BLEND    TRUE                    // Aktiviert Transparenz für Popups. Kann zu Grafikfehlern mit Day-Night-System führen.

// Pokémon Center
#define OW_IGNORE_EGGS_ON_HEAL           GEN_LATEST         // In Gen4+ heilt die Schwester im Center keine Eier mehr.
#define OW_UNION_DISABLE_CHECK           FALSE              // Wenn TRUE, informiert die Schwester nicht über wartende Trainer im Union Room. Beschleunigt das Laden des Centers.
#define OW_FLAG_MOVE_UNION_ROOM_CHECK    0                  // Wenn gesetzt, wird nur beim Heilen auf Union Room geprüft, nicht beim Betreten des Centers. Ignoriert, wenn OW_UNION_DISABLE_CHECK TRUE ist.

// Beerenschleuder
#define BERRY_BLENDER_THROW_ALL_BERRIES_AT_ONCE TRUE        // Alle Beeren werden gleichzeitig in die Schleuder geworfen. Beschleunigt die Animation.

#endif // GUARD_CONFIG_OVERWORLD_H
