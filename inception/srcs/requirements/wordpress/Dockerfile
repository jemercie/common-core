FROM	alpine:3.19

RUN	apk update ; apk upgrade ; apk add wget mariadb-client

#install and configure php
RUN apk add php php-fpm php-phar php-mysqli php-zip php-mbstring 
RUN chmod +x usr/sbin/php-fpm82

RUN addgroup -S nginx
RUN adduser -S -G nginx nginx

COPY  www.conf /etc/php82/php-fpm.d
COPY ./wordpress-conf.sh /etc
RUN	chmod +x /etc/wordpress-conf.sh

ENTRYPOINT [ "sh", "/etc/wordpress-conf.sh" ]
