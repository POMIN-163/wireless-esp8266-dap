#ifndef __OLED_H
#define __OLED_H

#include "DAP_config.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#define OLED_CMD        0
#define OLED_DATA       1

#define OLED_SCLK_Clr() gpio_set_level(4, 0);
#define OLED_SCLK_Set() gpio_set_level(4, 1);

#define OLED_SDIN_Clr() gpio_set_level(5, 0);
#define OLED_SDIN_Set() gpio_set_level(5, 1);

void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(char x, char y, char chr);
void OLED_ShowString(char x, char y, char *p);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_DrawBMP(unsigned char BMP[]);
void fill_picture(unsigned char fill_Data);
void oled_task();

extern char oled_buf[1024];
#define printf_oled(line, ...)      \
    sprintf(oled_buf, __VA_ARGS__); \
    OLED_ShowString(8, line * 2, oled_buf)

#define print_oled(line, str)        \
    sprintf(oled_buf, "%-15s", str); \
    OLED_ShowString(8, line * 2, oled_buf)

#endif
