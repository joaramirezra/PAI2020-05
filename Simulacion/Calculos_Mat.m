%UNIVERSIDAD NACIONAL DE COLOMBIA
%PROTOTIPO RESPIRACIÓN MECÁNICA
%EQUIPO 5
clear;
Frecuencia = 15 % #Respiraciones
Step = 400
T_Ciclo = 60/Frecuencia %segundos
Rel_Ins_Exp = 1/2   %Relación Insporación/Expiración
V_Tidal = 400 %Volumen Tidal ml

T_Ins = T_Ciclo*Rel_Ins_Exp
T_Exp = T_Ciclo - T_Ins

%Porcentajes de tiempos de Fase

Pc_Flujo_Ins = 0.65
Pc_Meseta = 0.35

Pc_Flujo_Exp = 0.7
Pc_Pausa = 0.3

%Tiempos de Proceso

T_Flujo_Ins = round(Pc_Flujo_Ins*T_Ins*1000)
T_Meseta = round(Pc_Meseta*T_Ins*1000)
T_Flujo_Exp = round(Pc_Flujo_Exp*T_Exp*1000)
T_Pausa = round(Pc_Pausa*T_Exp*1000)

%Puntos de Tiempo inicio
T1 = T_Flujo_Ins
T2 = T1+(T_Meseta) 
T3 = T2+(T_Flujo_Exp)
T4 = T3+(T_Pausa)

%Verificación
T_Ciclo_Ver = T_Flujo_Ins + T_Meseta + T_Flujo_Exp + T_Pausa
Tiempo = [0:1:(T_Ciclo*1000)];

%Ciclo de Inspiración
%Fase de Flujo

Pendiente = V_Tidal/T_Flujo_Ins

for x=0:1:T1
   Volumen(x+1) = Pendiente*Tiempo(x+1);
   %disp(x)
   disp(Volumen(x+1))
end

%Fase Meseta

for x=T1:1:T2
   Volumen(x+1) = V_Tidal;
  %disp(x)
end

%Ciclo de Expiración
%Fase de Flujo

Vertice = [T3 0]
P = [T2,V_Tidal]
h = Vertice(1)
k = Vertice(2)
x = P(1)
y = P(2)
a = (y+k)/(x-h)^2

for x=T2:1:T3
   %Volumen(x+1) = V_Tidal - Pendiente*(Tiempo(x+1)-T2); LINEAL
   Volumen(x+1) = a*((Tiempo(x+1)-h)^2)-k;   
end

%Fase Pausa

for x=T3:1:T4
   Volumen(x+1) = 0;
   %disp(x)
end

minLength = min(length(Tiempo), length(Volumen));
Tiempo = Tiempo(1:minLength);
Volumen = Volumen(1:minLength);
figure(1)
plot(Tiempo,Volumen,'g','LineWidth',2)
title('Perfil de Volumen Tidal')
xlabel('Tiempo [mSeg]') 
ylabel('Volumen [ml]') 

Offset = 40
Pos_Junta = Volumen/5.7 + Offset;
Vel_Junta = diff(Pos_Junta)*1000
Acel_Junta = diff(Vel_Junta)*1000

Vel_Junta(length(Tiempo)) = 0;
Acel_Junta(length(Tiempo)) = 0;

figure(2)
subplot(3,1,1)
plot(Tiempo,Pos_Junta,'b','LineWidth',2)
title('Perfil de posición de la junta')
xlabel('Tiempo [mSeg]') 
ylabel('Distancia [mm]') 

subplot(3,1,2)
plot(Tiempo,Vel_Junta,'b','LineWidth',2)
title('Perfil de velocidad de la junta')
xlabel('Tiempo [mSeg]') 
ylabel('Velocidad [mm/seg]') 

subplot(3,1,3)
plot(Tiempo,Acel_Junta,'b','LineWidth',2)
title('Perfil de aceleracion de la junta')
xlabel('Tiempo [mSeg]') 
ylabel('Aceleración [mm/seg^2]') 


%Calculo Perfiles Movimiento

%Sección 1 - Flujo Inspiración
P1 = [Tiempo(1),Pos_Junta(1)]
P2 = [Tiempo(T1),Pos_Junta(T1)]
Vel = (P2(2)-P1(2))/(P2(1)-P1(1))*1000
Acel = 0
P_I = Offset
P_F = Offset + (Vel)*(T1/1000)

%Sección 2 - Meseta
Vel = 0
Acel = 0
P_I = Offset + (Vel)*(T1/1000)
P_F = P_I

%Sección 3 - Flujo de Expiración
Acel = 2*a*(T2-T3)
P_I = Offset + (Vel)*(T1/1000)
P_F = 0


Pos_Motor = Pos_Junta/8
Pos_Motor = Pos_Motor*Step
Vel_Motor = diff(Pos_Motor)
Acel_Motor = diff(Pos_Motor,2)

Vel_Motor(length(Tiempo)) = 0;
Acel_Motor(length(Tiempo)) = 0;


figure(3)
subplot(3,1,1)
plot(Tiempo,Pos_Motor,'y','LineWidth',2)
title('Perfil de posición del motor')
xlabel('Tiempo [mSeg]') 
ylabel('Distancia [pasos]') 

subplot(3,1,2)
plot(Tiempo,Vel_Motor,'y','LineWidth',2)
title('Perfil de velocidad del motor')
xlabel('Tiempo [mSeg]') 
ylabel('Velocidad [pasos/seg]') 

subplot(3,1,3)
plot(Tiempo,Acel_Motor,'y','LineWidth',2)
title('Perfil de aceleracion del motor')
xlabel('Tiempo [mSeg]') 
ylabel('Aceleración [pasos/seg^2]') 