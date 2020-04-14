#include <AccelStepper.h>
#include "Movimiento.h"
#define enable 8

AccelStepper stepper = AccelStepper(1, 3, 2); // pin 3 : step, pin 2 : dir ; 1 indica que es driver

movimiento cicloRespiratorio;

byte Volumen = 2.5;
byte frecuencia= 0; 
byte relacion = 1; 

void setup() {
  // Se configura la posicion actual del motor como cero y se habilita el pin del enable
  stepper.setCurrentPosition(0);
  pinMode(enable, OUTPUT);
  
  // se configuran los parametros del motor inicial
  stepper.setMaxSpeed(6000);   
  stepper.setAcceleration(2800);  
  
  // Se habilita el motor para funcionar
  digitalWrite(enable, LOW);
  Serial.begin(9600);
  // se configuran parametros de configuracion
//  Serial.println(cicloRespiratorio.SetParametros(frecuencia , Volumen , relacion)); 
  cicloRespiratorio.SetParametros(frecuencia , Volumen , relacion); 
  //Serial.printl
  //Serial.println("velocidad SUBIDA" + String(cicloRespiratorio.velocidad_subida) + "posicion "+String(cicloRespiratorio.posicion_Final_subida));
  //delay(1500);
}

byte ciclo = 1;
double tiempo = 0;
void loop() {   
  // Inicio inspiracion -----------------------------------------------------------------
  if(ciclo == 1){  
    stepper.moveTo(cicloRespiratorio.posicion_Final_subida-2000);
    stepper.setSpeed(cicloRespiratorio.velocidad_subida);
    ciclo = 2;
   // Serial.println("Inicia Respiracion");
   }
  // corre a velocidad constante 
  else if(stepper.distanceToGo() >0 && ciclo == 2 )stepper.runSpeed();
  
  // inicio meseta ----------------------------------------------------------------------
  else if(stepper.distanceToGo() <=0 && ciclo == 2 ){
    ciclo = 3 ;
   // Serial.println("Inicia Meseta"); 
    tiempo = millis();
  }

  else if(ciclo == 3 && millis() <  (tiempo + cicloRespiratorio.Tiempo_meseta*1000)){}//fin meseta
  else if(ciclo == 3 && millis() >= (tiempo + cicloRespiratorio.Tiempo_meseta*1000)){
    ciclo = 4;
    //Serial.println("FIN Meseta"); 
  }//fin meseta

  // Expiracion 
  else if(ciclo == 4 ){ 
     stepper.setSpeed(cicloRespiratorio.Velocidad_inicial_bajada);
     //stepper.setAcceleration(cicloRespiratorio.acelaracion_bajada);
     
     stepper.moveTo(0);
     //Serial.println("Inicio Expiracion");
     delay(100);
     ciclo = 5;
    }

  else if(stepper.distanceToGo()<0 && ciclo == 5 ){
    //if(millis()%100 == 0)
      //Serial.println("V" + String(stepper.speed())+" P2" + String(cicloRespiratorio.Velocidad_inicial_bajada));
    stepper.run();
    }
  
  else if(stepper.distanceToGo()>=0 && ciclo == 5 ){// inicio meseta
    //Serial.println("Inicio pausa");
    ciclo = 6 ;
    tiempo = millis();
    }
    
  else if(ciclo == 6 && millis() < (tiempo+cicloRespiratorio.Tiempo_pausa*1000)){}//fin meseta
  else if(ciclo == 6 && millis() >= (tiempo+cicloRespiratorio.Tiempo_pausa*1000)){
    ciclo = 1;
   }//fin meseta
  if( millis()%1000 == 0) Serial.println("Posicion " + String(stepper.currentPosition()));
}
