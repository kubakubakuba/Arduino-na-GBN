# Serial.begin
## Využití sériového portu ke komunikaci
```cpp
void setup() {
Serial.begin(9600);
Serial.print('Hello World!');
}

void loop() {
Serial.println('Ahoj!');
delay(100);
}
```
Příkazem `Serial.begin(9600);` ve smyčce setup nastavíme hodnotu rychlosti komunikace na 9600 baudů. Do seriálového monitoru se dostaneme po kliknutí na příslušné tlačítko vpravo nahoře v rohu. Do seriálového portu vypisujeme příkazy `Serial.print()` a `Serial.println()`, druhý příkaz vypíše nový řádek.

Nyní tyto znalosti můžeme využít k vypisování hodnoty odporu potenciometru:

![alt Zapojení potenciometru](https://arduino8.webnode.cz/_files/200000038-6bc7a6cca5/ScreenShot003.jpg)

```cpp
const int analogPin = A0;
int value = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  value = analogRead(analogPin);    
  
  Serial.print("Value = ");                  
  Serial.print(value);
  Serial.println();
 
  delay(1000);                   
}
```
Vypisování můžeme zrychlit zapsáním na jeden řádek, a to pomocí "sčítání" textů.

```cpp
  Serial.println("Value = " + hodnota);                               
```

# Tlačítko s LED diodou

```cpp
const int ledPin = 5;
const int buttonPin = 6;

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop(){
  digitalWrite(ledPin, digitalRead(buttonPin));
}
```
Jelikož funkce digitalRead() vrací hodnotu 1 nebo 0 (tzn. HIGH nebo LOW), můžeme ji zapsat na ledku a tím ji ovládat).

![alt Zapojení](https://github.com/kubakubakuba/Arduino-na-GBN/blob/main/images/ledButton.png?raw=true)

Program můžeme trochu zkomplikovat konstantním ON nebo OFF na diodě, změní se po zmáčknutí tlačítka.
```cpp
const int ledPin = 5;
const int buttonPin = 6;
boolean isOn = false;

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop(){
  if(digitalRead(buttonPin) == true){
    if(isOn == true){
      isOn = false;
    }
    else{
      isOn = true;
    }
    digitalWrite(ledPin, isOn);
    while (digitalRead(buttonPin) == true){
      delay(50);
    }
  }
}
```
Program můžeme zjednodušit jednořádkovým zápisem if a else.

```cpp
void loop(){
  if(digitalRead(buttonPin)){
    if(isOn)
      isOn = false;
    else
      isOn = true;
    digitalWrite(ledPin, isOn);
    while (digitalRead(buttonPin))
      delay(50);
  }
}
```
