/*
** dedale.h for dedale in /home/givern_f/Modules/Prog-Elem-C/cartographer/dedale/includes
** 
** Made by Florian Givernaud
** Login   <givern_f@epitech.net>
** 
** Started on  Tue Oct 28 14:40:10 2014 Florian Givernaud
** Last update Sun Nov  9 14:56:56 2014 Florian Givernaud
*/

#ifndef DEDALE_H_
# define DEDALE_H_

#define OPEN (0)
#define CLOSE (1)

int	disp_labyrinth(int **, int **, int);
int	make_labyrinth(int);
void	select_wall(int ***, int ***, int ***, int);
void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
void	my_put_nbr(int);
int	is_pair(int);
int	in_out(int);
int	is_there_wall_v(int **, int **, int, int);
int	is_there_wall_h(int **, int **, int, int);
void	open_wall_h(int ***, int ***, int, int);
void	open_wall_v(int ***, int ***, int, int);
void	open_middle(char ***, int);
void	full_laby(int ***, int, int, int);
int	init_walls(int ***, int, int);
int	init_labyrinth(int ***, int);
int	init_display(char ***, int);
void	free_labyrinth(int ***, int);
void	free_display(char ***, int);

#endif /* !DEDALE_H_ */
