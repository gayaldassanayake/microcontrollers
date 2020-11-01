#ifndef READER_H
#define READER_H

void initializeBMP180();
void initializeDHT11();
float readPressure();
float readTemperature();
float readHumidity();
float readLightIntensity();

#endif