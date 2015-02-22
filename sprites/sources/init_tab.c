/*
** init_tab.c for init_tab in /home/danilo_d/semestre2/Allum1
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Mon Feb  2 12:23:39 2015 Danilov Dimitri
** Last update Sat Feb 21 18:20:37 2015 danilov dimitri
*/

#include "my.h"

void	put_zero(t_struct *tool, int allu_to_print, int line)
{
  int	i;
  int	j;

  i = -1;
  while (++i != allu_to_print)
    {
      j = -1;
      while (++j <= allu_to_print)
	{
	  if ((tool->param.tab[i][j] != 1 &&
	       tool->param.tab[i][j] != 2) || i < line)
	    tool->param.tab[i][j] = 0;
	}
    }
}

int	init_tab2(t_struct *tool, int allu_to_print, int j, int i)
{
  int	e;
  int	ret;

  ret = 0;
  while (allu_to_print >= 1)
    {
      e = -1;
      j = -1 + ret;
      while (++e < allu_to_print + 1)
	tool->param.tab[i][++j] = 1;
      tool->param.tab[i][j] = 0;
      allu_to_print = allu_to_print - 2;
      ret ++;
      i--;
    }
  i++;
  j = ret - 1;
  if (allu_to_print == 0)
    {
      tool->param.tab[--i][j] = 2;
      tool->param.tab[i][++j] = 0;
    }
  return (i);
}

void	init_tab(t_struct *tool)
{
  int	i;
  int	allu_to_print;
  int	j;

  j = -1;
  allu_to_print = tool->param.nbr_colum;
  i = tool->param.nbr_colum - 1;
  tool->param.tab = xmalloc(sizeof(*tool->param.tab) *
			    tool->param.nbr_colum + 10);
  while (++j != allu_to_print)
      tool->param.tab[j] = xmalloc(sizeof(**tool->param.tab) *
				   tool->param.nbr_colum + 10);
  i = init_tab2(tool, allu_to_print, j, i);
  put_zero(tool, tool->param.nbr_colum, i);
}
