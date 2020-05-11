class movimiento{
  public : 
    byte Frecuencia;                  // Valor configurado por el medico 
    byte volumen;                     // Valor Configurado por el medico
    byte Relacion;                    // Valor Configurado por el medico      
    double velocidad_subida;             // Calculado Inspiracion           
    double aceleracion_subida;           // Calculado Inspiracion
    double posicion_Final_subida;        // Calculado Inspiracion
    double Tiempo_meseta;                // Calculado Meseta
    double Velocidad_bajada;     // Calculado espiracion
    double acelaracion_bajada;   // Calculado espiracion
    double modo_motor;
    float coeficiente;
    double Tiempo_pausa;
    double offset; 
    
  //Constructor 
  movimiento (){
    Frecuencia = 0;               
    volumen = 0;                     
    Relacion = 0;                    
    velocidad_subida = 0;             
    aceleracion_subida = 0;           
    posicion_Final_subida = 0;        
    Tiempo_meseta = 0;                
    Velocidad_bajada = 0;     
    acelaracion_bajada = 0;
    modo_motor = 0.5;
    coeficiente = 0;
    Tiempo_pausa = 0;
    offset = 40; //Es el offset de la mordaza, distancia del home al Ambu
  }

  int get_velocidad_subida(){return velocidad_subida;}
  int get_posicion_Final_subida(){return posicion_Final_subida;}

  
  void SetParametros(byte frec, byte vol,byte rela){

    //relacion de tiempo sirve para definir subida y bajada 
    double tiempo_Ciclo = 60 /(2*frec+10);

    // Espiracion
    double Tiempo_bajada = tiempo_Ciclo*(double(rela)/(rela+1))*0.7;
    Tiempo_pausa =  tiempo_Ciclo*(double(rela)/(rela+1))*0.3;
    double Tiempo_inicio =  tiempo_Ciclo*(1.0/(rela+1))*.7;
    double Tiempo_final =  Tiempo_inicio + Tiempo_bajada;
    double delta_tiempo = Tiempo_inicio  - Tiempo_final;
    

    // Inspiracion 
    posicion_Final_subida  = ((vol*100.0)/5.7+offset); // 40 es un offset del tornillo   
    aceleracion_subida = ((posicion_Final_subida)/16)/((Tiempo_inicio*Tiempo_inicio)/2);
    
    // se calcula tiempo de meseta 
    Tiempo_meseta = tiempo_Ciclo*(1.0/(rela+1))*.3;
    Velocidad_bajada = posicion_Final_subida/bajada;
  }  
};
