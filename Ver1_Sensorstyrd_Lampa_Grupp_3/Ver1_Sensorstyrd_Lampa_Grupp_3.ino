#include <LiquidCrystal_I2C.h> //Använd bibliotek LiquidCrystal I2C by Frank de Brabander version 1.1.2

/*Använd detta i setup om adressen inte fungerar för att leta reda på din I2C adress:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
void setup()
{
 Wire.begin();
  Serial.begin(9600);
  while (!Serial); // Vänta på att Serial-porten är redo
  Serial.println("I2C Scanner Scanning...");
  for (byte address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Scan complete.");
}*/

//Pins
int ledPin = 3;
int motionSensor = 2;
int lightSensor = A3;

//Variabler för att kolla spara läsningar
int motionDetected = 0;
int lightSensorValue = 0;

//Variabler för att spara förfluten tid för LEDlampan sen senaste avläsningen
unsigned long lastMotionTime = 0;
unsigned long lightOnDuration = 5000;//(300000 för 5 min)
bool lampOn = false;

//Variabler för att se till att sensorn bara läses av en gång var 500 millisekund
int intervalForReadingSensors = 500;
int latestReadingOfSensors = 0;

//Variabler för att spara meddelande till LCD
String lastMessage1 = "";
String lastMessage2 = "";
LiquidCrystal_I2C lcd(0x27, 16, 2); 

//Funktion för att uppdatera LCD displayen med nytt meddelande vid förändring
void updateLCD(String message1, String message2) 
{
  if (message1 != lastMessage1 && message2 != lastMessage2) {
    lcd.clear();
    lcd.print(message1);
    lcd.setCursor(0, 1);
    lcd.print(message2);
    lastMessage1 = message1;
    lastMessage2 = message2;
  }
}

void lightOn(int ledBrightness, String brightnessMessage)
{
  updateLCD("Lamp on", brightnessMessage);
  analogWrite(ledPin, ledBrightness);
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(motionSensor, INPUT_PULLUP);
  pinMode(lightSensor, INPUT);
  
  /*Använd detta om du vill debugga programmet med hjälp av Serial Monitor
  Serial.begin(9600);
  Serial.println("Starting");*/
  
  //LCD start
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Lamp off");
  delay(2000);
}

void loop()
{
  //Se till att sensorerna bara läses av en gång var 500e millisekund
  int timeSinceSensorsWhereRead = millis();

  if(timeSinceSensorsWhereRead - latestReadingOfSensors >= intervalForReadingSensors)
  {
    latestReadingOfSensors = timeSinceSensorsWhereRead;
    motionDetected = digitalRead(motionSensor);
    lightSensorValue = analogRead(lightSensor);
    lightSensorValue = map(lightSensorValue, 40, 200, 0, 1023);
  }

  /*Använd detta vid debugging för att skriva ut ljusstyrkan som fotoresistorn tar upp
  Serial.println(lightSensorValue);
  delay(100);*/

  if(motionDetected == HIGH)
  {
      lastMotionTime = millis();
      lampOn = true;
  }

  if (lampOn) 
  { 
      if (motionDetected == HIGH && lightSensorValue > 800) 
      {
        lightOn(2, "Brightness 10%");
        //Serial.println("Motion Detected, 10% Brightness"); Använd vid debugging för att se så rörelser och ljusstyrka stämmer
      } 
      else if (motionDetected == HIGH && lightSensorValue > 500 && lightSensorValue <= 800) 
      {
        lightOn(55, "Brightness 50%");
        //Serial.println("Motion Detected, 50% Brightness"); Använd vid debugging för att se så rörelser och ljusstyrka stämmer
      } 
      else if (motionDetected == HIGH && lightSensorValue < 500) 
      {
        lightOn(255, "Brightness 100%");
        //Serial.println("Motion Detected, 100% Brightness"); Använd vid debugging för att se så rörelser och ljusstyrka stämmer
      }

    //Kontrollera om tiden som angetts har passerat sedan 
    //senaste rörelse
      if (millis() - lastMotionTime > lightOnDuration) 
      {
          lampOn = false;
      }
  }
  
  else
  {
      analogWrite(ledPin, 0);
      updateLCD("Lamp off", "");
      //Serial.println("No motion detected"); Använd vid debugging för att se så rörelser stämmer.
  }	
}
