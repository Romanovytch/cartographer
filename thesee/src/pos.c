/*
** pos.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Wed Oct 22 17:14:50 2014 kettan_s
** Last update Sun Nov  9 15:01:33 2014 Florian Givernaud
*/

#include <stdlib.h>
#include "thesee.h"

t_pos	get_pos_exit(char **map)
{
  t_pos	err;
  t_pos	pos;
  int	size;

  size = my_strlen(map[0]) - 1;
  pos.y = 0;
  while (map[pos.y])
    {
      pos.x = 0;
      while (map[pos.y][pos.x])
	{
	  if (pos.x == 0 || pos.x == size || pos.y == 0 || pos.y == size)
	    if (map[pos.y][pos.x] == ' ')
	      return (pos);
	  pos.x += 1;
	}
      pos.y += 1;
    }
  err.x = -1;
  err.y = -1;
  return (err);
}

t_pos	get_pos_center(char **map)
{
  t_pos	ct;

  ct.x = my_strlen(map[0]) / 2;
  ct.y = ct.x;
  return (ct);
}

t_pos	new_pos(int x, int y)
{
  t_pos	new;

  new.x = x;
  new.y = y;
  return (new);
}
