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
#include  "Paciente.h"                          // se usara para configurar las variables del paciente 
#include  "entrada.h"                           // se usa para configurar los botones

// se crea objetos de interfaz, paciente 
Paciente unico;
Entrada Poteciometro_volumen(A0);
Entrada Poteciometro_frecuencia(A1);
Entrada Poteciometro_presion(A2);
Entrada boton_modo_operacion(3,1);
Entrada boton_confirmacion(2,1);

// se crea el lcd
LiquidCrystal_I2C MyLCD(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// prototipos 
void imprimirLCD();
void limpiar_lcd();
void configurar_parametros();

void setup() {
  MyLCD.begin(16, 2); 
}

void loop() {
  if(boton_modo_operacion.medir_valor()){
    if(boton_confirmacion.medir_valor())configurar_parametros();
    else Impresion_lcd_configurando();
  }
  else Impresion_lcd_operando();
  delay(500);
  }

void Impresion_lcd_configurando(){
  limpiar_lcd();
  MyLCD.setCursor(0,0);
  MyLCD.print("Vt:"+ String(Poteciometro_volumen.medir_valor()));  
  MyLCD.print("Fr:"+ String(Poteciometro_frecuencia.medir_valor()));  
  MyLCD.print("Pr:"+ String(Poteciometro_presion.medir_valor()));  
  MyLCD.setCursor(0,1);
  MyLCD.print("  Configurando");  
}

void Impresion_lcd_operando(){
  limpiar_lcd();
  MyLCD.setCursor(0,0);
  MyLCD.print("Vt:"+ String(unico.get_frecuencia()));  
  MyLCD.print("Fr:"+ String(unico.get_volumen_tidal()));  
  MyLCD.print("Pr:"+ String(unico.get_presion()));  
  MyLCD.setCursor(0,1);
  MyLCD.print("Vt:"+ String(Poteciometro_volumen.medir_valor()));  
  MyLCD.print("Fr:"+ String(Poteciometro_frecuencia.medir_valor()));  
  MyLCD.print("Pr:"+ String(Poteciometro_presion.medir_valor()));  
}

void configurar_parametros(){
  unico.Set_parametros(Poteciometro_volumen.medir_valor(),Poteciometro_frecuencia.medir_valor(),Poteciometro_presion.medir_valor());  
  limpiar_lcd();
  MyLCD.setCursor(0,0);
  MyLCD.print("Listo");
  delay(500);
    
  }


void limpiar_lcd(){
  MyLCD.setCursor(0,0);
  MyLCD.print("                ");
  MyLCD.setCursor(0,1);
  MyLCD.print("                ");
}
