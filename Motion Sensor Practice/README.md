# Sensor de Movimiento

## Descripción de la practica
Se llevará acabó la programación e instalación de un sensor de movimiento, se mostrara la conexión, así como la forma en que funciona.

## Objetivo
Comprender el funcionamiento de un sensor de movimiento, así como la conexión del mismo, a través de un Arduino UNO.

## Materiales
* 1 placa Arduino UNO
* 1 sensor de movimiento 
* Cable para protoboard
* 1 LED

## Procedimiento
* Debemos armar el circuito como se muestra en el siguiente diagrama. 
 ![Diagrama de la conexión del sensor](http://image.ibb.co/eA8OCQ/Captura_de_pantalla_19.png)

1. Cargamos el programa en el Arduino UNO, código que se implementa en el Arduino.
2. De la parte del Arduino UNO ubicamos la parte análoga y del conector denominado 5V va a salir un cable así a un extremo del sensor y se conectara en la parte denominada VCC.
3. El otro extremo del sensor denominada GND va a salir un cable al arduino UNO el cual va a ir conectado en el conector GND
4. De la parte media del sensor denominada OUT se va a conectar al Arduino en la parte de los puertos digitales denominado 2.  
5. Dela parte de los conectores de digital conectar del puerto GND a un extremo del LED, el otro extremo del LED va a ir conectado a el conector digital 13.
6. El LED va a fungir como la alarma cada que el sensor detecte movimiento.

### Así concluimos con la conexión del sensor de movimiento.

## Liga del video
[Conexión de un sensor de movimiento](https://youtu.be/SH5j3SeRaBg)
