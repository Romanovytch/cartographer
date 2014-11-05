/*
** my_dtablen.c for my_dtablen.c in /home/kettan_s/Documents/minishell/lib/my
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Jan 31 05:12:11 2014 kettan_s
** Last update Fri Jan 31 05:13:04 2014 kettan_s
*/

int	my_dtablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}
