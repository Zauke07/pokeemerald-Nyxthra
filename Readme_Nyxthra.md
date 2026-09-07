# Pokémon Nyxthra - Beta 1.3.0

Pokémon Nyxthra ist eine deutschsprachige Modifikation auf Basis von pokeemerald-expansion (v1.16.3) mit eigener Story, neuen Systemen und stark erweitertem Gameplay.

Basisprojekt (RHH):  
https://github.com/rh-hideout/pokeemerald-expansion

---

## 🧪 Projektstatus

- Projektstart: 01.01.2024
- Basis: pokeemerald-expansion v1.16.3
- Aktuelle Nyxthra-Version: Beta 1.3.0
- Sprache: Deutsch
- Status: Erste öffentliche Beta

---

## ✨ Features & Änderungen

### 🎮 Gameplay & Story
- Teilweise überarbeitete Hauptstory mit eigenen Dialogen, Events und Szenen
- Neue Trainer, Teams und Begegnungen über mehrere Generationen hinweg
- Überarbeitetes Balancing für Levelkurve, KI und Kampfverlauf
- Freie Starterwahl: Starter aus Gen 1-9 statt klassischer Hoenn-Auswahl

### 🐉 Legendäre & besondere Begegnungen
- Jirachi: verborgen in einem rissigen weißen Stein in Mossdeep City - bricht erst nach einem bestimmten Fortschritt auf; entkommt es beim ersten Versuch, roamt es danach frei durch Hoenn
- Schillerndes Metagross als statische Begegnung in Granite Cave B6F
- Lavados (Moltres): verstecktes Legendary im Mystery Hole
- Mewtwo-Statue auf Route 119 (Mystery): erwacht nach Berührung zu einem echten Kampf
- Celebi in der Verborgenen Lichtung - ein zweites, eigenständiges Celebi-Event zusätzlich zum regulären Celebi-Encounter
- Uxie am Scorched Slab Secret *(vorläufig - dient aktuell als Platzhalter für Selfe/Mesprit, die noch nicht fertig implementiert ist; wird ersetzt, sobald Selfe fertig ist)*
- Arktos (Articuno) in Meteor Falls B1F: in Vanilla Emerald eigentlich gar nicht fangbar, hier neu als Begegnung ergänzt
- Easter Egg: geheimer Postgame-Trainer "ChatGPT" in Blütenburg City (nach Liga-Sieg) mit eigenem, überstarkem KI-Team

### 🎲 Randomizer & Progression
- Eigenes Challenge-Modus-Menü im Hauptmenü (vor den Optionen): aktuell Heimat für den Warp-Randomizer, weitere Herausforderungs-Regeln sind als "Coming soon" vorgemerkt
- Integriertes Randomizer-Setup direkt vor Spielstart
- Randomisierbare Wild-, Trainer-, Starter-, Evolutions-, Geschenk- und statische Pokémon
- Randomisierbare Feld-Items, versteckte Items, Shops sowie NPC-Itemgeschenke mit kontextabhängiger Zuordnung
- Separat randomisierbare TM-Attacken bei weiterhin fixen VMs
- Optional randomisierbare Attacken-AP, Attacken-Stärke, Lernsets, Fähigkeiten und Basiswerte
- Schutz wichtiger Progressions-Items: Keine Randomisierung von Key-Items, Platzhalter-Items oder VM/HM-Items
- Nationaldex wird direkt beim ersten Erhalt des Pokédex freigeschaltet
- Legendäre und statische Begegnungen wurden für das neue Encounter-System angepasst

### 🌞 Tag/Nacht, Uhr & Overworld
- DNS-System (Day/Night) auf Nyxthra angepasst
- Uhrzeit-Anzeige direkt im Startmenü (eigene Implementierung)
- Dynamische Lichtquellen in der Overworld
- Mehrere Stabilitätsfixes für Overworld-/Licht-Handling (u. a. Freeze-Fixes in Städten)

