/*
*  Sensor:MG-996R
*/

#include <Servo.h>

Servo MG996R;
int pos = 0; //設置馬達転動的位置變數

void setup() {
  MG996R.attach(5); //指定腳位:D1
  Serial.begin(9600);
}

void loop() {
  /*正轉 180度，從 0 度旋轉到 180 度，每次 1 度*/
  for(pos=0;pos<=180;pos+=1){
    MG996R_run(pos);
  }
  /*反轉 180度，從 180 度旋轉到 0 度，每次 1 度 */
  for(pos=180;pos>=0;pos-=1){
    MG996R_run(pos);
  }
}

void MG996R_run(int x){
  MG996R.write(x); //指定馬達転動角度
  /*輸出在序列埠*/
  Serial.print("MG-996R:");
  Serial.println(x);
  
  delay(100); //delay 100ms
}
