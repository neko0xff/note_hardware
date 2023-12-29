<?php
/*
*  功能: app回伝
*  Author: zangmenhsu
*/

/*資料庫設定*/
$host = "localhost";		  // 伺服器位置(default:localhost)
$dbname = "esp8266_data";     // 資料庫名稱
$username = "master";		  // 帳戶
$password = "AA10bb17";	      // 密碼

/*建立資料庫連結(MySQLi)*/
$conn = new mysqli($host, $username, $password, $dbname);

/*sensor SQL */
//1.dht
$dht_sql  = "SELECT * FROM `sensor_dht` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$dht_result = $conn->query($dht_sql);
$dht_row = $dht_result->fetch_assoc();

//2.watertemp 
$wt_sql  = "SELECT * FROM `sensor_watertemp` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$wt_result = $conn->query($wt_sql);
$wt_row = $wt_result->fetch_assoc();

//3.rfid 
$rfid_sql  = "SELECT * FROM `sensor_rfid` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$rfid_result = $conn->query($rfid_sql);
$rfid_row = $rfid_result->fetch_assoc();

//4.soil
$soil_sql  = "SELECT * FROM `sensor_soil` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$soil_result = $conn->query($soil_sql);
$soil_row = $soil_result->fetch_assoc();

//5.gps 
$gps_sql  = "SELECT * FROM `sensor_gps` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$gps_result = $conn->query($gps_sql);
$gps_row = $result->fetch_assoc();

//6.超音波
$us_sql  = "SELECT * FROM `sensor_ultrasound` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$us_result = $conn->query($us_sql);
$us_row = $us_result->fetch_assoc();

//7.防水超音波
$ipx_us_sql  = "SELECT * FROM `sensor_ultrasound_IPX` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$ipx_us_result = $conn->query($ipx_us_sql);
$ipx_us_row = $ipx_us_result->fetch_assoc();

//8.tof
$tof_sql  = "SELECT * FROM `sensor_tof` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$tof_result = $conn->query($tof_sql);
$tof_row = $tof_result->fetch_assoc();

//9.light
$light_sql  = "SELECT * FROM `sensor_light` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$light_result = $conn->query($light_sql);
$light_row = $light_result->fetch_assoc();

//10.alcohol
$alcohol_sql  = "SELECT * FROM `sensor_light` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$alcohol_result = $conn->query($alcohol_sql);
$alcohol_row = $alcohol_result->fetch_assoc();

//11.sound
$sound_sql  = "SELECT * FROM `sensor_sound` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$sound_result = $conn->query($sound_sql);
$sound_row = $sound_result->fetch_assoc();

//12.dec
$dec_sql  = "SELECT * FROM `sensor_dec`` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$dec_result = $conn->query($dec_sql);
$dec_row = $dec_result->fetch_assoc();

//13.voltage
$voltage_sql  = "SELECT * FROM `sensor_voltage` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$voltage_result = $conn->query($voltage_sql);
$voltage_row = $voltage_result->fetch_assoc();

//14.current
$current_sql  = "SELECT * FROM `sensor_current` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$current_result = $conn->query($current_sql);
$current_row = $current_result->fetch_assoc();

//15.pir
$pir_sql  = "SELECT * FROM `sensor_pir` ORDER BY `date` AND `time` DESC LIMIT 1 ";
$pir_result = $conn->query($pir_sql);
$pir_row = $pir_result->fetch_assoc();

/*預設值*/
$get_sql2 = "SELECT * FROM `default_sensor`";
$result2 = $conn->query($get_sql2);
$row2 = $result2->fetch_assoc();

/*變數*/
$Client = $_POST["Client"]; 
$watertemp = 'watertemp!';
$tds = 'tds!';
$soil = 'soil!';
$gps = 'gps!';
$us = 'convert_cm!';
$us_ipx = 'IPX_convert_cm!';
$temp = 'temp!';
$hum = 'hum!';
$pir = 'pir!';
$uid = 'uid!';
$tof = 'tof!';
$light = 'light!';
$alcohol = 'alcohol!';
$sound = 'sound!';
$voltage = 'voltage!';
$current = 'current!';

/*主程式*/
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}else{
	
	/*回伝型式*/
    if($client == $temp){
        echo "temp=".$dht_row["temp"];
	}else if($client == $hum){
	    echo "hum=".$dht_row["hum"];
	}else if($client == $pir){
	    echo "pir=".$pir_row["pir"];
    }else if($client == $tof){
	    echo "tof=".$tof_row["tof"];
	}else if($client == $uid){
	    echo "uid=".$uid_row["uid"];
	}else if($client == $light){
	    echo "light=".$light_row["light"];
    }else if($client == $gps){
	    echo "long_d=".$gps_row["long_d"];
	    echo ",long_val=".$gps_row["long_val"];
	    echo ",lan_d=".$gps_row["lan_d"];
	    echo ",long_val=".$gps_row["long_val"];
	}else if($client == $us){
		echo "convert_cm=".$us_row["convert_cm"];
	}else if($client == $us_ipx){
		echo "convert_cm_IPX=".$tof_row["convert_cm"];
	}else if($client == $sound){
		echo "sound=".$sound_row["sound"];
	}else if($client == $voltage){
		echo "voltage=".$voltage_row["voltage"];
	}else if($client == $current){
		echo "current=".$current_row["current"];
	}else if($client == $alcohol){
		echo "alcohol=".$alcohol_row["alcohol"];
	}else if($client == $watertemp){
		echo "watertemp=".$watertemp_row["watertemp"];
	}else if($client == $tds){
		echo "tds=".$tds_row["tds"];
	}else if($client == $soil){
		echo "soil=".$soil_row["soil"];
	}else{
	  echo "ERROR";
    }
	
}

$conn->close();

?>