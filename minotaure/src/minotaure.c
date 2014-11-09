/*
** minotaure.c for minotaure in /home/kettan_s/Documents/cartographer/minotaure
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Sat Nov  8 13:57:06 2014 kettan_s
** Last update Sun Nov  9 01:07:51 2014 kettan_s
*/

#include "minotaure.h"

void	minotaure(char *file)
{
  char	**map;
  t_pos	exit;
  t_pos	m;
  t_pos	t;

  map = fill_map(file);
  m = get_pos_center(map);
  t = get_pos_t(map);
  exit = get_pos_exit(map);
  pathfinding(&map, t, m, '0');
  pathfinding(&map, exit, t, '1');
  map[m.y][m.x] = 'M';
  map[t.y][t.x] = 'C';
  map[exit.y][exit.x] = 'T';
  print_map(map);
}
