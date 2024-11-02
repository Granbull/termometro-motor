#include <Thermistor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Thermistor temp(0);
int maiorTemp;
int menorTemp = 9999;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Estacio 2024-2");
  lcd.setCursor(2, 1);
  lcd.print("Iniciando...");
  delay(3000);
  lcd.clear();
}
void loop() {
  int temperatura = temp.getTemp();
  if (temperatura > maiorTemp) {
    maiorTemp = temperatura;
  }
  if (temperatura < menorTemp) {
    menorTemp = temperatura;
  }
  Serial.print(menorTemp);
  Serial.print(";");
  Serial.print(temperatura);
  Serial.print(";");
  Serial.print(maiorTemp);
  Serial.print(";");
  Serial.println(millis()/1000);

  lcd.setCursor(0, 0);
  lcd.print("Min:| Temp |Max:");

  lcd.setCursor(0, 1);
  lcd.print(menorTemp);
  lcd.print("\xDF""c|");

  lcd.setCursor(6, 1);
  lcd.print(temperatura);
  lcd.print("\xDF""c");

  lcd.setCursor(11, 1);
  lcd.print("|");
  lcd.print(maiorTemp);
  lcd.print("\xDF""c");

  delay(10000);
}