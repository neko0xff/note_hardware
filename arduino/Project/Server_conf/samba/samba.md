# SAMBA
## 服務
提供Windows檔案共享服務
## 存放的config 位置
/etc/samba/smb.conf
## 設置部分
### 啟用共享服務
```
[global]
	workgroup = WORKGROUP
	security = user
    syslog = 0
    syslog only = yes
	passdb backend = tdbsam
    netbios name = Fedora
    host msdfs = yes
	printing = cups
	printcap name = cups
	load printers = yes
	cups options = raw
```
### 建立共享資料夾
* www
```
[www]
        comment = www
        path = /var/www
        browseable = yes
        read only = no
        create mask = 777
        directory mask = 777
        public = yes
        msdfs root = yes
```
* local
```
[local]
       comment = local
       path = /var/local
       browseable = yes
       read only = no
       create mask = 777
       directory mask = 777
       public = yes
       msdfs root = yes
```
### 加入共享的使用者帳戶
```
# smbpasswd -a -s [user] [password]
```