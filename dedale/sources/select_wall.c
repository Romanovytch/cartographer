/*
** select_wall.c for select_wall in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 13:09:30 2014 Florian Givernaud
** Last update Thu Nov  6 17:02:13 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

#include <stdio.h>

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

static int	is_there_wall_v(int **tab, int **laby, int m, int n)
{
  int		i;
  int		j;

  i = 0;
  while (i < m)
    {
      j = 0;
      while (j < n)
	{
	  if (tab[i][j] == CLOSE)
	    if (laby[i][j] != laby[i][j + 1])
	      return (1);
	  ++j;
	}
      ++i;
    }
  return (0);
}

static int	is_there_wall_h(int **tab, int **laby, int m, int n)
{
  int		i;
  int		j;

  i = 0;
  while (i < m)
    {
      j = 0;
      while (j < n)
	{
	  if (tab[i][j] == CLOSE)
	    if (laby[i][j] != laby[i + 1][j])
	      return (1);
	  ++j;
	}
      ++i;
    }
  return (0);
}

void	select_wall(int ***murs_v, int ***murs_h, int ***laby, int size)
{
  int  rand_wall;

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
