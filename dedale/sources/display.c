/*
** display.c for display in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 11:27:04 2014 Florian Givernaud
** Last update Tue Oct 28 15:41:04 2014 Florian Givernaud
*/

#include "../includes/dedale.h"

static void	horizontal_wall(int **murs_h, int size, int i)
{
  int		j;

  j = 0;
  my_putchar('X');
  while (j < size)
    {
      if (murs_h[j][i] == CLOSE)
	my_putchar('X');
      else
	my_putchar(' ');
      my_putchar('X');
      ++j;
    }
  my_putchar ('\n');
}

static void	vertical_wall(int **murs_v, int size, int i)
{
  int		j;

  j = 0;
  my_putchar('X');
  my_putchar(' ');
  while (j < (size - 1))
    {
      if (murs_v[j][i] == CLOSE)
	my_putchar('X');
      else
	my_putchar(' ');
      my_putchar(' ');
      ++j;
    }
  my_putchar('X');
  my_putchar('\n');
}

static void	draw_line(int size)
{
  int		i;

  i = 0;
  while (i < (size + size + 1))
    {
      my_putchar('X');
      ++i;
    }
  my_putchar('\n');
}

void	disp_labyrinth(int **murs_v, int **murs_h, int size)
{
  int	i;

  i = 0;
  draw_line(size);
  while (i < size)
    {
      vertical_wall(murs_v, size, i);
      if (i < size - 1)
	horizontal_wall(murs_h, size, i);
      ++i;
    }
  draw_line(size);
}
