#include <WiFi.h>
#include "wifi_conn.h"
#include "config.h"
#include <Arduino.h>

void connectToWiFi(){
    Serial.print("Connecting to WiFi SSID: ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected successfully.");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }else{
        Serial.println("Failed to connect to WiFi.");
    }
}

bool isWiFiConnected() {
    return WiFi.status() == WL_CONNECTED;
}