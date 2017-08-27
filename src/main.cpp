#include<Arduino.h>
#include<Servo.h>
#include<math.h>

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
  valX = map(valX, 0.00, 1023.00, 180.00, 0.00); //magic function to map values
  Serial.println(valX);              //https://www.arduino.cc/en/Reference/Map
  servo1.write(valX);
  delay(50);
  valY = analogRead(analogY);
  Serial.println(valY);
  valY = map(valY, 0, 1023, 180, 0);
  Serial.println(valY);
  servo2.write(valY);
  delay(50);
}


/*
double modifiedMap(double x, double in_min, double in_max, double out_min, double out_max)
{
 double temp = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 temp = (int) (4*temp + .5);
 return (double) temp/4;
}
*/
