/*
 *   File: 在序列埠輸出Hello_world
 *   Date: 2020/09/24
 *   main: zangmenhsu
 *   使用板子:NodeMCU
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //只能設9600(有改過)
}

void loop() {
  // put your main code here, to run repeatedly:
  //輸出到序列埠視窗
  while(1){
    Serial.println("Hello_World");
    delay(1000);
   }

}

//(1)於額外的板子管理員網址欄位中輸入下面網址:http://arduino.esp8266.com/stable/package_esp8266com_index.json
//(2)按下板子管理員,輸入esp點選 esp8266 by ESP8266 Community 安裝
