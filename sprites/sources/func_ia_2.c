/*
** func_ia_2.c for func_ia_2 in /home/danilo_d/semestre2/CPE_2014_allum1
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Fri Feb 13 12:32:29 2015 danilov dimitri
** Last update Sun Feb 22 13:47:42 2015 danilov dimitri
*/

#include "my.h"

void	init_colum(t_colum *colum)
{
  colum->three = 0;
  colum->two = 0;
  colum->one = 0;
  colum->i = -1;
  colum->colum = 0;
}

int	how_many_colum(t_struct *tool)
{
  t_colum colum;

  init_colum(&colum);
  while (++colum.i != tool->param.nbr_colum)
    {
      colum.tmp = 0;
      colum.j = -1;
      while (++colum.j != tool->param.nbr_colum)
	if (tool->param.tab[colum.i][colum.j] != 0)
	  colum.tmp++;
      if (colum.tmp != 0)
	colum.colum++;
      if (colum.tmp == 1 && colum.two == 1)
	colum.three = 1;
      if (colum.tmp == 1 && colum.one == 1)
	colum.two = 1;
      if (colum.tmp == 1)
	colum.one = 1;
    }
  if (colum.one == 1 && colum.colum == 2 && colum.two != 1)
    return (1234);
  if (colum.one == 1 && colum.two == 1 && colum.colum == 3 && colum.three == 0)
    return (4321);
  return (colum.colum);
}

int	**recup_inf(t_struct *tool)
{
  int	**tab;
  int	i;

  i = 0;
  tab = xmalloc(sizeof(*tab) * tool->param.nbr_colum);
  while (i != tool->param.nbr_colum)
    {
      tab[i] = power_alum(tool->param.tab[i], tool->param.nbr_colum);
      i++;
    }
  return (tab);
}

int	delete_one_colum(t_struct *tool)
{
  int	i;
  int	j;
  int	tmp;

  i = -1;
  while (++i != tool->param.nbr_colum)
    {
      tmp = 0;
      j = -1;
      while (++j != tool->param.nbr_colum)
	if (tool->param.tab[i][j] != 0)
	  tmp++;
      if (tmp != 0 && tmp != 1)
	{
	  j = -1;
	  while (++j != tool->param.nbr_colum)
	    tool->param.tab[i][j] = 0;
	  return (1);
	}
    }
  return (0);
}

int	delete_one_colum2(t_struct *tool)
{
  int	i;
  int	j;
  int	tmp;

  i = -1;
  while (++i != tool->param.nbr_colum)
    {
      tmp = 0;
      j = -1;
      while (++j != tool->param.nbr_colum)
	if (tool->param.tab[i][j] != 0)
	  tmp++;
      if (tmp != 0)
	{
	  j = -1;
	  while (++j != tool->param.nbr_colum)
	    tool->param.tab[i][j] = 0;
	  return (1);
	}
    }
  return (0);
}
