void setup() {
  Serial.begin(9600);          // USB communication
  Serial1.begin(9600, SERIAL_8N1, 16, 17); // UART on GPIO16 (RX) and GPIO17 (TX)
}

void loop() {
  // Forward data from USB to UART
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }

  // Forward data from UART to USB
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}
