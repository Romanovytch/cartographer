/*
** node.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Wed Oct 22 15:21:12 2014 kettan_s
** Last update Tue Nov  4 17:55:46 2014 kettan_s
*/

#include <stdlib.h>
#include "thesee.h"

t_node		*create_node(t_node *parent, int g, t_pos pos, t_pos dst)
{
  t_node	*elem;

  if ((elem = malloc(sizeof(t_node))) == NULL)
    exit(EXIT_FAILURE);
  elem->g = g;
  elem->h = heuristic(pos, dst);
  elem->f = elem->g + elem->h;
  elem->pos.x = pos.x;
  elem->pos.y = pos.y;
  elem->parent = parent;
  elem->next = NULL;
  return (elem);
}

t_node		*update_node(t_node *old, t_node *new)
{
  old->g = new->g;
  old->h = new->h;
  old->f = new->f;
  free(new);
  return (old);
}

void		disp_nodes(t_node *node)
{
  t_node	*tmp;

  tmp = node;
  while (tmp != NULL)
    {
      my_putstr("f = ");
      my_putnbr_base(tmp->f, "0123456789");
      my_putstr("\tg = ");
      my_putnbr_base(tmp->g, "0123456789");
      my_putstr("\th = ");
      my_putnbr_base(tmp->h, "0123456789");
      my_putstr("\npos = (");
      my_putnbr_base(tmp->pos.x, "0123456789");
      my_putstr(";");
      my_putnbr_base(tmp->pos.y, "0123456789");
      my_putstr(")\n\n");
      tmp = tmp->next;
    }
}

t_node		*get_min_f(t_node *open)
{
  t_node	*tmp;
  t_node	*ret;
  int		ft;

  if (open == NULL)
    return (NULL);
  tmp = open;
  ft = tmp->f + 1;
  while (tmp != NULL)
    {
      if (tmp->f < ft)
	{
	  ret = tmp;
	  ft = tmp->f;
	}
      tmp = tmp->next;
    }
  return (ret);
}
