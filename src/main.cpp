#include <SPI.h>
#include "I2C.hpp"

 
const int AirValue = 790;   //you need to replace this value with Value_1
const int WaterValue = 390;  //you need to replace this value with Value_2
const int SensorPin = A0;
int soilMoistureValue = 0;
int soilmoisturepercent=0;
I2C dsp;
 
 
void setup() {
  Serial.begin(115200); // open serial port, set the baud rate to 9600 bps
  dsp.setupDisplay();
}
 
 
void loop() 
{
soilMoistureValue = analogRead(SensorPin);  //put Sensor insert into soil
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent > 100)
{
  dsp.highValue();
}
else if(soilmoisturepercent <0)
{
  dsp.lowValue();

}
else if(soilmoisturepercent >=0 && soilmoisturepercent <= 100)
{
  dsp.midValue(soilmoisturepercent);
}  
}