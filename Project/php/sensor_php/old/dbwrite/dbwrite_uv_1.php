<?php
/* 
*  功能 : 紫外線接收&伝送
*  Author: Zangmen Hsu
*/

/*資料庫設定*/
$host = "localhost";		  // 伺服器位置(default:localhost)
$dbname = "esp8266_data";     // 資料庫名稱
$username = "master";		  // 帳戶
$password = "AA10bb17";	      // 密碼


/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);

/*檢查是否有連線成功(同時傳給Arduino)*/
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }else{
      //向資料庫獲得新的資料(由'date'&'time'來判定)
      $get_sql = "SELECT * FROM `sensor_uv` ORDER BY `date` AND `time` DESC LIMIT 1 ";
      $result = $conn->query($get_sql);
      $row = $result->fetch_assoc();
	  //回伝:uv,default_uv,time
      echo "uv: ".$row["uv"];
      echo ",default_uv= ".$row["default_uv"]; 
      echo ",time= ".$row["time"];
      echo ",date= ".$row["date"];	  
   }

   
/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
/*timezone refer: https://www.php.net/manual/en/timezones.asia.php*/
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)
    
// If values send by NodeMCU are not empty then insert into MySQL database table
// 使用POST來送出資料
if(!empty($_POST['uv'])){
		$uv = $_POST['uv'];
        
        /*把資料上傳到資料庫的表格上*/
	    $post_sql = "INSERT INTO sensor_uv (uv, date, time) VALUES ('".$uv."', '".$d."', '".$t."')"; 
		
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {
		    //echo "Values inserted in MySQL database table.";
		}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
		} 
}


/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>
