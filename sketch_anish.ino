#include <LiquidCrystal.h>
#include "DHT.h"

#define Type DHT11
int sensePin = 13;
int OP = 9;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int dt = 1000;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float prevHumidity = 0.0;
float prevTempC = 0.0;

void setup() {
  // pinMode(OP, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  HT.begin();
  delay(setTime);
}

void loop() {
  // digitalWrite(OP, HIGH);
  float humidity = HT.readHumidity();
  float tempC = HT.readTemperature();
  // tempF = HT.readTemperature(true);
    lcd.setCursor(0, 0);
    lcd.print("Temp C= ");
    lcd.print(tempC);
    lcd.setCursor(0, 1);
    lcd.print("Humidity= ");
    lcd.print(humidity);
    lcd.print(" %");

  if (humidity != prevHumidity || tempC != prevTempC) {
    
    lcd.clear();
    // Serial.print("Humidity: ");
    Serial.println(humidity);
    // Serial.print("% Temperature ");
    Serial.println(tempC);
    // Serial.print(" C ");
    /*Serial.print(tempF);
    Serial.println(" F ");*/

    // Update the previous values
    prevHumidity = humidity;
    prevTempC = tempC;
  }

  delay(1000); // Adjust the delay as needed
}
