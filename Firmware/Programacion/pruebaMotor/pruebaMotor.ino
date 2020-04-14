#include <AccelStepper.h>
#include "Movimiento.h"
#define enable 8

AccelStepper stepper = AccelStepper(1, 3, 2); // pin 3 : step, pin 2 : dir ; 1 indica que es driver

movimiento cicloRespiratorio;

byte Volumen = 3;
byte frecuencia= 2.5; 
byte relacion = 1; 

void setup() {
  // Se configura la posicion actual del motor como cero y se habilita el pin del enable
  stepper.setCurrentPosition(0);
  pinMode(enable, OUTPUT);
<<<<<<< HEAD
  
  // se configuran los parametros del motor inicial
  stepper.setMaxSpeed(6000);   
  stepper.setAcceleration(0);  
  
  // Se habilita el motor para funcionar
  digitalWrite(enable, LOW);
  Serial.begin(9600);
  // se configuran parametros de configuracion
//  Serial.println(cicloRespiratorio.SetParametros(frecuencia , Volumen , relacion)); 
  cicloRespiratorio.SetParametros(frecuencia , Volumen , relacion); 
  //Serial.printl
  //Serial.println("velocidad SUBIDA" + String(cicloRespiratorio.velocidad_subida) + "posicion "+String(cicloRespiratorio.posicion_Final_subida));
  //delay(1500);
=======
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
>>>>>>> 13423d920c27a60e677d8e9bdc3eab104e8f7881
}

byte ciclo = 1;
double tiempo =0;
void loop() {  
<<<<<<< HEAD
 // inspiracion 
  if(ciclo == 1){ // inspiracion 
    stepper.moveTo(cicloRespiratorio.posicion_Final_subida-2000);
    stepper.setSpeed(cicloRespiratorio.velocidad_subida);
    ciclo = 2;
//    Serial.println("inicio : " +String(millis()));
   }
  if(stepper.distanceToGo()>0 && ciclo == 2 )stepper.runSpeed();
  
  if(stepper.distanceToGo()<=0 && ciclo == 2 ){// inicio meseta
    ciclo = 3 ;
    tiempo = millis();
    }

  if(ciclo == 3 && millis()<(tiempo+cicloRespiratorio.Tiempo_meseta*1000)){}//fin meseta
  else if(ciclo == 3 && millis() >= (tiempo +cicloRespiratorio.Tiempo_meseta*1000)){
    ciclo = 4;
    }//fin meseta

  // Expiracion 
  if(ciclo == 4 ){
     stepper.setSpeed(cicloRespiratorio.Velocidad_inicial_bajada);
     stepper.setAcceleration(cicloRespiratorio.acelaracion_bajada);
     stepper.moveTo(0);
    }

  if(stepper.distanceToGo()<0 && ciclo == 4 )stepper.run();
  
  if(stepper.distanceToGo()>=0 && ciclo == 4 ){// inicio meseta
    ciclo = 5 ;
    tiempo = millis();
    }
  if(ciclo == 5 && millis()<(tiempo+cicloRespiratorio.Tiempo_pausa*1000)){}//fin meseta
  else if(ciclo == 5 && millis()>= (tiempo+cicloRespiratorio.Tiempo_meseta*1000)){
    ciclo = 1;
   }//fin meseta

  if( millis()%1000 == 0) Serial.println("tiempo" +String(millis())+ "Posicion " + stepper.currentPosition());
=======
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
>>>>>>> 13423d920c27a60e677d8e9bdc3eab104e8f7881
}
