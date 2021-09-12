# S12SD
## 功能
* 類型:太陽紫外線強度感測器
## 特性
* 適合於檢測在太陽光的UV輻射。它可以用於任何需要監視UV光量的應用，並且可以很容易地連接到任何微控制器
## 規格
* 尺寸小：11mm×27mm
* 功耗低：供電電壓2.5V～5V，工作電流是微安級
* 線性好
* 靈敏度高
* 高穩定性
* 檢測範圍寬：240nm-370nm
* 大角度：130度
* 肖特基種類的光敏二極管，適用於光電模式
## 運行方式
* 連接到ADC輸入並讀取該值
## 電壓転換公式
* VCC=5V
```
sensorVoltage = sensorValue / 1024 * 3.3
```
* VCC=3.3V
```
sensorVoltage = sensorValue / 1024 * 5
```
## source
* https://www.taiwaniot.com.tw/product/guva-s12sd-%E5%A4%AA%E9%99%BD%E7%B4%AB%E5%A4%96%E7%B7%9A%E5%BC%B7%E5%BA%A6%E6%84%9F%E6%B8%AC%E5%99%A8-%E5%81%B5%E6%B8%AC%E7%B4%AB%E5%A4%96%E7%B7%9A%E5%BC%B7%E5%BA%A6/
