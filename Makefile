##
## EPITECH PROJECT, 2020
## B-CPE-210-MPL-2-1-solostumper05-hugo.gardes
## File description:
## Makefile
##

all:
	make -C solver
	make -C generator

clean:
	make clean -C solver
	make clean -C generator

fclean:
	make fclean -C solver
	make fclean -C generator

re:	fclean all
