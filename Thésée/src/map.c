/*
** map.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Oct 21 13:37:49 2014 kettan_s
** Last update Thu Nov  6 13:36:22 2014 Florian Givernaud
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "thesee.h"

char	**fill_map(char *path)
{
  char	**map;
  int	size;
  int	fd;
  int	i;

  if ((fd = open(path, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  i = 0;
  size = 29;
  map = malloc(sizeof(char *) * size + 1);
  while (i < size)
    {
      map[i] = get_next_line(fd);
      ++i;
    }
  return (map);
}

void	print_color(char *color, char c)
{
  my_putstr(color);
  my_putchar(c);
  my_putstr("\x1b[0m");
}

void	print_map(char **map)
{
  int	y;
  int	x;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x])
	{
	  if (map[y][x] == '*')
	    print_color("\x1b[42;30m", map[y][x]);
	  else if (map[y][x] == 'T' || map[y][x] == 'C')
	    print_color("\x1b[41;37m", map[y][x]);
	  /* else if (map[y][x] == 'X') */
	  /*   print_color("\x1b[47;30;6m", map[y][x]); */
	  else
	    my_putchar(map[y][x]);
	  ++x;
	}
      my_putchar('\n');
      ++y;
    }
}
