<?php session_start(); ?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<!-- timer -->
<script language="JavaScript">
  function ShowTime(){
　  document.getElementById('showbox').innerHTML = new Date();
　  setTimeout('ShowTime()',1000);
  }
</script>
<?php
/*將session清空*/
unset($_SESSION['username']);
echo '<h1>登出中......</h1>';
echo '<meta http-equiv=REFRESH CONTENT=2;url=index.html>';
?>
<body onload="ShowTime()">
  <p> 現在時間: <div id="showbox"></div> </p>
</body>