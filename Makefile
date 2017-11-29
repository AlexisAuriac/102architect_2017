##
## EPITECH PROJECT, 2017
## 102architect
## File description:
## Makrfile for 102architect
##

SRC	=	main.c			\
		transformations.c	\
		display.c

OBJ	=	$(SRC:.c=.o)

LIB	=	-lm -L./lib/my -lmy

NAME	=	102architect

all	:	lib	$(NAME)

$(NAME)	:	$(OBJ)
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
