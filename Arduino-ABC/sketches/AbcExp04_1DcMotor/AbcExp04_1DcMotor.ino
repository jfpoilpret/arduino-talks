const int DC_MOTOR_PIN = 9;

void setup() {
  pinMode(DC_MOTOR_PIN, OUTPUT);
}

void loop() {
  for (byte value = 0; value < 255; value += 10) {
    analogWrite(DC_MOTOR_PIN, value);
    delay(500);
  }
  delay(5000);
}
