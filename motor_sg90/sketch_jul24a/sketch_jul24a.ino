/*
* sensor:SG90
*/

#include <Servo.h>

Servo SG90;

void setup() {
  SG90.attach(5); //指定腳位:D1
  Serial.begin(9600);
}

void loop() {
  /*開始転動*/
  SG90_run(0); //転至0度
  SG90_run(90); //転至90度
  SG90_run(180); //転至180度
  SG90_run(90); //転至90度
}

/*指定馬達転動角度且輸出在序列埠的函數*/
void SG90_run(int x){
  SG90.write(x); //指定馬達転動角度
  /*輸出在序列埠*/
  Serial.print("SG90:" );
  Serial.println(x); 
  
  delay(1000); //delay 1000ms
}
