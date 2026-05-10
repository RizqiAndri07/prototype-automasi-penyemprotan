#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

// Configuration settings for the project

#define DHT_PIN 4 // recommended ESP32 GPIO for DHT data pin

// LCD configuration (I2C address and dimensions)
#define LCD_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2


//example USE THE DOUBLE QUOTE "" !!
#define BLYNK_TEMPLATE_ID "youre_template_id"
#define BLYNK_TEMPLATE_NAME "your_template_name"
#define BLYNK_AUTH_TOKEN "your_auth_token"



// WiFi credentials
//example USE THE DOUBLE QUOTE "" !!

static const char WIFI_SSID[]= "your_ssid";
static const char WIFI_PASS[]= "your_password";


// static const char WIFI_SSID[]= "rajamuran";
// static const char WIFI_PASS[]= "Bismillah234@";
#endif
