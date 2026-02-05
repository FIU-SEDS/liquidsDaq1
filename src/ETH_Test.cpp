#include <Arduino.h> //File to test INPUT/OUTPUT of Multiplexer with ETH, Using UART/UDP
#include <DHT.h>


#define DHT_PIN PA0
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
    dht.begin();
    Serial1.begin(9600); // Ready To Send Through ETH
}

void loop() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    Serial1.print("Temp: "); Serial1.print(t); Serial1.println("°C");
    Serial1.print("Humidity: "); Serial1.println(h);
    delay(500);

}