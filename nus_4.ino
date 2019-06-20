#define HEATER_0 10



#include <LiquidCrystal.h>
#define a -4.520959231464644e-07
#define b 7.716765868657807e-04
#define c -0.546501992496493
#define d 2.420025597828875e+02

LiquidCrystal lcd(16, 17, 23, 25, 27, 29);


#define TEMP_0_PIN         13   // Analog Input
#define TEMP_1_PIN         15   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input

int t,i=0;
double x, y;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20, 4);

  pinMode(HEATER_0, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  t = analogRead(TEMP_0_PIN);
  x = (double)t;
  y = a * x * x * x + b * x * x + c * x + d;
  lcd.setCursor(0, 0);
  lcd.print(y);

  if (i<50)
  {
    digitalWrite(HEATER_0, HIGH);
    i++;
  }
  else
    digitalWrite(HEATER_0, LOW);
 

  delay(100);

}
