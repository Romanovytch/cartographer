/*
** pop.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Nov  4 09:23:33 2014 kettan_s
** Last update Tue Nov  4 23:57:25 2014 kettan_s
*/

#include <stdlib.h>
#include "thesee.h"

t_node		*pop_front(t_node *list)
{
  if (list == NULL)
    return (NULL);
  list = list->next;
  return (list);
}

t_node		*pop_back(t_node *list)
{
  t_node	*prev;
  t_node	*tmp;

  if (list == NULL)
    return (NULL);
  tmp = list;
  if (list->next == NULL)
    return (NULL);
  while (tmp->next != NULL)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  prev->next = NULL;
  return (list);
}

t_node		*pop_pos(t_node *list, t_pos pos)
{
  t_node	*prev;
  t_node	*tmp;

  if (list->pos.x == pos.x && list->pos.y == pos.y)
    list = pop_front(list);
  else
    {
      prev = list;
      tmp = list->next;
      while (tmp->next != NULL)
	{
	  if (tmp->pos.x == pos.x && tmp->pos.y == pos.y)
	    {
	      prev->next = tmp->next;
	      return (list);
	    }
	  prev = tmp;
	  tmp = tmp->next;
	}
      if (tmp->pos.x == pos.x && tmp->pos.y == pos.y)
	list = pop_back(list);
    }
  return (list);
}
