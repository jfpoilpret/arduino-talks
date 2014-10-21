const int TRIGGER = 8;
const int ECHO = 9;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // Send trigger signal for 10us
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  // Wait for echo signal HIGH and measure duration
  unsigned long duration = pulseIn(ECHO, HIGH);
  
  // Calculate distance
  unsigned long distance = duration * 340L / 1000L / 2L;
  // Trace distance
  Serial.println(distance);
  delay(100);
}

