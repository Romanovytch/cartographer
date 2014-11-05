/*
** heuristic.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Sat Nov  1 21:25:38 2014 kettan_s
** Last update Sat Nov  1 23:40:11 2014 kettan_s
*/

#include "thesee.h"

int	heuristic(t_pos src, t_pos dst)
{
  int	h;

  h = (dst.x - src.x) + (dst.y - src.y);
  if (h < 0)
    h *= -1;
  return (h);
}
