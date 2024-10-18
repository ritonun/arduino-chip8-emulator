#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>

#define SSD1306_ADDR 0x3C

void initializeScreen();
void sendCommand();
void fillColor(uint8_t byte);

#endif