##
## Makefile for Makefile in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
## 
## Made by Florian Givernaud
## Login   <givern_f@epitech.net>
## 
## Started on  Tue Oct 28 10:20:49 2014 Florian Givernaud
## Last update Tue Oct 28 15:39:37 2014 Florian Givernaud
##

NAME	=	bin/dedale

SRC	=	sources/main.c \
		sources/labyrinth.c \
		sources/display.c \
		sources/select_wall.c \
		sources/lib/my_getnbr.c \
		sources/lib/my_put_nbr.c \
		sources/lib/my_putstr.c

OBJ	=	$(SRC:.c=.o)

$(NAME)	: $(OBJ)
		cc -o $(NAME) $(OBJ) -Wall -Wextra -Werror

all	: $(NAME)

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
