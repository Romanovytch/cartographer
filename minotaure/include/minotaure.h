/*
** minotaure.h for minotaure in /home/kettan_s/Documents/cartographer/minotaure
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Sat Nov  8 13:59:05 2014 kettan_s
** Last update Sun Nov  9 01:07:50 2014 kettan_s
*/

#ifndef MINOTAURE_H_
# define MINOTAURE_H_

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

/*
**			Lib
*/

void			my_putchar(char);
void			my_putstr(char *);
void			my_putnbr_base(int, char *);
int			my_strlen(char *);
int			my_strcmp(char *, char *);
char			*my_strdup(char *);
char			*get_next_line(const int);

/*
**			minotaure.c
*/

void			minotaure(char *);

/*
**			map.c
*/

char			**fill_map(char *);
void			print_map(char **);

/*
**			pos.c
*/

t_pos			get_pos_exit(char **);
t_pos			get_pos_center(char **);
t_pos			get_pos_t(char **);
t_pos			new_pos(int, int);

/*
**			pathfinding.c
*/

int			pathfinding(char ***, t_pos, t_pos, char);

#endif /* !MINOTAURE_H_ */
