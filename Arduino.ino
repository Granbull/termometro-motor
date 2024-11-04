#include <Thermistor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Thermistor temp(0);
float maiorTemp;
float menorTemp = 9999;
int maiorLCD;
int menorLCD;

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
  float temperatura = temp.getTemp();
  if (temperatura > maiorTemp) {
    maiorTemp = temperatura;
    maiorLCD = (int)temperatura;
  }
  if (temperatura < menorTemp) {
    menorTemp = temperatura;
    menorLCD = (int)temperatura;
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
  lcd.print(menorLCD);
  lcd.print("\xDF""c|");

  lcd.setCursor(5, 1);
  lcd.print(temperatura);
  lcd.print("\xDF""c");

  lcd.setCursor(11, 1);
  lcd.print("|");
  lcd.print(maiorLCD);
  lcd.print("\xDF""c");

  delay(1000);
}