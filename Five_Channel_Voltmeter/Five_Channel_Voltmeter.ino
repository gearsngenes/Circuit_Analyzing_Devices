/***************************************************
  This is a library for the Adafruit 0.96" Mini TFT Featherwing

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution

  ----------GnGminiTFTjoystickFeather notes---------
  The GnGminiTFTjoystickFeather library is a derived class from adafruit
  The main benefit is to improve the ease of setting it up for beginners
  This will be used for future lessons by GearsNGenes
 ****************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include "Adafruit_miniTFTWing.h"
#include "GnGminiTFTjoystickFeather.h"

int height;//160
int width;//80

GnGminiTFTjoystickFeather tft;
//Adafruit_miniTFTWing ss = tft.ss1;

int a1 = A1;
int a2 = A2;
int a3 = A3;
int a4 = A4;
int a5 = A5;
const float voltperreading = (3.3*1.0)/1023.0;
const float voltagedividerratio = 11.0;

void setup(void) {
  Serial.begin(115200);
  Serial.print("Hello! ST77xx TFT Test");
  tft.Setup();
 // tft.setDisplayVals();
  Serial.println("done");
  delay(100);
  pinMode(a1, INPUT);
  pinMode(a2, INPUT);
  pinMode(a3, INPUT);
  pinMode(a4, INPUT);
  pinMode(a5, INPUT);
}

float retunvoltage(int pin)
{
  return (analogRead(pin) *voltperreading*voltagedividerratio);
}

void loop() {
  float v1 = retunvoltage(a1);
  float v2 = retunvoltage(a2);
  float v3 = retunvoltage(a3);
  float v4 = retunvoltage(a4);
  float v5 = retunvoltage(a5);
  tft.setDisplayVals(0, 0, 2);

  tft.printString(String("v1:"));
  tft.printFloat(v1, 2, ST77XX_YELLOW);

  tft.nextline();

  tft.printString(String("v2:"));
  tft.printFloat(v2, 2, ST77XX_YELLOW);
  
  tft.nextline();
  
  tft.printString(String("v3:"));
  tft.printFloat(v3, 2, ST77XX_YELLOW);
  tft.nextline();
  
  tft.printString(String("v4:"));
  tft.printFloat(v4, 2, ST77XX_YELLOW);
  
  tft.nextline();
  
  tft.printString(String("v5:"));
  tft.printFloat(v5, 2, ST77XX_YELLOW);
  tft.clearDisplayAfter(500);
}
