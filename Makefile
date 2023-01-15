##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC 	=   $(wildcard *.c)\
			$(wildcard ./lib/my/utils/*.c)


NAME	=	my_sokoban

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -I./my/utils -g3

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g3 -o $(NAME) $(CGLAGS) $(OBJ) -lncurses

lib:
	make -C ./lib/my/ -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
re: fclean all