### 👤 Stylesystem statt Geschlechterwahl
- Komplettes Style-System als Kernmechanik
- Verfügbare Styles zu Spielbeginn (aktuell 20):
  - Brix (Brendan)
  - Mai (May)
  - Red
  - Leaf
  - Ethan
  - Lyra
  - Lukas (Lucas)
  - Lucia (Dawn)
  - Warren (Hilbert)
  - Lotta (Hilda)
  - Nate
  - Rosy (Rosa)
  - Kalem
  - Serena
  - Elio
  - Selene
  - Victor
  - Gloria
  - Florian
  - Juliana
- Rivalen, Dialoge und Eventabläufe reagieren dynamisch auf den gewählten Style
- Aktueller Grafikstatus (Beta 1.3.0):
  - Vollständig mit allen Grafikzuständen: Brix, Mai, Red, Leaf, Ethan, Lyra, Lucas, Dawn
  - Calem ist vollständig, außer bei Fahrrad-Zuständen (Eilrad/Kunstrad), dort wird Fallback genutzt
  - Alle übrigen Styles nutzen aktuell je nach Zustand Fallback-Grafiken, bis die finalen Assets fertig sind
  - Warren (Hilbert) und Lotta (Hilda): eigener Rücken-Sprite im Kampf aktualisiert (vorher teils fehlerhafte/veraltete Grafik); alle anderen Zustände nutzen weiterhin Fallback, bis auch die fertig sind
  - Taucher-Zustand (Unterwasser) nutzt derzeit für alle Styles einen stabilen Fallback auf Brix bzw. Mai
  - Rivalen-Fallback (nur für Elio, Florian, Gloria, Juliana, Nate, Rosa, Selene, Serena, Victor): nur Field Move sowie beide Fahrräder über Rival-Brendan/Rival-May-Fallback; sonst bleiben die normalen Zustände erhalten

### ⚙️ Komfortfunktionen
- Spitznamen-Dialog beim Fangen/Erhalten optional überspringbar
- Dauerhaftes Rennen im Optionsmenü konfigurierbar:
  - Halten
  - Umschalten

### 🧠 Technische Erweiterungen
- Eigenes Stylesystem vollständig in den Code integriert
- 50+ neue Scripts und zusätzliche Funktionslogik
- Geschlechterbasierte Checks weitgehend vereinheitlicht/ersetzt
- Neue Grafiken, Paletten und Overworld-Sprites eingebunden
- Fallback-Logik für fehlende Form-/Style-Grafiken, Paletten und Icons eingebunden

---

## 🆕 Neu in Beta 1.3.0

- Update auf pokeemerald-expansion v1.16.3 (vorher v1.15.0)
  - Hinweis: Upstream hat vor Kurzem v1.17.0 veröffentlicht - das Update darauf folgt zu einem späteren Zeitpunkt
- Neue Nyxthra-Prolog-Cutscene vor Prof. Birks Rede (läuft bei jedem neuen Spiel einmal ab):
  - Eigene Intro-Textkarten zur Vorgeschichte, gefolgt von der klassischen Groudon/Kyogre/Rayquaza-Szene
  - Neue "Legendäre Energie"-Sequenz: Groudon, Kyogre und Rayquaza reagieren nacheinander mit ihren jeweiligen Kampf-Übergangseffekten auf etwas Unbekanntes, bevor eine finale Energie-Entladung die Szene beendet
  - Eigenes Titel-Logo mit Versionsbanner statt reinem Textbildschirm vor der Übergabe an Prof. Birk
  - Mehrere Freeze-/Darstellungsfehler in der "Legendäre Energie"-Sequenz behoben (u. a. Aufhänger nach Rayquazas Reaktion, Speicherleck bei wiederholtem Szenenaufbau)
- Ever Grande City (Champions-Zimmer) komplett überarbeitet:
  - Ein fixer Champion (Mai oder Brix, abhängig vom gewählten Charakter-Style) ersetzt Wallace als eigentlichen Endgegner der Liga, mit eigenem Kampfteam (geteilte Hoenn-Starter-Endstufen plus drei starke Hoenn-Pokémon, kein Mega-Entwicklung)
  - Der tatsächliche dynamische Rivale (abhängig vom eigenen Style) bleibt als separate Figur erhalten und trifft weiterhin erst nach dem Champion-Kampf ein
