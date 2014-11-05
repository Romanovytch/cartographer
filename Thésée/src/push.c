/*
** push.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Wed Oct 22 15:16:10 2014 kettan_s
** Last update Mon Nov  3 18:23:43 2014 kettan_s
*/

#include <stdlib.h>
#include "thesee.h"

t_node		*push_front(t_node *list, t_node *elem)
{
  if (list == NULL)
    return (elem);
  elem->next = list;
  list = elem;
  return (list);
}

t_node		*push_back(t_node *list, t_node *elem)
{
  t_node	*tmp;

  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  return (list);
}

t_node		*add_open(t_node *list, t_node *elem)
{
  t_node	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->pos.x == elem->pos.x && tmp->pos.y == elem->pos.y)
	{
	  if (tmp->f > elem->f)
	    {
	      my_putstr("TA MERE\n");
	      tmp = update_node(tmp, elem);
	    }
	  return (list);
	}
      tmp = tmp->next;
    }
  return (list = push_front(list, elem));
}
