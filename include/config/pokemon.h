#ifndef GUARD_CONFIG_POKEMON_H
#define GUARD_CONFIG_POKEMON_H

// Einstellungen für Speziesdaten
#define P_UPDATED_TYPES GEN_LATEST        // Seit Gen. 6 wurden die Typen mehrerer Pokémon teilweise oder vollständig in den Typ Fee geändert.
#define P_UPDATED_STATS GEN_LATEST        // Seit Gen. 6 werden die Statuswerte der Pokémon mit jeder Generation aktualisiert.
#define P_UPDATED_ABILITIES GEN_LATEST    // Seit Gen. 6 wurden die Fähigkeiten bestimmter Pokémon geändert.
#define P_UPDATED_EGG_GROUPS GEN_LATEST   // Seit Gen. 8 haben bestimmte Pokémon neue Ei-Gruppen erhalten.
#define P_UPDATED_FRIENDSHIP GEN_LATEST   // Seit Gen. 8 wurde die Basis-Freundschaft bestimmter Pokémon geändert.
#define P_UPDATED_EVS GEN_LATEST          // Einige Pokémon erhielten nach ihrer Einführung EV-Updates (Fleißpunkte-Updates).
#define P_UPDATED_EXP_YIELDS GEN_LATEST   // Seit Gen. 5 haben einige Pokémon Änderungen an ihren Basis-Erfahrungspunkten (Exp. Yields) erhalten.

// Attacken-Lernsets
#define P_LVL_UP_LEARNSETS GEN_LATEST     // Wähle aus, welches Set von Level-Up-Attacken-Lernsets verwendet werden soll.
                                          // Für Generationen, in denen eine Spezies noch nicht eingeführt wurde, wird das Lernset aus ihrem ersten Auftreten verwendet (z.B. Endivies Gen. 2 Daten, wenn die Konfiguration auf GEN_1 gesetzt ist).
                                          // Für Generationen, die eine zuvor eingeführte Spezies nicht enthalten, wird ihr letztes Auftreten verwendet (z.B. Serpifeus' Gen. 7 Daten, wenn die Konfiguration auf GEN_8 gesetzt ist).
                                          // GEN_1/2/3/4/5/6/7: Lernsets von Gelb, Kristall, RSE, HGSS, S2W2, ORAS bzw. USUM.
                                          // GEN_8: Verwende die folgende Priorität: BDSP für Pokémon der Gen. 1-4, dann LA (Legenden: Arceus) für Spezies, die in diesem Spiel eingeführt wurden, dann SwSh für Spezies, die in diesen Spielen vorhanden sind. Andernfalls verwende GEN_7.
                                          // GEN_9: SV (Karmesin/Purpur) für Spezies, die in diesen Spielen vorhanden sind. Andernfalls verwende GEN_8.
#define P_EVOLUTION_LEVEL_1_LEARN GEN_LATEST // In Gen. 8+ erhalten Pokémon, die sich auf Level 1 entwickeln, nicht die Möglichkeit, ihre Level-1-Attacken zu erlernen, während dies zuvor der Fall war.

// Entwicklungseinstellungen
#define P_FRIENDSHIP_EVO_THRESHOLD GEN_LATEST // Seit Gen. 8 entwickeln sich Pokémon, die sich durch Freundschaft entwickeln, bei oder über 160 Freundschaft statt bei 220.

