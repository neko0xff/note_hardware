<?php
/*資料庫設定*/
$host = "localhost";		  // 伺服器位置(default:localhost)
$dbname = "esp8266_data";     // 資料庫名稱
$username = "master";		  // 帳戶
$password = "AA10bb17";	      // 密碼

/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);

/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
/*timezone refer: https://www.php.net/manual/en/timezones.asia.php*/
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)

// 使用POST來送出資料
$device_id = $_POST['device_id'];

/* 把資料上傳到資料庫的表格上 */
$post_sql = "INSERT INTO device_view(device_id,date, time) VALUES ('".$device_id."', '".$d."', '".$t."')"; 
$del_sql = "DELETE FROM device_view WHERE device_id='0';";

/* 檢查是否有成功上傳 */
if ($conn->query($post_sql) == TRUE) {
    //echo "Values inserted in MySQL database table.";
}else{
    echo "Error: " . $sql . "<br>" . $conn->error;
}

/* 刪在資料庫的device_id=0的資料 */
if ($conn->query($del_sql) === TRUE) {
  //echo "Record deleted successfully";
}else{
  echo "Error deleting record: " . $conn->error;
}

/*回伝狀態
  1:LORA , 2:WIFI , 3:BT
*/
if($device_id == 0){
	echo "NO_MSG";
}else if($device_id == 11) {
	echo "LORA_WaterTemp_ON";
}else if($device_id == 12){ 
    echo "LORA_TDS_ON";
}else if($device_id == 13){
	echo "LORA_UV_ON";
}else if($device_id == 14){
	echo "LORA_SOIL_ON";
}else if($device_id == 15){
	echo "LORA_GPS_ON";
}else if($device_id == 21){
	echo "WIFI_TEMP_ON";
}else if($device_id == 22){
	echo "WIFI_ULTRASOUND_ON";
}else if($device_id == 23){
    echo "WIFI_PIR_ON";
}else if($device_id == 24){
	echo "WIFI_LIGHT_ON";
}else if($device_id == 25){
	echo "WIFI_RFID_ON";
}else if($device_id == 31){
	echo "BT_TOF_ON";
}else if($device_id == 32){
	echo "BT_DOKI_ON";
}else if($device_id == 33){
	echo "BT_SOUND_ON";
}else if($device_id == 34){
	echo "BT_CO2_ON";
}else if($device_id == 35){
	echo "BT_HEAD_ON";
}else echo "ERROR ";

$conn->close();

?>