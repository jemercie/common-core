

FROM alpine:3.19

RUN apk update ; apk upgrade
RUN apk add openssl nginx

RUN rm -rf /var/cache/apk/*
RUN mkdir r -p /etc/nginx/ssl
RUN chmod +x /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Angouleme/O=42/OU=42/CN=jemercie.42.fr/UID=jemercie"
RUN mkdir -p /var/www/wp

RUN rm /etc/nginx/http.d/default.conf
COPY nginx.conf /etc/nginx/http.d/my.conf
RUN  chmod +x /etc/nginx/http.d/my.conf


EXPOSE 443

ENTRYPOINT	[ "nginx", "-g", "daemon off;" ]


