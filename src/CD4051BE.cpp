#include <Arduino.h>

CD4051BE::CD4051BE(int pinA, int pinB, int pinC) {
    // Save the incoming values to our private storage
    _pinA = pinA;
    _pinB = pinB;
    _pinC = pinC;
}

void setup() {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
}

void ledSwitch(){
    digitalWrite(LED_PIN, HIGH);
    // delay(100);
    // digitalWrite(LED_PIN, LOW);
    // delay(100);
}

void loop() {
    
    ledSwitch();

    digitalWrite(pinA, HIGH); // Channel 1

    ledSwitch();

    digitalWrite(pinA, LOW); // RESET

    digitalWrite(pinB, HIGH); // Channel 2


    ledSwitch();

    digitalWrite(pinB, LOW); // RESET

    digitalWrite(pinA, HIGH); // Channel 3
    digitalWrite(pinB, HIGH);

    ledSwitch();

    digitalWrite(pinA, LOW); // RESET
    digitalWrite(pinB, LOW);

    digitalWrite(pinC, HIGH); // Channel 4

    ledSwitch();
    
    digitalWrite(pinC, LOW); // RESET

    digitalWrite(pinA, HIGH); // Channel 5
    digitalWrite(pinC, HIGH);

    ledSwitch();

    digitalWrite(pinA, LOW); // RESET
    digitalWrite(pinC, LOW);

    digitalWrite(pinB, HIGH); // Channel 6
    digitalWrite(pinC, HIGH);

    ledSwitch();

    digitalWrite(pinB, LOW); // RESET
    digitalWrite(pinC, LOW);

    digitalWrite(pinA, HIGH); // Channel 7
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);

    ledSwitch();

    digitalWrite(pinA, LOW); // RESET
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);

}