#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN PD4

DHT dht(DHTPIN, DHTTYPE);

// Define a hardware serial instance on the specific pins
HardwareSerial TestSerial(PA10, PA9); // RX, TX (Order depends on core, usually RX, TX)

void setup() {
    // Initialize UART
    dht.begin();
    TestSerial.begin(115200);
}

void loop() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    TestSerial.print("Temp: "); TestSerial.print(t); TestSerial.println("°C");
    TestSerial.print("Humidity: "); TestSerial.println(h);
    delay(100);
}