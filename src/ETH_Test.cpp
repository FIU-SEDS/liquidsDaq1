#include <Arduino.h>

// Define a hardware serial instance on the specific pins
HardwareSerial TestSerial(PA10, PA9); // RX, TX (Order depends on core, usually RX, TX)

void setup() {
    // Initialize UART
    TestSerial.begin(115200);
}

void loop() {
    TestSerial.println("HELLO!!!");
    delay(100);
}