const int sensorPin = A5;
const int ledPin = 13;

void setup()
{
    Serial.begin(9600);
    pinMode(sensorPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int sensorStatus = analogRead(sensorPin);
    Serial.print(sensorStatus);
    Serial.print("\n");
    digitalWrite(ledPin, sensorStatus);
    delay(100);
}
