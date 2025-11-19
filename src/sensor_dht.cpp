#include <Arduino.h>
#include "sensor_dht.h"
#include "config.h"
#include "DHTesp.h"

DHTesp dht;

void initDHT() {
    dht.setup(DHT_PIN, DHTesp::DHT22);
}
float getTemperature() {
    float temperature = dht.getTemperature();
    if (isnan(temperature)) {
        Serial.println("Failed to read temperature from DHT sensor!");
        return -999.0;
    }
    return temperature;
}
float getHumidity() {
    float humidity = dht.getHumidity();
    if (isnan(humidity)) {
        Serial.println("Failed to read humidity from DHT sensor!");
        return -999.0;
    }
    return humidity;
}