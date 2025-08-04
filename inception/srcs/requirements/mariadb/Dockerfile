FROM	alpine:3.19

RUN apk update ; apk upgrade
RUN apk add mariadb mariadb-common mariadb-client

COPY ./script_config_db.sh ./etc
RUN	chmod +x /etc/script_config_db.sh

COPY ./mariadb.cnf ./etc
RUN chmod +x /etc/mariadb.cnf

ENTRYPOINT [ "sh", "/etc/script_config_db.sh" ]