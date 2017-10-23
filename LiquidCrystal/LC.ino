#include <LiquidCrystal.h>
#include <dht.h>

#define dht_pin A0

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
dht DHT;
bool flag = false;

void setup()
{
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
}

void loop()
{
    switch (DHT.read11(dht_pin))
    {
    case DHTLIB_OK:
        lcd.setCursor(0, 1);
        lcd.print("St:OK");
        flag = false;
        break;

    case DHTLIB_ERROR_CHECKSUM:
        lcd.clear();
        lcd.home();
        lcd.print("CHECKSUM Error!");
        flag = true;
        break;

    case DHTLIB_ERROR_TIMEOUT:
        //lcd.clear();
        lcd.home();
        lcd.print("TIMEOUT Error!");
        flag = true;
        break;

    default:
        lcd.clear();
        lcd.home();
        lcd.print("UNKNOWN ERROR!");
        flag = true;
        break;
    }

    if (flag == true)
    {
        if (DHTLIB_OK == DHT.read11(dht_pin))
        {
            setup();
        }
    }

    if (flag == false)
    {
        lcd.setCursor(11, 0);
        lcd.print(DHT.temperature, 1);
        lcd.setCursor(11, 1);
        lcd.print(DHT.humidity, 1);
        delay(1000);
    }
}