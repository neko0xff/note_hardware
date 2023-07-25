# php
## 存放的config 位置
* php-fpm: /etc/php-fpm.d/www.conf
* php.ini: /etc/php.ini
## 設置部分
* php-fpm
```
# 更改設定
user = nginx
group = nginx
listen.owner = nginx
listen.group = nginx
listen.mode = 0660
;listen.acl_users = apache,nginx
```
* php.ini
```
# 注解拿掉且把1設成0
cgi.fix_pathinfo=0 
```