#include <Arduino.h>
#include <WiFi.h>
#include "blynk_service.h"
#include "config.h"
#include <BlynkSimpleEsp32.h>
float lastTemperature = -1000.0;
float lastHumidity = -1000.0;
float THRESHOLD = 0.5; // Minimum change to trigger update
int stdTemp = 0;
int stdHum = 0;
int lastStdTemp = -1000;
int lastStdHum = -1000;
bool switchState = 0;
bool isOtomatic = 1;


BLYNK_WRITE(V5){
    int val = param.asInt();
    isOtomatic = val;
    Serial.println("Received automatic mode state from Blynk: " + String(isOtomatic));
}
BLYNK_WRITE(V2){
    int val = param.asInt();
    switchState = val;
    Serial.println("Received switch state from Blynk: " + String(switchState));
}

BLYNK_WRITE(V7){
    int val = param.asInt();
    stdHum = val;
    Serial.println("Received standard humidity from Blynk: " + String(stdHum));
}
BLYNK_WRITE(V6){
    int val = param.asInt();
    stdTemp = val;
    Serial.println("Received standard temperature from Blynk: " + String(stdTemp));
}
BLYNK_CONNECTED(){
    Blynk.syncVirtual(V7,V6,V2,V5);
}

void initBlynk() {
    Serial.println("Connecting to Blynk...");
    Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
    while (!Blynk.connected()) {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\nBlynk connected.");
}

void runBlynk() {
    Blynk.run();
}
void sendToBlynk(float temperature, float humidity) {
    if(abs(temperature - lastTemperature)>THRESHOLD){
        Blynk.virtualWrite(V0, temperature); // Send temperature to Virtual Pin V1
        lastTemperature = temperature;
        Serial.println("temperature updated to Bynk: " + String(temperature));
    }
    if(abs(humidity - lastHumidity)>THRESHOLD){
        Blynk.virtualWrite(V1, humidity);    // Send humidity to Virtual Pin V2
        lastHumidity = humidity;
        Serial.println("humidity updated to Bynk: " + String(humidity));
    }
}

int getStdTemp(){
    Serial.println("Standard temperature : " + String(stdTemp));
    lastStdTemp = stdTemp;
    return stdTemp;
}

int getStdHum(){
    Serial.println("Standard humidity : " + String(stdHum));
    lastStdHum = stdHum;
    return stdHum;
}

bool isOn(){
    return switchState;
}

bool isOtomaticMode(){
    return isOtomatic;
}