- Petalburg-Arena Story-Rework:
  - Norman ist im Zuge der Nyxthra-Story gestorben; sein bester Freund und langjähriger Rivale Marek hat die Arena als neuer Arenaleiter übernommen
  - Beim allerersten Arena-Besuch taucht anstelle von Heikos altem Fang-Tutorial überraschend der Champion auf (mit Ausrufezeichen-Auftritt), der zufällig vorbeischaut, um nach Marek zu sehen
  - Ausführlicher neuer Dialog: Der Champion erzählt von einer Erinnerung an den Spieler als Baby (die genannte Region richtet sich dynamisch nach dem gewählten Charakter-Style), Marek erzählt Hintergrundgeschichten über den verstorbenen Vater (mit ein paar humorvollen Seitenhieben), und am Ende gibt's einen dezenten, nicht explizit erklärten Hinweis darauf, dass der Champion mehr ist, als er/sie zunächst scheint
  - Der Champion zeigt dem Spieler danach automatisch (nicht spielergesteuert, wie bei Heikos Original-Tutorial) das Fangen mit dem eigenen Starter - korrekter Sprite, Name und Kampfansage je nach Champion
- Lilycove Kaufhaus: zwei neue Verkäufer im 2. Stock
  - Ein Verkäufer bietet alle verfügbaren Mega-Steine an
  - Ein Verkäufer bietet alle klassischen Entwicklungssteine an
- Dark Mode: größerer, systemweiter Fix
  - Normale NPC-Dialoge zeigten bisher fälschlicherweise noch die helle statt die dunkle Textfarbe - betraf praktisch jeden normalen Dialog im Spiel, nicht nur einzelne Bildschirme
  - Schattenfarbe bei der Geschlechts-/Charakterauswahl zu Spielbeginn korrigiert (war weiß statt schwarz und dadurch schlecht lesbar)
- Charakter-Styles Hans/Brigitte in Brix/Mai umbenannt (Konsistenz mit dem neuen Champion-Feature)

## 🧩 Aktueller Dev-Stand (nach Beta 1.3.0)

- Overworld-Palettenfehler bei mehreren eigenen NPCs endgültig behoben (u. a. Opa/Gentleman, Barry, PokeKid):
  - Ursache: Die interne Suchfunktion für Objekt-Paletten hat ihren Ergebnis-Index auf 8 Bit begrenzt zurückgegeben. Da die Palettentabelle inzwischen über 256 Einträge hat, wurde bei allen neueren, weiter hinten stehenden NPCs der Index umgebrochen (z. B. Index 274 wurde zu 18) - dadurch wurde dauerhaft die Palette eines völlig anderen, aber gültigen Charakters geladen (Opa zeigte z. B. Mais Farben, Barry die von Groudons Spiegelbild, PokeKid die des Rivalen)
  - Betraf ausschließlich neuere, weiter hinten in der Tabelle stehende Charaktere - reguläre Standard-NPCs waren nie betroffen
  - Aaron hatte zusätzlich einen eigenen, unabhängigen Fehler (falscher Palettentag verwies auf eine generische Passanten-Palette statt auf seine eigene) - ebenfalls behoben
- Route 104: Der See beim Blumenladen (Pretty Petal) trocknet nach Groudons Erwachen (Dürre-Story) dauerhaft aus - eigene private Tileset-Kopie mit angepasster Erdton-Palette, wirkt sich ausschließlich auf Route 104 aus

## 🆕 Neu in Beta 1.1.5

