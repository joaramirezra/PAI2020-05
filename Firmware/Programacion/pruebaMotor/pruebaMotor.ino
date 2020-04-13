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
  stepper.setMaxSpeed(12000);     
  stepper.setAcceleration(1600);
  digitalWrite(enable, LOW);
  Serial.begin(9600);
  delay(1000);
  
  int posicion_final= 20000; 
  int velocidad_Subida = 000;
  Serial.println("hola Perros");
  stepper.setSpeed(velocidad_Subida);
  stepper.moveTo(posicion_final);
//  stepper.runToPosition();
  stepper.run();
  
  Serial.println("Adios Perros");
}

void loop() {  
<<<<<<< HEAD
  stepper.run();
  if(millis()%100 == 0) Serial.println(String(millis())+" "+String(stepper.speed())+" Posicion "+String(stepper.currentPosition()));
=======

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
>>>>>>> 64b7da5f9310ab2fbdbfc2758c7b528668dadaa7
}
