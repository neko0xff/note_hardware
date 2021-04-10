#include <DHT.h>

DHT dht11_p1(D1,DHT11); //使用dht11(mode:dht11&dht22)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht11_p1.begin();
  Serial.println("DHT11 Testing");
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht11_p1.readTemperature(); //溫度
  float hum = dht11_p1.readHumidity(); //溼度

  //輸出數值
  Serial.print("hum= ");
  Serial.print((float)hum);
  Serial.println("%");
  Serial.print("temp= ");
  Serial.print((float)temp);
  Serial.println("C");
  delay(2000);
}
