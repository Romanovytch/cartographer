/*
** my_strdup.c for my_strdup in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Mon Sep 29 09:53:54 2014 kettan_s
** Last update Mon Sep 29 09:56:55 2014 kettan_s
*/

#include <stdlib.h>

char	*my_strdup(char *s)
{
  char	*dup;
  int	len;
  int	i;

  i = 0;
  len = 0;
  while (s[len])
    ++len;
  dup = malloc(sizeof(char) * len);
  while (i < len)
    {
      dup[i] = s[i];
      ++i;
    }
  return (dup);
}
