
# Fotoresistencias

## Descripción de la practica
Se llevará acabó la programación e instalación de una fotoresistencia, que se montará en una protoboard.

## Objetivo
Comprender el funcionamiento de la fotoresistencia, así como la conexión de la misma utilizando un Arduino UNO.

## Materiales
* 1 Placa Arduino uno
* 1 Fotoresistencia 
* Cable para protoboard
* 1 Protoboard
* 1 LED
* 1 Resistencia de 1 kilo ohm

## Procedimiento
1. Cargamos el programa en el Arduino UNO.
2. Debemos armar el circuito como se muestra en el siguiente diagrama. 

![Diagrama de la conexión.](http://image.ibb.co/mLiyCQ/Captura_de_pantalla_15.png)

3. De la parte del Arduino UNO ubicamos la parte análoga y del conector denominado A0 va a salir un cable así a la Protoboard a un extremo de nuestra fotoresistencia.
4. El otro extremo de la fotoresistencia se conectará a la alimentación del positivo (es importante recordar que la fotoresistencia no tiene polaridad.).  
5. De la parte de los conectores de digital conectar del puerto GND a la protoboard con la alimentación negativa.
6. Posteriormente el puerto 13 se conecta la protoboard en un extremo de la resistencia de 1 kilo ohm, el otro extremo va conectado al extremo del LED positiva, el otro extremo del LED va conectado a la alimentación negativa.
Así concluimos la conexión del sensor en la protoboard

Nota: Es importante recordar que el LED tienen polaridad y hay que respetarla.

## Liga del video
[Conexión de fotoresistencia](https://youtu.be/TATvSclthYY)

