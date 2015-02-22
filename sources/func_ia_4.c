/*
** func_ia_4.c for func_ia_4 in /home/danilo_d/semestre2/CPE_2014_allum1
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Fri Feb 13 13:25:28 2015 danilov dimitri
** Last update Sun Feb 22 13:49:22 2015 danilov dimitri
*/

#include "my.h"

int		analyse_next(t_exist *exist, t_struct *tool)
{
  if (how_many_colum(tool) == 1234)
    {
      delete_one_colum(tool);
      return (-1);
    }
  if (how_many_colum(tool) == 1)
    {
      delete_other(tool);
      return (-1);
    }
  if (how_many_colum(tool) == 4321)
    {
      delete_one_line(tool);
      return (-1);
    }
  if (exist->eight % 2 != 0)
    return (8);
  if (exist->four % 2 != 0)
    return (4);
  if (exist->two % 2 != 0)
    return (2);
  if (exist->one % 2 != 0)
    return (1);
  return (0);
}

void		init_exist(t_exist *exist, int *i)
{
  exist->one = 0;
  exist->two = 0;
  exist->four = 0;
  exist->eight = 0;
  *i = 0;
}

int		analyse_tab(t_struct *tool, int **inf_tab)
{
  t_exist	*exist;
  int		i;
  int		j;
  int		ret;

  exist = xmalloc(sizeof(*exist));
  init_exist(exist, &i);
  while (i != tool->param.nbr_colum)
    {
      j = -1;
      while (inf_tab[i][++j] != 1234)
	{
	  if (inf_tab[i][j] == 1)
	    exist->one++;
	  else if (inf_tab[i][j] == 2)
	    exist->two++;
	  else if (inf_tab[i][j] == 4)
	    exist->four++;
	  else if (inf_tab[i][j] == 8)
	    exist->eight++;
	}
      i++;
    }
  ret = analyse_next(exist, tool);
  return (ret);
}

int		delete_one(t_struct *tool)
{
  int		i;
  int		j;

  i = -1;
  while (++i != tool->param.nbr_colum)
    {
      j = -1;
      while (++j != tool->param.nbr_colum)
	if (tool->param.tab[i][j] != 0)
	  {
	    tool->param.tab[i][j] = 0;
	    return (0);
	  }
    }
  return (0);
}
