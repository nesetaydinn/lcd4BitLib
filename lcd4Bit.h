#ifndef LCD_4_BIT_LIB
#define LCD_4_BIT_LIB

#ifdef __cplusplus
extern 'C' {
#endif    

#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"

#define SCREEN_WIDTH    240 //Customize
#define SCREEN_HEIGHT   240 //Customize

/*  
    0th bit - 1st bit - 2nd bit - 3rd bit - 4th bit - 5th bit - 6th bit - 7th bit
                1st Nibble                -            2nd Nibble                 
*/
#define FIRST_NIBBLE    0xF0
#define SECOND_NIBBLE   0x0F
#define NIBBLE_SIZE     0x04

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


typedef enum{
    COLOR_BLACK_INDEX     = 0x00,
    COLOR_WHITE_INDEX           ,
    COLOR_RED_INDEX             ,
    COLOR_GREEN_INDEX           ,
    COLOR_BLUE_INDEX            ,
    COLOR_MAGENTA_INDEX         ,
    COLOR_CYAN_INDEX            ,
    COLOR_YELLOW_INDEX          ,
    COLOR_GRAY_INDEX            ,
    COLOR_BRED_INDEX            ,
    COLOR_GRED_INDEX            ,
    COLOR_GBLUE_INDEX           ,
    COLOR_BROWN_INDEX           ,
    COLOR_BRRED_INDEX           ,
    COLOR_DARKBLUE_INDEX        ,
    COLOR_LIGHTBLUE_INDEX       
}colors_index_enum_t;

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
uint16_t colorSelector(uint8_t color_val, uint16_t * x, uint16_t * y, uint16_t w , uint16_t x_s);

#ifdef __cplusplus
}
#endif

#endif