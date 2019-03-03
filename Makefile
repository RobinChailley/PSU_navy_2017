##
## EPITECH PROJECT, 2018
## PSU_2017_navy
## File description:
## Makefile
##

CC		=	gcc -g

CLFAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I ./include

RM		=	rm -rf

SRC		=	main.c	\
			sources/display.c \
			sources/map_creation.c 	\
			sources/init.c 	 \
			sources/send.c 	\
			sources/connection.c 	\
			sources/loop_game.c 	\
			sources/win.c 	\
			sources/sending_funcs.c 	\
			sources/error_management_map.c	\

OBJS		=	$(SRC:.c=.o)

NAME		=	navy


all: $(NAME)


$(NAME): $(OBJS)
	@cd lib && make && cd ..
	$(CC) -o $(NAME) $(OBJS) $(CLFAGS) -L./lib/ -lmy

clean:
	@cd lib && make clean && cd ..
	$(RM) $(OBJS)

fclean: clean
	@cd lib && make fclean && cd ..
	$(RM) $(NAME)


re: fclean all
