/*
** map.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Oct 21 13:37:49 2014 kettan_s
** Last update Sun Nov  9 15:30:38 2014 kettan_s
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minotaure.h"

char	**fill_map(char *path)
{
  char	**map;
  int	size;
  int	fd;
  int	i;

  if (path != NULL)
    {
      if ((fd = open(path, O_RDONLY)) == -1)
	{
	  my_putstr("Error : open() failed to open ");
	  my_putstr(path);
	  my_putchar('\n');
	  exit(EXIT_FAILURE);
	}
    }
  else
    fd = 0;
  i = 0;
  size = 29;
  map = malloc(sizeof(char *) * size + 1);
  while (i < size)
    map[i++] = get_next_line(fd);
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
	  if (map[y][x] == '0' || map[y][x] == '1' || map[y][x] == '*')
	    print_color("\x1b[42;30m", '*');
	  else if (map[y][x] == 'T' || map[y][x] == 'M' || map[y][x] == 'C')
	    print_color("\x1b[41;37m", map[y][x]);
	  else
	    my_putchar(map[y][x]);
	  ++x;
	}
      my_putchar('\n');
      ++y;
    }
}
