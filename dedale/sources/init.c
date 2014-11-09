/*
** init.c for init in /home/givern_f/Modules/cartographer/dedale/sources
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sun Nov  9 14:15:34 2014 Florian Givernaud
** Last update Sun Nov  9 14:53:05 2014 Florian Givernaud
*/

#include <stdlib.h>
#include "../includes/dedale.h"

int	init_walls(int ***tab, int m, int n)
{
  int	i;
  int	j;

  i = 0;
  if (((*tab) = malloc(m * sizeof(int *))) == NULL)
    return (0);
  while (i < m)
    if (((*tab)[i++] = malloc(n * sizeof(int))) == NULL)
      return (0);
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
  return (1);
}

int	init_labyrinth(int ***tab, int size)
{
  int	i;
  int	j;
  int	k;

  k = 0;
  i = 0;
  if (((*tab) = malloc(size * sizeof(int *))) == NULL)
    return (0);
  while (i < size)
    if (((*tab)[i++] = malloc(size * sizeof(int))) == NULL)
      return (0);
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
  return (1);
}

int	init_display(char ***tab, int size)
{
  int	i;

  i = 0;
  if (((*tab) = malloc((size * 2 + 2) * sizeof(char *))) == NULL)
    return (0);
  while (i < (size * 2 + 1))
    if (((*tab)[i++] = malloc((size * 2 + 2) * sizeof(char))) == NULL)
      return (0);
  return (1);
}

void	free_labyrinth(int ***tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    free((*tab)[i++]);
  free(*tab);
}

void	free_display(char ***tab, int size)
{
  int	i;

  i = 0;
  while (i < (size * 2 + 1))
    free((*tab)[i++]);
  free(*tab);
}
