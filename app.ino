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
    valorObtido = analogRead(LDR);
    if (valorObtido >= 690 && a == false)
    {
        digitalWrite(led, HIGH);
        Serial.print(valorObtido);
        Serial.println(" - Led ligado!");
        a = true;
    }

    if (valorObtido <= 689 && a == true)
    {
        digitalWrite(led, LOW);
        Serial.print(valorObtido);
        Serial.println(" - Led desligado!");
        a = false;
    }

    if ((millis() - auxTime) > 1000)
    {
        Serial.println(valorObtido);
        auxTime = millis();
    }
}