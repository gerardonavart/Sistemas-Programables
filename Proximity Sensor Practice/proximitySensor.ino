const int EchoPin = 5;    // Pin ECHO del Sensor
const int TriggerPin = 6; // Pin Trigger del Sensor
const int LedPin = 2;     // Pin asignado al Led de Comparación
const int LedPinG = 7;    // Pin asignado al Led de Pulso

void setup()
{
    Serial.begin(9600);          // Ajuste de baudios entre consola y Arduino
    pinMode(LedPin, OUTPUT);     // El Pin del Led de Comparación se establece en salida de corriente o datos
    pinMode(LedPinG, OUTPUT);    // El Pin del Led de Pulso se establece en salida de corriente o datos
    pinMode(TriggerPin, OUTPUT); // El Pin del Trigger del Sensor se establece en salida de corriente o datos
    pinMode(EchoPin, INPUT);     // El Pin del Echo del Sensor se establece en entrada de datos
}

void loop()
{
    int cm = ping(TriggerPin, EchoPin);  // Se llama a la función PING con los valores de TriggerPin y EchoPin y se asigna a la variable entera CM
    Serial.println(String(cm) + " cm."); // Se imprimen los valores retornados por la función PING
    int Limite = 50;                     // Límite de medición del sensor
    // Si el valor retornado por la función PING dentro de la variable CM es menor al Límite establecido, el Led de Comparación se enciende, de lo contrario, se apaga.
    if (cm < Limite)
        digitalWrite(LedPin, HIGH);
    else
        digitalWrite(LedPin, LOW);
    delay(1000); // Se espera 1 segundo para volver a repetir la operación
}

int ping(int TriggerPin, int EchoPin)
{
    long duracion, distanciaCm;

    digitalWrite(TriggerPin, LOW);  // Para generar un pulso limpio ponemos a LOW el disparador del sensor
    digitalWrite(LedPinG, LOW);     // Como el disparador está en LOW, el led de Pulso tambíen debe de estar en LOW
    delayMicroseconds(4);           // Esperamos 4 microsegundos
    digitalWrite(TriggerPin, HIGH); // Generamos Trigger (disparo) de 10us
    digitalWrite(LedPinG, HIGH);    // El Led de Pulso se enciende con el disparador por 10 us
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);         // El disparador deja de funcionar para esperar el rebote de la señal emitida
    digitalWrite(LedPinG, LOW);            // El Led de Pulso se apaga con el disparador
    duracion = pulseIn(EchoPin, HIGH);     // Medimos el tiempo entre pulsos, en microsegundos
    distanciaCm = duracion * 10 / 292 / 2; // Convertimos a distancia, en cm
    return distanciaCm;                    // Retornamos el valor obtenido en DISTANCIACM para que pueda ser utilizado dentro de la función LOOP, y el proceso se vuelve a repetir
}