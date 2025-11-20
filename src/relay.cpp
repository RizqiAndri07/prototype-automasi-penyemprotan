// #include <Arduino.h>
// #include "relay.h"
// #include  "config.h"

// static bool relayState = false; 

// void initRelay() {
//     pinMode(RELAY_PIN, OUTPUT);
//     setRelay(false); // Initialize relay to OFF
//     Serial.println("Relay initialized on pin " + String(RELAY_PIN));
// }

// void setRelay(bool isOtomaticMode,float hum ,int stdHum) {
//     if(isOtomaticMode){
//         digitalWrite(RELAY_PIN, hum < stdHum ? HIGH : LOW);
//     }else digitalWrite(RELAY_PIN, isOn() ? HIGH : LOW);
//     Serial.println("Relay turned " + String(on ? "ON" : "OFF
// }
// bool getRelayState() {
//     return relayState;
// }