/*
** select_wall.c for select_wall in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 13:09:30 2014 Florian Givernaud
** Last update Sun Nov  9 14:55:30 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

static	int	is_it_link(int **tab, int size)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  if (tab[i][j] != 0)
	    return (0);
	  ++j;
	}
      ++i;
    }
  return (1);
}

void	full_laby(int ***laby, int x, int y, int size)
{
  int	min;
  int	i;
  int	j;

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

void	select_wall(int ***murs_v, int ***murs_h, int ***laby, int size)
{
  int	rand_wall;

  srand(time(NULL));
  while (is_it_link((*laby), size) == 0)
    {
      rand_wall = rand() % 2;
      if (rand_wall == 0)
	{
	  if (is_there_wall_h((*murs_h), (*laby), (size - 1), size) == 1)
	    open_wall_h(murs_h, laby, (size - 1), size);
	}
      else
	{
	  if (is_there_wall_v((*murs_v), (*laby), size, (size - 1)) == 1)
	    open_wall_v(murs_v, laby, size, (size - 1));
	}
    }
}
