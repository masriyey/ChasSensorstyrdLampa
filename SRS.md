# Sensorstyrd Lampa 

## Introduktion

Projektet är en smart lampa som ska ha egenskaperna att tändas automatiskt när den upptäcker rörelse samt att den ska justera ljusstyrkan efter hur starkt ljus det är i omgivningen. Är det starkt ljus i omgivningen ska lampan lysa lite svagare, och är det mörkt i omgivningen ska den lysa starkare. Lampan har även en LCD display som talar om ifall lampan är på eller av, samt vilken ljusstyrka lampan lyser med ifall den är igång. I en framtida uppdatering ska lampan även ta hänsyn till vilken tid det är på dygnet och anpassa ljusstyrkan efter det, mitt i natten lyser den svagare för att undvika att blända människor som passerar den.

## Specifika Krav

### Funktionella Krav

- Rörelsesensorn ska upptäcka rörelse och tända lampan.
- Rörelsesensorn ska släcka lampan om det inte varit någon rörelse på angiven tid.
- Fotomotstånd Sensorn ska mäta ljusstyrkan och justera lampans ljusstyrka därefter.
- LCD display som skriver ut ljusstyrkan på lampan samt om den är av eller på.
- Inbyggd RTC(Real Time Clock) för att kunna justera ljusstyrka utefter vilken tid på dygnet det är.
- LDR-sensor modul, läser av vilken ljusstyrka det är i rummet och används för att aktivera nightmode vid tillräckligt svag ljusstyrka.


### Icke-Funktionella Krav

### Prestanda

- Lampan ska släckas på angiven tid efter att ingen rörelse upptäcks, med anpassning till vilket rum den är i. 
- Rörelsesensorn ska tända lampan inom 0,5 sekund vid rörelse upptäckt.
- LCD Displayen ska uppdatera status på lampan med max 1 sekunds fördröjning efter ändring.
- Optimal drift-temperatur är mellan 10 grader celsius och 30 grader celsius samt luftfuktighet mellan 40% och 60%. Normalt inomhus-klimat. 
- Sensorerna ska läsas av 1 gång var 500 millisekund.  
- Koden ska vara väl strukturerad med lätt för anpassning av förändring och vidareutveckling. 

### Säkerhet

- Elsäkerhet, systemet ska ha skydd mot kortslutning genom att använda rätt dimensioner på resistorer. 
- Systemet ska ha en fungerande resetfunktion vid ev problem med mjukvaran. 

### Användargränssnitt

- Grundläggande konfiguration kan ske via seriell monitor i Arduino IDE.



## Externa Gränssnitt


### Maskinvara 

- HC-SR501, Infraröd rörelsesensor
- Fotomotstånd, Mäter ljusstyrka
- Använda sig utav inbyggt RTC (VRTC), (Real Time Clock)
- Arduino UNO R4 WiFi (eller kompatibel mikrokontroller)
- LED-lampa
- Resistor(er), för anpassning av strömstyrka
- LDR-modul

### Mjukvara

- Ardunio IDE
- C++(Arduino-kod)
- **Nödvändiga bibliotek**:
  - **LiquidCrystal I2C by Frank de Brabander (version 1.1.2)**
  - **RTCZero by Arduino (version 1.6.0) *(endast vid användning av realtidsklocka)***

### Testkrav

- Bekräfta att rörelsesensorn tänder lampan inom 0.5 sekunder vid upptäckt rörelse.
- Testa att lampan justerar ljusstyrkan korrekt i olika ljusnivåer.
- Kontrollerar att displayen visar korrekt information inom 1 sekund efter ändring
- Testa att systemet återställs korrekt vid användning av reset knapp.
- Säkerställa att läsningarna från fotoresistorn är stabila. 
