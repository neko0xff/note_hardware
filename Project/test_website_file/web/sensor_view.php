<html>
  <title>sensor_view</title>
</html>
<?php

/*資料庫設定*/
$host = "localhost";		    // 伺服器位置(default:localhost)
$dbname = "esp8266_data";       // 資料庫名稱               
$username = "master";		    // 帳戶              
$password = "AA10bb17";	        // 密碼             

/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);
/*檢查是否有連線成功*/
if ($conn->connect_error) {
       die("Connection failed: " . $conn->connect_error);
}else{
	  echo "Connected to mysql database. <br>";
      $get_sql_dht = "SELECT * FROM `sensor_dht` ORDER BY `date` AND `time` DESC LIMIT 1";
      $get_sql_tds = "SELECT * FROM `sensor_tds` ORDER BY `date` AND `time` DESC LIMIT 1";
      $get_sql_soil = "SELECT * FROM `sensor_soil` ORDER BY `date` AND `time` DESC LIMIT 1";
      $get_sql_light = "SELECT * FROM `sensor_light` ORDER BY `date` AND `time` DESC LIMIT 1";
      $get_sql_uv = "SELECT * FROM `sensor_uv` ORDER BY `date` AND `time` DESC LIMIT 1";
      $get_sql_sensor = "SELECT * FROM `default_sensor` ORDER BY `id` DESC LIMIT 1";
      $get_sql_switch = "SELECT * FROM `device_switch` ORDER BY `id` DESC LIMIT 1";

      $result_dht = $conn->query($get_sql_dht);
      $result_tds = $conn->query($get_sql_tds);
      $result_soil = $conn->query($get_sql_soil);
      $result_light = $conn->query($get_sql_light);
      $result_uv = $conn->query($get_sql_uv);
	  $result_sensor = $conn->query($get_sql_sensor);
	  $result_switch = $conn->query($get_sql_switch);

      $row_dht = $result_dht->fetch_assoc();
      $row_light = $result_light->fetch_assoc();
      $row_soil = $result_soil->fetch_assoc();
      $row_tds = $result_tds->fetch_assoc();
      $row_uv = $result_uv->fetch_assoc();
	  $row_sensor = $result_sensor->fetch_assoc(); 
	  $row_switch = $result_switch->fetch_assoc();

      /*output website*/
	  echo "<h2>dht</h2><br>";
	  echo "temp= ".$row_dht["temp"];
	  echo " ,hum= ".$row_dht["hum"];
	  echo " ,time= ".$row_dht["time"];
	  echo " ,date= ".$row_dht["date"];
	  
	  echo "<br><h2>light</h2><br>";
	  echo "light= ".$row_light["light"];
	  echo " ,time= ".$row_light["time"];
	  echo " ,date= ".$row_light["date"];
	  
	  echo "<br><h2>soil</h2><br>";
	  echo "soil= ".$row_soil["soil"];
	  echo " ,time= ".$row_soil["time"];
	  echo " ,date= ".$row_soil["date"];
	  
	  echo "<br><h2>tds</h2><br>";
	  echo "tds= ".$row_tds["tds"];
	  echo " ,time= ".$row_tds["time"];
	  echo " ,date= ".$row_tds["date"];
	  
	  echo "<br><h2>uv</h2><br>";
	  echo "uv= ".$row_uv["uv"];
	  echo " ,time= ".$row_uv["time"];
	  echo " ,date= ".$row_uv["date"];
	  
	  echo "<br><h2>default_sensor</h2><br>";
	  echo "default_temp=".$row_sensor["default_temp"];
	  echo " ,default_hum=".$row_sensor["default_hum"];
	  echo " ,default_soil=".$row_sensor["default_soil"];
	  echo " ,default_uv=".$row_sensor["default_uv"];
	  echo " ,default_tds=".$row_sensor["default_tds"];

      echo "<br><h2>switch</h2><br>";
	  echo "fan_switch=".$row_switch["fan_switch"];
	  echo " ,led_switch=".$row_switch["led_switch"];
	  echo " ,motor_switch=".$row_switch["motor_switch"];
}
      	  
/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>