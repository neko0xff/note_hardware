/*
* sensor: HC-SR04
* 請安裝"Ultrasonic"的函式庫
*/

#include <Ultrasonic.h>

#define TRIGGER 5 //D1(GPIO5)
#define ECHO 4 //D2(GPIO4)
Ultrasonic ultrasonic(TRIGGER,ECHO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  hcsr04_run();
}

void hcsr04_run(){
  Serial.print("Distance; ");
  Serial.print(ultrasonic.distanceRead());
  Serial.println(" cm");
  delay(2000);
}
