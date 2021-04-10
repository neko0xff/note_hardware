<title>File_Upload</title>
<meta http-equiv="content-type" charset="UTF-8"/>

<h1>檔案上傳</h1>
        
<?php

/*時區設置*/
date_default_timezone_set("Asia/Taipei");
echo date("H:m:s");
echo "<br />";

/*上傳檔案*/
if($_FILES['file']['error']>0){
      echo "檔案上傳失敗";
}else{
      move_uploaded_file($_FILES['file']['tmp_name'], 'file/'.$_FILES['file']['name']);
      echo "路徑位置：".'<a href="file/'.$_FILES['file']['name'].'">file/'.$_FILES['file']['name'].'</a>';
      echo "<br />";
      echo "類型：".$_FILES['file']['type']."<br />大小：".$_FILES['file']['size']."<br />";
}

?>
