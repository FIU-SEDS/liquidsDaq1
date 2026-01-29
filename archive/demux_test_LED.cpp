#include <Arduino.h>

#define LED_PIN PA0 // This is connected to MUX common input/output
#define SWITCH_PIN_A PA5 // Connected to A port on the MUX
#define SWITCH_PIN_B PC4 // Connected to B port on the MUX
#define SWITCH_PIN_C PA7 // Connected to C port on the MUX


void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SWITCH_PIN_A, OUTPUT);
    pinMode(SWITCH_PIN_B, OUTPUT);
    pinMode(SWITCH_PIN_C, OUTPUT);

    digitalWrite(SWITCH_PIN_A, LOW);
    digitalWrite(SWITCH_PIN_B, LOW);
    digitalWrite(SWITCH_PIN_C, LOW);
}

void ledSwitch(){
    digitalWrite(LED_PIN, HIGH);
    // delay(100);
    // digitalWrite(LED_PIN, LOW);
    // delay(100);
}

void loop() {
    
    ledSwitch();

    digitalWrite(SWITCH_PIN_A, HIGH); // Channel 1

    ledSwitch();

    digitalWrite(SWITCH_PIN_A, LOW); // RESET

    digitalWrite(SWITCH_PIN_B, HIGH); // Channel 2


    ledSwitch();

    digitalWrite(SWITCH_PIN_B, LOW); // RESET

    digitalWrite(SWITCH_PIN_A, HIGH); // Channel 3
    digitalWrite(SWITCH_PIN_B, HIGH);

    ledSwitch();

    digitalWrite(SWITCH_PIN_A, LOW); // RESET
    digitalWrite(SWITCH_PIN_B, LOW);

    digitalWrite(SWITCH_PIN_C, HIGH); // Channel 4

    ledSwitch();
    
    digitalWrite(SWITCH_PIN_C, LOW); // RESET

    digitalWrite(SWITCH_PIN_A, HIGH); // Channel 5
    digitalWrite(SWITCH_PIN_C, HIGH);

    ledSwitch();

    digitalWrite(SWITCH_PIN_A, LOW); // RESET
    digitalWrite(SWITCH_PIN_C, LOW);

    digitalWrite(SWITCH_PIN_B, HIGH); // Channel 6
    digitalWrite(SWITCH_PIN_C, HIGH);

    ledSwitch();

    digitalWrite(SWITCH_PIN_B, LOW); // RESET
    digitalWrite(SWITCH_PIN_C, LOW);

    digitalWrite(SWITCH_PIN_A, HIGH); // Channel 7
    digitalWrite(SWITCH_PIN_B, HIGH);
    digitalWrite(SWITCH_PIN_C, HIGH);

    ledSwitch();

    digitalWrite(SWITCH_PIN_A, LOW); // RESET
    digitalWrite(SWITCH_PIN_B, LOW);
    digitalWrite(SWITCH_PIN_C, LOW);

}