#include <Thermistor.h>

Thermistor temp(0);
int maiorTemp;
int menorTemp = 9999;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int temperatura = temp.getTemp();
  if (temperatura > maiorTemp) {
    maiorTemp = temperatura;
  }
  if (temperatura < menorTemp) {
    menorTemp = temperatura;
  }
  Serial.print("Temperatura atual: ");
  Serial.print(temperatura);
  Serial.println("°C");
  Serial.print("Mínima: ");
  Serial.print(menorTemp);
  Serial.print("°C | Máxima: ");
  Serial.print(maiorTemp);
  Serial.println("°C");
  Serial.println("----------------------------"); 
  delay(10000);
}