#include <Arduino.h>
#include "functions.h"

//************Variables etc***********************
const char *AP_SSID = "HUB";
const char *AP_PWD = "";
const String HUB_ADDRESS = "http://192.168.4.1/";
String sensorMacAddress = "";

int soilMoistureValue = 0;
int soilMoisturePercent = 0;

int SENSOR_PIN = A0;

int AIR_VALUE = 1023;
int WATER_VALUE = 0;

//************Setup and Loop***********************

void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.print("\n");

    connectToHub();
}

void loop()
{
    connectToHub();
    sensor();
    postToHub();
    delay(10000);
}