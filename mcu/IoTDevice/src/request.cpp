#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "env.h"

bool httpPOSTRequestHelper(char *body)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;

        String endpoint = (String)SERVERNAME + "/update";
        // String endpoint = (String)SERVERNAME + "/post";

        http.begin(endpoint);

        http.addHeader("Content-Type", "application/xml");
        // http.addHeader("Content-Type", "text/plain");

        int httpResponseCode = http.POST((String)body);

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

bool httpPOSTRequest(char *body)
{
    for (int i = 0; i < 5; i++)
    {
        if (httpPOSTRequestHelper(body))
        {
            return true;
        }
    }

    return false;
}