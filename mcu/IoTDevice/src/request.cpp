#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "env.h"

bool httpPOSTRequestHelper(String body)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;

        String endpoint = (String)SERVERNAME + "/update";
        // String endpoint = (String)SERVERNAME + "/post";

        http.begin(endpoint);

        http.addHeader("Content-Type", "application/xml");
        // http.addHeader("Content-Type", "text/plain");

        int httpResponseCode = http.POST(body);

        http.end();

        if (httpResponseCode == HTTP_CODE_OK)
        {
            Serial.println("Request sent.");
            return true;
        }

        Serial.print("HTTP Error:");
        Serial.println("httpResponseCode");
        return false;
    }

    Serial.println("WiFi Disconnected");
    return false;
}

bool httpPOSTRequest(int &lastTime, char *body)
{   
    if ((millis() - lastTime) > TIMER_DELAY)
    {
        bool response = httpPOSTRequestHelper((String)body);
        lastTime = millis();
        return response;
    }
    return true;
}