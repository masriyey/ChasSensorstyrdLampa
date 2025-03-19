#include <LiquidCrystal_I2C.h> 


//Pins
int ledPin = 3;
int sensor = 2;
int lightSensor = A3;
int digitalLightSensor = 4;

//Variabler för att kolla spara läsningar
int motionDetected = 0;
int lightSensorValue = 0;
int darkDetected = 0;


//Variabler för att spara förfluten tid
unsigned long lastMotionTime = 0;
unsigned long lightOnDuration = 5000;//(300000 för 5 min)
bool lampOn = false;

//Variabler för att spara meddelande till LCD
String lastMessage1 = "";
String lastMessage2 = "";
LiquidCrystal_I2C lcd(0x27, 16, 2); 
/*0x27 är adressen, använd detta i setup om adressen inte fungerar för att leta reda på din I2C adress:
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
  Serial.println("Scan complete.");*/

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(lightSensor, INPUT);
  pinMode(digitalLightSensor, INPUT);
 
  
  
  Serial.begin(9600);
  Serial.println("Starting");
  
  //LCD start
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Lamp off");
  delay(2000);
}

//FUnktion som uppdaterar meddelandet vid förändringar
void updateLCD(String message1, String message2) {
  if (message1 != lastMessage1 && message2 != lastMessage2) {
    lcd.clear();
    lcd.print(message1);
    lcd.setCursor(0, 1);
    lcd.print(message2);
    lastMessage1 = message1;
    lastMessage2 = message2;
  }
}

void loop()
{

	motionDetected = digitalRead(sensor);
  	lightSensorValue = analogRead(lightSensor);
    darkDetected = digitalRead(digitalLightSensor);
    Serial.println(digitalRead(digitalLightSensor));
    lightSensorValue = map(lightSensorValue, 40, 200, 0, 1023);
  
  
  
    Serial.println(lightSensorValue);
    delay(50);


    if(motionDetected == HIGH)
    {
        lastMotionTime = millis();
        lampOn = true;
     }
     

    if(lampOn)
           {
          if (motionDetected == HIGH && darkDetected == HIGH)
          {
            updateLCD("Lamp on", "Nightmode 27%");
            Serial.println("Motion detected, 27% light Nightmode");
            analogWrite(ledPin, 18);
          } else if (motionDetected == HIGH && lightSensorValue > 800) {
            updateLCD("Lamp on", "Brightness 10%");
            Serial.println("Motion detected, 10% light");
            analogWrite(ledPin, 2);
          } else if (motionDetected == HIGH && lightSensorValue > 500 && lightSensorValue <= 800) {
            updateLCD("Lamp on", "Brightness 50%");
            Serial.println("Motion detected, 50% light");
            analogWrite(ledPin, 55);
          } else if (motionDetected == HIGH && lightSensorValue < 500) {
            updateLCD("Lamp on", "Brightness 100%");
            Serial.println("Motion detected, 100% light");
            analogWrite(ledPin, 255);
          }
 
      
       
      

        //Kontrollera om tiden som angetts har passerat sedan 
        //senaste rörelse
        	if (millis() - lastMotionTime > lightOnDuration) 
            {
          		lampOn = false;
        	}
    	

      }

    // Om lampan ska vara avstängd
    	if (!lampOn)
        {
          analogWrite(ledPin, 0);
          updateLCD("Lamp off", "");
          Serial.println("No motion detected");
    	}	
  
}

