#!/bin/bash
#https://www.digitalocean.com/community/tutorials/how-to-install-wordpress-with-docker-compose

sleep 3

#if [ ! -f /usr/local/bin/wp ]
#then
#install wp-cli to configure wp
    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
    mkdir -p /run/php
    chmod +x /run/php -R
    mkdir -p /var/www/wp
    chmod +x /var/www/wp -R
    chown -R nginx:nginx /var/www/wp
#fi

if [ ! -f /usr/src/wordpress/wp-config.php ]
then
    cd /var/www/wp
    echo "download wp :"
    wp core download
    echo "configure  wp :"
    wp config create --dbname="$DB_NAME" --dbuser="$DB_USER" --dbpass="$DB_PASSWORD" --dbhost="mariadb"
    echo "install wp :"
    wp core install --url="$DOMAIN_NAME" --title="TITLE" --admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASSWD" --admin_email=huh@gmail.com
    
fi

/usr/sbin/php-fpm82 -F

