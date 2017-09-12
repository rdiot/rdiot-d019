/* 9376 Motor Miniatura (9376) [D019] : http://rdiot.tistory.com/277 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int R = 2;
byte lastButton = HIGH;
byte nowButton = HIGH;
int servo = 7;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
  pinMode(R, INPUT);
  pinMode(servo, OUTPUT);
 
  digitalWrite(R, HIGH);
  digitalWrite(servo, LOW);
  
  delay(1000); 
  lcd.clear();
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("D019:9376 Motor");
 
  byte nowButton = digitalRead(R);
 
  lcd.setCursor(0,1);
  lcd.print("value="+(String)nowButton);
 
  if (HIGH == lastButton)
  {
    if (LOW == nowButton)
    {
     lcd.setCursor(0,2);
     lcd.print("running motor  ");
     digitalWrite(servo, HIGH);
    }
  }
  else
  {
    if (HIGH == nowButton)
    {
     lcd.setCursor(0,2);
     lcd.print("stopped motor  ");
     digitalWrite(servo, LOW);
    }
  }
 
 lastButton = digitalRead(R);
 delay(100); 
}
