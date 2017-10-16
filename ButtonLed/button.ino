#define led 13
#define btn 2

byte state = 0,
     a = 0;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop()
{
    a = digitalRead(button);
    if (a == 0)
    {
        blink();
        digitalWrite(led, state);
        delay(200);
    }
}

void blink()
{
    state = !state;
}