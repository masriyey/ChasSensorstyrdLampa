# Sensorstyrd Lampa - Förbättrad SRS

## Introduktion

Projektet är en smart lampa som tänds automatiskt när den upptäcker rörelse och justerar ljusstyrkan baserat på omgivande ljus. Om det är starkt ljus i omgivningen ska lampan lysa svagare, och om det är mörkt ska den lysa starkare. Lampan har en LCD-display som visar om lampan är på eller av och vilken ljusstyrka den har. I en framtida uppdatering ska lampan även ta hänsyn till tid på dygnet, där den lyser svagare mitt i natten för att undvika att blända.

## Specifika Krav

### Funktionella Krav

- Rörelsesensorn (HC-SR501) ska upptäcka rörelse inom en radie av **5 meter** och en vinkel på **120°** samt tända lampan inom **0,5 sekunder**.
- Rörelsesensorn ska släcka lampan efter en användarspecificerad tid (t.ex. **10 sekunder**) om ingen rörelse upptäcks.
- Fotomotståndet ska mäta ljusstyrka inom ett intervall av **0–1000 lux** och justera lampans ljusstyrka proportionerligt.
- LCD-displayen ska visa aktuell status meddelande, till exempel: *"Lampan är På, Ljusstyrka: 70%"* eller *"Lampan är Av"*.
- DS1302 realtidsklockmodul ska kunna justera ljusstyrkan baserat på tid på dygnet (i framtida uppdatering).

### Icke-Funktionella Krav

#### Prestanda

- Lampan ska släckas efter angiven tid (standard: 10 sekunder) om ingen rörelse upptäcks.
- Sensorn ska uppdateras **2 gånger per sekund** (var 500 ms).
- LCD-displayen ska visa aktuell status inom **1 sekund** efter ändring.
- Optimal driftstemperatur är mellan **10°C och 30°C** och luftfuktighet mellan **40% och 60%**.
- Systemet ska kunna återställa sig från mjukvarufel inom **2 sekunder**.

#### Säkerhet

- Systemet ska skyddas mot överspänning och kortslutning med korrekt dimensionerade resistorer.
- En **Watchdog Timer** ska implementeras för att automatiskt återställa systemet vid mjukvarufel.
- Korrekt jordning och isolering av strömförande delar.

#### Användargränssnitt

- Grundläggande konfiguration, som ljusstyrka och tidsinställningar, ska kunna göras via seriell monitor i Arduino IDE.
- Felmeddelanden och statusuppdateringar ska skrivas ut till den seriella monitorn.

## Externa Gränssnitt

### Maskinvara

- **HC-SR501:** Infraröd rörelsesensor, ansluten till digital pin på Arduino.
- **Fotomotstånd:** Ansluten till en analog ingång för att mäta ljusstyrka.
- **DS1302 realtidsklockmodul:** Ansluten via SPI (framtida uppdatering).
- **Arduino UNO R4 WiFi** eller kompatibel mikrokontroller.
- **LED-lampa** med passande resistorer för strömbegränsning.
- **Resistorer:** Anpassade för att skydda kretsar och sensorer.

### Mjukvara

- **Arduino IDE** (specificera version vid behov).
- **Programmeringsspråk:** C++ (Arduino-kod).
- Nödvändiga externa bibliotek, exempelvis för DS1302 och LCD-styrning.

## Testkrav

- Bekräfta att rörelsesensorn tänder lampan inom **0,5 sekunder** vid upptäckt rörelse.
- Testa att lampan justerar ljusstyrkan korrekt i olika ljusnivåer.
- Kontrollera att displayen visar korrekt information inom **1 sekund** efter ändring.
- Testa att systemet återställs korrekt efter en simulering av mjukvarufel.

---

Denna förbättrade SRS är avsedd att göra kraven tydligare, mätbara och mer detaljerade för att underlätta både implementation och testning av den sensorstyrda lampan.

