/*
** my_putstr.c for my_putstr in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Sep 26 13:06:21 2014 kettan_s
** Last update Tue Oct 21 13:25:12 2014 kettan_s
*/

#include "thesee.h"

void	my_putstr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    my_putchar(s[i++]);
}
