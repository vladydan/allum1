##
## Makefile for makefile in /home/danilo_d/rendu/PSU_2014_my_printf
## 
## Made by Dimitri Danilov
## Login   <danilo_d@epitech.net>
## 
## Started on  Sat Nov 15 13:07:25 2014 Dimitri Danilov
## Last update Sun Feb 22 14:11:47 2015 danilov dimitri
##

NAME	= allum1

SRCS	= sources/main.c \
	  sources/func_ia.c \
	  sources/func_ia_2.c \
	  sources/func_ia_3.c \
	  sources/func_ia_4.c \
	  sources/one_player_sdl.c \
	  sources/two_player_sdl.c \
	  sources/init_tab.c \
	  sources/my_strdup.c \
	  sources/my_strcat.c \
	  sources/allum_1_player.c \
	  sources/gere_click_text.c \
	  sources/select_alum.c \
	  sources/allum1_2_player.c \
	  sources/ia.c \
	  sources/sdl_version.c \
	  sources/my_putnbr.c \
	  sources/my_strncmp.c \
	  sources/gere_click.c \
	  sources/my_strndup.c \
	  sources/my_putchar.c \
	  sources/xmalloc.c \
	  sources/my_getnbr.c \
	  sources/my_strcmp.c \
	  sources/my_putstr.c \
	  sources/my_strlen.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Iinclude/ -Wall -Wextra -lSDL -lSDL -lSDLmain

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(SRCS) $(CFLAGS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
