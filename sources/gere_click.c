/*
** gere_click.c for gere_click in /home/danilo_d/semestre2/Allum1
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Tue Feb  3 13:02:05 2015 danilov dimitri
** Last update Sat Feb 21 18:49:56 2015 danilov dimitri
*/

#include "my.h"

int		take_off_one(t_struct *tool, int x, int y, int i)
{
  if (tool->param.tab[tool->tab_pos[x][y].x]
      [tool->tab_pos[x][y].y] == 1 ||
      tool->param.tab[tool->tab_pos[x][y].x]
      [tool->tab_pos[x][y].y] == 2)
    {
      if (i == tool->tab_pos[x][y].x)
	{
	  tool->param.tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] = 0;
	  return (1);
	}
    }
  return (0);
}

int		alum_or_not(t_struct *tool, int *i)
{
  int		j;

  j = 0;
  while (j != tool->param.nbr_colum)
    {
      if (tool->param.tab[*i][j] == 1 || tool->param.tab[*i][j] == 2)
	return (1);
      j++;
    }
  *i = 0;
  return (0);
}

int		click_alum(t_struct *tool)
{
  int		x;
  int		y;
  static int	i;
  static int	first_round;
  static int	take_off;

  x = tool->screen.event.button.x;
  y = tool->screen.event.button.y;
  if (i == 0)
    i = tool->tab_pos[x][y].x;
  if (alum_or_not(tool, &i) == 1)
    take_off += take_off_one(tool , x, y, i);
  if (x > 795 && x < 900 && y > 100 && y < 202 &&
	   (first_round == 0 || take_off > 0))
    {
      take_off = 0;
      first_round++;
      i = 0;
      return (1);
    }
  return (0);
}
