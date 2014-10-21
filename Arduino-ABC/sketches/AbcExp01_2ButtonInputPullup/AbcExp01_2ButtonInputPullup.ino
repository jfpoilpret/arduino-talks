void setup() {
  pinMode(11, INPUT);
  Serial.begin(9600);
}

void loop() {
  int button = digitalRead(11);
  if (button == HIGH)
    Serial.println("ON");
  else
    Serial.println("OFF");
}
