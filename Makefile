##
## Makefile for Cartographer in /home/kettan_s/Documents/cartographer
## 
## Made by kettan_s
## Login   <kettan_s@epitech.net>
## 
## Started on  Sun Nov  9 15:31:23 2014 kettan_s
## Last update Sun Nov  9 17:31:34 2014 kettan_s
##

DEDALE		=	dedale/

THESEE		=	thesee/

MINOTAURE	=	minotaure/

all:	dedale thesee minotaure


dedale:
	make -C $(DEDALE)

thesee:
	make -C $(THESEE)

minotaure:
	make -C $(MINOTAURE)

clean:
	make -C $(DEDALE) clean
	make -C $(THESEE) clean
	make -C $(MINOTAURE) clean

fclean:
	make -C $(DEDALE) fclean
	make -C $(THESEE) fclean
	make -C $(MINOTAURE) fclean

re:	fclean all

.PHONY: all dedale thesee minotaure clean fclean re
