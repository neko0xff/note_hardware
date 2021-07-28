# HC-SR04
## 功能
* 類型: 超音波測距 / 避障模組
## 函式庫
* Ultrasonic
## 規格
* 重量：9g
* 工作電壓：0(低電位)~5(高電位)V
* 感應角度：不大於15度
* 探測距離：2~450cm
## 運行方式
* 使用用IO觸發測距，給至少10us的高電平信號
* 模組自動發送8個40khz的方波，自動檢測是否有信號返回
* 有信號返回時通過IO輸出一高電平，高電平持續的時間就是超聲波從發射到返回的時間
* 測試距離=(高電平時間*聲速(340M/S))/2
* trig引腳是內部上拉10K的電阻，用單片機的IO口拉低TRIP引腳，然後給一個10us以上的脈沖信號
## 接腳(由左開始)
*  VCC (+5V)
* trig （控制端）   –> 任意Digital Pin
* echo（接收端）   –> 任意Digital Pin
* GND
## source
* https://www.taiwaniot.com.tw/product/hc-sr04/
* http://hammer1007.blogspot.com/2017/12/esp82662-4hc-sro4.html
