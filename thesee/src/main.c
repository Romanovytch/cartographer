/*
** main.c for Magic 21 in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Sep 26 12:48:52 2014 kettan_s
** Last update Sun Nov  9 15:01:06 2014 Florian Givernaud
*/

#include <stdlib.h>
#include "thesee.h"

int	main(int ac, char **av)
{
  if (ac == 1)
    thesee(NULL);
  else if (ac == 2)
    thesee(av[1]);
  else
    {
      my_putstr("Usage : ./thesee [maze.txt]\n");
      return (1);
    }
  return (0);
}
