/*
** cost.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Oct 24 09:03:42 2014 kettan_s
** Last update Fri Oct 24 09:09:47 2014 kettan_s
*/

#include "thesee.h"

int	get_heuristic(t_pos cur, t_pos dest)
{
  int	heuristic;

  heuristic = dest.x - cur.x;
  heuristic += dest.y - cur.y;
  return (heuristic);
}
