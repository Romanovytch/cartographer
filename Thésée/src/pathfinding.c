/*
** pathfinding.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Wed Oct 22 15:30:24 2014 kettan_s
** Last update Tue Nov  4 23:58:08 2014 kettan_s
*/

#include <stdlib.h>
#include "thesee.h"

#include <stdio.h>

char		**pathfinding(char **map, t_pos src, t_pos dst)
{
  t_list	list;
  t_node	*p;
  t_pos		pos;
  int		i = 30;

  list.open = NULL;
  list.close = create_node(NULL, 0, src, dst);
  while ((list.close->pos.x != dst.x || list.close->pos.y != dst.y) && i > 0)
    {
      pos = list.close->pos;
      map[pos.y][pos.x] = '*';
      a_star_foulah(map, &list, pos, dst);
  my_putstr("\nOPEN LIST :\n");
  disp_nodes(list.open);
      p = get_min_f(list.open);
      list.close = push_front(list.close, p);
      list.open = pop_pos(list.open, p->pos);
      --i;
      print_map(map);
    }
  my_putstr("CLOSE LIST :\n");
  disp_nodes(list.close);
  my_putstr("\nOPEN LIST :\n");
  disp_nodes(list.open);
  return (map);
}

void		a_star_foulah(char **map, t_list *list, t_pos pos, t_pos dst)
{
  static int	g = 1;

  if (map[pos.y - 1][pos.x] != 'X')
    list->open = add_open(list->open, create_node(list->close, g, new_pos(pos.x, pos.y - 1), dst));
  if (map[pos.y][pos.x + 1] != 'X')
    list->open = add_open(list->open, create_node(list->close, g, new_pos(pos.x + 1, pos.y), dst));
  if (map[pos.y + 1][pos.x] != 'X')
    list->open = add_open(list->open, create_node(list->close, g, new_pos(pos.x, pos.y + 1), dst));
  if (map[pos.y][pos.x - 1] != 'X')
    list->open = add_open(list->open, create_node(list->close, g, new_pos(pos.x - 1, pos.y), dst));
  ++g;
}
