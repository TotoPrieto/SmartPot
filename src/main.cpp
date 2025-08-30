#include <SPI.h>
#include "I2C.hpp"
#include "Button.hpp"
#define BUTTON_PIN    0

 
const int AirValue = 790;   //you need to replace this value with Value_1
const int WaterValue = 390;  //you need to replace this value with Value_2
const int SensorPin = A0;
int soilMoistureValue = 0;
int soilmoisturepercent=0;
bool systemOn = false;



I2C dsp;

Button powerButton(BUTTON_PIN,true,[](){
  systemOn = !systemOn;
    if (!systemOn) {
        dsp.turnOff();
    }else {
        dsp.setupDisplay();
    }
  });


void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
 
 
void loop(){
  powerButton.update();
  if(systemOn) {
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
}

