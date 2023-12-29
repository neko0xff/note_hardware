<?php session_start(); ?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php

include("mysql_connect.inc.php");

/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)
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
	  echo "Connected to mysql database. <br>"; }
$sql = "SELECT id, temp, hum,light,soil,tds,uv, date, time FROM html_sensor";

echo " <table width='800' height='30' border='1'>";
		 echo	"<tr><td height='30'>Id</td>
		 		<td height='30'>溫度</td>
				<td height='30'>濕度</td>
				<td height='30'>光照</td>
				<td height='30'>土壤品質</td>
				<td height='30'>水質</td>
				<td height='30'>紫外線強度</td>
				<td height='30'>日期</td>
				<td height='30'>時間</td></tr>";
				
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
echo 
"<tr><td height='30'>" . $row["id"]."</td>". 
" <td height='30'>". $row["temp"]."</td>".
 "<td height='30'>" . $row["hum"]."</td>".
  " <td height='30'>". $row["light"]."</td>".
   " <td height='30'> " . $row["soil"]."</td>". 
   "<td height='30'>" . $row["tds"]."</td>".
   "<td height='30'>" . $row["uv"]."</td>". 
   "<td height='30'>" . $row["date"]."</td>"
   ."<td height='30'>" .$row["time"]. "</td></tr>";
    }	
}else{
    echo "0 results";
}
$sql = "SELECT id, default_temp, default_hum,default_light,default_soil,default_tds,default_uv FROM default_sensor";
$result = $conn->query($sql);

echo " <table width='800' height='30' border='1'>";
		 echo	"<tr><td height='30'>Id</td>
		 		<td height='30'>預設溫度</td>
				<td height='30'>預設濕度</td>
				<td height='30'>預設光照</td>
				<td height='30'>預設土壤品質</td>
				<td height='30'>預設水質</td>
				<td height='30'>預設紫外線強度</td></tr>";
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
		
echo 
"<tr><td height='30'>" . $row["id"]."</td>". 
  " <td height='30'>". $row["default_temp"]."</td>".
  "<td height='30'>" . $row["default_hum"]."</td>".
  " <td height='30'>". $row["default_light"]."</td>".
  " <td height='30'> " . $row["default_soil"]."</td>". 	  "<td height='30'>" . $row["default_tds"]."</td>".
  "<td height='30'>" . $row["default_uv"]."</td></tr>";
    }	
}else{
    echo "0 results";
}




/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>
