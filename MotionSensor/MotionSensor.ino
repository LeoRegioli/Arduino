#define motionSensor 7
#define led 13
byte a;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(motionSensor, INPUT);
    Serial.begin(9600);
}

void loop()
{
    a = digitalRead(motionSensor);

    if (a == 1)
    {
        digitalWrite(led, HIGH);
    }
    else
    {
        digitalWrite(led, LOW);
    }

    Serial.print(a);
    Serial.print(" ");
    delay(1000);
}