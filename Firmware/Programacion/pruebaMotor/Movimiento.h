class movimiento{
  public : 
    byte Frecuencia;                  // Valor configurado por el medico 
    byte volumen;                     // Valor Configurado por el medico
    byte Relacion;                    // Valor Configurado por el medico      
    int velocidad_subida;             // Calculado Inspiracion           
    int aceleracion_subida;           // Calculado Inspiracion
    int posicion_Final_subida;        // Calculado Inspiracion
    int Tiempo_meseta;                // Calculado Meseta
    int Velocidad_inicial_bajada;     // Calculado espiracion
    int acelaracion_inicial_bajada;   // Calculado espiracion
  
  //Constructor 
  movimiento (){
    Frecuencia = 0;               
    volumen = 0;                     
    Relacion = 0;                    
    velocidad_subida = 0;             
    aceleracion_subida = 0;           
    posicion_Final_subida = 0;        
    Tiempo_meseta = 0;                
    Velocidad_inicial_bajada = 0;     
    acelaracion_inicial_bajada = 0;   
  }
  void SetParametros(byte frec, byte vol,byte rela){
    //relacion de tiempo sirve para definir subida y bajada 
    int tiempo_Ciclo = 60 /(2*frec+10);
    byte offset = 40; // en mm
    posicion_Final_subida  = vol/5.7 + offset; // 40 es un offset de la
    // la velocidad de subida se calcula asi :
    // v = dx/dt , como inicia en la posicion cero en el t = 0 entonces
    // v = (posicion final)/(tiempo que sube)
    // la posicion final se encuentra como la relacion del volumen tidal
    // mas un offset del desplazamiento del tornillo
    // el tiempo de subida se halla como el tiempo de inspiracion total
    // menos el tiempo de meseta como relacion el uno del otro 
    // [X,X,X,X,Y,Y,Y,Y]
    // donde el tiempo de inspiracion es la relacion del tiempo total 
    // por lo cual, ti = (tiempo_total)*(relacion/(relacion+1)
    velocidad_subida = (posicion_Final_subida/((tiempo_Ciclo*(rela/(rela+1)))/2));   
    aceleracion_subida = 0
    // se calcula tiempo de meseta 
     
  }  
};
