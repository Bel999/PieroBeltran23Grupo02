
# Hito 2 Preguntas sobre el modelo matematico de un motor

## 1)Que es un modelo matematico 

Un modelo es un conjunt de relaciones que, empleamos para representar y describir un
sistema de forma simple, por ende un modelo matematico es aquel que emplea un conjuto 
de ecuaciones diferenciales para describir dicho sistema.

## 2)Cual son las especificaciones que nos interesan para realizar el modelado del motor
-Velocidad maxima
-Torque maximo
-inercia del rotor
-voltaje de operacion
-corriente de operacion
-tipo de motor
-constante de tiempo

## 3)En que unidades debemos trabajar
-Velocidad maxima [RPM] 
-Torque maximo [N*m]
-inercia del rotor [Kg*m^2]
-voltaje de operacion [V]
-corriente de operacion [A]
-tipo de motor [-]
-constante de tiempo [s]

## 4)Que son las funciones de transferencia 
Son ecuaciones algebraicas que se optienen apartir del las ecuaciones dieferenciales que 
modelan el porceso, las funciones de transferencia ni depeneden del tiempo

## 5)Que ecuaciones debemos de utilizar para definir el modelo

v(t)=Ri(t)+L(di(t)/dt)+E_a

J(dw/dt)=T_m(t)-Bw(t)

E_a(t)=K_a*w(t)

T_m=K_m*i(t)

L_s*i(s)=v(s)-R*i(s)-E_a(s)

J_s*w(s)=T_m(s)-B*w(s)

E_a(s)=K_a*w(s)

T_m(s)=K_m*i(s)

v(s)=((R+L_s)*T_m)/K_m-+K_a*w(s)

W(s)=T_m(s)/(J_s+B)

## 6)Que requisitos hacen falta para empezar a crear el modelo en simulink
Las constantes o parametros del motor y las funciones de transferencia

## 7)Como modelamos en simulink
simplemente creamos un nuevo proyecto, y con los bloques de math operation vamos
construyendo las diferentes ecuaciones previamente calculadas

### B
[1]https://controlautomaticoeducacion.com/analisis-de-sistemas/modelo-de-motor-dc/
