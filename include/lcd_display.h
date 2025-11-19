#include <WString.h>
#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

void initLCD();
void lcdPrint(int col,int row,String message);
void lcdClear();
#endif