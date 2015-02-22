/*
** gere_click.c for gere_click in /home/danilo_d/semestre2/Allum1
** 
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Feb  3 13:02:05 2015 danilov dimitri
** Last update Sat Feb 21 18:37:55 2015 danilov dimitri
*/

#include "my.h"

int		error(t_struct *tool, int x, int y)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (x >= tool->param.nbr_colum)
    {
      my_putstr("line incorrect\n");
      return (-1);
    }
  while (j != tool->param.nbr_colum)
    {
      if (tool->param.tab[x][j] == 1 || tool->param.tab[x][j] == 2)
	i++;
      j++;
    }
  if (i <= y)
    {
      my_putstr("match missing\n");
      return (-1);
    }
  return (0);
}

void		init_coord(int *y, int *x, int *getnbr, char buffer[2048])
{
  *getnbr = 0;
  *x = my_getnbr(buffer, getnbr);
  *y = my_getnbr(buffer, getnbr);
}

int		click_alum_text(t_struct *tool, char buffer[2048])
{
  int		x;
  int		y;
  int		getnbr;
  int		i;

  i = 0;
  init_coord(&y, &x, &getnbr, buffer);
  if (x <= 0 || y <= 0)
    {
      my_putstr("The arguments must be positif\n");
      return (0);
    }
  if (error(tool, x - 1, y - 1) == -1)
    return (0);
  while (y != 0)
    {
      if (tool->param.tab[x - 1][i] == 1 || tool->param.tab[x - 1][i] == 2)
	{
	  tool->param.tab[x - 1][i] = 0;
	  y--;
	}
      i++;
    }
  return (1);
}
