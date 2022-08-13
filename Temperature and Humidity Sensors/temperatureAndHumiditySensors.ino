#include <Adafruit_Sensor.h> 
#include <DHT.h>

#define DHTTYPE                 \
    DHT11 const int DHTpin = 5; \
    DHT dht(DHTpin, DHTTYPE);   \
    void setup()                \
    {}

void loop()
{
    if (isnan(h) | isnan(t))
    {
        Serial.println("Fallo en la lectura del sensor");
        return;
    }

    Serial.print("Humedad:");
    Serial.print(h);
    Serial.print("Temperatura:");
    Serial.print(t);
    Serial.print("\n");
}