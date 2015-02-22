/*
** func_ia.c for func_ioa in /home/danilo_d/semestre2/CPE_2014_allum1
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Fri Feb 13 12:29:19 2015 danilov dimitri
** Last update Sun Feb 22 13:50:02 2015 danilov dimitri
*/

#include "my.h"

int	count_alum(char *line, int size_line)
{
  int	i;
  int	nbr_alum;

  nbr_alum = 0;
  i = 0;
  while (i != size_line)
    {
      if (line[i] == 1 || line[i] == 2)
	nbr_alum++;
      i++;
    }
  return (nbr_alum);
}

int	find_in_pow2(int nbr)
{
  int	pow_2[4];
  int	i;

  pow_2[0] = 1;
  pow_2[1] = 2;
  pow_2[2] = 4;
  pow_2[3] = 8;
  i = 3;
  while (pow_2[i] > nbr)
    i--;
  return (pow_2[i]);
}

int	somme(int *nbr, int size)
{
  int	i;
  int	somme;

  somme = 0;
  i = 0;
  while (i != size)
    {
      somme += nbr[i];
      i++;
    }
  return (somme);
}

int	*power_alum(char *line, int size_line)
{
  int	*nbr;
  int	nbr_alum;
  int	tmp;
  int	ok;
  int	i;

  i = -1;
  nbr = xmalloc(sizeof(int) * 10);
  ok = 1;
  nbr_alum = count_alum(line, size_line);
  tmp = nbr_alum;
  while (ok != 0)
    {
      nbr[++i] = find_in_pow2(nbr_alum);
      nbr_alum -= nbr[i];
      if (somme(nbr, i) == tmp)
	{
	  nbr[++i] = 1234;
	  ok = 0;
	}
    }
  return (nbr);
}
