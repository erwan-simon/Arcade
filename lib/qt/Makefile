##
## Makefile for wolf3d in /home/rinaz_a/rendu/gfx_wolf3d
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.eu>
## 
## Started on  Tue Dec 22 13:57:35 2015 selim rinaz
## Last update Thu Mar 30 17:12:39 2017 Selim Rinaz
##

NAME		=	test

CXXFLAGS        +=       -I../../graphic/
CXXFLAGS        +=       -W -Wall -Werror -std=c++11

SRCS		=	myQt.cpp

CPP		= 	g++

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CPP) $(OBJS) $(CXXFLAGS) -o $(NAME)
clean		:
			rm -f $(OBJS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re
