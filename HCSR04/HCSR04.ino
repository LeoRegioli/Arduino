#include <Ultrasonic.h>

Ultrasonic ultrassom(7,6);
long dist = 0;

void setup(){
    Serial.begin(9600);
}

void loop(){

//dist = ultrassom.Ranging(CM);
dist = ultrassom.distanceRead(CM);

Serial.print(dist);
Serial.println("CM");
delay(500);

}