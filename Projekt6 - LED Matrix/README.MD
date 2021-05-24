# Program na zprovoznění LED Matrixu
Budeme využívat knihovnu LedControl.h
Displej připojíme následujícím způsobem:
* DIN (DataIn) na pin 12
* CLK (Clock) na pin 11
* CS (LOAD) na pin 10
Program pak bude následující:
```cpp
#include "LedControl.h"

LedControl lc = LedControl(12,11,10,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);
}


void loop() { 
  lc.clearDisplay(0);
  lc.setLed(0, 1, 2, true);
  delay(3000);
  
  lc.clearDisplay(0);
  lc.setRow(0,2,0xFF);
  delay(3000);
  
  lc.clearDisplay(0);
  lc.setColumn(0,5,0xFF); 
  delay(3000);
}
```
Budeme využívat následující příkazy
* `lc.clearDisplay(i);` - smaže displej i
* `lc.setLed(i, x, y, boolean);` - nastaví led diodu na souřadnicích x y na displeji i na hodnotu booleanu (true / false)
* `lc.setRow(i, x, byte);` - nastaví řádek x na displeji i na hodnotu byte (B00000000, nebo v HEX jako 0x00)
* `lc.setColumn(i, x, byte);` - obdobně jako u řádku

Jelikož však chceme předem vytvořit "znak" a ten na displej poté poslat, musíme si napsat bitové pole a pak ho na displej pomocí jedné smyčky for poslat.
Bitové pole definujeme následujícím způsobem:
```cpp
byte test[8]={
  B00000000,
  B11111111,
  B00000000,
  B11111111,
  B00000000,
  B11111111,
  B00000000,
  B11111111 
};
```
Jeho zápis můžeme zkrátit využitím zápisu v HEX:
```cpp
byte test[8]={
  0x00,
  0xFF,
  0x00,
  0xFF,
  0x00,
  0xFF,
  0x00,
  0xFF 
};
//dále zkrátíme zápis:
byte test[8]={0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF};
```
Funkci která nám pak na displej pošle tento byte sestavíme velmi lehce za použití dříve zmíněných funkcí (řádek po řádku přečteme hodnotu a zapíšeme ji na displej).
```cpp
void writeMatrix(int arr, byte leds[8]){
  for(int i = 0; i <= 7; i++){
    lc.setRow(arr, i, leds[i]);
  }
}
```
Na displej pak vypisujeme způsobem `writeMatrix(0, test);`.
