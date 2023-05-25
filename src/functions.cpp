#include "functions.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void connectToHub()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("HUB not connected");
        WiFi.begin(AP_SSID, AP_PWD);
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.print("Connecting to HUB...");
            Serial.print("\n");
            delay(2000);
        }
        Serial.println("");
        Serial.println("Connected to HUB");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println("MAC address: ");
        Serial.println(WiFi.macAddress());

        sensorMacAddress = WiFi.macAddress();
    }
}

void postToHub()
{
    WiFiClient client;
    HTTPClient http;

    String path = HUB_ADDRESS + "update-sensor";

    http.begin(client, path);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "macAddress=" + sensorMacAddress + "&soilMoisturePercent=" + soilMoisturePercent;
    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0)
    {
        Serial.printf("[HTTP] POST... code: %d\n", httpResponseCode);
        if (httpResponseCode == HTTP_CODE_OK)
        {
            String payload = http.getString();
            Serial.println(payload);
        }
    }
    else
    {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
    }
    http.end();
}

void sensor()
{
    soilMoistureValue = analogRead(SENSOR_PIN);
    soilMoisturePercent = map(soilMoistureValue, AIR_VALUE, WATER_VALUE, 0, 100);
}
