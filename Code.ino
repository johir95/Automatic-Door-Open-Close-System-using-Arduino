#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo1;

int led = 5;
int echoPin = 8;
int trigPin = 9;
int Buzzer = 11; 
int servo1_pin=6;

void setup() {
Serial.begin(9600); 
pinMode(Buzzer, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
  servo1.attach(servo1_pin);
  servo1.write(90);
  lcd.begin();
  lcd.backlight();


}
void loop() {
long duration, distance;
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    duration=pulseIn(echoPin, HIGH);
    distance =(duration*0.034)/2;
    delay(10);
   
  
if((distance<=10)) 
{
    Serial.print("distance");
    Serial.println("Door open");
    Serial.print( distance);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(led, HIGH);
    servo1.write(90);
    delay(50);
    lcd.clear();
    lcd.print("Wellcome");
    delay(500);

}
else if(distance>10)
{
    Serial.print("distance");
    Serial.println("Door closed");
    Serial.print( distance);
    digitalWrite(Buzzer, LOW);
    digitalWrite(led, LOW);
    servo1.write(0);
    delay(50);
    lcd.clear();
    lcd.print("Goodbye");
    delay(500);

}
}
