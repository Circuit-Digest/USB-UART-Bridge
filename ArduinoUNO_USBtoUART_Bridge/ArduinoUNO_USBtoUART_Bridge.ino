// Arduino UNO as USB to UART Bridge with software 
#include <SoftwareSerial.h>
SoftwareSerial SERIAL_BRIDGE(2, 3);  // RX, TX for Uno

void setup() {
  Serial.begin(9600);         // USB communication
  SERIAL_BRIDGE.begin(9600);  // UART communication
}

void loop() {
  // Forward data from USB to UART
  if (Serial.available()) {
    SERIAL_BRIDGE.write(Serial.read());
  }

  // Forward data from UART to USB
  if (SERIAL_BRIDGE.available()) {
    Serial.write(SERIAL_BRIDGE.read());
  }
}
