/*
** my_strlen.c for my_strlen in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Mon Sep 29 16:42:01 2014 kettan_s
** Last update Mon Sep 29 16:42:41 2014 kettan_s
*/

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    ++i;
  return (i);
}
