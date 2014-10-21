void setup() {
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  int button = digitalRead(12);
  if (button == HIGH)
    Serial.println("ON");
  else
    Serial.println("OFF");
}
