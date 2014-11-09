/*
** path.c for path in /home/givern_f/Modules/cartographer/dedale/sources
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Sun Nov  9 14:00:58 2014 Florian Givernaud
** Last update Sun Nov  9 14:54:42 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <time.h>
#include "../includes/dedale.h"

void	open_middle(char ***laby, int size)
{
  int	access;
  int	pos;

  access = 0;
  pos = size;
  (*laby)[size][size] = ' ';
  if ((*laby)[size][size + 1] == ' ' ||
      (*laby)[size][size - 1] == ' ' ||
      (*laby)[size + 1][size] == ' ' ||
      (*laby)[size - 1][size] == ' ')
    {
      access = 1;
    }
  while (access == 0)
    {
      if ((*laby)[size][pos - 1] != ' ')
        {
          (*laby)[size][pos - 1] = ' ';
          --pos;
        }
      else
        access = 1;
    }
}

int	in_out(int size)
{
  int	number;

  srand(time(NULL));
  number = rand() % size;
  return (number);
}
