/*
** main.c for main in /home/danilo_d/semestre2/Allum1
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Mon Feb  2 10:52:36 2015 Danilov Dimitri
** Last update Sat Feb 21 18:48:24 2015 danilov dimitri
*/

#include "my.h"

void		help()
{
  my_putstr("Welcome to the Nim Game ! \n");
  my_putstr("-gui to play in graphic mod\n");
  my_putstr("-match(1-10) to select the higest amount of match in a line\n");
  my_putstr("-pvp to play against an other player\n");
  my_putstr("exemple: \n");
  my_putstr("<<./allum1 -gui -pvp -match5>> to play in gui mode against a");
  my_putstr(" player with 5 match in the lowest line\n");
}

int		parse_var(int argc, char **argv, int *gui, int *pvp)
{
  int		i;
  int		nbr_allum;

  nbr_allum = 7;
  i = 0;
  while (++i != argc)
    {
      if (my_strncmp("-gui", argv[i], 4) == 0)
	*gui = 1;
      if (my_strncmp("-pvp", argv[i], 4) == 0)
	*pvp = 2;
      if (my_strncmp("--help", argv[i], 6) == 0)
	help();
      if (my_strncmp("-match", argv[i], 6) == 0)
	{
	  nbr_allum = my_strlen(argv[i]) - 4;
	  nbr_allum = my_getnbr(argv[i], &nbr_allum);
	}
    }
  return (nbr_allum);
}

int		main(int argc, char **argv, char **env)
{
  int		gui;
  int		pvp;
  int		nbr_allum;

  if (env[0] == NULL)
    return (0);
  pvp = 1;
  gui = 0;
  if (argc > 4)
    {
      my_putstr("Usage : ./allum1 [-gui] [-pvp] [-match(1-10)]\n");
      return (0);
    }
  my_putstr("type --help to see all available options\n");
  nbr_allum = parse_var(argc, argv, &gui, &pvp);
  if (gui == 1)
    sdl_version(nbr_allum, pvp);
  else
    text_version(nbr_allum, pvp);
  return (0);
}

int		text_version(int nbr_allum, int pvp)
{
  t_struct	*tool;

  tool = xmalloc(sizeof(*tool));
  if ((tool->param.nbr_colum = nbr_allum) > 15 || nbr_allum == 0)
    {
      my_putstr("Maximum size of alum is 15\n");
      return (0);
    }
  tool->param.player = pvp;
  init_tab(tool);
  aff_alumette(tool, 1);
  my_putstr("Select the line and the number of match you wanna take : ");
  if (tool->param.player == 2)
    allum_2_player_text(tool);
  if (tool->param.player == 1)
    allum_1_player_text(tool);
  return (EXIT_SUCCESS);
}
