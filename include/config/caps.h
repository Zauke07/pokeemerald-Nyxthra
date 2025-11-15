#ifndef GUARD_CONFIG_CAPS_H
#define GUARD_CONFIG_CAPS_H

// Level Cap Konstanten
#define EXP_CAP_NONE                    0 // Normales Verhalten, kein Level-Cap aktiv
#define EXP_CAP_HARD                    1 // Pokémon mit Level >= Cap erhalten keine EP
#define EXP_CAP_SOFT                    2 // Pokémon mit Level >= Cap erhalten reduzierte EP

#define LEVEL_CAP_NONE                  0 // Kein Level-Cap; nur wirksam, wenn B_EXP_CAP_TYPE = EXP_CAP_NONE
#define LEVEL_CAP_FLAG_LIST             1 // Level-Cap wird nach dem ersten UNGESETZTEN Flag in `sLevelCapFlagMap` gewählt
#define LEVEL_CAP_VARIABLE              2 // Level-Cap kommt aus der in B_LEVEL_CAP_VARIABLE angegebenen Event-Variable

// Level-Cap Konfiguration
#define B_EXP_CAP_TYPE                  EXP_CAP_NONE   // [EXP_CAP_NONE, EXP_CAP_HARD, EXP_CAP_SOFT] Art des EP/Level-Caps
#define B_LEVEL_CAP_TYPE                LEVEL_CAP_NONE // [LEVEL_CAP_NONE, LEVEL_CAP_FLAG_LIST, LEVEL_CAP_VARIABLE] Methode zur Bestimmung des Level-Caps
#define B_LEVEL_CAP_VARIABLE            0 // Event-Variable fürs Level-Cap, falls B_LEVEL_CAP_TYPE = LEVEL_CAP_VARIABLE

#define B_RARE_CANDY_CAP                FALSE // TRUE: Sonderbonbons können nicht über den Level-Cap hinaus benutzt werden
#define B_LEVEL_CAP_EXP_UP              FALSE // TRUE: Unterhalb des Caps erhalten Mons mehr EP

// EV-Cap Konstanten
#define EV_CAP_NONE                     0 // Normales Verhalten, kein EV-Cap aktiv
#define EV_CAP_FLAG_LIST                1 // EV-Cap wird nach dem ersten UNGESETZTEN Flag in `sEVCapFlagMap` gewählt
#define EV_CAP_VARIABLE                 2 // EV-Cap kommt aus der in B_EV_CAP_VARIABLE angegebenen Event-Variable
#define EV_CAP_NO_GAIN                  3 // Es können keine EVs gewonnen werden

// EV-Cap Konfiguration
#define B_EV_CAP_TYPE                   EV_CAP_NONE   // [EV_CAP_NONE, EV_CAP_FLAG_LIST, EV_CAP_VARIABLE, EV_CAP_NO_GAIN] Art des EV-Caps
#define B_EV_CAP_VARIABLE               8            // Event-Variable fürs EV-Cap, falls B_EV_CAP_TYPE = EV_CAP_VARIABLE

#define B_EV_ITEMS_CAP                  FALSE // TRUE: EV-steigernde Items können nicht über den EV-Cap hinaus verwendet werden

#endif /* GUARD_CONFIG_CAPS_H */
