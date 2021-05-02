##
## EPITECH PROJECT, 2020
## B-CPE-210-MPL-2-1-solostumper05-hugo.gardes
## File description:
## Makefile
##

CC	=	gcc

NAME	=	generator

SRC		=	$(wildcard *.c)
SRC		+=	$(wildcard */*.c)
SRC		+=	$(wildcard */*/*.c)

OBJS	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -I include/ -g3

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) #*#

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
