##
## EPITECH PROJECT, 2018
## MUL_my_hunter_2018
## File description:
## myhunter makefile
##
SRC =	main.c \
		events.c \
		bird_animation.c \
		bird_management.c \
		setup_objects.c \
		objects.c \
		display_window.c \
		background.c \
		clear.c \
		manual.c \

OBJ = $(SRC:.c=.o)

NAME = my_hunter

CFLAGS =  -Wall -Wextra -Werror -g

LDFLAGS = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lm -L lib/ -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)
	rm -f $(OBJ)

clean:
	make -C lib clean
	rm -rf $(OBJ)

fclean: clean
	make -C lib fclean
	rm -rf $(NAME)

re: fclean all
