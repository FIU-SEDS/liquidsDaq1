#include <Arduino.h>

#define LED_PIN PA0 // This is connected to MUX common input/output
#define SWITCH_PIN_A PA1 // Connected to A port on the MUX

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SWITCH_PIN_A, OUTPUT);
}

void loop() {
    digitalWrite(SWITCH_PIN_A, HIGH); // Change between HIGH and LOW to change the "LED" being Used.
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(LED_PIN, LOW);
    delay(500);

    digitalWrite(SWITCH_PIN_A, LOW);
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(LED_PIN, LOW);

    delay(500);
}