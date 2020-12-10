#include <SoftwareSerial.h>

char incomingByte ; // for incoming serial data
unsigned long timer = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  timer = micros();
}
float x,y,z;
void loop() {

  if(Serial.available()){
    String first  = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this
    String second = Serial.readStringUntil(',');
    Serial.read();
    String third  = Serial.readStringUntil('\n');
    //parse your data here. example:
    x = first.toFloat();
    y = second.toFloat();
    z = third.toFloat();
//    Serial.println(sizeof(x));
    sendToPC(&x,&y,&z);
  } 
}


void timeSync(unsigned long deltaT) {
  unsigned long currTime = micros();
  long timeToDelay = deltaT - (currTime - timer);
  if (timeToDelay > 5000) {
    delay(timeToDelay / 1000);
    delayMicroseconds(timeToDelay % 1000);
  }
  else if (timeToDelay > 0) {
    delayMicroseconds(timeToDelay);
  }
  else
  {
    // timeToDelay is negative so we start immediately
  }
  timer = currTime + timeToDelay;
}


void sendToPC(float* data1, float* data2, float* data3){
  byte* byteData1 = (byte*)(data1);
  byte* byteData2 = (byte*)(data2);
  byte* byteData3 = (byte*)(data3);
  byte buf[12] = {byteData1[0], byteData1[1], byteData1[2], byteData1[3],
                 byteData2[0], byteData2[1], byteData2[2], byteData2[3],
                 byteData3[0], byteData3[1], byteData3[2], byteData3[3]};
  Serial.write(buf, 12);
}
