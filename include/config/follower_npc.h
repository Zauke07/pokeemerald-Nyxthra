#ifndef GUARD_FOLLOWER_NPC_OVERWORLD_H
#define GUARD_FOLLOWER_NPC_OVERWORLD_H

// NPC Followers
#define FNPC_ENABLE_NPC_FOLLOWERS                 FALSE // Aktiviert die Verwendung von Skript-Makros, um NPCs zu bestimmen, die dem Spieler folgen, DPP-Stil. Erhöht die Größe des Saveblocks (SaveBlock3) geringfügig.
#define FNPC_FLAG_HEAL_AFTER_FOLLOWER_BATTLE      0     // Ersetze die 0 mit einer Flagge, um diese Flagge zu verwenden, um zu schalten, ob die Gruppe des Spielers nach jedem Follower-Partner-Kampf automatisch geheilt wird. Wenn du möchtest, dass dies immer aktiv ist ohne eine Flagge zu verwenden, ersetze 0 mit FNPC_ALWAYS.
#define FNPC_FLAG_PARTNER_WILD_BATTLES            0     // Ersetze die 0 mit einer Flagge, um diese Flagge zu verwenden, um zu schalten, ob der Follower-Partner dir bei wilden Kämpfen beitritt. Wenn du möchtest, dass dies immer aktiv ist ohne eine Flagge zu verwenden, ersetze 0 mit FNPC_ALWAYS.
#define FNPC_NPC_FOLLOWER_WILD_BATTLE_VS_2        TRUE  // Wenn auf TRUE gesetzt, werden zwei wilde Pokemon im Partner-Kampf erscheinen anstatt nur eines.
#define FNPC_NPC_FOLLOWER_PARTY_PREVIEW           TRUE  // Wenn auf TRUE gesetzt, wird eine Vorschau der Spieler- und Partner-Teams vor jedem Trainer-Kampf gezeigt.
#define FNPC_FACE_NPC_FOLLOWER_ON_DOOR_EXIT       TRUE  // Wenn auf TRUE gesetzt, wird sich der Spieler dem Follower zuwenden, wenn er durch eine Tür hinausgeht.
#define FNPC_NPC_FOLLOWER_SHOW_AFTER_LEAVE_ROUTE  TRUE  // Wenn auf TRUE gesetzt, wird der Follower wieder erscheinen und aus dem Spieler herauslaufen nach der Verwendung von Fliegen, Fluchtseil oder Teleport.

#endif // GUARD_FOLLOWER_NPC_OVERWORLD_H
