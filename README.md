# Sensorstyd lampa (grupp 3) - Chas Academy

## Gruppmedlemmar:

### Jonathan R
### Anna S
### Nikki N
### Mahmoud M
### Robert B

## Länkar:

### [SRS](https://github.com/masriyey/ChasSensorstyrdLampa/blob/main/SRS.md)
### [Github (kod)](https://github.com/masriyey/ChasSensorstyrdLampa)
### [Github (tavla)](https://github.com/masriyey/ChasSensorstyrdLampa/edit/main/README.md)
### [Google Drive](https://docs.google.com/document/d/1EhLYOxIQsRwtQsxHoJ5MGX98XY1ruyxY7rxymrV0jyY/edit?pli=1&tab=t.0)
	
## Komponenter: 

### Infraröd sensormodul HC SR501;
### Fotomotståndssensormodul för ljusbarriärer.
### DS1302 realtidsklockmodul; (Vid tid över, lägger vi på denna också);


# Smart Lampa med Rörelsesensor och Ljusstyrningsfunktion

## :pushpin: Projektbeskrivning

### Detta projekt går ut på att skapa en smart lampa som:
Tänds automatiskt vid rörelseupptäckt med en infraröd sensormodul (HC-SR501).
Anpassar LED-lampans ljusstyrka beroende på omgivande ljusnivå, mätt av en fotomotståndssensormodul.
(Vid tid och möjlighet) integrerar en DS1302 realtidsklockmodul för att möjliggöra tidsstyrning av lampan.


## :hammer_and_wrench: Använda komponenter

### HC-SR501 – Infraröd rörelsesensor
### Fotomotståndsmodul – Mäter ljusstyrka
### DS1302 realtidsklockmodul (eventuell framtida uppgradering)
### Arduino UNO R4 WiFi (eller kompatibel mikrokontroller)
### LED-lampa
### Resistor(er) för anpassning av strömstyrka

## :zap: Funktionalitet

### Rörelsesensor (HC-SR501) upptäcker rörelse och aktiverar LED-lampan.
### Fotomotståndssensorn mäter ljusnivån och justerar ljusstyrkan på LED-lampan.
(Framtida utveckling) DS1302 realtidsklockmodul används för att möjliggöra tidsschemaläggning av lampans funktion.
