/*
** create_word_tab.c for create_word_tab in /home/kettan_s/rendu/Piscine-rattrapage-Jour_05PM/ex_01
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Dec 20 17:53:05 2013 kettan_s
** Last update Wed Oct 22 12:42:11 2014 kettan_s
*/

#include <stdlib.h>

char	*my_strncpy(char *dst, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] >= 0 && i < n)
    {
      dst[i] = src[i];
      i = i + 1;
    }
  return (dst);
}

int	is_wrd(char c)
{
  if (c == 'X' || c == ' ')
    return (1);
  else
    return (0);
}

int	my_countwrd(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i])
    {
      if (j == 0 && is_wrd(str[i]))
	j = j + 1;
      else if (!is_wrd(str[i]) && is_wrd(str[i + 1]))
	j = j + 1;
      i = i + 1;
    }
  return (j);
}

int	my_nxt_wrdlen(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (is_wrd(str[i]))
	j = j + 1;
      else if (j != 0)
	return (j);
      i = i + 1;
    }
  return (j);
}

char	**create_word_tab(char *str)
{
  char	**wrd_tab;
  int	nb_wrd;
  int	i;

  i = 0;
  nb_wrd = my_countwrd(str);
  wrd_tab = malloc((nb_wrd + 1) * sizeof(char *));
  if (wrd_tab == NULL)
    return (NULL);
  while (i < nb_wrd)
    {
      while (*str && !is_wrd(*str))
	str = str + 1;
      wrd_tab[i] = malloc(sizeof(char) * (my_nxt_wrdlen(str) + 1));
      my_strncpy(wrd_tab[i], str, my_nxt_wrdlen(str));
      str = str + my_nxt_wrdlen(str);
      i = i + 1;
    }
  wrd_tab[i] = NULL;
  return (wrd_tab);
}
