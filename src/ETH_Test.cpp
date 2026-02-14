#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN PD4

DHT dht(DHTPIN, DHTTYPE);

HardwareSerial TestSerial(PA10, PA9); 

void setup() {
    dht.begin();
    TestSerial.begin(115200);
}

void loop() {
    float dhtT = dht.readTemperature();
    float dhtH = dht.readHumidity();
    
    if (isnan(dhtH) || isnan(dhtT)) return;
    
    TestSerial.write((byte*)&dhtT, sizeof(float)); 
    TestSerial.write((byte*)&dhtH, sizeof(float));
    
    delay(50);
}