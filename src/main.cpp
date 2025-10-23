#include <SPI.h>
#include "I2C.hpp"
#include "Button.hpp"
#include "LightSensor.hpp"
#include "SoilSensor.hpp"
#include <Wire.h>

#define BUTTON_PIN    0
bool systemOn = true;


I2C dsp;
SoilSensor soilMoistureSensor(dsp);
LightSensor lightSensor(dsp);

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

  // --- I2C Scanner ---
  Serial.println("\nEscaneando bus I2C...");
  byte count = 0;
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo I2C encontrado en 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();
      count++;
      delay(5);
    }
  }
  if (count == 0) Serial.println("No se encontraron dispositivos I2C\n");
  else Serial.println("Escaneo I2C finalizado\n");

}
 
 
void loop(){
  powerButton.update();
  if(systemOn) {
    soilMoistureSensor.checkSoilMoistureLevel();
    lightSensor.checkLux();
    dsp.updateDisplay();
    dsp.cleanDisplay();
  }
}
