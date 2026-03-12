#include <SPI.h>
#include "I2C.hpp"
#include "Button.hpp"
#include "LightSensor.hpp"
#include "SoilSensor.hpp"
#include "LED.hpp"
#include "Ultrasonic.hpp"
#include <Wire.h>

#define BUTTON_PIN    0
bool systemOn = true;
unsigned long lastDetectionTime = 0;


I2C dsp;
SoilSensor soilMoistureSensor(dsp);
LightSensor lightSensor(dsp);
LED led;
Ultrasonic ultrasonic(D7, D8);  // Trig D7, Echo D8

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
  Wire.begin(D2, D1); // SDA, SCL para ESP8266
  dsp.setupDisplay();
  lightSensor.begin();
  led.begin();
  ultrasonic.begin();
}

void loop(){
  // Detección ultrasónica
  if (ultrasonic.detectPresence()) {
    lastDetectionTime = millis();
    if (!systemOn) {
      systemOn = true;
      dsp.setupDisplay();
    }
  }

  // Apagar después de 1 minuto sin detección
  if (systemOn && millis() - lastDetectionTime > 60000) {
    systemOn = false;
    dsp.turnOff();
  }

  powerButton.update();
  if(systemOn) {
    soilMoistureSensor.checkSoilMoistureLevel();
    lightSensor.checkLux();
    //led.setRed(soilMoistureSensor.getSoilMoistureLevel() < 50);  // Rojo si humedad < 50%
    
    //led.setYellow(lightSensor.noSunForWhile());  // Amarillo si luz < 100 lux
    dsp.updateDisplay();
    dsp.cleanDisplay();
  }
}