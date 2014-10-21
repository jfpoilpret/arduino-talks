void setup() {
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
}

static bool state = false;
static int count = 0;

void loop() {
  int button = digitalRead(10);
  bool newState = (button == HIGH);
  if (state != newState) {
    state = newState;
    count++;
    Serial.print(count);
    Serial.println(state ? " ON" : " OFF");
  }
}
