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


/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
//*timezone refer: https://www.php.net/manual/en/timezones.asia.php
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)
    
// If values send by NodeMCU are not empty then insert into MySQL database table
// 使用POST來送出資料
if(!empty($_POST['default_tds'])){
	
		$default_tds = $_POST['default_tds'];
		
        /*把資料上傳到資料庫的表格上*/
	    $post_sql = "INSERT INTO sensor_tds (default_tds,date, time) VALUES ('".$default_tds."','".$d."','".$t."')"; 
		
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {
		    echo "Values inserted in MySQL database table.";
		}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
}


/*把資料庫的表格叫出來*/
$sql = "SELECT id, tds, date, time FROM sensor_tds";  // Update your tablename here
$result = $conn->query($sql);
echo "<center>";

/*輸出表格的資料到網頁上*/
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        echo "<strong> Id:</strong> " . $row["id"]. " &nbsp <strong>tds:</strong> " . $row["tds"]. " &nbsp   <strong>Date:</strong> " . $row["date"]." &nbsp <strong>Time:</strong>" .$row["time"]. "<p>";
    }	
}else{
    echo "0 results";
}

echo "</center>";

/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>
