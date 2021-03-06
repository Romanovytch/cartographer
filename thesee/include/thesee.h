/*
** thesee.h for Thésée in 
** 
** Made by kettan_s
** Login   <kettan_s@epitech.net>
** 
** Started on  Tue Oct 21 13:24:11 2014 kettan_s
** Last update Sun Nov  9 17:37:46 2014 kettan_s
*/

#ifndef THESEE_H_
# define THESEE_H_

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_node
{
  int			f;
  int			g;
  int			h;
  t_pos			pos;
  struct s_node		*parent;
  struct s_node		*next;
}			t_node;

typedef struct		s_list
{
  t_node		*open;
  t_node		*close;
}			t_list;

/*
**			Lib
*/

void			my_putchar(char);
void			my_putstr(char *);
void			my_putnbr_base(int, char *);
int			my_strlen(char *);
int			my_strcmp(char *, char *);
int			my_getnbr(char *);
int			my_dtablen(char **);
char			*my_strdup(char *);
char			*my_strcat(char *, char *);
char			*get_next_line(const int);
char			**create_word_tab(char *);

/*
**			thesee.c
*/

void			thesee(char *);

/*
**			map.c
*/

char			**fill_map(char *);
void			print_map(char **);
void			empty_map(char **);

/*
**			pos.c
*/

t_pos			get_pos_exit(char **);
t_pos			get_pos_center(char **);
t_pos			new_pos(int, int);

/*
**			pathfinding.c
*/

int			pathfinding(char ***, t_pos, int, int);

/*
**			node.c
*/

t_node			*create_node(t_node *, int, t_pos, t_pos);
t_node			*update_node(t_node *, t_node *);
t_node			*get_min_f(t_node *);
void			disp_nodes(t_node *);

/*
**			push.c
*/

t_node			*push_front(t_node *, t_node *);
t_node			*push_back(t_node *, t_node *);
t_node			*add_open(t_node *, t_node *);

/*
**			pop.c
*/

t_node			*pop_front(t_node *);
t_node			*pop_back(t_node *);
t_node			*pop_pos(t_node *, t_pos);

/*
**			heuristic.c
*/

int			heuristic(t_pos, t_pos);

#endif /* !THESEE_H_ */
