#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C MyLCD(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {  
  MyLCD.begin(16, 2);
  MyLCD.print("Saben algo de");
  MyLCD.setCursor(0, 1);
  MyLCD.print("Julian paez ?");
 
  delay(1000);
}

void loop() {

}
