#include <Wire.h>

const byte RTC_ADDRESS = 0x68;

struct time_t {
  byte second;
  byte minute;
  byte hour;
  byte day;
  byte date;
  byte month;
  byte year;
};

static byte fromBcd(byte input) {
  return (input >> 4) * 10 + (input & 0x0F);
}

void getTime(time_t& now);

void getTime(time_t& now) {
  // First force the register counter to 0x00 5second)
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  
  // Now wait for the right number of bytes received from the slave
  Wire.requestFrom(RTC_ADDRESS, sizeof(time_t));
  now.second = fromBcd(Wire.read());
  now.minute = fromBcd(Wire.read());
  now.hour = fromBcd(Wire.read());
  now.day = fromBcd(Wire.read());
  now.date = fromBcd(Wire.read());
  now.month = fromBcd(Wire.read());
  now.year = fromBcd(Wire.read());
}

void setup() {
  Serial.begin(57600);
  // Initialize communication as master on the I2C bus
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  time_t now;
  getTime(now);
  Serial.print(now.date);
  Serial.print(".");
  Serial.print(now.month);
  Serial.print(".20");
  Serial.print(now.year);
  Serial.print(" ");
  Serial.print(now.hour);
  Serial.print(":");
  Serial.print(now.minute);
  Serial.print(":");
  Serial.println(now.second);
  
  delay(300);
}

