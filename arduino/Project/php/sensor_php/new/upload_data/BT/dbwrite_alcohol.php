<?php
/* 
*  功能 : 酒精接收&伝送
*  Author: Zangmen Hsu
*/

/*資料庫設定*/
$host = "localhost";		  // 伺服器位置(default:localhost)
$dbname = "esp8266_data";     // 資料庫名稱
$username = "master";		  // 帳戶
$password = "AA10bb17";	      // 密碼

/*上伝欄位*/
$Alcohol = $_POST['alcohol'];

/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);

/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)
   
/*把資料上傳到資料庫的表格上*/
$post_sql = "INSERT INTO sensor_alcohol (alcohol, date, time) VALUES ('".$Alcohol."', '".$d."', '".$t."')"; 	
	
/*檢查是否有成功上傳*/
if ($conn->query($post_sql) == TRUE) {
    echo "receive";
}else{
    echo "Error: " . $sql . "<br>" . $conn->error;
}

/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>
