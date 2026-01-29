#include <Arduino.h>

#define LED_PIN PA0 // This is connected to MUX common input/output
#define SWITCH_PIN_A PA5 // Connected to A port on the MUX
#define SWITCH_PIN_B PA6 // Connected to B port on the MUX
#define SWITCH_PIN_C PA7 // Connected to C port on the MUX


void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SWITCH_PIN_A, OUTPUT);
    pinMode(SWITCH_PIN_B, OUTPUT);
    pinMode(SWITCH_PIN_C, OUTPUT);
}

void loop() {
    digitalWrite(SWITCH_PIN_A, HIGH); // Change between HIGH and LOW to change the LED
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(500);

    digitalWrite(SWITCH_PIN_A, LOW);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(500);
}