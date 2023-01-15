##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC 	=   my/utils/my_putchar.c \
		my/utils/is_float.c \
		my/utils/my_put_nbr.c \
		my/utils/my_putstr.c \
		my/utils/my_revstr.c \
		my/utils/my_strcat.c \
		my/utils/my_strcpy.c \
		my/utils/my_str_isalpha.c \
		my/utils/my_strlen.c \
		my/utils/my_strncat.c \
		my/utils/my_int_to_str.c \
		my/utils/my_long_to_str.c \
		my/utils/my_strdup.c \
		my/utils/my_uint_to_str.c \
		my/utils/my_ulong_long_to_str.c \
		my/utils/is_only_num.c \
		my/utils/is_num.c \
		my/utils/str_split.c \
		my/utils/my_strcmp.c \
		my/utils/check_if_file.c \
		my/utils/print_file_path.c \
		my/utils/calls_read_directory.c \
		my/utils/display_usage \
		my/utils/init_map.c \
		my/utils/game.c \
		my/utils/create_o_structures.c \
		my/utils/reset_map.c \
		my/utils/manage_o.c \
		my/utils/is_map_to_small.c \




NAME	=	libmy.a

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -I./my/utils -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
