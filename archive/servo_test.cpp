#include <Arduino.h>
#include <Servo.h>

Servo myServo;

#define SERVO_PIN PA0 

void setup() {
    //Attach the servo to the pin
    myServo.attach(SERVO_PIN);
}

void loop() {
    //Sweep from 0 to 180 degrees
    for (int pos = 0; pos <= 180; pos += 1) { 
        myServo.write(pos);              //Tell servo to go to position in variable pos
        delay(15);                       
    }
    
    //Sweep back from 180 to 0 degrees
    for (int pos = 180; pos >= 0; pos -= 1) { 
        myServo.write(pos);              
        delay(15);                       
    }
}