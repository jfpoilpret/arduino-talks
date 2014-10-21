const int RED = 6;
const int GREEN = 5;
const int BLUE = 3;

const long DELAY = 500;
const int INCREMENT = 50;

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
  for (int red = 0; red <= 255; red += INCREMENT) {
    for (int green = 0; green <= 255; green += INCREMENT) {
      for (int blue = 0; blue <= 255; blue += INCREMENT) {
        setColor(red, green, blue);
        delay(DELAY);
      }
    }
  }
}
