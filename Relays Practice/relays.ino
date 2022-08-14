const int pinSensor = 3;
const int pinTransistor = 4;
int estado;

void setup()
{
    pinMode(pinSensor, INPUT);
    pinMode(pinTransistor, OUTPUT);
    digitalWrite(pinTransistor, LOW);
}

void loop()
{
    estado = digitalRead(pinSensor); // Se obtiene el estado del sensor
    if (estado == HIGH)
    {
        digitalWrite(pinTransistor, HIGH); // Se enciende el transistor
    }
    else
    {
        digitalWrite(pinTransistor, LOW); // Se apaga el transistor
    }
}