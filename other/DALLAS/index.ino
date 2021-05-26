#include <U8glib.h>
#include <OneWire.h>
#include <DallasTemperature.h>

U8GLIB_SSD1306_128X64 mujOled(U8G_I2C_OPT_NONE);
const int pinCidlaDS = 4;
OneWire oneWireDS(pinCidlaDS);
DallasTemperature senzorDS(&oneWireDS);

long int prepis = 0;

void vypis_oled(String temp){
  mujOled.setFont(u8g_font_osb18);
  mujOled.setPrintPos(10, 25);
  mujOled.print((String)senzorDS.getTempCByIndex(0) + "C");
  }

void setup(void) {
  Serial.begin(9600);
  senzorDS.begin();
}

void loop(void) {
  senzorDS.requestTemperatures();
  Serial.println(senzorDS.getTempCByIndex(0));
  
  if (millis()-prepis > 50) {
    // následující skupina příkazů
    // obnoví obsah OLED displeje
    mujOled.firstPage();
    do {
      // funkce vykresli vykreslí žádaný obsah
      vypis_oled((String)senzorDS.getTempCByIndex(0));
    } while( mujOled.nextPage() );
    // uložení posledního času obnovení
    prepis = millis();
  }
  
  delay(50);
}
