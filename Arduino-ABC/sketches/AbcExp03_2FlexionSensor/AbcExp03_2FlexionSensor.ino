const int ANALOG_VALUE_0 = 133;
const int ANALOG_VALUE_90 = 85;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get voltage on A0 analog input
  unsigned int value = analogRead(A0);
  int flex = map(value, ANALOG_VALUE_0, ANALOG_VALUE_90, 0, 90);
  
  // Display all values for debugging
  Serial.print("A0=");
  Serial.println(value);
  Serial.print("flex=");
  Serial.println(flex);

  delay(500);
}

