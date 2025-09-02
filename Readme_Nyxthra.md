# Pokémon Nyxthra – Alpha v1.0.3

**Pokémon Nyxthra** ist eine auf **pokeemerald-expansion** (v1.12.1) basierende Modifikation mit zahlreichen eigenen Erweiterungen, Änderungen und neuen Inhalten.  
Die Basis stammt vom RHH-Team (rh-hideout). Mehr Infos zum Originalprojekt:  
🔗 https://github.com/rh-hideout/pokeemerald-expansion/blob/master/README.md

---

## 🧪 Versionsinfo

- **Projektstart:** 01.01.2024  
- **Basis:** pokeemerald-expansion v1.12.1  
- **Nyxthra-Version:** Alpha v1.0.3  
- **Sprache:** Deutsch  
- **Status:** Testphase (nur ausgewählte Tester)

---

## ✨ Hauptänderungen gegenüber pokeemerald-expansion

### 🎮 Gameplay & Story
- Vollständig überarbeitete Story mit eigenen Dialogen  
- Neue Events und Szenen eingebaut  
- Starter frei wählbar – **alle Starter aller Regionen** (Gen 1–9) stehen zur Auswahl, statt nur die Hoenn-Starter  
- Neue Trainer & Teams, inklusive Kämpfe gegen Charaktere aus verschiedenen Generationen  
- Trainerlevel, KI und Begegnungen stark angepasst  

### 🌞 Tag-Nacht-System & Uhr
- Tag-Nacht-System aus **pokeemerald-expansion (RHH)** integriert, **Codes jedoch komplett selbst angepasst**  
- Anzeige der **aktuellen Uhrzeit direkt im Startmenü** (eigene Implementierung)  
- Dynamische **Lichteffekte** in Abhängigkeit von der Tageszeit (Code teils von uns, teils von RHH)  

### 👤 Charakterauswahl & Stylesystem
- Statt geschlechtsbasierter Auswahl wurde ein **komplettes Style-System** eingeführt  
- Direkt zu Beginn wählbar:
  - **Ethan**
  - **Lyra**
  - **Red**
  - **Leaf**
  - **Hans** (Brendan)
  - **Brigitte** (May)
  - **Lukas** (Lucas)
  - **Lucia** (Dawn)
  - **Warren** (Hilbert)
  - **Lotta** (Hilda)
- Das Spiel nutzt intern den Style statt dem Geschlecht → **dynamische Rivalen, Dialoge und Events**  

### ⚙️ Komfortfunktionen
- **Spitznamen-Überspringen** beim Fangen oder Erhalten eines Pokémon möglich *(Idee aus Pokémon Rogue)*  
- **Dauerhaftes Rennen** einstellbar: Im Optionsmenü wählbar zwischen „Halten“ oder „Umschalten“ *(Idee aus Pokémon Rogue)*  

### 🧠 Technisch & Code
- Eigenes Stylesystem vollständig implementiert  
- Über 50 neue Scripts und zahlreiche zusätzliche Funktionen (u.a. Event-Handling, Debugfunktionen, Spezial-Events)  
- Komplette Neuordnung und Vereinheitlichung von geschlechterbasierten Checks  
- Neue Grafiken, Paletten und Charaktersprites eingebunden  

---

## ℹ️ Hinweise für Tester
- Dies ist eine **Alpha-Version**. Fehler, fehlende Grafiken oder falsche Trigger können auftreten.  
- ⚠️ **Debug-Menü:** Nur in der Alpha vorhanden – noch nicht alle Funktionen sind einsatzbereit.  
  - **Falsche Auswahl kann zu Spielabstürzen oder beschädigten Spielständen führen!**  
  - Viele Einträge erklären sich selbst.  
  - Für gezielte Tests ist das Debug-Menü dennoch sehr nützlich.  
- Bitte dokumentiert alle Fehler möglichst genau (Ort, Situation, ggf. Screenshots) und meldet sie an den Dev.
---

## 🐞 Bekannte Probleme
- **Grafikfehler mit dem Eilrad** (gelegentlich auch beim Kunstrad)  
	Beim fahren läuft der spieler aber die musik vom rad ist da und auch der speed. Problem ist, sobald ein kampf oder so kommt bleibt die musik aber die schnelligkeit ist weg. Dann muss man wieder das Rad auswählen. Tipp: Bei sachen wo man fahren muss, einfach am besten Schutz aktivieren und evenutell vorher alle trainer in der nähe besiegen bis das problem gefixt ist.

- **Field Move Effekte** könnten in bestimmten Situationen nicht korrekt funktionieren (z. B. *Fliegen*, *Blitz* usw.)

- **Overworld Grafikfehler** 
	einige Pokémon haben noch grafikfehler in der oberwelt, voraussichtlicher fix in der nächsten oder übernächsten version


---

## 📌 Noch geplant / In Arbeit
- Abschluss der Postgame-Inhalte  
- Neue Musik, Titelbildschirm & Startsequenz  
- Update auf neuere Expansion-Version  
- Trainerkämpfe mit vollständigen Teams für alle Rivalen in jeder Phase  
- Neue legendäre Events & alternative Enden  
- **Erweiterte Formen von Shinys** (zunächst nur für legendäre Pokémon)  
- **Mehrere Teams** ins Spiel einbauen 
	(alle vorhandenen Teams im Projekt, jedoch aktuell noch ohne Story – derzeit am Ende von Metarost City sichtbar)  

---

## 🔗 Credits

- **pokeemerald-expansion (RHH)**  
  → https://github.com/rh-hideout/pokeemerald-expansion  
- Diverse Sprites, Musik und Tools stammen aus der Pokémon-Romhack-Community (Credits folgen zum Release)  
