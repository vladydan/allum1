/*
** my.h for header in /home/danilo_d/rendu/PSU_2014_my_select
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Thu Jan  8 23:18:31 2015 Danilov Dimitri
** Last update Sun Feb 22 13:40:07 2015 danilov dimitri
*/

#ifndef MY_H_
# define MY_H_
# define LENGHT 1000
# define HEIGHT 1000

# include <stdlib.h>
# include <unistd.h>
# include <SDL/SDL.h>

typedef struct	s_ia
{
  int		what_to_delete;
  int		i;
  int		index_to_delete;
  int		first_play;
}		t_ia;

typedef struct	s_colum
{
  int		i;
  int		j;
  int		colum;
  int		tmp;
  int		one;
  int		two;
  int		three;
}		t_colum;

typedef struct	s_param
{
  int		player;
  int		nbr_colum;
  char		**tab;
}		t_param;

typedef struct	s_exist
{
  int		one;
  int		two;
  int		four;
  int		eight;
}		t_exist;

typedef struct  s_mini_map
{
  int		i;
  int		j;
  int		coord_x;
  int		coord_y;
}		t_mini_map;

typedef struct	s_screen
{
  SDL_Event	event;
  SDL_Surface	*screen;
  SDL_Surface	*player1;
  SDL_Surface	*player2;
  SDL_Surface	*win_play_1;
  SDL_Surface	*menu;
  SDL_Surface	*win_play_2;
  SDL_Surface	*lose;
  SDL_Surface	*win;
  SDL_Rect	position;
  SDL_Rect	pos_mouse;
  SDL_Surface	*allum;
  SDL_Rect	pos_alumette;
}		t_screen;

typedef struct	s_position
{
  int		x;
  int		y;
}		t_position;

typedef struct	s_struct
{
  t_param	param;
  t_screen	screen;
  t_position	**tab_pos;
}		t_struct;

char		*my_strdup(char *src);
int		my_putchar(int c);
int		my_putstr(char *str);
int		my_strlen(char *str);
char		*my_strcpy(char *dest, char *src);
void		*xmalloc(int nbr);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcat(char *dest, char *src);
char		*my_strdup(char *src);
char		*my_strndup(char *src, int size);
char		*my_strdup_mod(char *src, int lenght);
char		**recup_argv(char *line, char c);
int		my_getnbr(char *str, int *);
void		init_tab(t_struct *tool);
int		allum_2_player(t_struct *tool);
int		click_alum(t_struct *tool);
void		map_creator(t_struct *tool);
int		allum_1_player(t_struct *tool);
int		ia_to_play(t_struct *tool);
void		aff_alumette(t_struct *tool, int);
int		who_won(t_struct *tool, int player);
void		init_var(t_ia *ia);
int		delete_one(t_struct *tool);
int		analyse_tab(t_struct *tool, int **inf_tab);
int		**recup_inf(t_struct *tool);
int		*power_alum(char *line, int size_line);
int		my_putnbr(int nb);
int		delete_one_line(t_struct *tool);
int		delete_other(t_struct *tool);
int		delete_one_colum(t_struct *tool);
int		analyse_next(t_exist *exist, t_struct *tool);
int		how_many_colum(t_struct *tool);
int		count_alum(char *line, int size_line);
int		sdl_version(int nbr_allum, int pvp);
int		click_alum_text(t_struct *tool, char buffer[2048]);
int		sdl_version(int nbr_allum, int pvp);
int		text_version(int nbr_allum, int pvp);
void		aff_alumette(t_struct *tool, int player);
void		aff_alumette_sdl(t_struct *tool, int player);
int		who_won_sdl(t_struct *tool, int player);
int		allum_2_player_text(t_struct *tool);
int		allum_1_player_text(t_struct *tool);
void		put_big_square(t_struct *tool, t_mini_map map);

#endif  /* !MY_H_ */
