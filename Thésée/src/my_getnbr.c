/*
** my_getnbr.c for lem-in in /home/kettan_s/Documents/lem-in/lib/my
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Mon Apr 28 11:34:59 2014 kettan_s
** Last update Mon Apr 28 11:35:04 2014 kettan_s
*/

int	my_getnbr(char *str)
{
  int	i;
  int	n;
  int	t;
  long	nb;

  i = 0;
  n = 1;
  t = 0;
  nb = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	n = n * -1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      t = t + (str[i] - '0');
      t = t * 10;
      i = i + 1;
    }
  nb = t / 10 * n;
  return (nb);
}
