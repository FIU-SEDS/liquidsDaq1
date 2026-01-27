#include <Arduino.h>

#define MUX_COM_PIN PA0
#define SWITCH_PIN_A PA1

void setup() {
    pinMode(MUX_COM_PIN, INPUT_ANALOG);
    pinMode(SWITCH_PIN_A, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(SWITCH_PIN_A, HIGH);
    Serial.println(analogRead(MUX_COM_PIN));
    delay(1);

    digitalWrite(SWITCH_PIN_A, LOW);
    Serial.println(analogRead(MUX_COM_PIN));

    delay(1);
}