#include "lcd4Bit.h"
#include "stdio.h"

uint8_t image_test[] = {0x00,0x01,0x02,0x03,
                        0x04,0x05,0x06,0x07,
                        0x08,0x09,0x0A,0x0B,
                        0x0C,0x0D,0x0E,0x0F,
                        0xC0,0xD0,0xE0,0xF0,
                        0x80,0x90,0xA0,0xB0,
                        0x40,0x50,0x60,0x70,
                        0x00,0x10,0x20,0x30
                        };

fourBitColor_t testColor = {
    .data = &image_test[0],
    .data_pkg_len =sizeof(image_test),
    .x = SCREEN_WIDTH/2,
    .y = SCREEN_HEIGHT/2,
    .w = sizeof(image_test),
    .h = sizeof(image_test)
};

void testPrintColorVals(uint16_t x, uint16_t y , uint16_t color){
    printf("%d. x = %d, y = %d, colorId = 0x%x\n", x, y ,color);
}

int main(int argc, char const *argv[])
{   
    decode4BitsImgArr(&testPrintColorVals, testColor);
    return 0;
}
