const int RED = 6;
const int GREEN = 5;
const int BLUE = 3;

const long DELAY = 2000;

void setColor(byte red, byte green, byte blue) {
  analogWrite(RED, 255 - red);
  analogWrite(GREEN, 255 - green);
  analogWrite(BLUE, 255 - blue);
}
  
void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  // Ensure no light appears at the beginning (necessary because LED is Common Anode)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void loop() {
  delay(DELAY);
  setColor(255, 0, 0);
  delay(DELAY);
  setColor(0, 255, 0);
  delay(DELAY);
  setColor(0, 0, 255);
  delay(DELAY);
  setColor(0, 0, 0);
  delay(DELAY);
  setColor(255, 255, 255);
}
