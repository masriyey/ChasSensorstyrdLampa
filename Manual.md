# **Användarmanual: Sensorstyrd Lampa**

## **Introduktion**
Denna användarmanual beskriver installation, användning och felsökning av den sensorstyrda lampan. Lampan tänds automatiskt vid rörelse och anpassar ljusstyrkan efter omgivande ljusnivå. En LCD-display visar aktuell status och ljusstyrka. Ver2 inkluderar en realtidsklocka som man kan ställa in för nightmode med hjälp av den inbyggda VRTC i Arduino Uno R4. Ver3 hanterar nightmode med hjälp av en LDR modul som läser av ljusstyrkan i rummet och aktiverar nightmode vid mörker via en inbyggd justerbar potentiometer. 

---

## **1. Komponenter**

### **Hårdvara**
- **Arduino UNO R4 WiFi** (eller kompatibel mikrokontroller)
- **HC-SR501** – Infraröd rörelsesensor
- **Fotomotstånd** – Mäter ljusstyrka
- **LDR sensor-modul** - Modul som mäter ljusstyrka (Ver3)
- **VRTC** - Inbyggd Real Time Clock
- **LED-lampa**
- **LCD 16x2-display**
- **Resistorer** *(1KΩ och 100KΩ för anpassning av strömstyrka)*
- **Kablar och kopplingskort**

### **Mjukvara**
- **Arduino IDE** för kodning och uppladdning
- **C++ (Arduino-kod)**
- **Nödvändiga bibliotek**:
  - **LiquidCrystal I2C by Frank de Brabander (version 1.1.2)**
  - **RTCZero by Arduino (version 1.6.0) *(endast vid användning av realtidsklocka)***

---

## **2. Funktionalitet**

### **Grundläggande funktioner**
- **Rörelsesensor (HC-SR501):** Upptäcker rörelse och tänder lampan.
- **Fotomotstånd:** Mäter ljusnivån och justerar lampans ljusstyrka.
- **LCD-display:** Visar om lampan är tänd eller släckt samt aktuell ljusstyrka.
- **VRTC - Real Time Clock:** Möjliggör tidsstyrning av ljusstyrkan. (Ver2)
- **LDR sensor-modul** - Modul som mäter av om det är tillräckligt mörkt för darkMode, kan justeras med inbyggd potentiometer. (Ver3)

### **Systemets beteende**
1. När rörelse upptäcks, tänds LED-lampan automatiskt.
2. Ljusstyrkan justeras baserat på det omgivande ljuset.
3. Om ingen rörelse upptäcks inom en viss tid, släcks lampan.
4. LCD-skärmen visar status och ljusstyrka.

---

## **3. Installation & Konfiguration**

### **Steg-för-steg**
1. **Koppla in hårdvaran** enligt kopplingsschemat.
2. **Installera de nödvändiga biblioteken** i Arduino IDE:
   - Öppna **Bibliotekshanteraren** (Sketch → Inkludera bibliotek → Hantera bibliotek).
   - Sök efter **"LiquidCrystal I2C"**, installera **version 1.1.2** av **Frank de Brabander**.
   - Sök efter **"RTCZero"**, installera **version 1.6.0** av **Arduino**.
3. **Ladda upp koden** till Arduino via Arduino IDE.
4. **Anslut strömförsörjning** till systemet.
5. **Testa funktionalitet**:
   - Vifta med handen framför rörelsesensorn för att se om lampan tänds.
   - Ändra ljusförhållanden för att observera ljusstyrkans anpassning.
   - Kontrollera att LCD-skärmen visar korrekt information.

---

## **4. Användning**

### **Grundläggande användning**
- Lampan fungerar automatiskt och kräver ingen manuell styrning.
- När rörelsesensorn upptäcker rörelse tänds lampan omedelbart.
- Ljusstyrkan justeras automatiskt beroende på omgivningens ljusförhållanden.
- LCD-displayen visar om lampan är tänd eller släckt samt aktuell ljusstyrka.

### **Manuella justeringar**
- **Om ljusstyrkan behöver anpassas:**
  - Ändra känsligheten på fotomotståndet genom att justera koden i Arduino IDE.
  - *(Framtida uppdatering)* Om en realtidsklocka implementeras kan ljusstyrkan justeras baserat på tid på dygnet.

### **Vad användaren kan förvänta sig**
- Lampan släcks automatiskt om ingen rörelse upptäcks inom den inställda tidsgränsen.
- Om ljusnivån är hög (t.ex. dagsljus) kommer lampan att lysa svagare.
- Systemet kräver minimalt underhåll, men regelbunden rengöring av sensorer rekommenderas för optimal funktion.

---

## **5. Felsökning**

### **Problem & Lösningar**
| **Problem** | **Möjlig orsak** | **Lösning** |
|------------|----------------|------------|
| Lampan tänds inte | Sensorn är felkopplad | Kontrollera kablar och kopplingsschema |
| Ljusstyrkan ändras inte | Fotomotståndet fungerar inte | Testa att byta ut komponenten |
| Displayen visar inget | Felaktig kod eller dålig kontakt | Kontrollera kod och kablar |
| Systemet hänger sig | Kodbugg eller överbelastning | Återställ Arduino via reset-knapp |

---

## **6. Specifikationer & Krav**

### **Prestanda**
- **Responstid:** <0.5s för att tända lampan vid rörelse.
- **Uppdatering av LCD-skärm:** Max 1s efter ändrad status.
- **Sensorn avläses:** Varje 500ms.
- **Drifttemperatur:** 10°C – 30°C.
- **Luftfuktighet:** 40% – 60%.

### **Säkerhet**
- **Elsäkerhet:** Korrekt dimensionerade resistorer för att skydda kretsen.
- **Systemåterställning:** Möjlighet att återställa via reset-knapp.

### **Användargränssnitt**
- **Grundläggande konfiguration** kan göras via seriell monitor i Arduino IDE.

---

## **7. Testning**

- Kontrollera att **rörelsesensorn** tänder lampan inom 0.5 sekunder.
- Testa att **fotomotståndet** justerar ljusstyrkan korrekt vid olika ljusnivåer.
- Verifiera att **LCD-displayen** visar rätt information inom 1 sekund efter ändring.
- Testa **reset-knappen** för att se att systemet startar om korrekt.

---

## **8. Framtida Utveckling**
- Möjlighet att ställa in ljusstyrkans anpassning manuellt via en mobilapp.
- **Energieffektivisering** genom optimerade algoritmer.

---

## **9. Sammanfattning**
Den sensorstyrda lampan är en smart lösning för att automatiskt anpassa ljusstyrkan och aktiveras vid rörelse. Lampan kräver ingen manuell styrning men kan justeras via kod vid behov. Med framtida uppdateringar kan den även justeras baserat på tid på dygnet. Använd denna manual för att installera, använda och felsöka systemet.

---

📅 **Datum:** 2025-03-19  
🔖 **Version:** 1.2  
👥 **Projektgrupp:** Chas Academy grupp 3
