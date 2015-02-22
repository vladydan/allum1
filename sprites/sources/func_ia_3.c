/*
** func_ia_3.c for func_ia_3 in /home/danilo_d/semestre2/CPE_2014_allum1
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Fri Feb 13 12:44:34 2015 danilov dimitri
** Last update Sun Feb 22 13:48:35 2015 danilov dimitri
*/

#include "my.h"

void	what_to_delete(int nbr_allum, t_struct *tool, int *j, int i)
{
  if (nbr_allum == 1)
    {
      while (nbr_allum != 0)
	{
	  if (tool->param.tab[i][*j] == 1 || tool->param.tab[i][*j] == 2)
	    {
	      tool->param.tab[i][*j] = 0;
	      nbr_allum--;
	    }
	  *j += 1;
	}
    }
  else
    {
      while (nbr_allum != 1)
	{
	  if (tool->param.tab[i][*j] == 1 || tool->param.tab[i][*j] == 2)
	    {
	      tool->param.tab[i][*j] = 0;
	      nbr_allum--;
	    }
	  *j += 1;
	}
    }
}

int	delete_one_line(t_struct *tool)
{
  int	i;
  int	j;
  int	tmp;
  int	nbr_allum;

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
	  j  = -1;
	  nbr_allum = count_alum(tool->param.tab[i], tool->param.nbr_colum);
	  what_to_delete(nbr_allum, tool , &j, i);
	}
    }
  return (0);
}

void	delete_a_lot_of_allum(t_struct *tool, int nbr_allum, int *j, int i)
{
  if (nbr_allum == 1)
    {
      while (nbr_allum != 0)
	{
	  if (tool->param.tab[i][*j] == 1 || tool->param.tab[i][*j] == 2)
	    {
	      tool->param.tab[i][*j] = 0;
	      nbr_allum--;
	    }
	  *j += 1;
	}
    }
  else
    {
      while (nbr_allum != 1)
	{
	  if (tool->param.tab[i][*j] == 1 || tool->param.tab[i][*j] == 2)
	    {
	      tool->param.tab[i][*j] = 0;
	      nbr_allum--;
	    }
	  *j += 1;
	}
    }
}

int	delete_other(t_struct *tool)
{
  int	i;
  int	j;
  int	tmp;
  int	nbr_allum;

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
	  j  = -1;
	  nbr_allum = count_alum(tool->param.tab[i], tool->param.nbr_colum);
	  delete_a_lot_of_allum(tool, nbr_allum, &j, i);
	}
    }
  return (0);
}
