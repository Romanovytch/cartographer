/*
** dedale.h for dedale in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale/includes
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 14:40:10 2014 Florian Givernaud
** Last update Tue Nov  4 09:16:10 2014 Florian Givernaud
*/

#ifndef DEDALE_H_
# define DEDALE_H_

#define OPEN (0)
#define CLOSE (1)

void	disp_labyrinth(int **, int **, int);
void	make_labyrinth(int);
void	select_wall(int ***, int ***, int ***, int);
void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
void	my_put_nbr(int);
int	in_out(int **, int);

#endif /* !DEDALE_H_ */
