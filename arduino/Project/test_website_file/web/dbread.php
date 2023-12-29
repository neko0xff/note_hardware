<?php session_start(); ?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php

include("mysql_connect.inc.php");

/*時間設定*/
date_default_timezone_set('Asia/Taipei');  //時區 
$d = date("Y-m-d"); //日期(格式:年-月-日)
$t = date("H:i:s"); //時間(格式:時-分-秒)
 
/*
 * sensor控制
*/

//接收確認碼
if(!empty($_POST['confirm'])){
  echo "接收到確認碼".$_POST['confirm'];
  $confirm=(int)$_POST['confirm'];


if($confirm==2){
    
	// 使用POST來送出資料temp
    if(!empty($_POST['default_temp'])){
        /*把資料修改到資料庫的表格上*/
		$default_temp=$_POST['default_temp'];
	 	$post_sql = "update `default_sensor` set `default_temp`= ".$default_temp."";
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {    
		}else{
		    echo "Error: ". $sql ."<br>" . $conn->error;
		}
    }
	
    //soil
    if(!empty($_POST['default_soil'])){
     	$default_soil = $_POST['default_soil'];		  
	    $post_sql = "update `default_sensor` set `default_soil`= ".$default_soil." ";
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {    
		}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
    }
	
    //tds
    if(!empty($_POST['default_tds'])){
		$default_tds = $_POST['default_tds'];
        /*把資料上傳到資料庫的表格上*/
		$post_sql = "update `default_sensor` set `default_tds`= ".$default_tds."";	
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {  
		}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
    }
	
    //uv
    if(!empty($_POST['default_uv'])){
	
		$default_uv = $_POST['default_uv'];
        /*把資料上傳到資料庫的表格上*/
		$post_sql = "update `default_sensor` set `default_uv`= ".$default_uv."";				
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {   
		}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
    }

    //light
    if(!empty($_POST['default_light'])){
	
		$default_light = $_POST['default_light'];		
        /*把資料上傳到資料庫的表格上*/
	    $post_sql = "update `default_sensor` set `default_light`= ".$default_light."";			
		/*檢查是否有成功上傳*/
		if ($conn->query($post_sql) == TRUE) {    
		}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
    }

    /*輸出目前預設值*/
    echo "<br>New Data :";
    echo "<br>defalt_temp= ".$default_temp;
    echo "<br>defalt_light= ".$default_light;
    echo "<br>defalt_uv= ".$default_uv;
    echo "<br>defalt_tds= ".$default_tds;
    echo "<br>defalt_soil= ".$default_soil; 
    echo "<br>date= ".$d;
    echo ",time= ".$t;

}else if($confirm==3){
		
	/*把資料上傳到資料庫的表格上*/		
	if(!empty($_POST['fan_switch'])){
		  $fan_switch= $_POST['fan_switch'];
	}else{
		  $fan_switch= 0;
	}
			
	if(!empty($_POST['led_switch'])){
		  $led_switch= $_POST['led_switch'];
		  echo "確定有收到2";
	}else{ 
		  $led_switch= 0;
	}
			
	if(!empty($_POST['motor_switch'])){
		  $motor_switch= $_POST['motor_switch'];
	}else{ 
		  $motor_switch= 0;
	}
			
	$post_sql = "update `device_switch` set `fan_switch`=  ".$fan_switch.",`led_switch`=".$led_switch.",`motor_switch`=".$motor_switch."";
	echo "<br>風扇:".$fan_switch."<br>燈條:".$led_switch."<br>馬達:".$motor_switch;
	if ($conn->query($post_sql) == TRUE) {
	}else{
		    echo "Error: " . $sql . "<br>" . $conn->error;
	}
	
}
}
else{
	echo "未讀取到分類值";
}
	
echo "</center>";



/*関閉資料庫連線(MySQLi)*/
$conn->close();

?>
