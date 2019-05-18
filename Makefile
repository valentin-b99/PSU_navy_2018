##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## for navy
##

NAMEF	=	src/lib.c			\
			src/game.c			\
			src/main.c			\
			src/signal.c		\
			src/error.c			\
			src/use_map.c		\
			src/create_map.c	\
			src/player_one.c	\
			src/player_two.c	\
			src/communication.c \
			src/struct.c

NAME	=	navy

OPT		=	-g3 -no-pie -o

CFLAGS	=	-Werror -Wextra -W

LIB		=	-L./lib/my -lmy

$(NAME):	fclean
	(cd lib/my && make re -s)
	gcc $(OPT) $(NAME) $(NAMEF) $(LIB) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(NAME)~

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
