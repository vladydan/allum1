/*
** allum1.c for allum1 in /home/danilo_d/semestre2/Allum1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Mon Feb  2 16:27:37 2015 Danilov Dimitri
** Last update Sat Feb 21 14:48:22 2015 danilov dimitri
*/

#include "my.h"

int	allum_1_player_text(t_struct *tool)
{
  int	ret;
  char	buffer[2048];

  while ((ret = read(0, buffer, 2047)) > 0)
    {
      if (my_strncmp("exit", buffer, 4) == 0)
	return (0);
      else
	{
	  if (click_alum_text(tool, buffer) == 1)
	    {
	      aff_alumette(tool, 2);
	      ia_to_play(tool);
	      if (who_won(tool, 2) == 0)
		return (0);
	    }
	}
      if (who_won(tool, 1) == 0)
	return (0);
      aff_alumette(tool, 1);
      my_putstr("Select the line and the number of match you wanna take : ");
    }
  return (0);
}
