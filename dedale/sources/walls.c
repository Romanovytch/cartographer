/*
** walls.c for walls in /home/givern_f/Modules/cartographer/dedale/sources
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sun Nov  9 13:53:54 2014 Florian Givernaud
** Last update Sun Nov  9 14:38:22 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

int	is_there_wall_v(int **tab, int **laby, int m, int n)
{
  int	i;
  int	j;

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

int	is_there_wall_h(int **tab, int **laby, int m, int n)
{
  int	i;
  int	j;

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

void	open_wall_h(int ***tab, int ***laby, int m, int n)
{
  int	i;
  int	j;
  int	stop;

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

void	open_wall_v(int ***tab, int ***laby, int m, int n)
{
  int	i;
  int	j;
  int	stop;

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
