##
## Makefile for Magic42 in /home/kettan_s/Documents/Magic42
## 
## Made by kettan_s
## Login   <kettan_s@epitech.net>
## 
## Started on  Wed Oct  1 07:26:08 2014 kettan_s
## Last update Sun Nov  9 14:59:11 2014 Florian Givernaud
##

SRC	=	src/main.c		\
		src/my_putchar.c	\
		src/my_putstr.c		\
		src/my_strdup.c		\
		src/my_strlen.c		\
		src/my_strcmp.c		\
		src/my_putnbr_base.c	\
		src/get_next_line.c	\
		src/thesee.c		\
		src/map.c		\
		src/pos.c		\
		src/pathfinding.c	\

NAME	=	thesee

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Werror -Wextra
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I include -std=gnu99

CC	=	gcc -g3

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

rc:		all clean

.PHONY:		all clean fclean re rc
