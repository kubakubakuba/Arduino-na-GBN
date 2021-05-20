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
}
 
void loop() {
  lcd.clear();
  Serial.print("Time: ");
  myTime = millis();
  Serial.println(myTime);
  lcd.print(time);
  delay(100);                  
}
```
Displej k arduinu připojíme podle následujícího schématu:
![alt Zapojení LCD displeje](https://arduino8.webnode.cz/_files/200000042-ea663ebf3d/ScreenShot006.jpg)
