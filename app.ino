int led = 13,
    LDR = 0,
    getValue = 0;
bool a = false;
long auxTime = 0;
/*-----------------------------------------------*/

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    getValue = analogRead(LDR);
    if (getValue >= 690 && a == false)
    {
        digitalWrite(led, HIGH);
        Serial.print(getValue);
        Serial.println(" - Led ligado!");
        a = true;
    }

    if (getValue <= 689 && a == true)
    {
        digitalWrite(led, LOW);
        Serial.print(getValue);
        Serial.println(" - Led desligado!");
        a = false;
    }

    if ((millis() - auxTime) > 1000)
    {
        Serial.println(getValue);
        auxTime = millis();
    }
}