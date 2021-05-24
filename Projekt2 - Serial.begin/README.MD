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

Nyní tyto znalosti můžeme yužít k vypisování hodnoty odporu potenciometru:

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
  Serial.print(hodnota);
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
const int buttonPin = 9;
void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}
void loop(){
  digitalWrite(ledPin, digitalRead(buttonPin));
}
```
Jelikož funkce digitalRead() vrací hodnotu 1 nebo 0 (tzn. HIGH nebo LOW), můžeme ji zapsat na ledku a tím ji ovládat).

Program můžeme strochu zkomplikovat konstantním ON nebo OFF na diodě, změní se po zmáčknutí tlačítka.
```cpp
digitalWrite(pinMode, HIGH);
digitalWrite(pinMode, LOW);
```
Funkcí digitalWrite() zapíšeme digitální jedničku pokud zapíšeme HIGH (maximální napětí), digitální nulu pokud LOW (nulové napětí). Exituje i funkce analogWrite(), tou nezapisujeme hodnoty HIGH / LOW, ale hodnoty od 0 - 255, tím regulujeme výstupní napětí.
```cpp
delay(1000);
```
Funkcí delay "pozastavíme" program na předem daný čas, čílo uvnitř závorek je v ms.

Celý program pak vypadá následovně:
```cpp
const int ledPin = 13;
const int del = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(del);
  digitalWrite(ledPin, LOW);
  delay(del);    
}
```
Můžeme ho přepsat i následujícím způsobem za využití define ("konstanta", která má hodnotu před samotnou kompilací programu):
```cpp
#define ledPin 13
#define DELAY 1000

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(DELAY);
  digitalWrite(ledPin, LOW);
  delay(DELAY);    
}
```
Pokud si chcete do programu něco poznamenat využijte komentáře za // jsou jednořádkové a mezi /* a \*/ jsou víceřádkové.
```cpp
for(i = 0; i <= VALUE; ++i){
//jednořádkový komentář
}
for(i = 0; i <= VALUE; ++i){
/*
více
řádkový
komentář
*/
}
```
Kód vložený mezi komentáře se nebude kompilovat.
Po napsání připojte desku k počítači, vyberte správný druh desky a COM port.
Pak zmáčkněte tlačítko kompilace, a program na desku nahrajte.
Jelikož využíváme pin 13, nemusíme k desce připojovat led diodu, už je zabudována na desce.
