/*
Respirador UN
Fecha : 4 / 4 / 2020
Colaboladores: Johan Ramirez
Version : 0.01
Descripcion: En el contexto de la pandemia de covid-19 la universidad nacional de colombia, tiene como motivavion construir
             Respiradores mecanicos para ayudar a mitigar las muertes asociadas a fallas respiratorias, por lo se construye 
             el control de los respiradores mecanicos basado en arduino
*/

// importacion de librerias 
#include  "Paciente.h";

// Se crea el paciente unico, puede servir a futuro 
Paciente unico;

void setup() {
  Serial.begin(9600);
  }

void loop() {
}
