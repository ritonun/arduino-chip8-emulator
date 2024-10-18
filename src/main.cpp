#include <Arduino.h>
#include <Wire.h>
#include <ssd1306.h>


void setup() {
  Wire.begin();
  initializeSSD1306();
}

void loop() {
  fillColor(0xFF);
  delay(1000);
  fillColor(0x00);
  delay(1000);
}
