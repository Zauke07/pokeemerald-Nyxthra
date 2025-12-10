#ifndef GUARD_CONFIG_SUMMARY_SCREEN_H
#define GUARD_CONFIG_SUMMARY_SCREEN_H

// Settings
#define P_SUMMARY_SCREEN_NATURE_COLORS   TRUE   // Wenn TRUE, werden naturbasierte Statusboosts und -reduzierungen rot und blau im Zusammenfassungsbildschirm angezeigt.
#define P_SUMMARY_SCREEN_RENAME          TRUE   // Wenn TRUE, ersetzt eine Option zum Ändern von Pokémon-Spitznamen die Abbrechen-Aufforderung auf der Info-Seite des Zusammenfassungsbildschirms.

// DV/FP-Einstellungen
#define P_SUMMARY_SCREEN_IV_EV_INFO      FALSE  // Wenn TRUE, kann der Spieler zwischen Statuswerten, DVs und FPs auf der Fertigkeiten-Seite des Zusammenfassungsbildschirms wechseln.
#define P_SUMMARY_SCREEN_IV_EV_BOX_ONLY  FALSE  // Wenn TRUE, kann der Spieler zwischen Statuswerten, DVs und FPs auf der Fertigkeiten-Seite des Zusammenfassungsbildschirms wechseln, aber nur in der PC-Lagerbox.
#define P_SUMMARY_SCREEN_IV_HYPERTRAIN   TRUE   // Wenn TRUE, werden hypertrainierte Statuswerte als 31/S angezeigt, wenn sie im Zusammenfassungsbildschirm betrachtet werden.
#define P_SUMMARY_SCREEN_IV_EV_TILESET   FALSE  // Wenn TRUE, lädt ein alternatives Tileset, um das Ändern der "STATUSWERTE"-Bezeichnung auf der Fertigkeiten-Seite des Zusammenfassungsbildschirms zu ermöglichen. Hinweis: Falls nach dem Ändern und Neukompilieren immer noch das alternative Tileset geladen wird, benötigen Sie möglicherweise ein `make clean` vor der Kompilierung.
#define P_SUMMARY_SCREEN_IV_EV_VALUES    FALSE  // Wenn TRUE, wird der tatsächliche DV-Wert anstelle der Buchstabenbewertung angezeigt.
/*
LETTER GRADE GUIDE:

    F = 0
    D = 1 - 15
    C = 16 - 25
    B = 26 - 29
    A = 30
    S = 31

Info taken from https://bulbapedia.bulbagarden.net/wiki/Stats_judge.
*/
#define P_SUMMARY_SCREEN_IV_ONLY         FALSE  // Wenn TRUE, wird nur DV-Info im Zusammenfassungsbildschirm angezeigt.
#define P_SUMMARY_SCREEN_EV_ONLY         FALSE  // Wenn TRUE, wird nur FP-Info im Zusammenfassungsbildschirm angezeigt.

// DV/FP-Flags
#define P_FLAG_SUMMARY_SCREEN_IV_EV_INFO 0      // Wenn dieses Flag gesetzt ist, ermöglicht es dem Spieler zwischen Statuswerten, DVs und FPs auf der Fertigkeiten-Seite des Zusammenfassungsbildschirms zu wechseln. Hinweis: wenn P_SUMMARY_SCREEN_IV_EV_INFO TRUE ist, bewirkt dieses Flag nichts.

// Attacken-Wiedererlernen-Einstellungen
#define P_ENABLE_MOVE_RELEARNERS         FALSE   // Wenn TRUE, aktiviert Attacken-Wiedererlernen für Ei-, TM- und Tutor-Attacken. (siehe unten für spezifische Konfigurationen/Flags)
#define P_SORT_MOVES                     FALSE   // Wenn TRUE, sortiert alle Attacken alphabetisch in der Liste des Wiedererlerners.

// Level-Up-Wiedererlernen
#define P_PRE_EVO_MOVES                  TRUE   // Wenn TRUE, ermöglicht es dem Pokémon, Attacken seiner Vorentwicklung zu erlernen.
#define P_ENABLE_ALL_LEVEL_UP_MOVES      FALSE   // Wenn TRUE, ermöglicht es dem Pokémon, alle Level-Up-Attacken zu erlernen, unabhängig von seinem Level.

// TM-Wiedererlernen
#define P_TM_MOVES_RELEARNER             TRUE    // Wenn TRUE, aktiviert Maschinen-Attacken-Wiedererlernen.
#define P_ENABLE_ALL_TM_MOVES            FALSE   // Wenn TRUE, ermöglicht es dem Pokémon, alle TMs zu erlernen, mit denen es kompatibel ist, unabhängig davon, ob sie im Beutel sind.

// Wiedererlernen-Flags - Überflüssig wenn P_ENABLE_MOVE_RELEARNERS TRUE ist, aber trotzdem hier hinzugefügt, falls Sie nicht alle Wiedererlernen gleichzeitig freischalten möchten.
// Um die folgenden Features in Skripten zu verwenden, ersetzen Sie die 0en mit der Flag-ID, die Sie zuweisen.
// Z.B.: Ersetzen mit FLAG_UNUSED_0x264, damit Sie dieses Flag verwenden können, um das Feature zu aktivieren.
#define P_FLAG_EGG_MOVES                 0       // Wenn dieses Flag gesetzt ist, aktiviert Ei-Attacken-Wiedererlernen.
#define P_FLAG_TUTOR_MOVES               0       // Wenn dieses Flag gesetzt ist, aktiviert Tutor-Attacken-Wiedererlernen.

// Attacken-Wiedererlernen im Zusammenfassungsbildschirm
#define P_SUMMARY_SCREEN_MOVE_RELEARNER  TRUE   // Wenn TRUE, zeigt eine Option für Pokémon an, Attacken auf der Attacken-Seite des Zusammenfassungsbildschirms wiederzuerlernen.
#define P_SUMMARY_MOVE_RELEARNER_FULL_PP TRUE   // Wenn TRUE, stellt der Attacken-Wiedererlernen im Zusammenfassungsbildschirm die AP wiederlernter Attacken vollständig wieder her.

// Attacken-Wiedererlernen im Team-Menü
#define P_PARTY_MOVE_RELEARNER           FALSE  // Wenn TRUE, aktiviert den Attacken-Wiedererlernen im Team-Menü.

#endif // GUARD_CONFIG_SUMMARY_SCREEN_H
