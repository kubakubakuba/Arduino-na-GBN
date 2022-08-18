# Program na zprovoznění LCD 16\*2 displeje
Budeme sestavovat následující program:
```cpp
#include  <LiquidCrystal.h>

unsigned long myTime;

LiquidCrystal lcd(2,3,4,5,6,7); 
 
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Arduino na GBN");
  delay(2500);
}
 
void loop() {
  lcd.clear();
  Serial.print("Time: ");
  myTime = millis();
  Serial.println(myTime);
  lcd.print(myTime);
  delay(100);                  
}
```
Displej k arduinu připojíme podle následujícího schématu:

![alt Zapojení LCD displeje](https://github.com/kubakubakuba/Arduino-na-GBN/blob/main/Projekt5%20-%20LCD%20displej/ScreenShot006.jpg)
