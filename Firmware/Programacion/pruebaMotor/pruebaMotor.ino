#include <AccelStepper.h>

#define boton 7
#define enable 8
#define homing 4

int dato=0;
bool activateMovement = 0 ;
AccelStepper stepper = AccelStepper(1, 3, 2); // pin 3 : step, pin 2 : dir ; 1 indica que es driver

void setup() {
  stepper.setCurrentPosition(0);
  pinMode(enable, OUTPUT);
  stepper.setMaxSpeed(3000);     
  stepper.setAcceleration(1000);
  digitalWrite(enable, LOW);
}

void loop() {  

  int velocidad_Subida = 300;
  int tiempo_meseta = 5000; // milisegundos
  // inspiracion 
 
  stepper.moveTo(0); 
  stepper.runToPosition();
  stepper.setSpeed(velocidad_Subida);
  stepper.moveTo(500);
  stepper.runToPosition();
  // Meseta
  delay(1500);

  // expiracion
  stepper.moveTo(0); 
  stepper.runToPosition();
  delay(500); 
}