// Zuchteinstellungen
#define P_NIDORAN_M_DITTO_BREED GEN_LATEST    // Seit Gen. 5 kann Nidoran♂ bei der Zucht mit Ditto auch Nidoran♀-Nachkommen produzieren. Zuvor wurden nur männliche Nachkommen erzeugt. Diese Änderung gilt auch für Volbeat.
#define P_INCENSE_BREEDING GEN_LATEST         // Seit Gen. 9 benötigen Baby-Pokémon aus verschiedenen Generationen kein Räucherwerk der Eltern mehr, um durch Zucht erhalten zu werden.
#define P_EGG_HATCH_LEVEL GEN_LATEST          // Seit Gen. 4 schlüpfen Pokémon auf Level 1 statt auf Level 5 aus Eiern.
#define P_BALL_INHERITING GEN_LATEST          // Seit Gen. 6 erben Eier aus der Pension den Pokéball der Mutter. Ab Gen. 7 kann auch der Vater den Ball weitergeben, solange er derselben Spezies wie die Mutter angehört.
#define P_TM_INHERITANCE GEN_LATEST           // Seit Gen. 6 gibt der Vater keine TMs mehr an das Baby weiter.
#define P_MOTHER_EGG_MOVE_INHERITANCE GEN_LATEST // Seit Gen. 6 kann auch die Mutter Zuchtattacken (Egg Moves) weitergeben.
#define P_NATURE_INHERITANCE GEN_LATEST       // In Gen. 3 gibt der Ewigstein Ditto und Müttern eine 50%ige Chance, das Wesen zu vererben. Seit Gen. 4 kann jeder das Wesen weitergeben. Seit Gen. 5 beträgt die Chance 100%.
#define P_ABILITY_INHERITANCE GEN_LATEST      // In S2W2 hat ein weibliches Pokémon eine 80%ige Chance, seine Fähigkeit weiterzugeben, wenn es mit einem Männchen gezüchtet wird. Seit Gen. 6 beträgt die Chance 80% für normale Fähigkeit und 60% für Versteckte Fähigkeit, und jeder kann seine Fähigkeiten weitergeben, wenn mit Ditto gezüchtet wird. HINWEIS: Der Effekt von SW: 60% Chance zur Weitergabe von VF und zufällig für normale Fähigkeit, wurde weggelassen.
#define P_EGG_MOVE_TRANSFER GEN_LATEST        // Ab Gen. 8 erhält ein Pokémon eine Zuchtattacke auf dem leeren Platz, wenn zwei Pokémon derselben Spezies in der Pension sind, und eines eine Zuchtattacke kennt, während das andere einen leeren Platz hat. In Gen. 9 erhält ein Pokémon Zuchtattacken vom anderen (unabhängig von der Spezies), wenn es ein Spiegelsamen hält.
#define P_SCATTERBUG_LINE_FORM_BREED SPECIES_SCATTERBUG_FANCY // Wähle die Purmel-Form, in die sich alle Vivillon/Puponcho/Purmel züchten lassen, im Grunde angepasst an den "Standort" des Spieler-Spiels.

// Speziesspezifische Einstellungen
#define P_SHEDINJA_BALL GEN_LATEST        // Seit Gen. 4 benötigt Ninjatom einen Pokéball für seine Entwicklung. In Gen. 3 erbt Ninjatom den Ball von Nincada.
#define P_KADABRA_EVERSTONE GEN_LATEST    // Seit Gen. 4 kann Kadabra auch dann noch entwickeln, wenn es einen Ewigstein hält.
#define P_SHUCKLE_BERRY_JUICE GEN_LATEST  // In Gen. 2 hatte Pottrott eine 1/16-Chance, die gehaltene Beere in Beerensaft umzuwandeln. Die Aktivierung dieser Option erlaubt es Pottrott, dies mit einer Sinelbeere (die der geistige Nachfolger der Beere ist) zu tun.

// Grafikeinstellungen für Spezies
#define P_GENDER_DIFFERENCES TRUE         // Wenn WAHR, haben weibliche Pokémon nur grafische Unterschiede. Weibliche *Formen* wie Psiaugon sind davon nicht betroffen.
#define P_CUSTOM_GENDER_DIFF_ICONS TRUE   // Wenn WAHR, erhalten mehr Pokémon benutzerdefinierte Icons für ihre weiblichen Unterschiede, z.B. Hippopotas und Hippoterus.
#define P_ARCEUS_UNIQUE_FORM_ICONS GEN_LATEST // Seit Gen. 9 ändert Arceus zusätzlich sein Icon, um seine aktuelle Form widerzuspiegeln.
#define P_FOOTPRINTS TRUE                 // Wenn WAHR, haben Pokémon Fußabdrücke (wie es bis Gen. 5 und in BDSP der Fall war). Die Deaktivierung dieser Option spart ROM-Speicherplatz.
#define P_TWO_FRAME_FRONT_SPRITES TRUE    // In Pokémon Smaragd bestehen Pokémon-Vorder-Sprites immer aus zwei Frames. Diese Konfiguration kann dies rückgängig machen, sodass nur der erste Frame verwendet wird, wie es in den anderen Gen.-3-Spielen der Fall ist.
#define P_GBA_STYLE_SPECIES_GFX FALSE     // Standardmäßig verwenden Pokémon-Sprites den Stil der Gen. 4/5. Diese Konfiguration kann sie auf den GBA-Stil zurücksetzen. HINWEIS: B_ENEMY_MON_SHADOW_STYLE ist bei Verwendung dieser Sprites derzeit deaktiviert.
#define P_GBA_STYLE_SPECIES_ICONS FALSE   // Standardmäßig haben Pokémon ihre aktualisierten Icons. Diese Konfiguration kann sie auf den GBA-Stil zurücksetzen.
#define P_GBA_STYLE_SPECIES_FOOTPRINTS FALSE // Standardmäßig haben Pokémon ihre aktualisierten Fußabdrücke. Diese Konfiguration kann sie auf den GBA-Stil zurücksetzen.

