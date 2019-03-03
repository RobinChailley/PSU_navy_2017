##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

SRC	=	my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_getfile.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

FLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
