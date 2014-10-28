/*
** select_wall.c for select_wall in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 13:09:30 2014 Florian Givernaud
** Last update Tue Oct 28 15:43:24 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

static void	open_wall(int ***tab, int m, int n)
{
  int		i;
  int		j;
  int		stop;

  stop = 0;
  srand(time(NULL));
  while (stop == 0)
    {
      i = rand() % m;
      j = rand() % n;
      if ((*tab)[i][j] == CLOSE)
	{
	  (*tab)[i][j] = OPEN;
	  stop = 1;
	}
    }
}

void	select_wall(int ***murs_v, int ***murs_h, int size)
{
  int  rand_wall;
  int	i;

  i = 0;
  srand(time(NULL));
  while (i < (size * size - 1))
    {
      rand_wall = rand() % 2;
      if (rand_wall == 0)
	open_wall(murs_h, size, (size - 1));
      else
	open_wall(murs_v, (size - 1), size);
      ++i;
    }
}
