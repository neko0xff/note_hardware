---
tittle: D1 Mini(ESP8266) in Linux (1) -install
tags: ESP8266
---
# D1 Mini(ESP8266) in Linux (1) -install
## 1.安裝Thonny
```
[zangmenhsu@E1304 ~]$ sudo pacman -S tk python-pip
[zangmenhsu@E1304 ~]$ sudo pip3 install thonny
```
* 加入用Thonny連結自己板子連結埠的權限
```
[zangmenhsu@E1304 ~]$ sudo nano /etc/udev/rules.d/70-ttyusb.rules
KERNEL=="ttyUSB[0-9]*",MODE="0666"
```
引用來源:https://github.com/thonny/thonny/issues/511
## 2.查找自己的D1 Mini
```
[zangmenhsu@E1304 ~]$ ls -l /dev/tty*
crw-rw-rw- 1 root tty    5,  0  5月  8 13:29 /dev/tty
....
crw-rw---- 1 root uucp 188,  0  5月  8 13:43 /dev/ttyUSB0 //自己的板子的連結埠
```
## 3.用USB連結自己板子
* 指令: screen 自己的板子的連結埠 通訊頻率
```
[zangmenhsu@E1304 ~]$ sudo pacman -S screen
[zangmenhsu@E1304 ~]$ screen /dev/ttyUSB0 115200
```
* CTRL-D reboot
* CTRL-B exit
## 4.燒錄軔体
```
[zangmenhsu@E1304 ~]$ sudo pip3 install esptool
[zangmenhsu@E1304 ~]$ sudo esptool.py --port 連結埠 --baud 115200 write_flash --flash_size=detect -fm dio 0 軔体檔.bin
```
## 5.上伝程式到ESP8266
* 安裝
```
[zangmenhsu@E1304 ~]$ sudo pip3 install adafruit-ampy
```
* 運行
```
[zangmenhsu@E1304 ~]$ cd /home/zangmenhsu/桌面/17-3
[zangmenhsu@E1304 17-3]$ sudo ampy --port (你的板子連結埠) (指令) (檔案)
run  : 立即運行
put  : 上伝到板子上
ls   : 列出板子上的檔案
get  : 檢視檔案上的內容或下戴到電腦(請在最後加上檔案路徑和檔名)
rm   : 刪掉板子上的檔案
```
##  使用的資料
1. Getting started with the D1 mini (ESP8266) https://gist.github.com/carljdp/e6a3f5a11edea63c2c14312b534f4e53