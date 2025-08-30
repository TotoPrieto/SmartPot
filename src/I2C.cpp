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

void I2C::midValue(int soilmoisturepercent){
  Serial.print(soilmoisturepercent);
  Serial.println("%");
  
  display.setCursor(22,0);  //oled display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Humedad");
  display.setCursor(35,15);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Suelo");

  display.setCursor(30,40);  //oled display
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.println(soilmoisturepercent);
  display.setCursor(70,40);
  display.setTextSize(3);
  display.println(" %");
  display.display();
 
  delay(250);
  display.clearDisplay();
}

void I2C::lowValue() {
  Serial.println("0 %");
  
  display.setCursor(22,0);  //oled display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Humedad");
  display.setCursor(35,15);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Suelo");

  display.setCursor(30,40);  //oled display
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.println("0 %");
  display.display();
 
  delay(250);
  display.clearDisplay();
}

void I2C::highValue(){
  Serial.println("100 %");
  
  display.setCursor(22,0);  //oled display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Humedad");
  display.setCursor(35,15);  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Suelo");
  
  display.setCursor(30,40);  //oled display
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.println("100 %");
  display.display();
  
  delay(250);
  display.clearDisplay();
}