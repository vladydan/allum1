/*
** allum1.c for allum1 in /home/danilo_d/semestre2/Allum1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Mon Feb  2 16:27:37 2015 Danilov Dimitri
** Last update Sun Feb 22 14:03:20 2015 danilov dimitri
*/

#include "my.h"

int	who_won_sdl(t_struct *tool, int player)
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
  tool->screen.pos_alumette.x = 0;
  tool->screen.pos_alumette.y = 0;
  if (player == 1)
    SDL_BlitSurface(tool->screen.win_play_2, NULL, tool->screen.screen,
		    &tool->screen.pos_alumette);
  if (player == 2)
    SDL_BlitSurface(tool->screen.win_play_1, NULL, tool->screen.screen,
		    &tool->screen.pos_alumette);
  SDL_Flip(tool->screen.screen);
  SDL_Delay(2000);
  return (0);
}

void     aff_allum(t_struct *tool)
{
  int	j;
  int	i;

  i = -1;
  tool->screen.pos_alumette.y = 10;
  while (++i != tool->param.nbr_colum)
    {
      j = -1;
      tool->screen.pos_alumette.x = 10;
      while (++j != tool->param.nbr_colum)
	{
	  if (tool->param.tab[i][j] == 1)
	    SDL_BlitSurface(tool->screen.allum, NULL, tool->screen.screen,
			    &tool->screen.pos_alumette);
	  if (tool->param.tab[i][j] == 2)
	    {
	      tool->screen.pos_alumette.x += 50;
	      SDL_BlitSurface(tool->screen.allum, NULL, tool->screen.screen,
			      &tool->screen.pos_alumette);
	      tool->screen.pos_alumette.x -= 50;
	    }
	  tool->screen.pos_alumette.x += 100;
	}
      tool->screen.pos_alumette.y += 100;
    }
}

void	aff_alumette_sdl(t_struct *tool, int player)
{
  if (player == 1)
    {
      tool->screen.pos_alumette.y = 100;
      tool->screen.pos_alumette.x = 600;
      SDL_BlitSurface(tool->screen.player1, NULL, tool->screen.screen,
		      &tool->screen.pos_alumette);
    }
  if (player == 2)
    {
      tool->screen.pos_alumette.y = 100;
      tool->screen.pos_alumette.x = 600;
      SDL_BlitSurface(tool->screen.player2, NULL, tool->screen.screen,
		      &tool->screen.pos_alumette);
    }
  tool->screen.pos_alumette.y = 100;
  tool->screen.pos_alumette.x = 800;
  SDL_BlitSurface(tool->screen.menu, NULL, tool->screen.screen,
  		  &tool->screen.pos_alumette);
  aff_allum(tool);
  SDL_Flip(tool->screen.screen);
}

int	allum_2_player(t_struct *tool)
{
  int	finish;
  int	finish_round;
  int	player;

  player = 1;
  finish = 1;
  map_creator(tool);
  aff_alumette(tool, player);
  while (finish)
    {
      SDL_WaitEvent(&tool->screen.event);
      if (tool->screen.event.type == SDL_QUIT)
	finish = 0;
      if (tool->screen.event.type == SDL_MOUSEBUTTONUP)
	finish_round = click_alum(tool);
      if (finish_round == 1)
	player = (player == 1) ? 2 : 1;
      finish_round = 0;
      if (who_won_sdl(tool, player) == 0)
	return (0);
      SDL_FillRect(tool->screen.screen, NULL,
		   SDL_MapRGB(tool->screen.screen->format, 255, 255, 255));
      aff_alumette_sdl(tool, player);
    }
  return (0);
}
