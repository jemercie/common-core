FROM debian:bullseye

RUN apt update -y
RUN apt upgrade -y
RUN apt install nginx=1.18.* -y
RUN apt install openssl -y
RUN apt clean
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/transcendence.crt -keyout /etc/nginx/ssl/transcendence.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=localhost/UID=qwe"
RUN mkdir -p /var/run/nginx
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

COPY conf/nginx.conf /etc/nginx/sites-available/transcendence
RUN ln -s /etc/nginx/sites-available/transcendence /etc/nginx/sites-enabled/transcendence
RUN rm /etc/nginx/sites-enabled/default

CMD [ "nginx", "-g", "daemon off;" ]
