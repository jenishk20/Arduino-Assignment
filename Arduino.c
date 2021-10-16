#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

float gas = A0;
float tilt = A1;
float light = A2;
float temp = A3;
float PIR = A4;

void setup()
{
  pinMode(gas, INPUT);
  pinMode(tilt, INPUT);
  pinMode(light, INPUT);
  pinMode(temp, INPUT);
  pinMode(PIR, INPUT);
  lcd.begin(16, 2);
  lcd.home();
  lcd.write("ECO");
  lcd.setCursor(1, 1);
  lcd.write("sensing station");
  Serial.begin(9600);
  delay(5000);
}
void loop()
{
  gas = analogRead(A0);
  tilt = analogRead(A1);
  light = analogRead(A2);
  temp = analogRead(A3);
  PIR = analogRead(A4);
  temp = (analogRead(A3) * 5.0f / 1024 - 0.5) / 0.01;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("The temp");
  lcd.setCursor(0, 1);
  lcd.print(temp);
  delay(3000);
  lcd.clear();
  lcd.write("The tilt:    ");
  lcd.write(tilt);
  delay(3000);
  Serial.println(PIR);
  if (PIR > 50)
  {
    lcd.clear();
    lcd.write("Someone's nearby");
    delay(3000);
  }
  if (light < 10)
  {
    lcd.clear();
    lcd.write("Night Time");
    delay(3000);
  } else
  {
    lcd.clear();
    lcd.write("Day Time");
    delay(3000);
  }
  if (gas > 100)
  {
    lcd.clear();
    lcd.write("Leakage of GAS");
    delay(3000);
  }
}