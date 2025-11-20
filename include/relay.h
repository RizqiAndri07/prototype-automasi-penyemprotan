#ifndef RELAY_H
#define RELAY_H

void initRelay(int pin);
void setRelay(bool isOtomaticMode,float hum ,int stdHum, bool isOn);
bool getRelayState();
#endif