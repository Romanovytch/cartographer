/*
** select_wall.c for select_wall in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 13:09:30 2014 Florian Givernaud
** Last update Mon Nov  3 13:31:40 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

static void	full_laby(int ***laby, int x, int y, int size)
{
  int		min;
  int		i;
  int		j;

  i = 0;
  if (x < y)
    min = x;
  else
    min = y;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  if ((*laby)[i][j] == x || (*laby)[i][j] == y)
	    (*laby)[i][j] = min;
	  ++j;
	}
      ++i;
    }
}

static void	open_wall_h(int ***tab, int ***laby, int m, int n)
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
	  if ((*laby)[i][j] != (*laby)[i + 1][j])
	    {
	      (*tab)[i][j] = OPEN;
	      full_laby(laby, (*laby)[i][j], (*laby)[i + 1][j], n);
	      stop = 1;
	    }
	}
    }
}

static void	open_wall_v(int ***tab, int ***laby, int m, int n)
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
	  if ((*laby)[i][j] != (*laby)[i][j + 1])
	    {
	      (*tab)[i][j] = OPEN;
	      full_laby(laby, (*laby)[i][j], (*laby)[i][j + 1], m);
	      stop = 1;
	    }
	}
    }
}

void	select_wall(int ***murs_v, int ***murs_h, int ***laby, int size)
{
  int  rand_wall;
  int	i;

  i = 0;
  srand(time(NULL));
  while (i < (size * size - 1))
    {
      rand_wall = rand() % 2;
      if (rand_wall == 0)
	open_wall_h(murs_h, laby, (size - 1), size);
      else
	open_wall_v(murs_v, laby, size, (size - 1));
      ++i;
    }
}
