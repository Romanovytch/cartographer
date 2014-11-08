/*
** thesee.c for Thésée in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Oct 21 13:29:23 2014 kettan_s
** Last update Wed Nov  5 12:32:30 2014 kettan_s
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
  pathfinding(&map, exit, center.x, center.y);
  map[center.y][center.x] = 'C';
  map[exit.y][exit.x] = 'T';
  print_map(map);
}
