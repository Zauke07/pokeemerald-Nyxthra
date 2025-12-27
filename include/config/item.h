#ifndef GUARD_CONFIG_ITEM_H
#define GUARD_CONFIG_ITEM_H

// Item config
#define I_SHINY_CHARM_ADDITIONAL_ROLLS  2           // Anzahl zusätzlicher Shiny-Würfe, wenn der Spieler den Shiny-Charm besitzt. Auf 0 setzen, um die Wirkung des Shiny-Charm zu deaktivieren.
#define I_KEY_FOSSILS                   GEN_LATEST  // Ab Gen4+ wurden alle Gen3-Fossilien zu normalen Items.
#define I_KEY_ESCAPE_ROPE               GEN_LATEST  // Ab Gen8 ist das Fluchtseil ein Schlüssel-Item. Beachte: Es ist dann kostenlos in Shops erhältlich.
#define I_HEALTH_RECOVERY               GEN_LATEST  // Ab Gen7+ stellen bestimmte Heilitems eine andere Menge an KP wieder her als zuvor.
#define I_SITRUS_BERRY_HEAL             GEN_LATEST  // Ab Gen4+ heilt die Sitrusbeere 25% der maximalen KP statt 30 KP.
#define I_VITAMIN_EV_CAP                GEN_LATEST  // Ab Gen8+ haben Vitamine kein EV-Limit von 100 pro Wert mehr.
#define I_BERRY_EV_JUMP                 GEN_LATEST  // Nur in Gen4: EV-senkende Beeren setzen den EV-Wert auf 100, falls er darüber liegt.
#define I_GRISEOUS_ORB_FORM_CHANGE      GEN_LATEST  // Ab Gen9+ ändert die Griseous-Orb Giratinas Form nicht mehr, wenn sie getragen wird.
#define I_GEM_BOOST_POWER               GEN_LATEST  // Ab Gen6+ wurde der Kraftschub von Juwelen von 50% auf 30% reduziert.
#define I_USE_EVO_HELD_ITEMS_FROM_BAG   TRUE       // Wenn TRUE, können Entwicklungsitems wie Rasierklaue oder Stromisierer direkt aus der Tasche zum Entwickeln verwendet werden (wie in LA).
#define I_TYPE_BOOST_POWER              GEN_LATEST  // Ab Gen4+ wurde die Kraft aller normalen Typ-Verstärker-Items von 10% auf 20% erhöht (z.B. Holzkohle).
#define I_SELL_VALUE_FRACTION           GEN_LATEST  // Ab Gen9+ verkaufen sich Items nur noch für 1/4 ihres Wertes statt für die Hälfte.
#define I_PRICE                         GEN_LATEST  // Einige Items haben ihren Wert über die Generationen hinweg verändert.
#define I_BERRY_PRICE                   GEN_7       // Da Beeren ab Gen8+ nicht mehr gepflanzt werden können, ist ihr Preis gestiegen.
#define I_POWER_ITEM_BOOST              GEN_LATEST  // Ab Gen7+ geben Kraftitems 8 EVs statt 4 EVs.
#define I_PREMIER_BALL_BONUS            GEN_LATEST  // Ab LGPE (Gen8+) erhält man für je 10 beliebige Pokébälle in einem Kauf einen Premierball. Früher galt das nur für normale Pokébälle und nur 1 pro Kauf.
#define I_ROTOM_CATALOG_THUNDER_SHOCK   GEN_LATEST  // Ab Gen9+ lernt Rotom beim Zurücksetzen in die Basisform Donnerschock, auch wenn es schon 4 Attacken hat.
#define I_REPEL_INCLUDE_FAINTED         GEN_LATEST  // In Gen1 und Gen6+ wird für Schutz-Items immer das Level des ersten Teammitglieds verwendet, auch wenn es besiegt ist. In Gen2-5 zählt nur das erste nicht besiegte Pokémon.

// TM config
#define I_REUSABLE_TMS          FALSE       // In Gen5-8 sind TMs wiederverwendbar. TRUE macht alle Standard-TMs wiederverwendbar, kann aber auch einzeln über die Wichtigkeit gesteuert werden.

// Exp. Share config
// Um dieses Feature zu nutzen, ersetze die 0 durch die Flag-ID, die du zuweist.
// Beispiel: Ersetze durch FLAG_UNUSED_0x264, um diese Flag zum Umschalten zu verwenden.
#define I_EXP_SHARE_FLAG        FLAG_EXP_SHARE           // Wenn diese Flag gesetzt ist, erhalten alle Pokémon im Team Erfahrung, unabhängig davon, ob sie am Kampf teilgenommen haben.
#define I_EXP_SHARE_ITEM        GEN_6                       // Ab Gen6+ wurde der EP-Teiler von einem gehaltenen Item zu einem Schlüssel-Item, das den oben beschriebenen Effekt aktiviert.

// Repel/Lure config
// Diese beiden Einstellungen sind unabhängig und ergänzen sich.
#define VAR_LAST_REPEL_LURE_USED    VAR_REPEL_LURE_MENU       // Wenn diese Variable gesetzt ist, wird das zuletzt verwendete Schutz-/Lockmittel gespeichert und der Spieler bekommt die Standard-Schutzabfrage, außer I_REPEL_LURE_MENU ist TRUE.
#define I_REPEL_LURE_MENU           FALSE    // Wenn TRUE, kann der Spieler auswählen, welches Schutz-/Lockmittel er nach Ablauf verwenden möchte. Die Cursorposition wird von VAR_LAST_REPEL_LURE_USED gespeichert, falls nicht 0.

// Vs. Seeker
#define I_VS_SEEKER_CHARGING        0     // Falls diese Flag zugewiesen wird, wird die Vs. Seeker Funktionalität aktiviert. Wenn der Spieler den Vs. Seeker hat, funktionieren die Kampfanruf-Rückkampf-Funktionen nicht mehr. Dokumentation für den Vs. Seeker findet sich in docs/tutorials/vs_seeker.md.

// ORAS Detektor
#define I_ORAS_DOWSING_FLAG         FLAG_ORAS_DOWSING  // Ersetze 0 durch eine unbenutzte Flag, um den Detektor-Mechanismus aus ORAS zu aktivieren.
#define I_ORAS_DOWSING_SOUNDS       TRUE        // Wenn TRUE, gibt der Detektor Geräusche basierend auf der Entfernung zum versteckten Item ab.
#define I_ORAS_DOWSING_COLOR_PAL    15          // Die Farbe innerhalb der Palette, die sich basierend auf der Nähe zum Item ändert.
// Farbwerte für die ORAS Detektor-Entfernungen/Animationen
#define I_ORAS_DOWSING_COLOR_NONE   RGB_GRAY
#define I_ORAS_DOWSING_COLOR_SLOW   RGB2GBA(56, 120, 255)
#define I_ORAS_DOWSING_COLOR_NORMAL RGB2GBA(24, 216, 24)
#define I_ORAS_DOWSING_COLOR_FAST   RGB2GBA(255, 255, 40)
#define I_ORAS_DOWSING_COLOR_FASTER RGB_RED

#endif // GUARD_CONFIG_ITEM_H
