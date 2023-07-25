# 資料庫存入
## 查詢所有(SELECT)
```php=
$sql = "SELECT id, temp, hum, date, time FROM sensor_data";
```
### 查詢最新的一筆資料
```php=
$get_sql = "SELECT * FROM `sensor_light` ORDER BY `date` AND `time` DESC LIMIT 1 ";
```
## 存入單一筆資料(INSERT)
```php=
$post_sql = "INSERT INTO sensor_dht (temp, hum, date, time) VALUES ('".$temp."','".$hum."', '".$d."', '".$t."')";
```
## 強制更新資料欄位(UPDATE)
```php=
$update_sql = " UPDATE `default_sensor` SET `default_temp` ";
```