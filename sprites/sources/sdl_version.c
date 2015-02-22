/*
** main.c for main in /home/danilo_d/semestre2/Allum1
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Mon Feb  2 10:52:36 2015 Danilov Dimitri
** Last update Sun Feb 22 14:01:47 2015 danilov dimitri
*/

#include "my.h"

void		init_sprites(t_struct *tool)
{
  tool->screen.allum = SDL_LoadBMP("sprites/allumette.bmp");
  tool->screen.menu = SDL_LoadBMP("sprites/button_next.bmp");
  tool->screen.player1 = SDL_LoadBMP("sprites/player1.bmp");
  tool->screen.player2 = SDL_LoadBMP("sprites/player2.bmp");
  tool->screen.win_play_1 = SDL_LoadBMP("sprites/win_play_1.bmp");
  tool->screen.win_play_2 = SDL_LoadBMP("sprites/win_play_2.bmp");
  tool->screen.lose = SDL_LoadBMP("sprites/lose.bmp");
  map_creator(tool);
}

int		sdl_version(int nbr_allum, int pvp)
{
  t_struct	*tool;

  tool = xmalloc(sizeof(*tool));
  if (((tool->param.nbr_colum = nbr_allum) > 10) || nbr_allum == 0)
    {
      my_putstr("Maximum size is 10\n");
      return (0);
    }
  SDL_Init(SDL_INIT_VIDEO);
  tool->screen.screen = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE);
  tool->param.player = pvp;
  init_tab(tool);
  init_sprites(tool);
  SDL_FillRect(tool->screen.screen, NULL,
	       SDL_MapRGB(tool->screen.screen->format, 255, 255, 255));
  if (tool->param.player == 2)
    allum_2_player(tool);
  if (tool->param.player == 1)
    {
      tool->screen.win_play_1 = SDL_LoadBMP("sprites/win.bmp");
      tool->screen.win_play_2 = SDL_LoadBMP("sprites/lose.bmp");
      allum_1_player(tool);
    }
  SDL_Quit();
  return (EXIT_SUCCESS);
}
