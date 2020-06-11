---
tittle: D1 Mini(ESP8266) in Linux (2)
tags: ESP8266
---
# D1 Mini(ESP8266) in Linux (2) - BUG

## 17-3 讀取並顯示 HTML 網頁和圖像
* 把/www(網頁資料夾) 透過ampy上傳到esp8266上去
```
[zangmenhsu@E1304 17-3]$ sudo ampy --port (你的板子連結埠) put www
```
* 主程式請透過Thonny控制esp8266去運行
![](https://i.imgur.com/DXz1g3n.png)

## 15-5 連接 MicroSD/SD 記憶卡
* 請上傳sdcard.py到esp8266,如果沒有則會有錯誤
![](https://i.imgur.com/o3GDScT.png)
* 実際過程出現的bug
1. OSError: no SD Card (你沒有插SD卡)
![](https://i.imgur.com/uIHXcHU.png)
2. OSError: [Errno 1] EPERM ==> 把os.mount(vfs,'/sd')移掉
![](https://i.imgur.com/orOL6dq.png)

## 15-4 LED 矩陣動畫與多維序列資料程式設計
* 程式運行時有時接線會亮有時不會亮