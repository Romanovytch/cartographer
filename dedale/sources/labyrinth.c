/*
** labyrinth.c for labyrinth in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Fri Oct 17 11:50:33 2014 Florian Givernaud
** Last update Sun Nov  9 14:53:20 2014 Florian Givernaud
*/

#include "../includes/dedale.h"

int	make_labyrinth(int size)
{
  int	**murs_v;
  int	**murs_h;
  int	**laby;

  if (init_walls(&murs_v, size, (size - 1)) == 0)
    return (0);
  if (init_walls(&murs_h, (size - 1), size) == 0)
    return (0);
  if (init_labyrinth(&laby, size) == 0)
    return (0);
  select_wall(&murs_v, &murs_h, &laby, size);
  disp_labyrinth(murs_v, murs_h, size);
  free_labyrinth(&murs_v, size);
  free_labyrinth(&murs_h, (size - 1));
  free_labyrinth(&laby, size);
  return (0);
}
