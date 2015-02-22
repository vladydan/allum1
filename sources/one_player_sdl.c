/*
** allum1.c for allum1 in /home/danilo_d/semestre2/Allum1
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Mon Feb  2 16:27:37 2015 Danilov Dimitri
** Last update Sat Feb 21 18:07:30 2015 danilov dimitri
*/

#include "my.h"

int	allum_1_player(t_struct *tool)
{
  int	finish;

  finish = 1;
  while (finish)
    {
      SDL_WaitEvent(&tool->screen.event);
      if (tool->screen.event.type == SDL_QUIT)
	finish = 0;
      if (tool->screen.event.type == SDL_MOUSEBUTTONUP)
	{
	  if (click_alum(tool) == 1)
	    {
	      ia_to_play(tool);
	      if (who_won_sdl(tool, 2) == 0)
		return (0);
	    }
	}
      if (who_won_sdl(tool, 1) == 0)
	return (0);
      SDL_FillRect(tool->screen.screen, NULL,
		   SDL_MapRGB(tool->screen.screen->format, 255, 255, 255));
      aff_alumette_sdl(tool, 1);
    }
  return (0);
}
