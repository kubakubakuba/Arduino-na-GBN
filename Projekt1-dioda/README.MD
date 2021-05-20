# Program na zprovoznění LED diody
## Základní struktura programu
```
void setup() {
//setup
}

void loop() {
//loop
}
```
Ve smyčce setup se kód spustí pouze jednou na začátku programu, ve smyčce loop se kód periodicky opakuje, řádek po řádku.
Každý řádek ukončujeme středníkem ; (na české klávesnici nad klávesou TAB)
```
int ledPin = 13;
```
Zavedeme proměnou typu Integer, s názvem ledPin a vložíme do ní hodnotu 13. Tím si usnadníme pojmenování jednotlivých pinů na desce (nemusíme si pamatovat čísla).
```
pinMode(ledPin, OUTPUT);
```
Funkcí pinMode() řekneme, že na pinu ledPin máme výstupní zařízení.
```
digitalWrite(pinMode, HIGH);
digitalWrite(pinMode, LOW);
```
Funkcí digitalWrite() zapíšeme digitální jedničku pokud zapíšeme HIGH (maximální napětí), digitální nulu pokud LOW (nulové napětí). Exituje i funkce analogWrite(), tou nezapisujeme hodnoty HIGH / LOW, ale hodnoty od 0 - 255, tím regulujeme výstupní napětí.
