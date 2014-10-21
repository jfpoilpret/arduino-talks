void setup() {
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int button = digitalRead(10);
  if (button == HIGH)
    Serial.println("ON");
  else
    Serial.println("OFF");
}
