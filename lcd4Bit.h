#ifndef LCD_4_BIT_LIB
#define LCD_4_BIT_LIB

#ifdef __cplusplus
extern 'C' {
#endif    

#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"

typedef enum{
    COLOR_BLACK     = 0x0000,
    COLOR_WHITE     = 0xFFFF,
    COLOR_RED       = 0xF800,
    COLOR_GREEN     = 0x07E0,
    COLOR_BLUE      = 0x001F,
    COLOR_MAGENTA   = 0xF81F,
    COLOR_CYAN      = 0x7FFF,
    COLOR_YELLOW    = 0xFFE0,
    COLOR_GRAY      = 0X8430,
    COLOR_BRED      = 0XF81F,
    COLOR_GRED      = 0XFFE0,
    COLOR_GBLUE     = 0X07FF,
    COLOR_BROWN     = 0XBC40,
    COLOR_BRRED     = 0XFC07,
    COLOR_DARKBLUE  = 0X01CF,
    COLOR_LIGHTBLUE = 0X7D7C
}colors_enum_t;

typedef struct
{   
    uint16_t w;
    uint16_t h;
    uint16_t x;
    uint16_t y;
    uint32_t data_pkg_len;
    const uint8_t * data;
}fourBitColor_t;



void decode4BitsImgArr(void (*drawPx)(uint16_t x, uint16_t y , uint16_t color), fourBitColor_t arr);


#ifdef __cplusplus
}
#endif

#endif