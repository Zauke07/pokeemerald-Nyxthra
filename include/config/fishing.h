#ifndef GUARD_CONFIG_FISHING_H
#define GUARD_CONFIG_FISHING_H

#define I_FISHING_BITE_ODDS         GEN_LATEST // In Gen 1 und Gen 2 hat die Angel eine 100%ige Chance auf einen Biss, die Profi-Angel hat eine 66%ige Chance auf einen Biss und die Super-Angel hat eine 50%ige Chance auf einen Biss. In Gen 3 haben alle Angeln eine Basis-Chance von 50% auf einen Biss. In Gen 4 und später hat die Angel eine Basis-Chance von 25% auf einen Biss, die Profi-Angel hat eine 50%ige Chance auf einen Biss und die Super-Angel hat eine 75%ige Chance auf einen Biss.
#define I_FISHING_MINIGAME          GEN_3      // Jede Generation verwendet eine Variation des Einholens von Pokémon, sobald sie angebissen haben. HINWEIS: Nur die Gen 1/2 und Gen 3 Minispiele sind momentan implementiert!
#define I_FISHING_ENVIRONMENT       GEN_LATEST // In Gen 3 basiert die Kampfumgebung beim Bekämpfen eines gehakten Pokémon auf dem Feld, auf dem der Spieler steht. In Gen 4 und später basiert die Umgebung auf dem Feld, in dem geangelt wird, was normalerweise zu einer Wasserumgebung führt.
#define I_FISHING_STICKY_BOOST      GEN_LATEST // In Gen 3 bewirkt ein Pokémon mit Saugnapf oder Klebehalten im ersten Slot der Gruppe, dass die Chance auf einen Biss um etwa 35% steigt. In Gen 4 und später verdoppelt es die Basis-Biss-Chance.
#define I_FISHING_FOLLOWER_BOOST    FALSE      // In HGSS werden die Angel-Biss-Chancen je nach Freundschaft des aktuell folgenden Pokémon erhöht.
#define I_FISHING_CHAIN             FALSE      // Eingeführt in XY, das wiederholte Haken desselben Pokémon erhöht die Chancen, dass dieses Mon schillernd ist. HINWEIS: Diese Implementierung ist eine Annäherung an die tatsächliche Funktion, da XY nicht gründlich dokumentiert oder datamined wurden.
#define I_FISHING_PROXIMITY         FALSE      // In XY wird die Biss-Chance durch die Anzahl der angrenzenden nicht-surfbaren Felder neben der Angelleine erhöht
#define I_FISHING_TIME_OF_DAY_BOOST FALSE      // In XY wird die Biss-Chance während Morgen und Abend erhöht

#endif // GUARD_CONFIG_FISHING_H
