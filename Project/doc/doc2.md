# 連線
## 連線位置
* URL(for Arduino): http://[ip_address or web_address]/sensor_php/dbwrite_xx.php
* sensor_php/dbwrite_dht.php ==> 溫溼度
* sensor_php/dbwrite_light.php ==> 光度計 
* sensor_php/dbwrite_uv.php ==> 紫外線
* sensor_php/dbwrite_tds.php ==> 水質
* sensor_php/dbwrite_soil.php ==> 土壤溼度
### 向Arduino(espxx) 回伝 ==> php部分
* 溫溼度(dht) => temp,default_temp,hum,default_hum,fan_switch,time
* 光度計(light) => light,default_light,time
* 紫外線(uv) => uv,default_uv,time
* 水質(tds) => tds,default_tds,time
* 土壤溼度(soil) => soil,default_soil,time
### 向php(http_server) 回伝 ==> Arduino部分
* 溫溼度(dht) => temp,hum
* 光度計(light) => light
* 紫外線(uv) => uv
* 水質(tds) => tds
* 土壤溼度(soil) => soil