# nodejs_uart
## 使用語言和開發版
* Server: Node.js(JavaScrpit)+npm(serialport+express+ejs)
* Arduino UNO(C)
## 原理 
使用UART進行通訊
```
 Arduino <==(UART)==> node.js <===> Website(express+ejs)
```
## 材料 
* LED *4
* 220 歐電阻 * 4
## 啟動 
* 第一回使用(安裝相関套件)
```
$ npm install
```
* 正式啟動
```
$ node index.js [開發版的序列埠]
```