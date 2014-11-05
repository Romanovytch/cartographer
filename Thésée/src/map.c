/*
** map.c for thesee in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Oct 21 13:37:49 2014 kettan_s
** Last update Fri Oct 24 09:00:45 2014 kettan_s
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

void	print_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    {
      my_putstr(map[i]);
      my_putchar('\n');
      ++i;
    }
}
