#include <Arduino.h>

#define SENSOR_PIN PA0 // This is connected to MUX common input/output
#define SWITCH_PIN_A PA1 // Connected to A port on the MUX

void setup() {
    pinMode(SENSOR_PIN, INPUT_ANALOG);
    pinMode(SWITCH_PIN_A, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(SWITCH_PIN_A, HIGH); // Change between HIGH and LOW to change the "Sensor" being read.
    Serial.println(analogRead(SENSOR_PIN)); // Connected to different voltages.
    delay(1);

    digitalWrite(SWITCH_PIN_A, LOW);
    Serial.println(analogRead(SENSOR_PIN));

    delay(1);
}