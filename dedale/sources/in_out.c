/*
** in_out.c for in_out in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale/sources
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Mon Nov  3 09:17:04 2014 Florian Givernaud
** Last update Mon Nov  3 13:22:54 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

int	in_out(int **murs_h, int size)
{
  int	number;

  srand(time(NULL));
  while (42)
    {
      number = rand() % (size - 1);
      if (murs_h[1][number] == OPEN)
	return (number);
    }
}
