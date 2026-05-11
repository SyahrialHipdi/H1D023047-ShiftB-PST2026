// install library LCD_I2C, OK
// inisiasi pin, OK
// inisiasi object LCD, OK
// setup lcd, OK
// setup, OK
// mapping, OK
// write, OK

#include <LiquidCrystal_I2C.h>
#define LED 6
#define POTENSIO 7

int nilaipotensio;
LiquidCrystal_I2C lcd (0x27,16,2);


void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  nilaipotensio=analogRead(POTENSIO);
  int nilaimap = (
    nilaipotensio,
    0,
    1023,
    0,
    255
  );
  analogWrite(LED, nilaimap);
  lcd.setCursor(0,0);
  if (nilaimap<45){
    lcd.print("Lampu mati");
  }else{
    lcd.print("Lampu Nyala");
  }
  lcd.setCursor(1,0);
  lcd.print("kecerahan:", nilaimap);
  // put your main code here, to run repeatedly:

}
