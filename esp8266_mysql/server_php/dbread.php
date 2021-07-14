<?php

/*資料庫設定*/
$host = "localhost";		    // 伺服器位置(default:localhost)
$dbname = "esp8266_data";       // 資料庫名稱               
$username = "master";		    // 帳戶              
$password = "AA10bb17";	        // 密碼             


/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);


/*檢查是否有連線成功*/
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}else{
	echo "Connected to mysql database. <br>"; 
}


/*把資料庫的表格叫出來*/
$sql = "SELECT id, temp, hum, date, time FROM sensor_data";  // Update your tablename here
$result = $conn->query($sql);
echo "<center>";

/*輸出表格的資料到網頁上*/
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        echo "<strong> Id:</strong> " . $row["id"]. " &nbsp <strong>temp:</strong> " . $row["temp"]. " &nbsp <strong>hum:</strong> " . $row["hum"]. " &nbsp   <strong>Date:</strong> " . $row["date"]." &nbsp <strong>Time:</strong>" .$row["time"]. "<p>";
    }	
}else{
    echo "0 results";
}

echo "</center>";

/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>
