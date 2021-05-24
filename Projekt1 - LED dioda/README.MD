# Program na zprovoznění LED diody
## Základní struktura programu
```cpp
void setup() {
//setup
}

void loop() {
//loop
}
```
Ve smyčce setup se kód spustí pouze jednou na začátku programu, ve smyčce loop se kód periodicky opakuje, řádek po řádku.
Každý řádek ukončujeme středníkem ; (na české klávesnici nad klávesou TAB)
```cpp
int ledPin = 13;
const int ledPin = 13;
```
Zavedeme proměnou typu Integer, s názvem ledPin a vložíme do ní hodnotu 13. Tím si usnadníme pojmenování jednotlivých pinů na desce (nemusíme si pamatovat čísla). Slovo const přidáváme, pokud se jedná o konstantu a do proměnné později nebudeme zapisovat.
```cpp
pinMode(ledPin, OUTPUT);
```
Funkcí pinMode() řekneme, že na pinu ledPin máme výstupní zařízení.
```cpp
digitalWrite(ledPin, HIGH);
digitalWrite(ledPin, LOW);
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
