int id; // Variable del identificador del Esclavo

int p1 = 10;
int p2 = 9;
int p3 = 8;

int inicio1 = 0;
int inicio2 = 0;
int inicio3 = 0;

int controlA = 0;
int controlB = 0;
int controlC = 0;

int estadoA1 = 0;
int estadoB1 = 0;

int estadoA2 = 0;
int estadoB2 = 0;

int estadoA3 = 0;
int estadoB3 = 0;

void setup()
{
    Serial.begin(9600);  // Configuracion del puerto serial de comunicacion con la PC
    Serial1.begin(9600); // Configuracion del puerto serial de comunicacion con el ESCLAVO 1
    Serial2.begin(9600); // Configuracion del puerto serial de comunicacion con el ESCLAVO 2
    Serial3.begin(9600); // Configuracion del puerto serial de comunicacion con el ESCLAVO 3

    // Mensaje inicial en el monitor serial
    Serial.println("\t\t\t\tEnvío de datos seriales a través de Arduino\n");
    Serial.println("Identificador de Arduinos:");
    Serial.println(" - Zeus (Arduino Maestro) \n - Ares (Arduino 1) \n - Apolo (Arduino 2) \n - Atenea(Arduino 3)\n");

    pinMode(p1, INPUT);
    pinMode(p2, INPUT);
    pinMode(p3, INPUT);
}

void loop()
{
    identificacion_esclavo();
    mensaje_esclavo();
}

void identificacion_esclavo()
{ // RUTINA DE IDENTIFICACION DE ESCLAVOS 1, 2 y 3

    estadoA1 = digitalRead(p1);

    if (estadoA1 && estadoB1 == 0)
    {
        inicio1 = 1 - inicio1;
        delay(100);
    }

    estadoB1 = estadoA1;

    if (inicio1 == 0 && controlA == 1)
    {
        Serial1.write('a');
        // Serial.println("Led Encendido en Ares (A1)\n");
        controlA = 0;
    }

    else if (inicio1 == 1 && controlA == 0)
    {
        Serial1.write('A');
        // Serial.println("Led Apagado en Ares (A1)\n");
        controlA = 1;
    }

    estadoA2 = digitalRead(p2);

    if (estadoA2 && estadoB2 == 0)
    {
        inicio2 = 1 - inicio2;
        delay(100);
    }

    estadoB2 = estadoA2;

    if (inicio2 == 0 && controlB == 1)
    {
        Serial2.write('b');
        Serial.println("Led Encendido en Apolo (A2)\n");
        controlB = 0;
    }

    else if (inicio2 == 1 && controlB == 0)
    {
        Serial2.write('B');
        Serial.println("Led Apagado en Apolo (A2)\n");
        controlB = 1;
    }

    estadoA3 = digitalRead(p3);

    if (estadoA3 && estadoB3 == 0)
    {
        inicio3 = 1 - inicio3;
        delay(100);
    }

    estadoB3 = estadoA3;

    if (inicio3 == 0 && controlC == 1)
    {
        Serial3.write('c');
        Serial.println("Led Encendido en Atenea (A3)\n");
        controlC = 0;
    }

    else if (inicio3 == 1 && controlC == 0)
    {
        Serial3.write('C');
        Serial.println("Led Apagado en Atenea (A3)\n");
        controlC = 1;
    }
}

void mensaje_esclavo()
{ // RUTINA DE ACREDITACION DE IDENTIFICACION

    // RUTINA DE ACREDITACION DEL ESCLAVO 1
    while (Serial1.peek() == 'A')
    { // Discriminacion de la letra como diferenciador del esclavo
        Serial1.read();
        id = Serial1.parseInt();      // Extraccion de los numeros de las letras
        Serial.print("Esclavo id: "); // Mensaje de acreditacion del esclavo
        Serial.println(id);           // Numero de identificacion del esclavo
        break;
    }

    // RUTINA DE ACREDITACION DEL ESCLAVO 2
    while (Serial2.peek() == 'B')
    { // Discriminacion de la letra como diferenciador del esclavo
        Serial2.read();
        id = Serial2.parseInt();      // Extraccion de los numeros de las letras
        Serial.print("Esclavo id: "); // Mensaje de acreditacion del esclavo
        Serial.println(id);           // Numero de identificacion del esclavo
        break;
    }

    // RUTINA DE ACREDITACION DEL ESCLAVO 3
    while (Serial3.peek() == 'C')
    { // Discriminacion de la letra como diferenciador del esclavo
        Serial3.read();
        id = Serial3.parseInt();      // Extraccion de los numeros de las letras
        Serial.print("Esclavo id: "); // Mensaje de acreditacion del esclavo
        Serial.println(id);           // Numero de identificacion del esclavo
        break;
    }
}

const int led = 13;

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600); // Configuracion del puerto serial de comunicacion con el ESCLAVO
}

void loop()
{
    if (Serial.available())
    { // Verificacion que el puerto serial recibe datos
        delay(10);

        identificacion(); // Rutina de identificacion de esclavos 1 y 2

        while (Serial.available() > 0)
        {
            Serial.read();
        } // Rutina de limpieza del buffer del puerto serial
    }
}

void identificacion()
{
    // RUTINA DE IDENTIFICACION FISICA Y AUTENTIFICACION
    while (Serial.peek() == 'a')
    { // Discriminacion de la letra de identificacion
        // Cambiar 'a' por 'b' para el segundo esclavo

        digitalWrite(led, HIGH); // Encendido del LED del PIN 13
        Serial.write('a');       // Envio de la letra de incio de trama de autentificacion
        Serial.print('a');       // Envio del numero de autentificacion del esclavo al Maestro
        // Cambiar Serial.print(1) por Serial.print(2) para el segundo esclavo
        break;
    }

    // RUTINA DE IDENTIFICACION FISICA Y AUTENTIFICACION
    while (Serial.peek() == 'A')
    { // Discriminacion de la letra de identificacion
        // Cambiar 'a' por 'b' para el segundo esclavo

        digitalWrite(led, LOW); // Encendido del LED del PIN 13
        Serial.write('A');      // Envio de la letra de incio de trama de autentificacion
        Serial.print('A');      // Envio del numero de autentificacion del esclavo al Maestro
        // Cambiar Serial.print(1) por Serial.print(2) para el segundo esclavo
        break;
    }
}