

#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
  
int led_red = 2;
int led_green = 3;
int buzzer = 4;
int gas_sensor = A0;
int safe_value = 400;

void setup()
{
pinMode(led_red, OUTPUT);
pinMode(led_green,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(gas_sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  int analog_value = analogRead(gas_sensor);
  Serial.print(analog_value);
  if(analog_value>safe_value)
  {
    digitalWrite(led_red,HIGH);
    digitalWrite(led_green,LOW);
    tone(buzzer,1000,10000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALERT");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PLEASE CLOSE ");
    lcd.setCursor(0,1);
    lcd.print("   VALVE  ");
    delay(1000);
  }
  else
  {
    digitalWrite(led_green,HIGH);
    digitalWrite(led_red,LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALL CLEAR");
    delay(1000);
  }  
     
}
