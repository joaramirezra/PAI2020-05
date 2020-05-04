#include <AccelStepper.h>
#define enable 8

AccelStepper stepper = AccelStepper(1, 3, 2); // pin 3 : step, pin 2 : dir ; 1 indica que es driver

int velocidad = 1000;
int velocidad_max = 4000;
int aceleracion = 2000;
int posicion = 2500;

void setup() {
  // Se envia a home
  stepper.setCurrentPosition(0);
  pinMode(enable, OUTPUT);

  // se configuran los parametros del motor inicial
  stepper.setMaxSpeed(velocidad_max);
  stepper.setAcceleration(aceleracion);
  // Se habilita el motor para funcionar
  digitalWrite(enable, LOW);
  Serial.begin(9600);
  stepper.moveTo(25000);
}

bool tipo = 0; // 0 : velocidad cte ; 1 : aceleracion cte

void loop() {
//  stepper.setCurrentPosition(0);
//  stepper.setSpeed(velocidad);
//  
//  if(stepper.distanceToGo()>0)
    stepper.run();
  //
  //  if(tipo==0){
  //    stepper.moveTo(posicion);
  //    stepper.setSpeed(velocidad);
  //    while(stepper.distanceToGo()>0){
  //      stepper.runSpeed();
  //    }
  //    stepper.moveTo(0);
  //    while(stepper.distanceToGo()>0){
  //      stepper.runSpeed();
  //    }
  //  }
  //  if(tipo==1){
  //    stepper.moveTo(posicion);
  //    while(stepper.currentPosition()<posicion){
  //      if(millis()%1000== 0)Serial.println(stepper.currentPosition());
  //      stepper.run();
  //    }
  //    stepper.moveTo(0);
  //    while(stepper.currentPosition()>0){
  //      if(millis()%1000== 0)Serial.println(stepper.currentPosition());
  //      stepper.run();
  //    }
  //  }

}
