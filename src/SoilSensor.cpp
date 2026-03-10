#include "SoilSensor.hpp"


const int SensorPin = A0;
const int AirValue = 790;   //you need to replace this value with Value_1
const int WaterValue = 260;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

SoilSensor::SoilSensor(I2C& display) : dsp(display) {}

void SoilSensor::checkSoilMoistureLevel() {
  int soilMoistureValue = analogRead(SensorPin);
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent > 100)
  {
    dsp.soilHighValue();
  }
  else if(soilMoisturePercent <0)
    {
      dsp.soilLowValue();

    }
    else if(soilMoisturePercent >=0 && soilMoisturePercent <= 100)
    {
      dsp.soilMidValue(soilMoisturePercent);
      if(soilMoisturePercent < 50) {
        dsp.showWaterMessage();
      }
    }
  }

int SoilSensor::getSoilMoistureLevel() {
  return soilMoisturePercent;
}
