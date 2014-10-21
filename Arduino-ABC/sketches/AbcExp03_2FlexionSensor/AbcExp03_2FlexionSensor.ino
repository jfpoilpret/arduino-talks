void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get voltage on A0 analog input
  unsigned int value = analogRead(A0);
  double Vin = Vout * value / 1024.0;
  // compute flex sensor resistance
  double Rflex = R2 * (Vin / Vout - 1.0);
  // convert flex resistance
  // consider resistance varies linearly according to flexion angle
  // 25000  -> 0°
  // 125000 -> 90°
  int flex = map(Rflex, 25000, 125000, 0, 90);
  
  // Display all values for debugging
  Serial.print("A0=");
  Serial.println(value);
  Serial.print("Vin=");
  Serial.print(Vin);
  Serial.println("V");
  Serial.print("Rflex=");
  Serial.print(Rflex);
  Serial.println("Ohm");
  Serial.print("flex=");
  Serial.print(flex);
  Serial.println("°");

  delay(500);
}

