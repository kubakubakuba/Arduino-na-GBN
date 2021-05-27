# Zprovoznění LED Matrixu
Led Matrix pipojíme k Arduínu za využití následujícíího schématu a tabulky rozmístění pinů:

![alt matrix](https://www.circuitstoday.com/wp-content/uploads/2016/04/8X8-Matrix-Pinout-800x406.png)

<table summary="Mapping: LED Matrix pin numbers to rows and columns to Arduino pin numbers" border="1" align="center"><tbody><tr><td valign="top" align="center"><strong>Matrix pin no.</strong></td><td valign="top" align="center"><strong>Row</strong></td><td valign="top" align="center"><strong>Column</strong></td><td valign="top" align="center"><strong>Arduino pin number</strong></td></tr><tr><td valign="top" align="center">1</td><td valign="top" align="center">5</td><td valign="top" align="center">–</td><td valign="top" align="center">13</td></tr><tr><td valign="top" align="center">2</td><td valign="top" align="center">7</td><td valign="top" align="center">–</td><td valign="top" align="center">12</td></tr><tr><td valign="top" align="center">3</td><td valign="top" align="center">–</td><td valign="top" align="center">2</td><td valign="top" align="center">11</td></tr><tr><td valign="top" align="center">4</td><td valign="top" align="center">–</td><td valign="top" align="center">3</td><td valign="top" align="center">10</td></tr><tr><td valign="top" align="center">5</td><td valign="top" align="center">8</td><td valign="top" align="center">–</td><td valign="top" align="center">16 (analog pin 2)</td></tr><tr><td valign="top" align="center">6</td><td valign="top" align="center">–</td><td valign="top" align="center">5</td><td valign="top" align="center">17 (analog pin 3)</td></tr><tr><td valign="top" align="center">7</td><td valign="top" align="center">6</td><td valign="top" align="center">–</td><td valign="top" align="center">18 (analog pin 4)</td></tr><tr><td valign="top" align="center">8</td><td valign="top" align="center">3</td><td valign="top" align="center">–</td><td valign="top" align="center">19 (analog pin 5)</td></tr><tr><td valign="top" align="center">9</td><td valign="top" align="center">1</td><td valign="top" align="center">–</td><td valign="top" align="center">2</td></tr><tr><td valign="top" align="center">10</td><td valign="top" align="center">–</td><td valign="top" align="center">4</td><td valign="top" align="center">3</td></tr><tr><td valign="top" align="center">11</td><td valign="top" align="center">–</td><td valign="top" align="center">6</td><td valign="top" align="center">4</td></tr><tr><td valign="top" align="center">12</td><td valign="top" align="center">4</td><td valign="top" align="center">–</td><td valign="top" align="center">5</td></tr><tr><td valign="top" align="center">13</td><td valign="top" align="center">–</td><td valign="top" align="center">1</td><td valign="top" align="center">6</td></tr><tr><td valign="top" align="center">14</td><td valign="top" align="center">2</td><td valign="top" align="center">–</td><td valign="top" align="center">7</td></tr><tr><td valign="top" align="center">15</td><td valign="top" align="center">–</td><td valign="top" align="center">7</td><td valign="top" align="center">8</td></tr><tr><td valign="top" align="center">16</td><td valign="top" align="center">–</td><td valign="top" align="center">8</td><td valign="top" align="center">9</td></tr></tbody></table>

Dále pak ke každé diodě přistupujeme jako k jednotlivé, pouze však vždy musíme spojit dva piny - jeden na LOW druhý na HIGH. - zde příklad:

```cpp
void setup() {
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
}
void loop() {
  digitalWrite(13,LOW);
  digitalWrite(11,HIGH);
}
```
Zprovoznění celého matrixu je již však komplikovanější než jednotlivých diod, zde je celý kód:
```cpp
#define REFRESH 50 //refresh rate in microseconds

const int rows[8] = {2, 7, A5, 5, 13, A4, 12, A2};
const int cols[8] = {6, 11, 10, 3, A3, 4, 8, 9};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i <= 7; i++){
    pinMode(rows[i],OUTPUT);
    pinMode(cols[i],OUTPUT);
    }
  for(int i = 0; i <= 7; i++){
    digitalWrite(rows[i],LOW);
    }
}

void clearRows(){
  for(int i = 0; i <= 7; i++){
    digitalWrite(rows[i],HIGH);
    }
  }

void clearCols(){
  for(int i = 0; i <= 7; i++){
    digitalWrite(cols[i],LOW);
    }
  }

void ledOn(int x, int y){
  clearRows();
  clearCols();
  digitalWrite(rows[x],LOW);
  digitalWrite(cols[y],HIGH);
  }

void printRow(int x, byte matrixByte[8]){
  for(int i = 0; i <= 7; i++){
    int bitNow = bitRead(matrixByte[x], 7 - i);
    if(bitNow){
      ledOn(x,i);
      }
    delayMicroseconds(REFRESH);
    }
  }

void printMatrix(byte matrixByteIn[8]){
  for(int i = 0; i <= 7; i++){
    printRow(i, matrixByteIn);
    }
  }
  
byte test[8]={
  B10000011,
  B11111111,
  B00110000,
  B10111111,
  B00001100,
  B11111111,
  B00000000,
  B11111111 
};

byte test2[8]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

void loop() {
  printMatrix(test);
}
```

# Program na zprovoznění LED Matrixu s řadičem MAX72XX
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
void writeMatrix(int arr, byte leds[8], LedControl matrixDisplay){
  for(int i = 0; i <= 7; i++){
    matrixDisplay.setRow(arr, i, leds[i]);
  }
}
```
Na displej pak vypisujeme způsobem `writeMatrix(0, test, lc);`.
