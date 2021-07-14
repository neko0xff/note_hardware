/*
   Source  Code: https://www.instructables.com/How-to-Connect-NodeMCU-ESP8266-to-MySQL-Database-1/
   板子: WMOS D1 mini
   update: 20210714
*/

/*函式庫*/
#include "DHT.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

/*WiFi設定*/
#define HOST "192.168.20.195"          // 伺服器的IP或網址 (without "http:// "  and "/" at the end of URL)
#define WIFI_SSID "Hydroponics"        // Wifi 名稱                                    
#define WIFI_PASSWORD "AA10BB17"       // WIFI 密碼 
#define URL "http://192.168.20.195/dbwrite.php"

/*全局變數*/
#define DHTPIN D1       //腳位:D1
#define DHTTYPE DHT11  // mode:DHT11
int val,val2;
String sendval, sendval2, postData;
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600); //啟用串列埠 
  dht.begin(); //啟用dht11
  Serial.println("Communication Started \n\n");  
  delay(1000);
  
  pinMode(LED_BUILTIN, OUTPUT);     // initialize built in led on the board
   
  get_wifi();  
  delay(30);
  
  dht.begin(); //啟用dht11
}


void loop() { 

HTTPClient http;    // http object of clas HTTPClient
WiFiClient wificlient; //wifi object of WiFiClient

int val = dht.readTemperature(); //溫度(Temperature)
int val2 = dht.readHumidity(); //溼度(Humidity)

// Convert integer variables to string
sendval = String(val);  
sendval2 = String(val2);   
/*使用POST來送出資料*/
postData = "sendval=" + sendval  + "&sendval2=" + sendval2;

// We can post values to PHP files as  example.com/dbwrite.php?name1=val1&name2=val2&name3=val3
// Hence created variable postDAta and stored our variables in it in desired format
// For more detials, refer:- https://www.tutorialspoint.com/php/php_get_post.htm

  // Update Host URL here:-  
   http.begin(wificlient,URL);   //要連線的位置
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header

   int httpCode = http.POST(postData);   // Send POST request to php file and store server response code in variable named httpCode
   Serial.println("Values are, temp = " + sendval + " and hum = "+ sendval2 );

   Serial.print("Send GET request to URL: ");
   Serial.println(URL);

   if (httpCode == 200) { 
      /*如果連線成功*/
      Serial.println("Values uploaded successfully."); 
      Serial.print("Http Code: ");
      Serial.println(httpCode); 
      String webpage = http.getString();    // Get html webpage output and store it in a string
      Serial.println(webpage + "\n"); 
   }else{ 
      /*如果連線不成功*/
     Serial.print("Http Code: ");
     Serial.println(httpCode); 
     Serial.println("Failed to upload values. \n"); 
     http.end(); 
     return;   }  
   led_now();

}


void get_wifi(){
   /*啟用WiFi連線*/
  WiFi.mode(WIFI_STA);           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) { 
      Serial.print(".");
      delay(500); 
   }

  /*輸出連到的Wifi名&連線分到的ip位置*/
  Serial.println();
  //輸出連到的Wifi名
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  //輸出連線分到的ip位置
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP()); 

}


void led_now(){
  /*led指示燈(板子上的LED:LOW&HIGH)*/
  delay(3000); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH); 
}
