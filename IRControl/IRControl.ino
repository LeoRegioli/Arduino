#include <IRremote.h>
#include <IRremoteInt.h>

#define IRControl 13
#define led 8

IRrecv irrecv(IRControl);
decode_results results;
void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode(&results))
    {

        switch (results.value)
        {

        case 0xFF30CF: //1
            digitalWrite(led, HIGH);
            Serial.println("Led ligado");

            break;

        case 0xFF6897: //0
            digitalWrite(led, LOW);
            Serial.println("Led desligado");
            break;
        }
        irrecv.resume();
    }
}