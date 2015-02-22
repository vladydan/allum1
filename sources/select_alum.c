/*
** map_creator.c for map_creator in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Tue Dec 23 13:40:32 2014 Danilov Dimitri
** Last update Sat Feb 21 18:19:03 2015 danilov dimitri
*/

#include "my.h"

void	fill_tab(t_struct *tool)
{
  int	i;
  int	j;

  i = 0;
  while (i != HEIGHT)
    {
      j = 0;
      while (j != HEIGHT)
	{
	  tool->tab_pos[i][j].x = 0;
	  tool->tab_pos[i][j].y = 0;
	  j++;
	}
      i++;
    }
}

void    put_big_square(t_struct *tool, t_mini_map map);

void	create_map(t_struct *tool)
{
  t_mini_map	*map;

  map = xmalloc(sizeof(*map));
  map->i = 0;
  map->coord_x = 10;
  while (map->i != tool->param.nbr_colum)
    {
      map->j = 0;
      map->coord_y = 10;
      while (map->j != tool->param.nbr_colum)
	{
	  if (tool->param.tab[map->i][map->j] == 2)
	    put_big_square(tool, *map);
	  if (tool->param.tab[map->i][map->j] == 0)
	    put_big_square(tool, *map);
	  if (tool->param.tab[map->i][map->j] == 1)
	    put_big_square(tool, *map);
	  map->j++;
	  map->coord_y += 100;
	}
      map->coord_x += 100;
      map->i++;
    }
}

void	put_big_square(t_struct *tool, t_mini_map map)
{
  int   i;
  int   j;
  int   tmp;

  tmp = map.coord_y;
  j = -1;
  while (++j != 100)
    {
      i = 0;
      map.coord_y = tmp;
      while (i != 100)
	{
	  tool->tab_pos[map.coord_y][map.coord_x].x = map.i;
	  tool->tab_pos[map.coord_y][map.coord_x].y = map.j;
	  map.coord_y++;
	  i++;
	}
      map.coord_x++;
    }
}

void		map_creator(t_struct *tool)
{
  int		i;

  i = 0;
  tool->tab_pos = xmalloc(sizeof(*tool->tab_pos) * HEIGHT * 2);
  while (i != LENGHT * 2)
    {
      tool->tab_pos[i] = xmalloc(sizeof(**tool->tab_pos) * HEIGHT);
      i++;
    }
  fill_tab(tool);
  create_map(tool);
}
