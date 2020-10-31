#include "WiFi.h"
#include "env.h"

void setupWifiConnection(){
    Serial.begin(SERIAL_RATE);
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print("Connecting to WiFi: ");
        Serial.println(SSID);
    }

    Serial.println("Connected to the WIFi network!");
}