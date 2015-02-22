/*
** ia.c for ia in /home/danilo_d/semestre2/Allum1
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Wed Feb  4 00:19:00 2015 danilov dimitri
** Last update Sat Feb 21 18:51:20 2015 danilov dimitri
*/

#include "my.h"

int	delete_that_elem(int i, int what_to_delete,
			 t_struct *tool, int index_to_delete)
{
  int	j;

  j = 0;
  while (what_to_delete != 0)
    {
      if (tool->param.tab[i][j] == 1 || tool->param.tab[i][j] == 2)
	{
	  if (index_to_delete == 4321 || index_to_delete == i)
	    {
	      tool->param.tab[i][j] = 0;
	      what_to_delete--;
	      return (i);
	    }
	}
      j++;
    }
  return (0);
}

int	delete(int what_to_delete, t_struct *tool,
	       int **inf_tab, int index_to_delete)
{
  int	i;
  int	j;

  i = 0;
  while (i != tool->param.nbr_colum)
    {
      j = -1;
      while (inf_tab[i][++j] != 0)
	{
	  if (inf_tab[i][j] == what_to_delete)
	    {
	      if (index_to_delete == i || index_to_delete == 4321)
		{
		  index_to_delete = delete_that_elem
		    (i, what_to_delete, tool, index_to_delete);
		  inf_tab[i] = power_alum(tool->param.tab[i], tool->param.nbr_colum);
		  return (index_to_delete);
		}
	    }
	}
      i++;
    }
  return (4321);
}

void		init_var(t_ia *ia)
{
  ia->i = 0;
  ia->index_to_delete = 4321;
  ia->what_to_delete = 1;
  ia->first_play = 0;
}

int		ia_to_play(t_struct *tool)
{
  int		**inf_tab;
  t_ia		ia;

  init_var(&ia);
  inf_tab = recup_inf(tool);
  while (ia.what_to_delete != 0)
    {
      ia.what_to_delete = analyse_tab(tool, inf_tab);
      if (ia.what_to_delete == 0 && ia.first_play == 0)
	{
	  ia.what_to_delete = 1;
	  delete_one(tool);
	  return (0);
	}
      if (ia.what_to_delete == 0  || ia.what_to_delete == -1)
	  return (0);
      ia.index_to_delete = delete(ia.what_to_delete, tool,
				  inf_tab, ia.index_to_delete);
      ia.i++;
      ia.first_play++;
    }
  return (0);
}
