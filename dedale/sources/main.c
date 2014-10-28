/*
** main.c for main in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Fri Oct 17 11:22:26 2014 Florian Givernaud
** Last update Tue Oct 28 15:31:49 2014 Florian Givernaud
*/

#include <stdlib.h>
#include "../includes/dedale.h"

int	check_args(int argc, char **argv)
{
  int	number;

  number = 0;
  if (argc < 2)
    {
      my_putstr("Usage: [./dedale X] where X is a number between 9 and 29.\n");
      return (0);
    }
  number = my_getnbr(argv[1]);
  if (number < 9)
    {
      my_putstr("The size of the labyrinth must be superior to 9\n");
      return (0);
    }
  if (number > 29)
    {
      my_putstr("The size of the labyrinth must be inferior to 29\n");
      return (0);
    }
  return (number);
}


int	main(int argc, char **argv)
{
  int	size;

  if ((size = check_args(argc, argv)) == 0)
    return (0);
  make_labyrinth(size);
  return (0);
}
