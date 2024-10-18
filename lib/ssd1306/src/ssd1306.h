#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>

#define SSD1306_ADDR 0x3C

void initializeSSD1306();
uint8_t sendCommand(uint8_t command);
void fillColor(uint8_t byte);

#endif