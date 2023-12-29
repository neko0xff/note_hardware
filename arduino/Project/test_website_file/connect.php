<?php session_start(); ?>
<!--上方語法為啟用session，此語法要放在網頁最前方-->
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php 
require("mysql_connect.inc.php");
require("index.html");


/*查詢資料庫資料*/
$user = $_POST['user'];
$password = $_POST['password'];
$sql = "SELECT * FROM `login_table` WHERE `user` = '$user' AND `password` = '$password'";
$result = mysqli_query($conn,$sql);
$row = mysqli_fetch_assoc($result);

/*判斷帳號與密碼是否為空白或存在資料庫*/
if($user != null && $password != null && $row['user'] == $user && $row['password'] == $password ) {
        //將帳號寫入session，方便驗證使用者身份
        $_SESSION['username'] = $user;
        echo '<h2> 狀態: 登入成功! </h2>';
        echo '<meta http-equiv=REFRESH CONTENT=1;url=main.php>';
}else{
        echo '<h2> 狀態: 登入失敗! </h2>';
        echo '<meta http-equiv=REFRESH CONTENT=1;url=index.html>';
}

?>