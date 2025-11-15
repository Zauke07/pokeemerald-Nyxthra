#ifndef GUARD_CONFIG_DEXNAV_H
#define GUARD_CONFIG_DEXNAV_H

#define DEXNAV_ENABLED                FALSE  // Ob DexNav aktiviert ist oder nicht. Falls TRUE, müssen alle Flags/Vars unten ungleich null sein
#define USE_DEXNAV_SEARCH_LEVELS      FALSE  /* WARNUNG: ÜBERSCHREITET MÖGLICHERWEISE SAVEBLOCK-SPEICHERPLATZ! BENÖTIGT 1 BYTE PRO SPEZIES */

// Flag/Var-Definitionen
#define DN_FLAG_SEARCHING             0 // Suche nach Mon
#define DN_FLAG_DEXNAV_GET            0 // DexNav wird im Startmenü angezeigt
#define DN_FLAG_DETECTOR_MODE         0 // Erlaubt dem Spieler versteckte Mons zu finden
#define DN_VAR_SPECIES                0 // Registrierte DexNav-Spezies
#define DN_VAR_STEP_COUNTER           0 // Schritte zum Finden versteckter Pokemon

// Suchparameter
#define DEXNAV_TIMEOUT                  15  // 15 Sekunden ist das Timeout. Maximum von 1092 Sekunden erlaubt
#define SNEAKING_PROXIMITY              4   // Anzahl Felder
#define CREEPING_PROXIMITY              2
#define MAX_PROXIMITY                   20

#define DEXNAV_CHAIN_MAX                100 // maximaler Kettenwert

// Versteckte Pokemon-Optionen - eine Annäherung der Werte aufgrund mangelnder verfügbarer Daten
#define HIDDEN_MON_STEP_COUNT       100  // Suche alle x Schritte nach versteckten Pokemon
#define HIDDEN_MON_SEARCH_RATE      25   // x% Chance versteckte Pokemon alle x Schritte zu finden
#define HIDDEN_MON_PROBABILTY       15   // x% Chance versteckte Mon zu finden verglichen mit regulären Begegnungsdaten

//// SEARCH PROBABILITIES
// See https://bulbapedia.bulbagarden.net/wiki/DexNav#Benefits
// Chance of encountering egg move at search levels
#define SEARCHLEVEL0_MOVECHANCE         0
#define SEARCHLEVEL5_MOVECHANCE         21
#define SEARCHLEVEL10_MOVECHANCE        46
#define SEARCHLEVEL25_MOVECHANCE        58
#define SEARCHLEVEL50_MOVECHANCE        63
#define SEARCHLEVEL100_MOVECHANCE       83
// Chance of encountering Hidden Abilities at search levels
#define SEARCHLEVEL0_ABILITYCHANCE      0
#define SEARCHLEVEL5_ABILITYCHANCE      0
#define SEARCHLEVEL10_ABILITYCHANCE     5
#define SEARCHLEVEL25_ABILITYCHANCE     15
#define SEARCHLEVEL50_ABILITYCHANCE     20
#define SEARCHLEVEL100_ABILITYCHANCE    23
// Chance of encountering held item
#define SEARCHLEVEL0_ITEM               0
#define SEARCHLEVEL5_ITEM               0
#define SEARCHLEVEL10_ITEM              1
#define SEARCHLEVEL25_ITEM              7
#define SEARCHLEVEL50_ITEM              6
#define SEARCHLEVEL100_ITEM             12
// Chance of encountering one star potential
#define SEARCHLEVEL0_ONESTAR            0
#define SEARCHLEVEL5_ONESTAR            14
#define SEARCHLEVEL10_ONESTAR           17
#define SEARCHLEVEL25_ONESTAR           17
#define SEARCHLEVEL50_ONESTAR           15
#define SEARCHLEVEL100_ONESTAR          8
// Chance of encountering two star potential
#define SEARCHLEVEL0_TWOSTAR            0
#define SEARCHLEVEL5_TWOSTAR            1
#define SEARCHLEVEL10_TWOSTAR           9
#define SEARCHLEVEL25_TWOSTAR           16
#define SEARCHLEVEL50_TWOSTAR           17
#define SEARCHLEVEL100_TWOSTAR          24
// Chance of encountering three star potential
#define SEARCHLEVEL0_THREESTAR          0
#define SEARCHLEVEL5_THREESTAR          0
#define SEARCHLEVEL10_THREESTAR         1
#define SEARCHLEVEL25_THREESTAR         7
#define SEARCHLEVEL50_THREESTAR         6
#define SEARCHLEVEL100_THREESTAR        12

#endif // GUARD_CONFIG_DEXNAV_H
