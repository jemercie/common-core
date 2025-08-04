FROM debian:bullseye

RUN apt update -y
RUN apt upgrade -y
RUN apt install python3 -y
RUN apt install python3-pip -y
RUN apt clean
RUN rm -rf /var/lib/apt/lists/*

RUN pip3 install django==4.2.11
RUN pip3 install channels==3.0.5
RUN pip3 install djangorestframework==3.15.1
RUN pip3 install psycopg[binary]==3.1.18
RUN pip3 install requests==2.31.0
RUN pip3 install django-widget-tweaks
RUN pip3 install Pillow

WORKDIR /transcendence

RUN django-admin startproject project .

COPY conf/exec.sh /exec.sh
RUN chmod +x /exec.sh

ENTRYPOINT ["/exec.sh"]
