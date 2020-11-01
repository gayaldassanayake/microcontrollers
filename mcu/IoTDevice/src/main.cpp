#include <Arduino.h>
#include <queue>
#include <WiFi.h>
#include <vector>
#include "network.h"
#include "request.h"
#include "time.h"
#include "reader.h"
#include "env.h"
#include "parameters.h"
#include "helpers.h"
#include "xml_preprocessor.h"


using std::queue;
using std::vector;

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = (int)(5.5 * 60 * 60);
const int daylightOffset_sec = 0;

queue<Parameters> parameterList;

vector<float> temperatureList;
vector<float> humidityList;
vector<float> pressureList;
vector<float> lightList;

int timer, sampler;
int identifier = 0;
char requestBody[1000];

void getTime(char *update_time)
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
  char buffer[20];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
  sprintf(update_time, buffer);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  setupWifiConnection();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  initializeBMP180();
  initializeDHT11();

  timer = millis();
  sampler = millis();

  Serial.println("Setup done");
  // int lastTime = 0;
  // char *body = (char *)"This is expected to be sent back as part of response body.";
  // httpPOSTRequest(lastTime, body);
}

void loop()
{

  if (millis() - timer > TIMER_DELAY)
  {
    timer = millis();
    // calc sd, mean and push to buffers

    Parameters param;
    param.humidity_mean = calculateMean(humidityList);
    param.temperature_mean = calculateMean(temperatureList);
    param.pressure_mean = calculateMean(pressureList);
    param.light_mean = calculateMean(lightList);

    param.humidity_std = calculateStd(humidityList, param.humidity_mean);
    param.temperature_std = calculateStd(temperatureList, param.temperature_mean);
    param.pressure_std = calculateStd(pressureList, param.pressure_mean);
    param.light_std = calculateStd(lightList, param.light_mean);

    humidityList.clear();
    temperatureList.clear();
    pressureList.clear();
    lightList.clear();

    param.id = identifier;
    identifier++;

    getTime(param.update_time);

    parameterList.push(param);
  }

  if (millis() - sampler > SAMPLING_RATE)
  {
    sampler = millis();
    temperatureList.push_back( readTemperature());
    humidityList.push_back( readHumidity());
    pressureList.push_back( readPressure());
    lightList.push_back( readLightIntensity());

  }

  while(parameterList.size()>0 && checkWifi()){
    XMLPreprocessor(requestBody, parameterList.front());

    if(httpPOSTRequest(requestBody)){
      parameterList.pop();
    }
    else{
      break;
    }
  }
}