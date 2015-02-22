/*
** allum1.c for allum1 in /home/danilo_d/semestre2/Allum1
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Mon Feb  2 16:27:37 2015 Danilov Dimitri
** Last update Sun Feb 22 13:46:00 2015 danilov dimitri
*/

#include "my.h"

int	who_won(t_struct *tool, int player)
{
  int	i;
  int	j;

  i = -1;
  while (++i != tool->param.nbr_colum)
    {
      j = -1;
      while (++j != tool->param.nbr_colum)
	{
	  if (tool->param.tab[i][j] == 1 || tool->param.tab[i][j] == 2)
	    return (1);
	}
    }
  if (player == 1)
    my_putstr("Player 1 won\n");
  if (player == 2)
    my_putstr("Player 2 won\n");
   return (0);
}

int	check_line(t_struct *tool, int i)
{
  int	j;

  j = -1;
  while (++j != tool->param.nbr_colum)
    {
      if (tool->param.tab[i][j] == 1 || tool->param.tab[i][j] == 2)
	return (1);
    }
  return (-1);
}

void	aff_alumette(t_struct *tool, int player)
{
  int	i;
  int	j;

  if (player == 1)
    my_putstr("Player 1 turn\n");
  if (player == 2)
    my_putstr("Player 2 turn\n");
  i = -1;
  while (++i != tool->param.nbr_colum)
    {
      if (check_line(tool, i) == 1)
	{
	  j = -1;
	  my_putnbr(i + 1);
	  my_putstr("  ");
	  while (++j != tool->param.nbr_colum)
	    {
	      if (tool->param.tab[i][j] == 1 || tool->param.tab[i][j] == 2)
		my_putchar('|');
	      else
		my_putchar(' ');
	    }
	  my_putchar('\n');
	}
    }
}

int	allum_2_player_text(t_struct *tool)
{
  int	finish_round;
  char	buffer[2048];
  int	ret;
  int	player;

  player = 1;
  while ((ret = read(0, buffer ,2047)) > 0)
    {
      buffer[ret] = 0;
      if (my_strncmp("exit", buffer, 4) == 0)
	return (0);
      finish_round = click_alum_text(tool, buffer);
      if (finish_round == 1)
	player = (player == 1) ? 2 : 1;
      finish_round = 0;
      if (who_won(tool, player) == 0)
	return (0);
      aff_alumette(tool, player);
      my_putstr("Select the line and the number of match you wanna take : ");
    }
  return (0);
}
