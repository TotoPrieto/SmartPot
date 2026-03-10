#ifndef SHT3X_HPP
#define SHT3X_HPP

#include <Adafruit_SHT31.h>
#include <Wire.h>
#include "I2C.hpp"

class SHT3xSensor {
public:
    SHT3xSensor();
    bool begin();
    float getTemperature();
    float getHumidity();
    void checkTemperatureHumidity(I2C &dsp);
    Adafruit_SHT31 sht31;
};

#endif