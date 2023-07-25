<!doctype html>
<html>
<?php session_start(); ?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php
include("mysql_connect.inc.php");
echo "目前使用者:".$_SESSION['username'];
echo '<br><a href="logout.php">登出</a><br>';
?>

<style type="text/css">
.main_font {
	font-family: "標楷體";
}
</style>
<head>
<meta charset="utf-8">
<title>監控溫室專案檔bata3.2</title>
<!--網頁佈置-->
<style type="text/css">
body{
	background-image: url(img/main.png);
}
.maintext a {
	color: #000;
	text-decoration: none;
	display: block;
}
.maintext a:hover {
	color: #F00;
	background-color: #FF0;
	text-decoration: none;
}
.maintext {
	background-color: #eee;
	text-align: center;
	text-decoration: none;
	overflow: hidden;
	font-size: 24px;
	font-style: normal;
	font-family: "標楷體";
}
.main td {
	font-size: 72px;
	font-family: "標楷體";
	color: #000;
	font-style: italic;
	line-height: normal;
}
.maintext1 {	
    background-color: #eee;
	text-align: center;
	text-decoration: none;
	overflow: hidden;
	font-size: 24px;
	font-style: normal;
	font-family: "標楷體";
}
.main_font strong {
	font-size: 36px;
	font-family: "標楷體";
}

table {
    display: table;
     -collapse: separate;
    box-sizing: border-box;
    text-indent: initial;
    border-spacing: 0px;
    border-color: 000;
}/* CSS Document */

iframe {
    border-width: 0px;
    border-style: inset;
    border-color: initial;
    border-image: initial;
}
</style>
</head>

<body bgcolor="#999999"><table width="1024" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr align="center" valign="middle">
    <td height="100" colspan="2" valign="middle"><h1 class="main_font"><strong>監視網頁</strong></h1></td>
  </tr>
  <tr>
    <td width="200" height="660" align="center" valign="middle"><iframe src="Menu.html" name="menu" width="200" height="663" scrolling="no"></iframe></td>
    <td width="824" height="683" align="center" valign="top"><table width="825" border="0" cellpadding="0">
      <tr>
        <td width="820" height="674"><table width="825" border="0" cellpadding="0">
          <tr>
            <td width="820" height="674"><iframe src="dbread.php" name="main" width="824" height="654" scrolling="auto"></iframe></td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
</table>

</body>
</html>