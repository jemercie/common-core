all:
	mkdir -p ./data
	mkdir -p ./data/django
	$(MAKE) build
	$(MAKE) up

build:
	docker compose --project-directory ./srcs build

up:
	docker compose --project-directory ./srcs up -d

show:
	@echo "Images:"
	@docker image ls
	@echo "\nContainers:"
	@docker ps
	@echo "\nVolumes:"
	@docker volume ls
	@echo "\nNetwork:"
	@docker network ls

down:
	docker compose --project-directory ./srcs down

clean:
	$(MAKE) down
	docker system prune -af

re:
	$(MAKE) clean
	$(MAKE) build
	$(MAKE) up

.PHONY: all, build, up, show, down, clean, re
