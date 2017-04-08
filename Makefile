##
## Makefile for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
## 
## Made by Simon
## Login   <erwan.simon@epitech.eu>
## 
## Started on  Thu Mar 30 11:17:19 2017 Simon
## Last update Sat Apr  8 18:07:27 2017 Simon
##

NAME_EXE	= arcade
SRCS_EXE	= ./Launcher.cpp	\
		  ./main.cpp
OBJS_EXE	= $(SRCS_EXE:.cpp=.o)

NAME_NC		= ./lib/lib_arcade_ncurses.so
SRCS_NC		= ./lib/ncurses/myNcurses.cpp
OBJS_NC		= $(SRCS_NC:.cpp=.o)

NAME_SF		= ./lib/lib_arcade_sfml.so
SRCS_SF		= ./lib/sfml/mySfml.cpp
OBJS_SF		= $(SRCS_SF:.cpp=.o)

NAME_LA		= ./lib/lib_arcade_lapin.so
SRCS_LA		= ./lib/lapin/myLibLapin.cpp
OBJS_LA		= $(SRCS_LA:.cpp=.o)

NAME_SN		= ./games/libarcade_snake.so
SRCS_SN		= ./games/snake/Snake.cpp
OBJS_SN		= $(SRCS_SN:.cpp=.o)

NAME_PA		= ./games/libarcade_pacman.so
SRCS_PA		= ./games/pacman/Pacman.cpp
OBJS_PA		= $(SRCS_PA:.cpp=.o)

CXXFLAGS	+= -Wall -Wextra -fPIC -std=c++11 		\
		   -Wfatal-errors -I./lib/include -g -g3	\
		   -I./games/include -I./error -I./

LDFLAGS		+= -ldl

LAFLAGS		=  -L/home/${USER}/.froot/lib/ -llapin			\
		   -L/usr/local/lib					\
		   -lm							\
		   -lsfml-graphics -lsfml-window -lsfml-system		\
		   -I../../graphic/ -I/home/${USER}/.froot/include/

LSFFLAGS	=  -L/home/${USER}/.sfml/lib/ -lm		\
		   -L/usr/local/lib				\
		   -lsfml-graphics -lsfml-window -lsfml-system	\
		   -I/home/${USER}/.sfml/include/

CXX		= g++
RM		= rm -f

mouli:		$(NAME_SN) $(NAME_PA)

lib:		$(NAME_EXE) $(NAME_SN) $(NAME_NC) $(NAME_SF) $(NAME_PA) # $(NAME_LA)

all:		mouli lib

$(NAME_EXE):	$(OBJS_EXE)
		$(CXX) -o $(NAME_EXE) $(OBJS_EXE) $(LDFLAGS)

$(NAME_SN):	$(OBJS_SN)
		$(CXX) -shared -o $(NAME_SN) $(OBJS_SN)

$(NAME_PA):	$(OBJS_PA)
		$(CXX) -shared -o $(NAME_PA) $(OBJS_PA)

$(NAME_NC):	$(OBJS_NC)
		$(CXX) -shared -o $(NAME_NC) $(OBJS_NC) -lncurses

$(NAME_SF):	$(OBJS_SF)
		$(CXX) -shared -o $(NAME_SF) $(OBJS_SF) $(LSFFLAGS)

$(NAME_LA):	$(OBJS_LA)
		$(CXX) -shared -o $(NAME_LA) $(OBJS_LA) $(LAFLAGS)

clean:
		$(RM) $(OBJS_EXE) $(OBJS_NC) $(OBJS_SF) $(OBJS_LA) $(OBJS_SN) $(OBJS_PA)

fclean: 	clean
		$(RM) $(NAME_EXE) $(NAME_NC) $(NAME_SF) $(NAME_LA) $(NAME_SN) $(NAME_PA)

re:		fclean all

.PHONY:		all clean fclean re