- Surf-Bug behoben: Charaktere bleiben nicht mehr nach Kämpfen auf Fuß auf dem Wasser
- Pokédex-Anzeige korrigiert: Alle Formen werden jetzt korrekt in ihren individuellen Einträgen angezeigt, statt alle Formen als normales Pokémon zu zeigen
- Stabilitätsfixes für Pokédex-Formeinträge im Ruf-Screen (u. a. Alola, Hisui, Galar, Shadow)
- Ruf-Logik überarbeitet: Form-Sprite/-Name bleiben erhalten, während der Cry zuverlässig über die Basisform abgespielt wird
- Mehrere Absturz- und Darstellungsfehler im Pokédex-Ruf-Screen behoben
- Overworld-Style-Fallbacks überarbeitet, um Resets/Abstürze bei fehlenden Bewegungs-Sprites zu verhindern
- Rivalen-Zustände für moderne Styles gezielt abgesichert: Fallback nur bei Field Move und beiden Fahrrädern
- Pokémon-Boxen von 10 auf 12 erweitert
- Dark Mode (Alpha) eingebaut
  - Hinweis: Daran wird noch gearbeitet, da es bei einzelnen Anzeigen noch Darstellungsfehler gibt
- Trainerpass farblich angepasst
- Verbindungsschnur eingebaut
  - Ermöglicht Tauschentwicklungen ohne Tausch
- Fehler in `include/constants/event_objects.h` bereinigt, um Grafikfehler durch doppelte/inkonsistente IDs zu vermeiden
- Battle-Speed-Optionen für Wildkämpfe, Trainerkämpfe und wichtige Kämpfe wegen Bugs vorübergehend entfernt

## 🧩 Aktueller Dev-Stand (nach Beta 1.1.2)

- Challenge-Menü (Dark Mode) lesbarer gemacht: weiße Texte mit schwarzem Schatten, grüner Titel ebenfalls mit schwarzem Schatten
- Hauptmenü-Reihenfolge angepasst: Challenge-Menü steht vor Optionen, inklusive korrekter Cursor-/Rücksprunglogik
- Warp-Randomizer stabilisiert:
  - Dynamic-Warp-Indexing in der Overworld-Logik korrigiert
  - Zusätzliche Bounds-Checks beim Warp-Setup ergänzt
  - Tür-Zwillingswarps (linke/rechte Tür-Kachel) werden auf einen kanonischen Warp zusammengeführt, damit Rückwege stabil bleiben
  - Zusätzliche Ziel-Validierung für Warp-Spawns (Map-Layout/Koordinaten) ergänzt
  - Sicherer Fallback eingebaut: Bei ungültigem Override wird auf normalen Warp zurückgefallen statt Absturz
- Harte Warp-Exclusions für kritische Bereiche aktiv:
  - Wurzelheim
  - LKW-Innenraum
  - Testlabor-Maps
  - Trainer Hill (inkl. Eingang, Etagen, Dach, Aufzug)
  - Ruhmeshalle (Ever Grande + Pokémon-Liga-Hall of Fame)
- Zusätzlicher Hinweis-NPC (Bill) vor dem Trainer-Hill-Eingang ergänzt:
  - Klare Ingame-Warnung, dass der Bereich aktuell nicht final bearbeitet ist
  - Hinweis auf mögliches Fehlverhalten/Softlocks bei erzwungenem Eintritt (z. B. via Debug)
- Softlock-Schutz bei leerem Team nach Weißwerden ergänzt:
  - Pokémon-Center und Mutter-Event prüfen die Party
  - Bei 0 kampffähigen Pokémon wird ein Notfall-Zigzachs (Level 5) vergeben
  - Zusätzliche Dialoge für Erfolgs-/Fehlerfälle ergänzt
- Trainer-Whiteout-Guard korrigiert, um globale Eingabesperren zu verhindern (nur aktiv, wenn wirklich ein Trainerkampf unmittelbar startet)
- Notfall-Teleporter in BIRKs Labor für aktiven Tür-Warp-Randomizer ergänzt:
  - Item wird beim Pokédex-/Pokéball-Abschnitt nur einmal vergeben
  - Dialogfluss im Labor angepasst, damit der Hinweis sichtbar von Prof. Birk kommt
  - Teleporter nutzt Rückkehr zum letzten Heilpunkt als Softlock-Absicherung
