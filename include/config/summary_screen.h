#ifndef GUARD_CONFIG_SUMMARY_SCREEN_H
#define GUARD_CONFIG_SUMMARY_SCREEN_H

// Settings
#define P_SUMMARY_SCREEN_MOVE_RELEARNER  TRUE   // Wenn TRUE, zeigt eine Option für Pokémon an, Attacken im Zusammenfassungsbildschirm auf der Attacken-Seite wieder zu erlernen.
#define P_SUMMARY_SCREEN_NATURE_COLORS  TRUE    // Wenn TRUE, werden naturbasierte Statuswert-Erhöhungen und -Verringerungen rot und blau im Zusammenfassungsbildschirm angezeigt.
#define P_SUMMARY_MOVE_RELEARNER_FULL_PP TRUE   // Wenn TRUE, stellt der Attacken-Wiedererlerner im Zusammenfassungsbildschirm die AP wiedererlerter Attacken vollständig wieder her.
#define P_SUMMARY_SCREEN_RENAME          TRUE   // Wenn TRUE, ersetzt eine Option zum Ändern von Pokémon-Spitznamen die Abbrechen-Eingabeaufforderung auf der Info-Seite des Zusammenfassungsbildschirms.
#define P_SUMMARY_SCREEN_IV_EV_INFO      FALSE  // Wenn TRUE, ermöglicht es dem Spieler, zwischen Status, DVs und FPs auf der Fähigkeiten-Seite des Zusammenfassungsbildschirms zu wechseln.
#define P_SUMMARY_SCREEN_IV_EV_BOX_ONLY  FALSE  // Wenn TRUE, ermöglicht es dem Spieler, zwischen Status, DVs und FPs auf der Fähigkeiten-Seite des Zusammenfassungsbildschirms zu wechseln, aber nur in der PC-Lagerbox.
#define P_SUMMARY_SCREEN_IV_EV_TILESET   FALSE  // Wenn TRUE, lädt ein alternatives Tileset, um das Ändern des "STATS"-Labels auf der Fähigkeiten-Seite des Zusammenfassungsbildschirms zu ermöglichen. Hinweis: Falls es nach dem Ändern und Neukompilieren immer noch das alternative Tileset lädt, benötigen Sie möglicherweise ein `make clean` vor der Kompilierung.
#define P_SUMMARY_SCREEN_IV_EV_VALUES    FALSE  // Wenn TRUE, wird der tatsächliche DV-Wert anstelle der Buchstabennote angezeigt.
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

// Flags
#define P_FLAG_SUMMARY_SCREEN_IV_EV_INFO 0      // Wenn dieses Flag gesetzt ist, ermöglicht es dem Spieler, zwischen Status, DVs und FPs auf der Fähigkeiten-Seite des Zusammenfassungsbildschirms zu wechseln. Hinweis: Falls P_SUMMARY_SCREEN_IV_EV_INFO TRUE ist, bewirkt dieses Flag nichts.

#endif // GUARD_CONFIG_SUMMARY_SCREEN_H
