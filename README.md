# Sensorstyd lampa (grupp 3) - Chas Academy

## Gruppmedlemmar:

### Jonathan R
### Anna S
### Nikki N
### Mahmoud M
### Robert B

## Länkar:

### [Användarmanual](https://github.com/masriyey/ChasSensorstyrdLampa/blob/main/Manual.md)
### [SRS](https://github.com/masriyey/ChasSensorstyrdLampa/blob/main/SRS.md)
### [Kopplingsschema Ver 1 och 2](https://github.com/masriyey/ChasSensorstyrdLampa/blob/main/Ver_1_Chas_grupp_3%2CSensor_Lampa1.pdf)
### [Kopplingsschema Ver 3](https://github.com/masriyey/ChasSensorstyrdLampa/blob/main/Ver3_Sensorstyrd_Lampa_Dark_Detector.png)
### [Github (kod)](https://github.com/masriyey/ChasSensorstyrdLampa)
### [Github (tavla)](https://github.com/users/masriyey/projects/4)
	

# Smart Lampa med Rörelsesensor och Ljusstyrningsfunktion

## :pushpin: Projektbeskrivning

### Detta projekt går ut på att skapa en smart lampa som:
Tänds automatiskt vid rörelseupptäckt med en infraröd sensormodul (HC-SR501).
Anpassar LED-lampans ljusstyrka beroende på omgivande ljusnivå, mätt av ett fotomotstånd.
Via VRTC kan man ställa in tid när nightmode ska aktiveras. (Ver2).
Via en LDR modul kan man ställa in vid vilken ljusstyrka nightmode ska aktiveras.(Ver3)


## :hammer_and_wrench: Använda komponenter

### HC-SR501 – Infraröd rörelsesensor
### Fotomotstånd – Mäter ljusstyrka
### Arduino UNO R4 WiFi (eller kompatibel mikrokontroller)
### LED-lampa
### Resistor(er) för anpassning av strömstyrka
### LCD-Display
### LDR Modul - för att justera när nightmode ska aktiveras

## :zap: Funktionalitet

### Rörelsesensor (HC-SR501) upptäcker rörelse och aktiverar LED-lampan.
### Fotomotståndet mäter ljusnivån och justerar ljusstyrkan på LED-lampan.
### VRTC används för att möjliggöra tidsschemaläggning av lampans nightmode.
### LDR modul används för att kunna manuellt justera när nightmode ska aktiveras. 
### LCD displayen visar ljusstyrka, lampa på/av samt om nightmode är aktiverat. 
