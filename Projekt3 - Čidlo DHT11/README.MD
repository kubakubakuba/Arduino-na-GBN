# Čidlo DHT11
Čidlo zapojíme k arduíno podle následujícího obrázku:
<!-- https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/ -->
![alt Zapojení 1](https://www.circuitbasics.com/wp-content/uploads/2015/10/Arduino-DHT11-Tutorial-3-Pin-DHT11-Wiring-Diagram-768x391.png)
![alt Zapojení 1](https://www.circuitbasics.com/wp-content/uploads/2015/10/Arduino-DHT11-Tutorial-4-Pin-DHT11-Wiring-Diagram-768x356.png)

Využijeme knihovnu pro ovládání DHT [zde](https://github.com/kubakubakuba/Arduino-na-GBN/blob/main/Projekt3%20-%20%C4%8Cidlo%20DHT11/DHT11.rar?raw=true)
```cpp
#include <dht11.h>
 
dht11 senzor;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
 
  senzor.read(1); // čteme z pinu 1
  int tempVal = senzor.temperature;
  int humVal = senzor.humidity;    
  Serial.println("Temperature: " + tempVal + "°C");
  Serial.println("Humidity: " + humVal + "%");
  delay(1000);                 
}
```
