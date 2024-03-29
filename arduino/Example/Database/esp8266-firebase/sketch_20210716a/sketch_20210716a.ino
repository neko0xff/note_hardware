/*
*    File: 使用ESP8266把資料上伝到Firebase
*    使用版子: WEMOS D1 mini
*    main: zangmenhsu
*    Date: 20210228
*    Update: 20210714
*/

#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>


/* Firebase URL&auth key*/
#define firebaseURl "https://esp8266-demo-a5cca-default-rtdb.firebaseio.com"
#define authCode "AAAAlRmNeNs:APA91bEBBgtgj8is_l9aEObtp0cL3aMygAmaLQoo4rLaWqp383csT9XoFg7-b2R8_-qzwcMZxRpfrA-UdNWKwg8F2EdOa4kBn2_CCWgEfKvTx7I_6AZDIq-pTTdPWE4xE7cdYBRHOS23 "

/*WiFi的連線設置 */
#define wifi_name "kitty"
#define wifi_password "26104012"

FirebaseData Firebase_led;
FirebaseData Firebase_temp;
int pasttime;
int t=0;
int led;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setup_Wifi();
  //setup_Firebase();
  Firebase.begin(firebaseURl, authCode);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  get_Data();
  delay(100);
}

/*資料上伝*/
void get_Data() {
  int myTime = millis();
  if(myTime - pasttime >= 1000){
     pasttime = myTime;
     t++;
     Firebase.setInt(Firebase_temp,"/ledopen/open",t);
   }
   
  Firebase.getInt(Firebase_led,"/ledopen/open",led);
  
  if(led % 2  == 0){
      digitalWrite(LED_BUILTIN, LOW); 
  }else{
      digitalWrite(LED_BUILTIN, HIGH); 
  }
}

/*啟動firebase*/
/*void setup_Firebase() {
  Firebase.begin(firebaseURl, authCode);
}*/

/*WIFI連線*/
void setup_Wifi() {
  WiFi.mode(WIFI_STA); //mode:連結到wifi ap
  WiFi.begin(wifi_name, wifi_password);
  Serial.println("ESP8266 is connecting wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //連線到的wifi位置
}
