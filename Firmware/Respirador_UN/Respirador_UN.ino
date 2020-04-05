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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include  "Paciente.h"; // se usara para configurar las variables del paciente 
#include  "entrada.h";  // se usa para configurar los botones

// se crea objetos de interfaz, paciente 
Paciente unico;
Entrada Poteciometro_volumen(A0);
Entrada Poteciometro_frecuencia(A1);
Entrada Poteciometro_presion(A2);
LiquidCrystal_I2C MyLCD(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// prototipos 
void imprimirLCD();
void setup() {
  MyLCD.begin(16, 2); 
}

void loop() {
  imprimirLCD();
  delay(1000);
  }

void imprimirLCD(){
  MyLCD.setCursor(0,0);
  MyLCD.print("                ");
  MyLCD.setCursor(0,0);
  MyLCD.print("Vt:"+ String(Poteciometro_volumen.medir_valor()));  
  MyLCD.print("Fr:"+ String(Poteciometro_frecuencia.medir_valor()));  
  MyLCD.print("Pr:"+ String(Poteciometro_presion.medir_valor()));  
  MyLCD.setCursor(0,1);
  MyLCD.print("  Configurando");  
}
