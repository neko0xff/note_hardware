<?php
/* 
*  功能 : GPS接收&伝送
*  Author: Zangmen Hsu
*/

/*資料庫設定*/
$host = "localhost";		  // 伺服器位置(default:localhost)
$dbname = "esp8266_data";     // 資料庫名稱
$username = "master";		  // 帳戶
$password = "AA10bb17";	      // 密碼

/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
/*timezone refer: https://www.php.net/manual/en/timezones.asia.php*/
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)

/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);

// If values send by NodeMCU are not empty then insert into MySQL database table
// 使用POST來送出資料
$long_d = $_POST['long_d'];
$longval = $_POST['longval'];
$lat_d = $_POST['lat_d'];
$latval = $_POST['latval'];

/*把資料上傳到資料庫的表格上*/
$post_sql = "INSERT INTO sensor_gps(long_d,longval,lat_d,latval, date, time) VALUES ('".$long_d."','".$longval."','".$lat_d."','".$latval."','".$d."', '".$t."')"; 		
/*檢查是否有成功上傳*/
if ($conn->query($post_sql) == TRUE) {
    //echo "Values inserted in MySQL database table.";
}else{
    echo "Error: " . $sql . "<br>" . $conn->error;
} 

$conn->close();
?>