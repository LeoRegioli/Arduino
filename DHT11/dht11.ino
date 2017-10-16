#include <dht.h>

dht DHT;

#define DHT11_PIN A1

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    //int chk = DHT.read11(DHT11_PIN);

    Serial.print("DHT11, Status -> ");

    switch (DHT.read11(DHT11_PIN))
    {
    case DHTLIB_OK:
        Serial.print("OK\t");
        break;

    case DHTLIB_ERROR_CHECKSUM:
        Serial.print("Error checksum\t");
        break;

    case DHTLIB_ERROR_TIMEOUT:
        Serial.print("Error time out\t");
        break;

    default:
        Serial.print("Unknown error\t");
        break;
    }

    Serial.print(DHT.humidity);
    Serial.print("% Humidity | ");
    Serial.print(DHT.temperature);
    Serial.println("C Temperature");

    delay(2000);
}