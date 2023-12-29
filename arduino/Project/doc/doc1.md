# 比賽用資料庫格式
## 資料庫
* db_name = esp8266
## 欲要建立的資料表
* sensor_dht ==> 溫溼度
  * 欄位:
    * id (int)
    * temp (int)
    * hum (int)
    * data,time 
* sensor_light ==> 光度計
  * 欄位:
    * id (int)
    * light (int)
    * data,time 
* sensor_uv ==> 紫外線
  * 欄位: 
    * id (int)
    * uv (int)
    * date,time 
* sensor_tds ==> 水質
  * 欄位:
    * id (int)
    * tds (int)
    * date,time 
* sensor_soil ==> 土壤溼度
  * 欄位:
    * id (int)
    * soil (int)
    * date,time 
* device_switch ==>裝置開関
  * 欄位:
    * id (int)
    * fan_switch (int)
    * led_switch (int)
    * motor_switch (int)
* default_sensor ==> 存放預設值
  * 欄位:
    * id (int)
    * default_temp (int)
    * default_hum (int)
    * default_light (int)
    * default_uv (int)
    * default_tds (int)
    * default_soil  (int)
* login_table ==> 使用者帳戶
  * 欄位:
    * id (int)
    * user (char)
    * password (char)
  * 使用者: user1,user2,user3
  * 密碼: AA10bb17