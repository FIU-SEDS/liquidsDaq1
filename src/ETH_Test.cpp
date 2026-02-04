#include <Arduino.h> //File to test INPUT/OUTPUT of Multiplexer with ETH, Using UART/UDP
#include <DHT.h>

#define MUX_COM_PIN PA0
#define SWITCH_PIN_A PA1
#define DHTTYPE DHT11

DHT dht(MUX_COM_PIN, DHTTYPE);

void setup() {
    pinMode(SWITCH_PIN_A, OUTPUT);
    dht.begin();
    Serial1.begin(9600); // Ready To Send Through ETH
}

void loop() {
    digitalWrite(SWITCH_PIN_A, HIGH);
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    Serial1.print("Temp: "); Serial1.print(t); Serial1.println("°C");
    Serial1.print("Humidity: "); Serial1.println(h);
    delay(500);

    digitalWrite(SWITCH_PIN_A, LOW);
    Serial1.println(analogRead(MUX_COM_PIN));
    delay(500);
}