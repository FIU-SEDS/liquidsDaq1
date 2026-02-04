#include <Arduino.h>
#include <CD4051BE.h>

#define LED_PIN PA0 // This is connected to MUX common input/output

CD4051BE mux(PA5, PC4, PA7);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    mux.begin();
}


void pinLED(){
    digitalWrite(LED_PIN, HIGH);
    // delay(100);
    // digitalWrite(LED_PIN, LOW);
    // delay(100);
}

void loop() {
    
    pinLED();
    for(int i = 0; i < 8; i++){
        delay(100);
        mux.selectChannel(i);
    }
}