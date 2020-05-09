/*
  Autor : Johan Ramirez
  date  : 5/05/2020
  Description : Code here 
*/

#include <SPI.h>
#define slaveAPin 2

// global variables ---------------------------------

unsigned long timer = 0;
long loopTime = 5000;
short dataDigital = 0;
double dataAnaloga = 0; 

// set up the speed, data order and data mode--------

SPISettings settingsA(425000, MSBFIRST, SPI_MODE0);

// Function prototypes-------------------------------

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
  Serial.print(leerDigital());
  delay(10);
  Serial.print(',');
  Serial.print(leerAnalogo(A1,60.0));
  delay(10);
  Serial.print(',');
  Serial.println(leerAnalogo(A2,15.0));
  delay(5);
/*  Serial.print(',');
  Serial.println(leerAnalogo(A2,15.0));
  delay(15);
*/
}

double leerAnalogo(byte pin , double presion ){
  dataAnaloga= analogRead(pin);
  if (dataAnaloga <= 102) return 0;
  //else if  (dataAnaloga > 921) return double(presion); 
  return (dataAnaloga - 0.1*(1024.0))/((0.8*(1024.0))/(presion));
}

double leerDigital(){
  SPI.beginTransaction(settingsA);
  digitalWrite (slaveAPin, LOW);
  dataDigital = SPI.transfer16(0x00);
  digitalWrite (slaveAPin, HIGH);
  SPI.endTransaction();
  if (dataDigital <= 16384 * 0.1) return -1;
  else if (dataDigital >= 16384 * 0.9) return 1;
  else return (dataDigital - 0.1 * 16384.0 ) / (0.4 * 16384.0) - 1.0;
}

void timeSync(unsigned long deltaT){
  unsigned long currTime = micros();
  long timeToDelay = deltaT - (currTime - timer);
  if (timeToDelay > 5000){
    delay(timeToDelay / 1000);
    delayMicroseconds(timeToDelay % 1000);
  }
  else if (timeToDelay > 0) delayMicroseconds(timeToDelay);
  timer = currTime + timeToDelay;
}

void sendToPC(int* data1, int* data2, int* data3)
{
  byte* byteData1 = (byte*)(data1);
  byte* byteData2 = (byte*)(data2);
  byte* byteData3 = (byte*)(data3);
  byte buf[6] = {byteData1[0], byteData1[1],
                 byteData2[0], byteData2[1],
                 byteData3[0], byteData3[1]};
  Serial.write(buf, 6);
}

void sendToPC(double* data1, double* data2, double* data3){
  byte* byteData1 = (byte*)(data1);
  byte* byteData2 = (byte*)(data2);
  byte* byteData3 = (byte*)(data3);
  byte buf[12] = {byteData1[0], byteData1[1], byteData1[2], byteData1[3],
                 byteData2[0], byteData2[1], byteData2[2], byteData2[3],
                 byteData3[0], byteData3[1], byteData3[2], byteData3[3]};
  Serial.write(buf, 12);
}
