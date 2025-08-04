#!/bin/bash

#https://wiki.alpinelinux.org/wiki/MariaDB

#https://dev.mysql.com/doc/refman/8.0/en/data-directory-initialization.html

if [ ! -d "/run/mysqld" ]
then
    mkdir -p /run/mysqld
    chmod -R 775 /run/mysqld
    chown -R mysql:mysql /run/mysqld
    mkdir -p /var/lib/mysql
    chown -R mysql:mysql /var/lib/mysql

    mysql_install_db --datadir=/var/lib/mysql --user=mysql

    /usr/bin/mysqld \
        --defaults-file=/etc/mariadb.cnf \
        --user=mysql \
        --bootstrap <<- EOF
		USE mysql;
		FLUSH PRIVILEGES ;
		ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';
		CREATE DATABASE IF NOT EXISTS $DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
		GRANT ALL ON $DB_NAME.* to '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';
		FLUSH PRIVILEGES ;
EOF

fi

mysqld --defaults-file=/etc/mariadb.cnf --user=mysql --console

