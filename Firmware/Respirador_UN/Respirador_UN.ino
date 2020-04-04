/*
Respirador UN
Fecha : 4 / 4 / 2020
Colaboladores: Johan Ramirez
Version : 0.01
Descripcion: En el contexto de la pandemia de covid-19 la universidad nacional de colombia, tiene como motivavion construir
             Respiradores mecanicos para ayudar a mitigar las muertes asociadas a fallas respiratorias, por lo se construye 
             el control de los respiradores mecanicos basado en arduino
*/
byte pin = A0;

// importacion de librerias 
#include  "Paciente.h"; 
#include  "entrada.h";

// se crea objetos de interfaz, paciente 
Paciente unico;
Entrada volumen_tidal(A0);

void setup() {
  Serial.begin(9600);
  pinMode(pin,INPUT);
  
}

void loop() {
  Serial.println(volumen_tidal.medir_valor());
  Serial.println(volumen_tidal.get_pin());
  
  delay(1000);
  
  
}
