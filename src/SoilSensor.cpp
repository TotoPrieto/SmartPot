#include "SoilSensor.hpp"


const int SensorPin = A0;
const int AirValue = 790;   //you need to replace this value with Value_1
const int WaterValue = 390;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

SoilSensor::SoilSensor(I2C& display) : dsp(display) {}

void SoilSensor::checkSoilMoistureLevel() {
  int soilMoistureValue = analogRead(SensorPin);
  int soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent > 100)
  {
    dsp.soilHighValue();
  }
  else if(soilmoisturepercent <0)
    {
      dsp.soilLowValue();

    }
    else if(soilmoisturepercent >=0 && soilmoisturepercent <= 100)
    {
      dsp.soilMidValue(soilmoisturepercent);
    }
  }