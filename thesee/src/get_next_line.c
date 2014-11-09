/*
** get_next_line.c for get_next_line in /home/kettan_s/Documents/Epitech/get_next_line
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Sat Nov 23 16:41:16 2013 kettan_s
** Last update Sun Nov  9 15:00:00 2014 Florian Givernaud
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void		*my_memcpy(void *dest, void *src, int taille)
{
  int		i;
  char		*tdst;
  char		*tsrc;

  i = 0;
  tdst = dest;
  tsrc = src;
  if (!dest || !src)
    return (dest);
  while (i < taille)
    {
      *tdst = *tsrc;
      tdst = tdst + 1;
      tsrc = tsrc + 1;
      i = i + 1;
    }
  return (dest);
}

void		*my_realloc(void *ptr, size_t taille)
{
  void		*nv_ptr;

  if (ptr == NULL)
    return (malloc(taille));
  if (taille < 1)
    return (ptr);
  nv_ptr = malloc(taille);
  my_memcpy(nv_ptr, ptr, taille);
  free(ptr);
  return (nv_ptr);
}

int		get_cat(const int fd, char *c)
{
  static int	i = 0;
  static char	buff[READ_SIZE];
  static int	nb_r = READ_SIZE;

  if (i >= nb_r || i == 0)
    {
      i = 0;
      if ((nb_r = read(fd, buff, READ_SIZE)) < 0)
        return (0);
    }
  if (nb_r == 0)
    {
      *c = '\0';
      i = -1;
    }
  else
    if (buff[i] == '\n')
      *c = '\0';
    else
      *c = buff[i];
  i = i + 1;
  return (nb_r);
}

char		*get_next_line(const int fd)
{
  char		*next_line;
  int		i;
  int		nb_r;

  i = 0;
  next_line = malloc((READ_SIZE) * sizeof(*next_line));
  if (next_line == NULL)
    return (NULL);
  nb_r = get_cat(fd, &next_line[i]);
  if (nb_r == 0)
    return (NULL);
  while (next_line[i])
    {
      i = i + 1;
      if (i % READ_SIZE == 0)
        next_line = my_realloc(next_line, READ_SIZE + i);
      nb_r = get_cat(fd, &next_line[i]);
    }
  return (next_line);
}
