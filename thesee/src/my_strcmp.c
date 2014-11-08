/*
** my_strcmp.c for my_strcmp in /home/kettan_s/Documents/P2J4/Ex_02
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Mon Sep 22 14:38:54 2014 kettan_s
** Last update Mon Sep 22 14:41:59 2014 kettan_s
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	cmp;

  i = 0;
  cmp = 0;
  if (s1 == NULL && s2 != NULL)
    cmp -= s2[i];
  else if (s1 != NULL && s2 == NULL)
    cmp += s1[i];
  while (!cmp && (s1[i] || s2[i]))
    {
      cmp += (s1[i] - s2[i]);
      ++i;
    }
  return (cmp);
}
