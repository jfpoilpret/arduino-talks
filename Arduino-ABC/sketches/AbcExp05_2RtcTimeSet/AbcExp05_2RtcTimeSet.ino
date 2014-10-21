#include <Wire.h>

const byte RTC_ADDRESS = 0x68;

static byte toBcd(byte input) {
  return (input / 10) << 4 | (input % 10);
}

void setTime(byte year, byte month, byte date, byte day, byte hour, byte minute, byte second);

void setTime(byte year, byte month, byte date, byte day, byte hour, byte minute, byte second) {
  // Start I2C transmission to the RTC slave
  Wire.beginTransmission(RTC_ADDRESS);
  // Address of 1st register to write 0x00
  Wire.write(0x00);
  Wire.write(toBcd(second));
  Wire.write(toBcd(minute));
  Wire.write(toBcd(hour));
  // Not sure we have to set the week day
  Wire.write(day & 0x07);
  Wire.write(toBcd(date));
  Wire.write(toBcd(month));
  Wire.write(toBcd(year));
  // Now transmit everything to the RTC slave
  Wire.endTransmission();
}

void setup() {
  // Initialize communication as master on the I2C bus
  Wire.begin();
  setTime(14, 9, 9, 3, 21, 8, 0);
}

void loop() {
}

