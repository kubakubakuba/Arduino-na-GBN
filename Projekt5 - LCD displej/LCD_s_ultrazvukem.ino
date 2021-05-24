#include  <LiquidCrystal.h>
#define ECHO 4
#define TRIG 5

unsigned long myTime;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); 
  
void setup() {
  lcd.begin(16, 2);
  lcd.print("Arduino na GBN");
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  delay(2500);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  float dist = pulseIn(ECHO, HIGH);
  float distance = dist * 0.017315f;
  
  Serial.println("Distance: " + (String)distance);

  lcd.clear();
  lcd.setCursor(0, 0);
  Serial.print("Time: ");
  myTime = millis();
  Serial.println(myTime);
  lcd.print(String(floor(myTime/1000)) + " s");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000); 
}
