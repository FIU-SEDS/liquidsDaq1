#include <Arduino.h>
#include <SPI.h>

// --- Pin Definitions for SPI3 on STM32F407VE ---
// We explicitly define these to ensure the correct hardware peripheral is used.
#define SPI3_MOSI_PIN PC12
#define SPI3_MISO_PIN PC11
#define SPI3_SCK_PIN  PC10
#define MCP_CS_PIN    PD4  // Chip Select

// Create a custom SPI instance for SPI3
SPIClass SPI_3(SPI3_MOSI_PIN, SPI3_MISO_PIN, SPI3_SCK_PIN);

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);
  while (!Serial) delay(10); // Wait for serial monitor
  
  Serial.println("Starting MCP3208 on SPI3 (Differential Mode)...");

  // Configure CS pin
  pinMode(MCP_CS_PIN, OUTPUT);
  digitalWrite(MCP_CS_PIN, HIGH); // Deselect (Active Low)

  // Initialize SPI3
  SPI_3.begin();
}

// Function to read MCP3208 in Differential Mode
// ch_pos is the positive input, ch_neg is the negative input
// For CH0(+)-CH1(-), pass 0
uint16_t readMCP3208_Diff(int channel) {
  
  // Settings: 1MHz clock (safe speed), MSB First, SPI Mode 0
  SPI_3.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  
  digitalWrite(MCP_CS_PIN, LOW); // Activate CS

  // --- SPI Transaction Logic ---
  // The MCP3208 needs a Start Bit, followed by the Control Bits.
  // We send 3 bytes total to align the 12-bit result.

  // Byte 1: Start Bit (1) | SGL/DIFF (0) | D2 (0)
  // Binary: 0000 0100 -> 0x04
  // Note: SGL/DIFF is 0 for Differential. 
  // For CH0-CH1 pair, D2=0, D1=0, D0=0.
  SPI_3.transfer(0x04); 

  // Byte 2: D1 (0) | D0 (0) | ... reading upper nibble ...
  // We send 0x00 just to clock the data out.
  // The upper 4 bits of the result come in the lower nibble of this byte.
  byte upperByte = SPI_3.transfer(0x00);

  // Byte 3: ... reading lower byte ...
  // The lower 8 bits of the result come in here.
  byte lowerByte = SPI_3.transfer(0x00);

  digitalWrite(MCP_CS_PIN, HIGH); // Deactivate CS
  SPI_3.endTransaction();

  // --- Process Data ---
  // Mask the upper byte to keep only the last 4 bits (0x0F)
  // Combine with lower byte
  uint16_t result = ((upperByte & 0x0F) << 8) | lowerByte;

  return result;
}

void loop() {
  // Read Differential CH0(+) - CH1(-)
  uint16_t rawValue = readMCP3208_Diff(0);
  
  // Convert to Voltage (Assuming 3.3V VREF)
  float voltage = (rawValue * 3.3) / 4096.0;

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print("\tVoltage: ");
  Serial.print(voltage, 4);
  Serial.println(" V");

  delay(100);
}