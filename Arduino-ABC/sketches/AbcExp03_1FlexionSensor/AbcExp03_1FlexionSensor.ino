void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get voltage on A0 analog input
  unsigned int value = analogRead(A0);

  // Display read value for calibration
  Serial.println(value);
  delay(1000);
}

