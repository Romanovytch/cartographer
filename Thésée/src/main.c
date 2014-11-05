/*
** main.c for Magic 21 in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Sep 26 12:48:52 2014 kettan_s
** Last update Tue Oct 21 13:28:55 2014 kettan_s
*/

#include "thesee.h"

int	main(int ac, char **av)
{
  if (ac == 2)
    thesee(av[1]);
  else
    {
      my_putstr("Usage : ./thesee maze.txt\n");
      return (1);
    }
  return (0);
}
