#include "DHT.h"
#define dhtPin 2
#define dhtType DHT11

DHT  dht(dhtPin, dhtType);
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display


void  setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void  loop() {

  float h = dht.readHumidity();
  float t  = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Check Sensor");
  } 
  else{
    lcd.setCursor(0, 0);
    lcd.print("H: ");
    lcd.print(h);
    lcd.print(" g.kg-1");
    lcd.setCursor(0, 1);
    lcd.print("T: ");
    lcd.print(t);
    lcd.print(" Celsius");
  }
  delay(2000);
}
