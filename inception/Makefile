# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 14:46:35 by jemercie          #+#    #+#              #
#    Updated: 2024/01/20 14:46:37 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : compose

create_data_folders:
	mkdir -p /home/jemercie/data/wordpress
	mkdir -p /home/jemercie/data/mariadb

build:
	docker build -t nginx srcs/requirements/nginx
	docker build -t mariadb srcs/requirements/mariadb
	docker build -t wordpress srcs/requirements/wordpress

compose: create_data_folders build
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker compose -f ./srcs/docker-compose.yml down -v --rmi local

clean: down
	rm -rf /home/jemercie/data/wordpress /home/jemercie/data/mariadb
	docker system prune -a
	docker volume prune -a

#exec_mariadb:
#	docker exec -it mariadb $(sudo ~bin/bash)

show:
	@echo "\033[1;34m    images:\033[0;38m"ps

	@docker image ls
	@echo "\033[1;34m    containers:\033[0;38m"
	@docker ps
	@echo "\033[1;34m    volumes:\033[0;38m"
	@docker volume ls
	@echo "\033[1;34m    network:\033[0;38m"
	@docker network ls

PHONY:all create_data_folder build compose down clean show
