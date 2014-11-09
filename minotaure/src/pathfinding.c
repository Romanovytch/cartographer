/*
** pathfinding.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Wed Oct 22 15:30:24 2014 kettan_s
** Last update Sun Nov  9 01:09:15 2014 kettan_s
*/

#include <stdlib.h>
#include "minotaure.h"

int	pathfinding(char ***map, t_pos dst, t_pos pos, char c)
{
  char	tmp;

  if (pos.x == dst.x && pos.y == dst.y)
    return (1);
  else if (pos.x < 0 || pos.y < 0)
    return (0);
  else if ((*map)[pos.y][pos.x] == 'X' || (*map)[pos.y][pos.x] == c)
    return (0);
  tmp = (*map)[pos.y][pos.x];
  (*map)[pos.y][pos.x] = c;
  if (pathfinding(map, dst, new_pos(pos.x, pos.y + 1), c))
    return (1);
  if (pathfinding(map, dst, new_pos(pos.x + 1, pos.y), c))
    return (1);
  if (pathfinding(map, dst, new_pos(pos.x, pos.y - 1), c))
    return (1);
  if (pathfinding(map, dst, new_pos(pos.x - 1, pos.y), c))
    return (1);
  (*map)[pos.y][pos.x] = tmp;
  return (0);
}
