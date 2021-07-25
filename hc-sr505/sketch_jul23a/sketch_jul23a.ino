/*  
 *   sensor:hc-sr505/hc-hr501
 *   功能: 人體紅外線感測器 (PIR Motion Sensor)
*/


int sensor = 4; //pin

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moving = digitalRead(sensor);
  /*是否運行*/
  if(moving == HIGH){
     Serial.println("Yes");  
  }else{
     Serial.println("No");
  }
}
