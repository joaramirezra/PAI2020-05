/*
  Autor : Johan Ramirez
  date  : 5/05/2020
  Description : Code here 
*/

#include <SPI.h>
#define slaveAPin 2
  
short data = 0;

// set up the speed, data order and data mode
SPISettings settingsA(425000, MSBFIRST, SPI_MODE0);

double leerDigital();
double leerAnalogo(byte pin , byte presion );
void setup() {
  // set the Slave Select Pins as outputs:
  pinMode (slaveAPin, OUTPUT);
  // initialize SPI:
  SPI.begin();
  // Inicializacion Serial
  Serial.begin(9600);
}

void loop() {
  Serial.println(leerDigital());
  Serial.print(",");  
  Serial.print(leerAnalogo(A0,60));
  Serial.print(",");  
  Serial.print(leerAnalogo(A1,60));
  Serial.print(",");  
  Serial.println(leerAnalogo(A2,15));
  delay(20);
}

double leerAnalogo(byte pin , byte presion ){
  data = analogRead(pin);
  if (data <= 102) return 0;
  else if  (data > 921) return double(presion); 
  float pressure = (data - 0.1*(1024))/((0.8*(1024))/(presion));
  return pressure;
}

double leerDigital(){
  SPI.beginTransaction(settingsA);
  digitalWrite (slaveAPin, LOW);
  data = SPI.transfer16(0x00);
  digitalWrite (slaveAPin, HIGH);
  SPI.endTransaction();
  if (data <= 16384 * 0.1) return -1;
  else if (data >= 16384 * 0.9) return 1;
  else return (data - 0.1 * 16384 ) / (0.4 * 16384) - 1;
}
