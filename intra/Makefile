##
## Makefile for Makefile in /home/selimrinaz/repo/tek2/B4-CPP/cpp_nanotekspice
## 
## Made by Selim Rinaz
## Login   <selimrinaz@epitech.net>
## 
## Started on  Mon Feb 27 15:02:03 2017 Selim Rinaz
## Last update Mon Mar 13 17:38:07 2017 Selim Rinaz
##

NAME		 = ./nanotekspice

LIB		 = ./libnanotekspice.a

CC		 = g++
CXXFLAGS	+= -Wall -Wextra
CXXFLAGS	+= -std=c++11 -Iincludes/ -Iincludes/parsers/ -Iincludes/exceptions
CXXFLAGS	+= -Iincludes/components -Werror


SRCS_DIR	 = srcs/

SRCS_FILES	 = main.cpp			\
		  Parser/Parser.cpp		\
		  exceptions/AException.cpp	\
		  exceptions/FileError.cpp	\
		  exceptions/LexerError.cpp	\
		  exceptions/ParserError.cpp	\
		  components/AComponent.cpp	\
		  components/Component4081.cpp	\
		  FactoryComponent.cpp		\
		  components/Component4071.cpp

SRCS		 = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		 = $(SRCS:.cpp=.o)

SRCS_LIB_FILES	 = Parser/Parser.cpp		\
		  exceptions/AException.cpp	\
		  exceptions/FileError.cpp	\
		  exceptions/LexerError.cpp	\
		  exceptions/ParserError.cpp	\
		  components/AComponent.cpp	\
		  components/Component4081.cpp	\
		  FactoryComponent.cpp		\
		  components/Component4071.cpp

SRCS_LIB	 = $(addprefix $(SRCS_DIR), $(SRCS_LIB_FILES))

OBJS_LIB	 = $(SRCS_LIB:.cpp=.o)

RM		 = rm -f


all: $(NAME) $(LIB)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(LIB): $(OBJS_LIB)
	ar rvs $(LIB) $(OBJS_LIB)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB)

re: fclean all

.PHONY: all clean fclean re
