##
## Makefile for Makefile in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
## 
## Made by Florian Givernaud
## Login   <givern_f@epitech.net>
## 
## Started on  Tue Oct 28 10:20:49 2014 Florian Givernaud
## Last update Sun Nov  9 14:57:46 2014 Florian Givernaud
##

NAME	=	dedale

CFLAGS	=	-W -Wall -Wextra -Werror -ansi -pedantic

SRC	=	sources/main.c \
		sources/init.c \
		sources/labyrinth.c \
		sources/display.c \
		sources/walls.c \
		sources/select_wall.c \
		sources/path.c \
		sources/lib/my_getnbr.c \
		sources/lib/my_put_nbr.c \
		sources/lib/my_putstr.c \
		sources/lib/is_pair.c

OBJ	=	$(SRC:.c=.o)

$(NAME)	: $(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS) 

all	: $(NAME)

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
