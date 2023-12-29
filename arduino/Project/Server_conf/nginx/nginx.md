# nginx
## 服務
網頁伺服器
## 存放的config 位置
/etc/nginx/nginx.conf
## 設置部分
### PHP支緩
```
# PHP in user directories, e.g. http://example.com/~user/test.php
    location ~ ^/~(.+?)(/.+\.php)$ {
        alias          /home/$1/public_html$2;
        fastcgi_pass   unix:/run/php-fpm/php-fpm.sock;
        fastcgi_index  index.php;
        include        fastcgi.conf;
    }
```
### 建立自己的Userdir
* `update_load`
```
location ~^/upload_data {
        alias /var/www/html/update_load;
        autoindex on;
        index index.htm index.html index.php;
    }
```
* `website`
```
location ~^/website {
        alias /var/www/html/website;
        index index.htm index.html index.php; 
    }
```