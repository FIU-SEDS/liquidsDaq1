#include <Arduino.h> //File to test INPUT/OUTPUT of Multiplexer
#include <DHT.h>

#define MUX_COM_PIN PA0
#define SWITCH_PIN_A PA1
#define DHTTYPE DHT11

DHT dht(MUX_COM_PIN, DHTTYPE);

void setup() {
    analogReadResolution(12);
    pinMode(SWITCH_PIN_A, OUTPUT);
    dht.begin();
    Serial.begin(9600);
}

void loop() {
    digitalWrite(SWITCH_PIN_A, HIGH);
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    // Serial.print("Temp: "); Serial.print(t); Serial.println("°C");
    // Serial.print("Humidity: "); Serial.println(h);
    delay(10);

    digitalWrite(SWITCH_PIN_A, LOW);
    //float voltage = (analogRead(MUX_COM_PIN) * 3.3) / 4095.0;
    Serial.println(analogRead(MUX_COM_PIN));
    // Serial.println();
    delay(10);
}