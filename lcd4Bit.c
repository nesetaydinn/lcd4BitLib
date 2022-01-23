#include "lcd4Bit.h"

void decode4BitsImgArr(void (*drawPx)(uint16_t x, uint16_t y , uint16_t color), fourBitColor_t arr)  
{	
	if ((arr.x >= SCREEN_WIDTH) || (arr.y >= SCREEN_HEIGHT))
		return;
    if ((arr.x + arr.w - 1) >= SCREEN_WIDTH)
		return;
    if ((arr.y + arr.h - 1) >= SCREEN_HEIGHT)
		return;
    uint16_t color = 0, x = arr.x, y = arr. y;
    uint32_t data_c = 0;
    while(data_c < arr.data_pkg_len){
        color = colorSelector((arr.data[data_c] & FIRST_NIBBLE)  >> NIBBLE_SIZE);
        drawPx(x,y,color);
        indexUpdate(&x, &y, arr.w, arr.x);
        color = colorSelector((arr.data[data_c] & SECOND_NIBBLE));
        drawPx(x,y,color);
        indexUpdate(&x, &y, arr.w, arr.x);
        data_c++;
    }
}

void indexUpdate(uint16_t * x, uint16_t * y, uint16_t w , uint16_t x_start){
    *x+=1;
    if(*x >= (w + x_start)){
       *x = x_start;
       *y+=1;
    }
}
uint16_t colorSelector(uint8_t color_val){
    switch (color_val)
    {
    case COLOR_BLACK_INDEX:
        return COLOR_BLACK;
    case COLOR_WHITE_INDEX:
        return COLOR_WHITE;
    case COLOR_RED_INDEX:
        return COLOR_RED;
    case COLOR_GREEN_INDEX:
        return COLOR_GREEN;
    case COLOR_BLUE_INDEX:
        return COLOR_BLUE;
    case COLOR_MAGENTA_INDEX:
        return COLOR_MAGENTA;
    case COLOR_CYAN_INDEX:
        return COLOR_CYAN;
    case COLOR_YELLOW_INDEX:
        return COLOR_YELLOW;
    case COLOR_GRAY_INDEX:
        return COLOR_GRAY;
    case COLOR_BRED_INDEX:
        return COLOR_BRED;
    case COLOR_GRED_INDEX:
        return COLOR_GRED;
    case COLOR_GBLUE_INDEX:
        return COLOR_GBLUE;
    case COLOR_BROWN_INDEX:
        return COLOR_BROWN;
    case COLOR_BRRED_INDEX:
        return COLOR_BRRED;
    case COLOR_DARKBLUE_INDEX:
        return COLOR_DARKBLUE;
    case COLOR_LIGHTBLUE_INDEX:
        return COLOR_LIGHTBLUE;
    default:
        break;
    }
        return COLOR_BLACK;
}