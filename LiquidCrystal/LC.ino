#include <LiquidCrystal.h>
#include <dht.h>

#define dht_pin A0

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
dht DHT;

void setup()
{
    //lcd.clear();
    lcd.begin(16, 2);
    lcd.home();
    lcd.print("DHT11");
    lcd.setCursor(6, 0);
    lcd.print("Temp");
    lcd.setCursor(6, 1);
    lcd.print("Humd");
    lcd.setCursor(15, 0);
    lcd.print("C");
    lcd.setCursor(15, 1);
    lcd.print("%");
    //Serial.begin(115200);
}

void loop()
{
    setup();
// int chk = DHT.read11(dht_pin);
    switch (DHT.read11(dht_pin))
    {
    case DHTLIB_OK:
        lcd.setCursor(0, 1);
        lcd.print("St:OK");
        break;

    case DHTLIB_ERROR_CHECKSUM:
        lcd.clear();
        lcd.home();
        lcd.print("St: CHECKSUM Error!");
        break;

    case DHTLIB_ERROR_TIMEOUT:
        lcd.clear();
        lcd.home();
        lcd.print("St: TIMEOUT Error!");
        break;

    default:
        lcd.clear();
        lcd.home();
        lcd.print("St: UNKNOWN ERROR!");
        break;
    }

    // DHT.read11(dht_pin);
    lcd.setCursor(11, 0);
    lcd.print(DHT.temperature, 1);
    lcd.setCursor(11, 1);
    lcd.print(DHT.humidity, 1);
    // Serial.print(DHT.humidity, 1);
    // Serial.print(" ");
    delay(1000);
}