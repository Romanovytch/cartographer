/*
** pathfinding.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Wed Oct 22 15:30:24 2014 kettan_s
** Last update Sun Nov  9 15:01:49 2014 Florian Givernaud
*/

#include <stdlib.h>
#include "thesee.h"

int	pathfinding(char ***map, t_pos dst, int x, int y)
{
  if (x == dst.x && y == dst.y)
    return (1);
  if ((*map)[y][x] == 'X' || (*map)[y][x] == '*')
    return (0);
  (*map)[y][x] = '*';
  if (pathfinding(map, dst, x, y + 1))
    return (1);
  if (pathfinding(map, dst, x + 1, y))
    return (1);
  if (pathfinding(map, dst, x, y - 1))
    return (1);
  if (pathfinding(map, dst, x - 1, y))
    return (1);
  (*map)[y][x] = ' ';
  return (0);
}
