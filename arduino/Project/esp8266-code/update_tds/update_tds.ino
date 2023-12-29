/*
   Source  Code: https://www.instructables.com/How-to-Connect-NodeMCU-ESP8266-to-MySQL-Database-1/
   板子: WMOS D1 mini
   update: 20211006
*/

/*函式庫*/
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/*tds設定*/
#define TdsSensorPin A0        //tds腳位: A0
#define VREF 5.0              // analog reference voltage(Volt) of the ADC
#define SCOUNT  30           // sum of sample point
int analogBuffer[SCOUNT];    // store the analog value in the array, read from ADC
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0,copyIndex = 0;
float averageVoltage = 0,tdsValue = 0,temperature = 25;

/*WiFi設定*/
#define HOST "192.168.21.39"          // 伺服器的IP或網址 (without "http:// "  and "/" at the end of URL)
#define WIFI_SSID "Hydroponics"        // Wifi 名稱                                    
#define WIFI_PASSWORD "AA10bb17"       // WIFI 密碼 
#define URL "http://192.168.21.39/upload_data/dbwrite_tds_1.php"

/*上伝變數*/
int val,val2;
String sendval, sendval2, postData;
void setup(){
    Serial.begin(9600);
    Serial.println("Communication Started \n\n"); 
    delay(1000);
    
    pinMode(TdsSensorPin,INPUT);

    get_wifi();
    delay(30);
}
 
void loop(){
   HTTPClient http;    // http object of clas HTTPClient
   
   static unsigned long analogSampleTimepoint = millis();
   
   if(millis()-analogSampleTimepoint > 40U){     //every 40 milliseconds,read the analog value from the ADC
     analogSampleTimepoint = millis();
     analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);    //read the analog value and store into the buffer
     analogBufferIndex++;
     if(analogBufferIndex == SCOUNT) analogBufferIndex = 0;
   }   
   
   static unsigned long printTimepoint = millis();
   if(millis()-printTimepoint > 800U){
      printTimepoint = millis();
      for(copyIndex=0;copyIndex<SCOUNT;copyIndex++) analogBufferTemp[copyIndex]= analogBuffer[copyIndex];
      averageVoltage = getMedianNum(analogBufferTemp,SCOUNT) * (float)VREF / 1024.0; // read the analog value more stable by the median filtering algorithm, and convert to voltage value
      float compensationCoefficient=1.0+0.02*(temperature-25.0);    //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
      float compensationVolatge=averageVoltage/compensationCoefficient;  //temperature compensation
      tdsValue=(133.42*compensationVolatge*compensationVolatge*compensationVolatge - 255.86*compensationVolatge*compensationVolatge + 857.39*compensationVolatge)*0.5; //convert voltage value to tds value
      
      Serial.print("TDS Value:");
      Serial.print(tdsValue,0);
      Serial.println("ppm");

      int val= tdsValue; //tds
      sendval= String(val);

      /*使用POST來送出資料*/
      postData = "tds=" + sendval ;
      //Serial.println(postData);
   }

// We can post values to PHP files as  example.com/dbwrite.php?name1=val1&name2=val2&name3=val3
// Hence created variable postDAta and stored our variables in it in desired format
// For more detials, refer:- https://www.tutorialspoint.com/php/php_get_post.htm

   /*Update Host URL here:*/  
   http.begin(URL);   //要連線的位置
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header

   int httpCode = http.POST(postData);   // Send POST request to php file and store server response code in variable named httpCode
   Serial.println("Values are, TDS = " + sendval  );

   Serial.print("Send GET request to URL: ");
   Serial.println(URL);

   if (httpCode == 200){ 
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
     return;
   }  
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

/*led指示燈(板子上的LED:LOW&HIGH)*/
void led_now(){
  delay(3000); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH); 
}


/*數值転換*/
int getMedianNum(int bArray[], int iFilterLen){
      int bTab[iFilterLen];
      for (byte i = 0; i<iFilterLen; i++)  bTab[i] = bArray[i];
      
      int i, j, bTemp;
      for (j = 0; j < iFilterLen - 1; j++){
         for (i = 0; i < iFilterLen - j - 1; i++){
           if (bTab[i] > bTab[i + 1]){
                 bTemp = bTab[i];
                 bTab[i] = bTab[i + 1];
                 bTab[i + 1] = bTemp;
           }
         }
      }
      
      if ((iFilterLen & 1) > 0) bTemp = bTab[(iFilterLen - 1) / 2];
      else bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
      
      return bTemp;
}
