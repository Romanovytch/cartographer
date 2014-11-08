/*
** my_putnbr_base.c for my_putnbr_base in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Mon Sep 29 16:40:02 2014 kettan_s
** Last update Tue Oct 21 13:25:30 2014 kettan_s
*/

#include "thesee.h"

void	my_putnbr_base(int n, char *b)
{
  if (n < 0)
    my_putchar('-');
  if (n > my_strlen(b) - 1)
    my_putnbr_base(n / my_strlen(b), b);
  my_putchar(b[n % my_strlen(b)]);
}
