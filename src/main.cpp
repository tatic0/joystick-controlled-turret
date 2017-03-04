#include<Arduino.h>
#include <Servo.h>

Servo servo1;
Servo servo2;

int analogX = 0; 
int analogY = 1; 
int valX = 0;
int valY = 0;

void setup (){
  servo1.attach(9);
  servo2.attach(10);
  Serial.begin(9600);
  Serial.println("turret ready!");
}

void loop (){
  valX = analogRead(analogX);
  Serial.println(valX);
  valX = map(valX, 0, 1023, 0, 180); //magic function to map values
  Serial.println(valX);              //https://www.arduino.cc/en/Reference/Map
  servo1.write(valX);
  valY = analogRead(analogY);
  Serial.println(valY);
  valY = map(valY, 0, 1023, 0, 180);
  Serial.println(valY);
  servo2.write(valY);
  delay(50);
}
