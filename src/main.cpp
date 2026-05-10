#include <Arduino.h>
#include "sensor_dht.h"
#include <LiquidCrystal_I2C.h>
#include "lcd_display.h"
#include "blynk_service.h"
#include "wifi_conn.h"
#define RELAY_PIN 27
#define RELAY_ON LOW
#define RELAY_OFF HIGH

void setup() {
    Serial.begin(115200);
    initDHT();
    initLCD();
    connectToWiFi();
    initBlynk();
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, RELAY_OFF);
}
void loop() {
    runBlynk();
    float temperature = getTemperature();
    float humidity = getHumidity();
    int stdHum = getStdHum();
    bool isOtomatic = isOtomaticMode();
    if(isOtomatic){
        digitalWrite(RELAY_PIN, humidity < stdHum ? RELAY_ON : RELAY_OFF);
    }else {
        digitalWrite(RELAY_PIN, isOn() ? RELAY_ON : RELAY_OFF);
    }
    lcdPrint(0, 0, "Temp:" + String(temperature) + " C");
    lcdPrint(0,1, "Humidity:" + String(humidity) + " %");
    sendToBlynk(temperature, humidity);

    delay(2000); // Wait for 2 seconds before next reading
}
