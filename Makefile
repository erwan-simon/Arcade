##
## Makefile for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
## 
## Made by Simon
## Login   <erwan.simon@epitech.eu>
## 
## Started on  Thu Mar 30 11:17:19 2017 Simon
## Last update Thu Mar 30 12:04:24 2017 Simon
##

CC		= g++
RM		= rm -f

NAME_EXE	= arcade
SRCS_EXE	= ./launcher.cpp
OBJS_EXE	= $(SRCS_EXE:.cpp=.o)

NAME_NC		= lib_arcade_ncurses.so
SRCS_NC		= ./lib/ncurses/myNcurses.cpp
OBJS_NC		= $(SRCS_NC:.cpp=.o)

NAME_SF		= lib_arcade_sfml.so
SRCS_SF		= ./lib/sfml/mySfml.cpp
OBJS_SF		= $(SRCS_SF:.cpp=.o)

NAME_LA		= lib_arcade_lapin.so
SRCS_LA		= ./lib/lapin/myLapin.cpp
OBJS_LA		= $(SRCS_LA:.cpp=.o)

LDFLAGS		+= -ldl -Wall -Wextra
CCFLAGS		+= -fPIC
LSFLAGS		+= -shared

all:		$(NAME_EXE) $(NAME_SF) $(NAME_SF) $(NAME_SF)

$(NAME_EXE):	$(OBJS_EXE)
		$(CC) -o $(NAME_EXE) $(OBJS_EXE) $(LDFLAGS)

$(NAME_NC):	$(OBJS_NC)
		$(CC) -shared -o $(NAME_NC) $(OBJS_NC) -lncurses

$(NAME_SF):	$(OBJS_SF)
		$(CC) -shared -o $(NAME_SF) $(OBJS_SF) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME_NC):	$(OBJS_LA)
		$(CC) -shared -o $(NAME_LA) $(OBJS_LA) -lsfml-graphics -lsfml-window -lsfml-system

clean:
		$(RM) $(OBJS_EXE) $(OBJS_NC) $(OBJS_SF) $(OBJS_LA)

fclean: 	clean
		$(RM) $(NAME_EXE) $(NAME_NC) $(NAME_SF) $(NAME_LA)

re:		fclean all

.PHONY:		all clean fclean re
