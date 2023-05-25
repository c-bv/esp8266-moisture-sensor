#include <Arduino.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void connectToHub();
void postToHub();
void sensor();

extern const char *AP_SSID;
extern const char *AP_PWD;
extern const String HUB_ADDRESS;
extern String sensorMacAddress;

extern int SENSOR_PIN;

extern int AIR_VALUE;
extern int WATER_VALUE;

extern int soilMoistureValue;
extern int soilMoisturePercent;
#endif