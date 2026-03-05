# Pokémon Nyxthra - Alpha v1.0.8

Pokémon Nyxthra ist eine deutschsprachige Modifikation auf Basis von pokeemerald-expansion (v1.15.0) mit eigener Story, neuen Systemen und stark erweitertem Gameplay.

Basisprojekt (RHH):  
https://github.com/rh-hideout/pokeemerald-expansion

---

## 🧪 Projektstatus

- Projektstart: 01.01.2024
- Basis: pokeemerald-expansion v1.15.0
- Aktuelle Nyxthra-Version: Alpha v1.0.8
- Sprache: Deutsch
- Status: Interne Testphase (ausgewählte Tester)

---

## ✨ Features & Änderungen

### 🎮 Gameplay & Story
- Vollständig überarbeitete Hauptstory mit eigenen Dialogen, Events und Szenen
- Neue Trainer, Teams und Begegnungen über mehrere Generationen hinweg
- Überarbeitetes Balancing für Levelkurve, KI und Kampfverlauf
- Freie Starterwahl: Starter aus Gen 1-9 statt klassischer Hoenn-Auswahl

### 🌞 Tag/Nacht, Uhr & Overworld
- DNS-System (Day/Night) auf Nyxthra angepasst
- Uhrzeit-Anzeige direkt im Startmenü (eigene Implementierung)
- Dynamische Lichtquellen in der Overworld
- Mehrere Stabilitätsfixes für Overworld-/Licht-Handling (u. a. Freeze-Fixes in Städten)

### 👤 Stylesystem statt Geschlechterwahl
- Komplettes Style-System als Kernmechanik
- Verfügbare Styles zu Spielbeginn (aktuell 20):
  - Hans (Brendan)
  - Brigitte (May)
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
- Hinweis: Für einige Styles sind noch nicht alle Sprite-Zustände final (z. B. Surf/Fishing/Field Move/Rival-Varianten). In diesen Fällen nutzt das Spiel aktuell bewusst Fallback-Grafiken, bis alle finalen Assets fertig sind.

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

---

## 🆕 Neu in Alpha v1.0.8

- Weitere Story-/Eventanpassungen
- Überarbeitungen an Overworld-Objekten und Lichtverhalten
- Verbesserte Stabilität bei Stadt-/Gebäudewechseln
- Diverse interne Codebereinigungen und Bugfixes

---

## ℹ️ Hinweise für Tester

- Dies ist eine Alpha-Version. Fehler, fehlende Assets oder falsche Trigger sind möglich.
- Das Debug-Menü ist nur für Testzwecke vorhanden und nicht vollständig abgesichert.
- Falsche Debug-Auswahl kann Abstürze oder beschädigte Saves verursachen.
- Bitte Bugs möglichst genau melden (Ort, Situation, Schritte, ggf. Screenshot/Video).

---

## 🐞 Bekannte Probleme

- Eilrad/Kunstrad kann in Einzelfällen nach Kämpfen fehlerhaft weiterlaufen (Musik aktiv, Effekt in Teilen verloren)
- Einige Field Moves können situativ fehlerhaft reagieren (z. B. Fliegen, Blitz)
- Einzelne Overworld-Sprites besitzen noch grafische Ungenauigkeiten

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
