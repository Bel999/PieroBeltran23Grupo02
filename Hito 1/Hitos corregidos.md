# Hito 1 (Arduino)
## 1. Microprocesador
El microprocesador del Arduino es el ATmega2560, tecnología CMOS de 8bits, arquitectura RISC, alcanza un 1MIPS por MHz.
## 2. -Memorias
Cuenta con una memoria Flash de 256KB de los cuales 8 KB para el arranque
SRAM de 8KB
EEPROM de 4KB
## 3. Entradas digitales
Tenemos un total de 54 entradas digitales
(Cada pin funciona a 5V y reciben o proporcionan 20mA (carga max 40mA))
## 4. Entradas analógicas
Tenemos un total de 16 entradas analógicas 
Cada una proporciona una resolucion de 10bits
## 5. Alimentación
Tiene un voltaje de operacion de 5 V
El voltaje de entrada recomendado es de 7-12 V
Aunque admite un rango de 6-20 V
## 6. Salidas de tensión
En cuanto a salidas de tension tenemos dos o bien atraves de un cable USB o atraves de una bateria externa de 9 Voltios (Se supone que admite entre 7 y 20 V)
## 7. Gnd
## 8. PWM
Tenemos 15 entradas PWM 
Son entradas de modulación de ancho de pulsos. Generan señales analógicas usando una fuente digital. Consta de dos componentes principales: un ciclo de trabajo (señal en estado alto) y una frecuencia 
(que determina la velocidad entre el estado alto y bajo)
## 9. Uarts
Protocolo en serie, tenemos puertos en linea TX y RX que se cruzan para comunicar dos dispositivos. El harware que transmite TX y el que recive RX se transmite 8bits de datos
## 10. Comunicacion SPI
Protocolo en serie, Maestro-Esclavo el maestro envia una señal de reloj y tras cada pulso envia un bit l esclabo
(Señales SCK(reloj), MOSI(m out s in), MISO(m in s out))
### Bibliografía
[1] [Arduino Mega 2560 Rev3 — Arduino Official Store](https://store.arduino.cc/products/arduino-mega-2560-rev3)
[2] [▷ Arduino Mega 2560 Características, Especificaciones | Proyecto Arduino](https://proyectoarduino.com/arduino-mega-2560/)
[3] [Interrupciones con Arduino a través de un ejemplo práctico (programarfacil.com)](https://programarfacil.com/blog/arduino-blog/interrupciones-con-arduino-ejemplo-practico/)
