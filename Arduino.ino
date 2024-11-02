#include <Thermistor.h>

Thermistor temp(0);
void setup() {
  Serial.begin(9600);
}
void loop() {
  int temperatura = temp.getTemp();
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("°C");
  delay(1000);
}