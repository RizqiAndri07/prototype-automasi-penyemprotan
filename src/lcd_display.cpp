#include <Arduino.h>
#include "lcd_display.h"
#include "config.h"
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLUMNS, LCD_ROWS);

void initLCD() {
    lcd.init();
    lcd.backlight();
    lcdClear();
    Serial.println("LCD initialized.");
}
void lcdPrint(int col, int row, String message) {
    lcd.setCursor(col, row);
    lcd.print(message);
}
void lcdClear() {
    lcd.clear();
}