- Freundschaftssystem korrigiert:
  - Ursache für Sprung auf 255 nach K.O./Weißwerden behoben (Signed/Unsigned-Fehler in der Bonus-Berechnung)
  - Freundschafts-Eventwerte wieder auf normale Standard-Werte zurückgesetzt
- Shiny-Rate leicht erhöht:
  - Basisrate von 1/8192 auf 1/4096 (moderner Standard) angehoben
- Fang-/Form-Fix für temporäre Kampfformen ergänzt:
  - Gefangene Pokémon aus temporären Formen (z. B. Mega-/Kampf-Formen) werden beim Übergeben korrekt auf die Ursprungsform normalisiert
  - Standard-Spitznamen werden dabei sauber auf den korrekten Formnamen zurückgeführt
  - Pokédex-/Fang-Referenzen nutzen für diese Fälle jetzt ebenfalls die Ursprungsform
- Gen-9-Lokalisierung fortgeführt:
  - Erste größere Charge klar englischer Kategorie-/Beschreibungstexte auf Deutsch umgestellt
  - Fokus in diesem Schritt auf Form-Makros und mehrere noch englische Spezies-Einträge

## ⚠️ Wichtige Info

- Der Spielstand kann in dieser Version als "beschädigt" angezeigt werden.
- Grund: Es wurden Änderungen an der Save-Datenstruktur vorgenommen.
- Mit dieser Version ist deshalb ein Neustart erforderlich.

## 🆕 Enthalten aus Alpha v1.1.0

- Weitere Story-/Eventanpassungen
- Neues Randomizer-System mit Startkonfiguration vor Spielbeginn und erweiterten Toggle-Optionen
- Überarbeitete statische Begegnungen und legendäre Encounter-Logik
- Zusätzliche Randomizer-Optionen für TMs, Lernsets, Fähigkeiten, Basiswerte sowie Attackenwerte
- Sofortiger Nationaldex beim Pokédex-Erhalt
- Überarbeitungen an Overworld-Objekten und Lichtverhalten
- Verbesserte Stabilität bei Stadt-/Gebäudewechseln
- Diverse interne Codebereinigungen und Bugfixes

---

## 📝 Melder- & Fix-Log

Hier sammeln wir gemeldete Bugs mit Melder und Fix-Status.

- Melder: ChaosOli
  - Meldung: Blütenberg-NPC im PokéCenter hatte englischen Dialog.
  - Status: Gefixt.

- Melder: ChaosOli
  - Meldung: Hinterer Teil bei der Eingabe war nicht übersetzt.
  - Status: Gefixt.

- Melder: ChaosOli
  - Meldung: Freeze beim Einsatz von Zerschneider mit Elio.
  - Ursache: Fehlende Fallback-/Graphics-Info-Zuordnung in den Style-Zuständen.
  - Status: Gefixt.

- Melder: Metze
  - Meldung: Beim Angeln mit Red stürzt das Spiel ab.
  - Status: Gefixt.
  - Hinweis: Angeln wurde für alle Charaktere abgesichert; bei einzelnen Styles wird vorerst Fallback verwendet.

- Melder: Metze
  - Meldung: Battle-Style-Option (Wechsel/Folge) fehlte.
  - Status: Gefixt.
  - Hinweis: Battle-Style ist wieder im Optionsmenü verfügbar.

- Melder: _JuliaN_
  - Meldung: Gedankengut lässt das Spiel abstürzen.
  - Status: Gefixt.

- Melder: SurFaze
  - Meldung: Nach Ende der Safari-Zone spawnt der Spieler in Wurzelheim.
  - Status: Gefixt.

- Melder: Metze
  - Meldung: Purmel wurde fälschlicherweise mit dem Namen Fiaro angezeigt.
  - Status: Gefixt.

- Melder: Metze
  - Meldung: Englischer Text bei Flavia.
  - Status: Gefixt.
  - Hinweis: Auf Deutsch angepasst und an Nyxthra-Ton angepasst.

- Melder: Community (Randomizer-Tests)
  - Meldung: Tür-Warp-Randomizer konnte in die Ruhmeshalle führen (frühes Spielende + Folgefehler/Softlock-Risiko).
  - Status: Gefixt.
  - Hinweis: Ruhmeshalle ist jetzt aus dem Tür-Warp-Pool ausgeschlossen.

