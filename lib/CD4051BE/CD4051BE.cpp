#include <Arduino.h>
#include "CD4051BE.h" 

CD4051BE::CD4051BE(int pinA, int pinB, int pinC) {
    _pinA = pinA;
    _pinB = pinB;
    _pinC = pinC;
}

void CD4051BE::begin() {
    pinMode(_pinA, OUTPUT); 
    pinMode(_pinB, OUTPUT);
    pinMode(_pinC, OUTPUT);

    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
    digitalWrite(_pinC, LOW);
}

void CD4051BE::channelReset(){
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
    digitalWrite(_pinC, LOW);
}

void CD4051BE::selectChannel(int channel){
    channelReset(); 

    if (channel == 1) {
        digitalWrite(_pinA, HIGH);
    } else if (channel == 2) {
        digitalWrite(_pinB, HIGH);
    } else if (channel == 3) {
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinB, HIGH);
    } else if (channel == 4) {
        digitalWrite(_pinC, HIGH);
    } else if (channel == 5) {
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinC, HIGH);
    } else if (channel == 6) {
        digitalWrite(_pinB, HIGH);
        digitalWrite(_pinC, HIGH);
    } else if (channel == 7) {
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinB, HIGH);
        digitalWrite(_pinC, HIGH);
    }
}