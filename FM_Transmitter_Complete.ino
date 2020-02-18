#include <Wire.h>
#include <Adafruit_Si4713.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define RESETPIN 12

Adafruit_Si4713 radio = Adafruit_Si4713(RESETPIN);
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 7, 6, 5, 4);

void setup(){
  
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
  display.begin();
  display.clearDisplay();
  display.setContrast(50);
  display.setRotation(2);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(4,16);
  analogWrite(9, 150);
  display.print("Tuning");
  display.display();
  
  radio.begin();
  
  uint16_t lowestNoiseFrequency = 8750;
  uint8_t lowestNoiseLevel = 100;
  
  for (uint16_t f  = 8790; f < 10790; f += 20) {
   radio.readTuneMeasure(f);
   radio.readTuneStatus();
   uint16_t noiseLevel = radio.currNoiseLevel;
   if (noiseLevel < lowestNoiseLevel)
   {
      lowestNoiseLevel = noiseLevel;
      lowestNoiseFrequency = f;
   }
}

  radio.setTXpower(115);
  radio.tuneFM(lowestNoiseFrequency);        
  radio.readTuneStatus();
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Tuned to:");
  display.println();
  display.setTextSize(2);
  
  if(lowestNoiseFrequency < 10000) {
  display.setCursor(11,16); 
  display.print(radio.currFreq/100);
  display.print('.');
  display.println(radio.currFreq % 100);
  display.display();
  }
  
  else {
  display.setCursor(5,16);
  display.print(radio.currFreq/100);
  display.print('.');
  display.println(radio.currFreq % 100);
  display.display();
  }
  
  delay(7500);
  analogWrite(9, 0);  
}

void loop(){
  
}
