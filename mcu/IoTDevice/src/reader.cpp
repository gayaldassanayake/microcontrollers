
/**
 * Sample code Written by Limor Fried, Ladyada and,
 * Example testing sketch for various DHT humidity/temperature sensors
 * Written by ladyada for Adafruit Industries 
 * was used when constructing the following code.
 * Adafruit invests time and resources providing this open source code, 
 * please support Adafruit and open-source hardware by purchasing 
 * products from Adafruit!
 */

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"

#include "env.h"

Adafruit_BMP085 bmp;

#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void initializeBMP180()
{
    if (!bmp.begin())
    {
        Serial.println("Could not find a valid BMP085 sensor, check wiring!");
        while (1)
        {
        }
    }
    Serial.println("BMP085 Initialized!");
}

void initializeDHT11()
{
    dht.begin();
    Serial.println("DHT11 initialized!");    
}

float readPressure()
{
    float pressure = (float)bmp.readPressure();
    if (isnan(pressure))
    {
        Serial.println("Failed to read temperature from DHT sensor!");
        return -1;
    }   
    return pressure;
}

float readTemperature()
{
    float temperature = dht.readTemperature();  // temperature in celcius
    if (isnan(temperature))
    {
        Serial.println("Failed to read temperature from DHT sensor!");
        return -1;
    }
    return temperature;
}

float readHumidity()
{
    float humidity = dht.readHumidity();    // humidity as a percentage
    if (isnan(humidity))
    {
        Serial.println("Failed to read temperature from DHT sensor!");
        return -1;
    }
    return humidity;
}

float readLightIntensity()
{
    int LDRValue = analogRead(LDR_PIN);
	float lightIntensity = LDRValue * (100.0 / 4095.0);   // Intensity as a value in [0.0,1,0]
    return lightIntensity;
}
