/*
** labyrinth.c for labyrinth in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Fri Oct 17 11:50:33 2014 Florian Givernaud
** Last update Tue Oct 28 15:44:39 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

static void	init_walls(int ***tab, int m, int n)
{
  int		i;
  int		j;

  i = 0;
  if (((*tab) = malloc(m * sizeof(int *))) == NULL)
    exit(EXIT_FAILURE);
  while (i < m)
    if (((*tab)[i++] = malloc(n * sizeof(int))) == NULL)
      exit(EXIT_FAILURE);
  i = 0;
  while (i < m)
    {
      j = 0;
      while (j < n)
	{
	  (*tab)[i][j] = CLOSE;
	  ++j;
	}
      ++i;
    }
}

static void	init_labyrinth(int ***tab, int size)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  i = 0;
  if (((*tab) = malloc(size * sizeof(int *))) == NULL)
    exit(EXIT_FAILURE);
  while (i < size)
    if (((*tab)[i++] = malloc(size * sizeof(int))) == NULL)
      exit(EXIT_FAILURE);
  i = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  (*tab)[i][j] = k;
	  ++j;
	  ++k;
	}
      ++i;
    }
}

static void	free_labyrinth(int ***tab, int size)
{
  int		i;

  i = 0;
  while (i < size)
    free((*tab)[i++]);
  free(*tab);
}

void	make_labyrinth(int size)
{
  int	**murs_v;
  int	**murs_h;
  int	**tab;

  init_walls(&murs_v, (size - 1), size);
  init_walls(&murs_h, size, (size - 1));
  init_labyrinth(&tab, size);

  select_wall(&murs_v, &murs_h, size);
  disp_labyrinth(murs_v, murs_h, size);

  free_labyrinth(&murs_v, size - 1);
  free_labyrinth(&murs_h, size);
  free_labyrinth(&tab, size);
}
