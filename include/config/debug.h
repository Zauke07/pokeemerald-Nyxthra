#ifndef GUARD_CONFIG_DEBUG_H
#define GUARD_CONFIG_DEBUG_H

// Overworld-Debug
#define DEBUG_OVERWORLD_MENU            TRUE                // Aktiviert ein Overworld-Debug-Menü zum Setzen von Flags/Variablen, Pokémon geben u. a.; Standardaufruf: R halten und START drücken.
#define DEBUG_OVERWORLD_HELD_KEYS       (R_BUTTON)          // Tasten, die gehalten werden müssen, um das Debug-Menü zu öffnen.
#define DEBUG_OVERWORLD_TRIGGER_EVENT   pressedStartButton  // Ereignis, das beim Halten der oben definierten Tasten das Menü öffnet.
#define DEBUG_OVERWORLD_IN_MENU         TRUE                // Ersetzt die Tastenkombi durch einen Eintrag im Startmenü (über dem Pokédex).

// Kampf-Debug-Menü
#define DEBUG_BATTLE_MENU               TRUE    // TRUE: Aktiviert ein Debug-Menü im Kampf. Aufruf mit SELECT.
#define DEBUG_AI_DELAY_TIMER            FALSE   // TRUE: Zeigt die Frame-Anzahl bis zur AI-Zugwahl an. Ersetzt „Was soll PKMN tun“. Nützlich für AI-Performance-Checks.

// Pokémon-Debug
#define DEBUG_POKEMON_SPRITE_VISUALIZER TRUE    // TRUE: Aktiviert ein Debug-Menü für Pokémon-Sprites und -Icons. Aufruf mit SELECT im Statusbildschirm.

#endif // GUARD_CONFIG_DEBUG_H
