/*
   Source  Code: https://www.instructables.com/How-to-Connect-NodeMCU-ESP8266-to-MySQL-Database-1/
   板子: WMOS D1 mini
   update: 20210714
*/

/*函式庫*/
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

/*WiFi設定*/
#define HOST "192.168.21.39"          // 伺服器的IP或網址 (without "http:// "  and "/" at the end of URL)
#define WIFI_SSID "Hydroponics"        // Wifi 名稱                                    
#define WIFI_PASSWORD "AA10bb17"       // WIFI 密碼 
#define URL "http://192.168.21.39/upload_data/dbwrite_deviceConnent_1.php"

/*全局變數*/
int val,val2;
String sendval, sendval2, postData;
String sendval3;


void setup() {
  Serial.begin(9600); //啟用串列埠 
  Serial.println("Communication Started \n\n");  
  delay(1000);
  //pinMode(LED_BUILTIN, OUTPUT);     // initialize built in led on the board
  get_wifi();
  delay(30);
}


void loop() { 

/*HTTPClient http;    // http object of clas HTTPClient

//int device_id = Serial.parseInt(); //輸入=int
//Serial.println(device_id);

String val = "seekingdevice";

// Convert integer variables to string
sendval = val;  
  
//使用POST來送出資料
postData = "device=" + sendval ;

// We can post values to PHP files as  example.com/dbwrite.php?name1=val1&name2=val2&name3=val3
// Hence created variable postDAta and stored our variables in it in desired format
// For more detials, refer:- https://www.tutorialspoint.com/php/php_get_post.htm

  // Update Host URL here:-  
   http.begin(URL);   //要連線的位置
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header

   int httpCode = http.POST(postData);   // Send POST request to php file and store server response code in variable named httpCode
   Serial.println("Values are, devices = " + sendval);

   Serial.print("Send GET request to URL: ");
   Serial.println(URL);

   if (httpCode == 200) { 
      //如果連線成功
      Serial.println("Values uploaded successfully."); 
      Serial.print("Http Code: ");
      Serial.println(httpCode); 
      String webpage = http.getString();    // Get html webpage output and store it in a string
      Serial.println(webpage + "\n"); 
   }else{ 
      //如果連線不成功
     Serial.print("Http Code: ");
     Serial.println(httpCode); 
     Serial.println("Failed to upload values. \n"); 
     http.end(); 
     return;   }  
   //led_now();*/
  HTTPClient http; 
  
  http.begin("http://192.168.21.39/upload_data/dbwrite_deviceConnent_1.php");   // 連接到MySQL數據庫的主機 
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //指定內容類型標題
  int httpCode = http.POST("device=seekingdevice");   // 將POST請求發送到php文件，並將服務器響應代碼存儲在名為httpCode的變量中
  //Serial.println(postData); 
  if (httpCode == 200){   // 如果連接完成，則執行此操作 
      Serial.println("Values uploaded successfully."); 
      Serial.println(httpCode); 
      String webpage = http.getString(); // Get html webpage output and store it in a string
      Serial.println(webpage + "\n");
      //Data3 = webpage.substring(0,8);
      //Serial.println(Data3);
      //Data3 = webpage.substring(21,23);
      //Data4 = webpage.substring(57,58);
      //Serial.println(Data4);
      //defaultTemp = Data3.toInt();
    }
    else{
      Serial.println(httpCode);
      Serial.println("Failed to upload values. \n"); 
      http.end(); 
      return;
    }
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
  //digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  //digitalWrite(LED_BUILTIN, HIGH); 
}
