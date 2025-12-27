#ifndef GUARD_CONFIG_SAVE_H
#define GUARD_CONFIG_SAVE_H

// SaveBlock1 configs
#define FREE_EXTRA_SEEN_FLAGS_SAVEBLOCK1    FALSE   // Gib unbenutzte Pokédex-Gesehen-Flags frei (52 Bytes).
#define FREE_TRAINER_HILL                   FALSE   // Gibt Trainer Hill Daten frei (28 Bytes).
#define FREE_MYSTERY_EVENT_BUFFERS          FALSE   // Gibt ramScript frei (1104 Bytes).
#define FREE_MATCH_CALL                     FALSE   // Gibt Match Call und Rematch / VS Seeker Daten frei. (104 Bytes).
#define FREE_UNION_ROOM_CHAT                TRUE    // Gibt Union Room Chat frei (212 Bytes).
#define FREE_ENIGMA_BERRY                   FALSE   // Gibt E-Reader Enigma Berry Daten frei (52 Bytes).
#define FREE_LINK_BATTLE_RECORDS            TRUE    // Gibt Link Battle Record Daten frei (88 Bytes).
#define FREE_MYSTERY_GIFT                   FALSE   // Gibt Mystery Gift Daten frei (876 Bytes).
                                            // SaveBlock1 gesamt: 2516 Bytes
// SaveBlock2 Konfigurationen
#define FREE_BATTLE_TOWER_E_READER          TRUE    // Gibt Battle Tower E-Reader Daten frei (188 Bytes).
#define FREE_POKEMON_JUMP                   FALSE   // Gibt Pokémon Jump Daten frei (16 Bytes).
#define FREE_RECORD_MIXING_HALL_RECORDS     TRUE   // Gibt Hall Records für Record Mixing frei (1032 Bytes).
#define FREE_EXTRA_SEEN_FLAGS_SAVEBLOCK2    FALSE   // Gib unbenutzte Pokédex-Gesehen-Flags frei (108 Bytes).
                                            // SaveBlock2 gesamt: 1274 Bytes

                                            // Grand Total: 3790

#endif // GUARD_CONFIG_SAVE_H