- Melder: Community (Randomizer-Tests)
  - Meldung: Bei K.O./Weißwerden sprang Freundschaft teils direkt auf 255.
  - Status: Gefixt.
  - Ursache: Signed/Unsigned-Fehler in der Freundschaftsbonus-Berechnung.

- Melder: Community (Randomizer-Tests)
  - Meldung: Teleporter-Hinweis im BIRK-Labor wirkte im Ablauf wie Rivalen-Dialog.
  - Status: Gefixt.
  - Hinweis: Dialog-/Bewegungsablauf angepasst, damit der Hinweis eindeutig von Prof. Birk kommt.

- Melder: Community (Randomizer-Tests)
  - Meldung: Unklarer Status am Trainer-Hill-Eingang, obwohl Bereich derzeit instabil ist.
  - Status: Gefixt.
  - Hinweis: Bill-NPC mit expliziter Warnung vor Fehlern/Softlocks am Eingang ergänzt.

- Melder: Community
  - Meldung: Beim Fangen von temporären Formen (z. B. Mega) blieb nach dem Kampf teils ein falscher Name bestehen.
  - Status: Gefixt.
  - Ursache: Fang-/Dex-/Naming-Flow nutzte in Teilpfaden noch die temporäre Kampfform.

- Melder: Community
  - Meldung: Gen-9-Einträge enthielten weiterhin zahlreiche englische Kategorien/Beschreibungen.
  - Status: In Arbeit (erste größere Charge gefixt).

- Melder: _JuliaN_
  - Meldung: Einige Charaktere bleiben nach Kämpfen beim Surfen auf Fuß auf dem Wasser statt auf dem Surfer-Zustand.
  - Status: Gefixt.
  - Hinweis: Avatar-State-Mapping für Surf-Flag wurde korrigiert; alle Styles sollten nun stabil surfen können.

- Stand aktuell: Keine weiteren offenen Meldungen.

---

## ℹ️ Hinweise für Tester

- Dies ist eine Beta-Version. Fehler, fehlende Assets oder falsche Trigger sind weiterhin möglich.
- Das Debug-Menü ist nur für Testzwecke vorhanden und nicht vollständig abgesichert.
- Falsche Debug-Auswahl kann Abstürze oder beschädigte Saves verursachen.
- Bitte Bugs möglichst genau melden (Ort, Situation, Schritte, ggf. Screenshot/Video).

---

## 🐞 Bekannte Probleme

- Eilrad/Kunstrad kann in Einzelfällen nach Kämpfen fehlerhaft weiterlaufen (Musik aktiv, Effekt in Teilen verloren)
- Einige Field Moves können situativ fehlerhaft reagieren (z. B. Fliegen, Blitz)
- Einzelne Overworld-Sprites besitzen noch grafische Ungenauigkeiten
- Nicht alle Story-/Eventabschnitte sind bereits vollständig auf Nyxthra umgeschrieben
- Die neue Champion-Szene in der Petalburg-Arena wurde bisher nur für einen Anlaufweg zu Marek vollständig getestet (Blickrichtungen/Bewegungsablauf bei den anderen 3 möglichen Anlaufwegen können noch leicht abweichen)

---

## 📌 Geplant / In Arbeit

- Postgame-Inhalte abschließen
- Neue Musik, Titelbildschirm und Startsequenz
- Update auf neuere Expansion-Version
- Vollständige Rivalen-Teams für alle Storyphasen
- Weitere legendäre Events und alternative Enden
- Erweiterte Shiny-Formen (zunächst für legendäre Pokémon)
- Mehr Team-Fraktionen mit eigener Story-Integration

---

## 🔗 Credits

- pokeemerald-expansion (RHH):
  https://github.com/rh-hideout/pokeemerald-expansion
- Weitere Sprites, Musik und Tools aus der Romhack-Community
- Detaillierte Einzelcredits folgen zum Release
