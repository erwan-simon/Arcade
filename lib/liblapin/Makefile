##
## Makefile for wolf3d in /home/rinaz_a/rendu/gfx_wolf3d
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.eu>
## 
## Started on  Tue Dec 22 13:57:35 2015 selim rinaz
## Last update Wed Mar 29 15:19:29 2017 Simon
##

NAME		=	test

CXXFLAGS	=	-L/home/${USER}/.froot/lib/ -llapin
CXXFLAGS        +=       -L/usr/local/lib
CXXFLAGS        +=       -lsfml-audio
CXXFLAGS        +=       -lsfml-graphics
CXXFLAGS        +=       -lsfml-window
CXXFLAGS        +=       -lsfml-system
CXXFLAGS        +=       -lstdc++ -ldl
CXXFLAGS        +=       -lm
CXXFLAGS        +=       -I../../graphic/ -I/home/${USER}/.froot/include/
CXXFLAGS        +=       -W -Wall -Werror -std=c++11

SRCS		=	myLibLapin.cpp

CPP		= 	g++

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CPP) $(OBJS) $(CXXFLAGS) -o $(NAME)
clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re
