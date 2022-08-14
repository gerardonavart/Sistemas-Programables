# Práctica Final - Comunicación de un Arduino Maestro con 3 Esclavos

## Descripción
En esta práctica, aplicamos los conocimientos adquiridos durante la primera práctica de esta unidad, para poder comunicar un Arduino MEGA, que funcionaría como Maestro, con tres Arduino UNO, que funcionarían como Esclavos, utilizando la comunicación serial, aprovechando los 3 pares de puertos seriales en el Arduino MEGA.

La práctica funciona de la siguiente manera:
* El usuario pulsa un boton en la protoboard. 
* Este envía una señal al Arduino MEGA, el cual, por su puerto serial, envía una señal de encendido a un Arduino UNO, previamente identificado por su numero de esclavo, para que encienda un Led en el pin 13 del mismo Arduino.  
* Este Arduino UNO envía una señal de regreso de que el Led ha sido encendido al Arduino MEGA, y éste ultimo muestra el resultado en la consola del IDE de Arduino.
* Este proceso se replica en los otros esclavos conectados.

## Objetivo
Probar el funcionamiento de la comunicación serial entre Arduinos.

## Materiales
* Una placa protoboard
* Tres placas Arduino UNO
* Una placa Arduino MEGA
* Tres resistencias de 330 ohms.
* Tres pushbutton
* Tres Leds ultrabrillantes 
* Cables de conexión rápida
* Cables para protoboard

## Procedimiento
### Diagrama de conexión
![Diagrama conexión práctica final](https://image.ibb.co/fkimW5/Final.png)

## Video en Youtube
[Conexión de 4 Arduinos (Un maestro y tres esclavos) - Comunicación Serial](https://youtu.be/Z9q-bn_S6rU)

