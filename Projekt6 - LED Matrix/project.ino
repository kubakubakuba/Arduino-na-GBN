#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(12,11,10,4);

byte a[8]={
  B01111110,
  B10001000,
  B10001000,
  B10001000,
  B01111110,
  B00000000,
  B00000000,
  B00000000 
};

void writeMatrix(int arr, byte leds[8], LedControl matrixDisplay){
  for(int i = 0; i <= 7; i++){
    matrixDisplay.setRow(arr, i, leds[i]);
    }
  }

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);
}


void loop() { 
  lc.clearDisplay(0);
  /*lc.setLed(0, 1, 2, true);
  delay(3000);
  lc.clearDisplay(0);
  lc.setRow(0,2,0xFF);
  delay(3000);
  lc.clearDisplay(0);
  lc.setColumn(0,5,0xFF); 
  delay(3000); */
  writeMatrix(0, a, lc);
}
