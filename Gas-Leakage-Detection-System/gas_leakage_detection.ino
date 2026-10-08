#include <Adafruit_LiquidCrystal.h>

int gas_sensor = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  gas_sensor = analogRead(A0);
  Serial.println(gas_sensor);
  lcd_1.setCursor(0, 0);
  lcd_1.print(gas_sensor);
  if (gas_sensor >= 300) {
    lcd_1.setCursor(0, 1);
    lcd_1.print("GAS IS DETECTED");
    lcd_1.print("GAS IS DETECTED");
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
  } else {
    lcd_1.setCursor(0, 1);
    lcd_1.print("GAS IS NOT DETECTED");
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
