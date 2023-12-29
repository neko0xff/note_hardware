<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php

/*資料庫設定*/ 
$host="192.168.21.39";
$dbname="esp8266_data";
$username="master";
$password="AA10bb17";

/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}else{
	echo "資料庫連線成功!";
	echo "<br>";
}


?>