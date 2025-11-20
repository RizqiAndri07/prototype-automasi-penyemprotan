#include <Arduino.h>
#include "relay.h"
#include  "config.h"

static bool relayState = false; 

void initRelay() {
    pinMode(RELAY_PIN, OUTPUT);
    setRelay(false); // Initialize relay to OFF
    Serial.println("Relay initialized on pin " + String(RELAY_PIN));
}

void setRelay(bool on) {
    relayState = on;
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
    Serial.println("Relay turned " + String(on ? "ON" : "OFF"));
}
bool getRelayState() {
    return relayState;
}