/*
** my_put_nbr.c for my_put_nbr in /home/givern_f/Modules/Prog-Elem-C/blackjack
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Wed Oct  1 09:17:32 2014 Florian Givernaud
** Last update Tue Oct 28 15:40:09 2014 Florian Givernaud
*/

#include "../../includes/dedale.h"

void	my_put_nbr(int nb)
{
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          neg = 1;
          nb++;
        }
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
}
