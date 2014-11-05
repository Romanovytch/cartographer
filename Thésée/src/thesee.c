/*
** thesee.c for Thésée in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Oct 21 13:29:23 2014 kettan_s
** Last update Tue Nov  4 09:11:00 2014 kettan_s
*/

#include "thesee.h"

void	thesee(char *file)
{
  char	**map;
  t_pos	center;
  t_pos	exit;

  map = fill_map(file);
  center = get_pos_center(map);
  exit = get_pos_exit(map);
  map[center.y][center.x] = '*';
  map[exit.y][exit.x] = '*';
  map = pathfinding(map, center, exit);
  print_map(map);
}
