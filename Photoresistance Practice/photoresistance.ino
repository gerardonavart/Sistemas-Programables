const int ledPin = 13;
const int ldrPin = A0;
void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(ldrPin, INPUT);
}
void loop()
{

    int ldrStatus = analogRead(ldrPin);
    Serial.print(ldrStatus);
    Serial.print("\n");
    if (ldrStatus > 100)
        digitalWrite(ledPin, HIGH);
    else
        digitalWrite(ledPin, LOW);
    delay(100);
}