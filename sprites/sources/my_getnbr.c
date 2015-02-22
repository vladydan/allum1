/*
** my_getnbr.c for my_get_nbr in /home/danilo_d/rendu/PSU_2014_my_printf/lib/my
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Nov 15 12:58:16 2014 Dimitri Danilov
** Last update Sun Feb 22 13:53:42 2015 danilov dimitri
*/

#include "my.h"

int	is_true(char c)
{
  if (c >= 48 && c <= '9')
      return (1);
  else
      return (0);
}

int	my_getnbr(char *str, int *pos)
{
  int	nbr;
  int	i;

  nbr = 0;
  i = *pos;
  if (*pos > my_strlen(str))
    {
      my_putstr("Bad entry\n");
      return (-1234);
    }
  while (is_true(str[i]) == 0)
      i++;
  while (is_true(str[i]) == 1)
    {
      nbr = (nbr * 10) + (str[i] - 48);
      i++;
    }
  *pos = i;
  return (nbr);
}
