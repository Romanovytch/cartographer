/*
** my_putchar.c for my_putchar in /home/kettan_s/Documents/Magic21/src
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Fri Sep 26 13:06:00 2014 kettan_s
** Last update Fri Sep 26 13:11:05 2014 kettan_s
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
