/*
** my_putnbr.c for my_putnbr.c in /home/danilo_d/rendu/PSU_2014_my_printf/lib/my
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Nov 12 14:24:35 2014 Dimitri Danilov
** Last update Wed Feb 18 16:58:28 2015 danilov dimitri
*/

#include "my.h"

int	my_putnbr(int nb)
{
  int	i;
  int	divis;
  int	ret;

  ret = 0;
  if (nb < 0)
    {
      ret = ret + my_putchar('-');
      nb = -nb;
    }
  divis = 1;
  while ((nb / divis) > 9)
    divis = divis *10;
  while (divis > 0)
    {
      i = (nb /divis) % 10;
      ret = ret + my_putchar('0' + i);
      divis = divis / 10;
    }
  return (ret);
}
