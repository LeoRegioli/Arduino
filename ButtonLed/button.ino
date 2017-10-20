#define led 8
#define btn 2

byte state = 0,
     a = 0;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(btn, INPUT);
    Serial.begin(9600);
}

void loop()
{
    a = digitalRead(btn);
    if (a == 1)
    {
        blink();
        digitalWrite(led, state);
        delay(500);
    }
    
}

void blink()
{
    state = !state;
}