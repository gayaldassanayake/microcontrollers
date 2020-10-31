#include <Arduino.h>
#include "network.h"
#include "request.h"

void setup()
{
  Serial.begin(115200);
  delay(100);
  Serial.println("Setup done");
  setupWifiConnection();
  int lastTime = 0;
  char *body = (char *)"This is expected to be sent back as part of response body.";
  httpPOSTRequest(lastTime, body);
}

void loop()
{
}