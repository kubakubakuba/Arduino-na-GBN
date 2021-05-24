![servo](https://github.com/kubakubakuba/Arduino-na-GBN/blob/main/images/servo.gif?raw=true)
```cpp
#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(9); //na pinu 9 je servo
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1){
    // in steps of 1 degree
    myservo.write(pos);
    delay(5);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(5);
  }
}
```