// Andere Einstellungen
#define P_CRIES_ENABLED TRUE              // Wenn WAHR, haben Pokémon Rufe. Die Deaktivierung spart VIEL ROM-Speicherplatz (über 25 %!), aber stattdessen empfehlen wir, einzelne ungenutzte Pokémon-Familien in include/config/species_enabled.h zu deaktivieren.
#define P_LEGENDARY_PERFECT_IVS GEN_LATEST // Seit Gen. 6 haben Legendäre, Mysteriöse Pokémon und Ultrabestien, die in der Wildnis gefunden oder durch Geschenke erhalten werden, mindestens 3 perfekte IVs (Individuelle Stärken).
#define P_EV_CAP GEN_LATEST               // Seit Gen. 6 beträgt die maximale Anzahl an EVs pro Statuswert 252 statt 255.
#define P_SHOW_TERA_TYPE GEN_8            // Seit Gen. 9 wird der Tera-Typ auf dem Berichtsbildschirm angezeigt.
#define P_TM_LITERACY GEN_LATEST          // Seit Gen. 6 können Pokémon, die TM-Analphabeten sind, TMs erlernen, die Attacken lehren, welche in ihren Level-Up-Lernsets enthalten sind.
#define P_CAN_FORGET_HIDDEN_MOVE FALSE    // Wenn WAHR, können Pokémon jede Attacke vergessen, auch wenn es eine Versteckte Attacke (VM) ist.
#define P_ASK_MOVE_CONFIRMATION FALSE     // Wenn FALSCH, fragt das Spiel den Spieler nicht nach Bestätigung, wenn er sich entscheidet, eine Attacke nicht zu erlernen.
#define P_EGG_CYCLE_LENGTH GEN_LATEST     // Seit Gen. 8 benötigen Ei-Zyklen nur noch halb so viele Schritte wie zuvor. Frühere Generationen hatten unterschiedliche Schrittzahlen um 255.
#define P_ONLY_OBTAINABLE_SHINIES FALSE   // Wenn WAHR, werden Pokémon, die in der Kampfpyramide oder bei deaktiviertem Fang angetroffen werden, nicht Shiny sein.
#define P_NO_SHINIES_WITHOUT_POKEBALLS FALSE // Wenn WAHR, werden Pokémon, die angetroffen werden, wenn der Spieler keine Pokébälle mehr hat, nicht Shiny sein.
#define P_SHOW_DYNAMIC_TYPES FALSE        // Wenn WAHR, werden alle Attacken mit dynamischen Typenänderungen in Kampf-/Berichtsbildschirmen als ihr aktueller Typ angezeigt, anstatt nur ausgewählte wie in Vanilla.

// Schalter für Lernset-Helfer
#define P_LEARNSET_HELPER_TEACHABLE TRUE  // Wenn WAHR, wird teachable_learnsets.h von tools/learnset_helpers/make_teachables.py anhand der enthaltenen JSON-Dateien und basierend auf verfügbaren TMs und Tutoren befüllt.
#define P_TUTOR_MOVES_ARRAY FALSE         // Wenn WAHR, wird ein gTutorMoves-Array automatisch mit make_teachables.py generiert (wird normalerweise nicht benötigt, aber der HGSS-Pokédex hat eine optionale Verwendung dafür).

// Flag-Einstellungen
// Um die folgenden Funktionen im Scripting zu verwenden, ersetze die 0en durch die Flag-ID, die du ihr zuweist. // Z.B.: Ersetze durch FLAG_UNUSED_0x264, damit du dieses Flag zum Umschalten der Funktion verwenden kannst.
#define P_FLAG_FORCE_SHINY 0              // Wenn dieses Flag gesetzt ist, werden alle wilden und Geschenk-Pokémon dazu gezwungen, Shiny zu sein.
#define P_FLAG_FORCE_NO_SHINY 0           // Wenn dieses Flag gesetzt ist, werden alle wilden und Geschenk-Pokémon dazu gezwungen, NICHT Shiny zu sein.

// Gehe hierhin, wenn du bestimmte Pokémon-Familien deaktivieren möchtest.
#include "config/species_enabled.h"

#endif // GUARD_CONFIG_POKEMON_H