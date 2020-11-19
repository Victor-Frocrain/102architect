##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	test.c			\
		../src/architect.c	\
		../src/parsing_errors.c \
		../src/operations.c	\
		../src/init_matrix.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ../include

LIB	=	../lib/my -lmy -lm --coverage -lcriterion

NAME	=	Unit_test

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -L $(LIB)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
