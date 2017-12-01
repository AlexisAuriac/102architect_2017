##
## EPITECH PROJECT, 2017
## 102architect
## File description:
## Makefile for 102architect
##

SRC	=	main.c			\
		transformations.c	\
		display.c		\
		error_management.c

OBJ	=	$(SRC:.c=.o)

LIB	=	-lm -L./lib/my -lmy

NAME	=	102architect

all	:	$(NAME)

$(NAME)	:	$(OBJ)	lib
		gcc -o $(NAME) $(OBJ) $(LIB)

lib	:	lib/my/Makefile
		make -C lib/my

clean	:
		rm -f $(OBJ) *~ *#*
		make clean -C lib/my

fclean	:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re	:	fclean	all

.PHONY	:	all	lib	clean	fclean	re
