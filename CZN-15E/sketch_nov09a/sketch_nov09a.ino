/*
 * sensor: CZN-15E 
*/

int sensorVoice = 2; //聲音感測器模組:D2
int LED_Pin = 13; //預設LED燈
boolean val= 0;
boolean LED_ON=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Pin, OUTPUT); 
  pinMode(sensorVoice, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensorVoice);
  Serial.println(val);

  if(val == HIGH){
    if( LED_ON == 1){
      digitalWrite(LED_Pin,HIGH);
      LED_ON = 1;
    }else{
      digitalWrite(LED_Pin,HIGH);
      LED_ON = 1;
    }
 }
}
