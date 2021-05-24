https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6

# Ultrazvuk
Zapojení podle obrázku:
![alt Zapojení](https://hackster.imgix.net/uploads/attachments/991561/uploads2ftmp2ff6c8de93-288c-4663-9a29-31c8e61172812fultrasonic5_WCDWvutJmv.png?auto=compress%2Cformat&w=680&h=510&fit=max)


```cpp
#define ECHO 4
#define TRIG 5

void setup() {
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicrosecond(10);
  digitalWrite(TRIG, LOW);
  
  float dist = pulseIn(ECHO, HIGH);
  float distance = dist * 0.017315f;
  
  Serial.println("Distance: " + distance);
  delay(1000);
}
```
Kde se vzala hodnota `0.017315`? Jedná se o rychlost zvuku ve vzduchu. Jelikož se zvuk odrazí a vrací se zpátky, musíme ji ještě ale podělit 2.
