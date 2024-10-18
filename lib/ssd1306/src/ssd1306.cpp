#include <ssd1306.h>
#include <Wire.h>

void initializeSSD1306() {
    // set MUX ratio for 128x64 display
    sendCommand(0xA8);
    sendCommand(0x3F);

    // set display offset
    sendCommand(0x3D);
    sendCommand(0x00);

    // set display start line
    sendCommand(0x40);

    // set segment remap
    sendCommand(0xA1);

    // set com output scan direction
    sendCommand(0xC8);

    // set com pins hardware configuration
    sendCommand(0xDA);
    sendCommand(0x12);

    // set contrast contol to max
    sendCommand(0x81);
    sendCommand(0x7F);

    // disable entire display on
    sendCommand(0xA4);

    // set oscillator frequency (to be changed later)
    sendCommand(0xD5);
    sendCommand(0x80);

    // enable charge pump regulator
    sendCommand(0x8D);
    sendCommand(0x14);

    // turn the display on
    sendCommand(0xAF);
}

uint8_t sendCommand(uint8_t command) {
    Wire.beginTransmission(SSD1306_ADDR);
    Wire.write(0x00);   // indicate command byte
    Wire.write(command);
    uint8_t error = Wire.endTransmission();
    return error;
}

void fillColor(uint8_t byte) {
    // set memory adressing mode to horizontal
    sendCommand(0x20);
    sendCommand(0x01);

    // set column adress range
    sendCommand(0x21);
    sendCommand(0x00);
    sendCommand(0x7F);  // 128 column

    // set page adress range (1 page = 8 row)
    sendCommand(0x22);
    sendCommand(0x00);
    sendCommand(0x07);  // 64/8 = 8 -> 0..7

    for (uint8_t page=0; page<8; page++) {
        for (uint8_t col=0; col<128; col++) {
            Wire.beginTransmission(SSD1306_ADDR);
            Wire.write(0x40);   // indicate data byte
            Wire.write(byte);
            Wire.endTransmission();
        }
    }
}