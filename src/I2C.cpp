#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#include "I2C.hpp"

// Implementación del constructor de I2C
I2C::I2C() {
  // Inicialización si es necesaria
}

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void I2C::setupDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();
}


void I2C::turnOff() {
  display.clearDisplay();
  display.display(); // Update the display to show the cleared screen
}


void I2C::soilMidValue(int soilmoisturepercent){

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Humedad");

  display.setCursor(70,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.println(soilmoisturepercent);
  display.setCursor(80,0);
  display.setTextSize(1);
  display.println(" %");
 
}

void I2C::soilLowValue() {

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Humedad");

  display.setCursor(70,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("0 %");
 
}

void I2C::soilHighValue(){

  display.setCursor(10,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Humedad");

  display.setCursor(70,0);  //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("100 %");
  
}

void I2C::lightValue(float lux) {
  display.setCursor(10, 10);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Luz");

  display.setCursor(50, 10);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  if (lux < 50) {
    display.println("Oscuridad");
  } else if (lux < 500) {
    display.println("Artificial");
  } else if (lux < 2000) {
    display.println("Nublado");
  } else if (lux < 10000) {
    display.println("Sol indir.");
  } else {
    display.println("Sol direc.");
  }
}
void I2C::updateDisplay() {
  display.display();
}

void I2C::cleanDisplay() {
  delay(250);
  display.clearDisplay();
}

void I2C::showWaterMessage() {
  display.setCursor(10,40);  // Nueva línea
  display.setTextSize(2);    // Tamaño grande para mayúsculas
  display.setTextColor(WHITE);
  display.println("REGAR");
}

void I2C::displayOn() {
  display.ssd1306_command(0xAF);  // Display ON
}

void I2C::displayOff() {
  display.ssd1306_command(0xAE);  // Display OFF
}