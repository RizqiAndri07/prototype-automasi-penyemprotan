#ifndef BLYNK_SERVICE_H
#define BLYNK_SERVICE_H

void initBlynk();
void runBlynk();
void sendToBlynk(float temperature, float humidity);
int getStdTemp();
int getStdHum();
#endif