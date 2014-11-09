/*
** display.c for display in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 11:27:04 2014 Florian Givernaud
** Last update Sun Nov  9 14:52:02 2014 Florian Givernaud
*/

#include <stdlib.h>
#include "../includes/dedale.h"

static void	horizontal_wall(char ***laby, int *murs_h, int size, int pos)
{
  int		j;
  int		k;

  k = 0;
  j = 0;
  (*laby)[pos][k++] = 'X';
  while (j < size)
    {
      if (murs_h[j] == CLOSE)
	(*laby)[pos][k++] = 'X';
      else
	(*laby)[pos][k++] = ' ';
      (*laby)[pos][k++] = 'X';
      ++j;
    }
  (*laby)[pos][k] = '\0';
}

static void	vertical_wall(char ***laby, int *murs_v, int size, int pos)
{
  int		j;
  int		k;

  j = 0;
  k = 0;
  (*laby)[pos][k++] = 'X';
  (*laby)[pos][k++] = ' ';
  while (j < (size - 1))
    {
      if (murs_v[j] == CLOSE)
	(*laby)[pos][k++] = 'X';
      else
	(*laby)[pos][k++] = ' ';
      (*laby)[pos][k++] = ' ';
      ++j;
    }
  (*laby)[pos][k++] = 'X';
  (*laby)[pos][k] = '\0';
}

static void	draw_line(char ***laby, int size, int x, int pos)
{
  int		i;

  i = 0;
  while (i < (size * 2 + 1))
    {
      if (i != (x * 2 + 1))
	(*laby)[pos][i] = 'X';
      else
	(*laby)[pos][i] = ' ';
      ++i;
    }
  (*laby)[pos][i] = '\0';
}

static void	aff_laby(char **laby, int size)
{
  int		i;

  i = 0;
  while (i < (size * 2 + 1))
    {
      my_putstr(laby[i]);
      my_putchar('\n');
      ++i;
    }
}

int	disp_labyrinth(int **murs_v, int **murs_h, int size)
{
  int	i;
  int	number;
  char	**laby;
  int	pos;

  pos = 0;
  i = 0;
  if (init_display(&laby, size) == 0)
    return (0);
  number = in_out(size);
  draw_line(&laby, size, number, pos++);
  while (i < size)
    {
      vertical_wall(&laby, murs_v[i], size, pos++);
      if (i < size - 1)
	horizontal_wall(&laby, murs_h[i], size, pos++);
      ++i;
    }
  draw_line(&laby, size, (size + size + 1), pos++);
  open_middle(&laby, size);
  aff_laby(laby, size);
  free_display(&laby, size);
  return (0);
}
