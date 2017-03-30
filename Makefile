##
## Makefile for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
## 
## Made by Simon
## Login   <erwan.simon@epitech.eu>
## 
## Started on  Thu Mar 30 11:17:19 2017 Simon
## Last update Thu Mar 30 11:19:17 2017 Simon
##

NAME	= libmy_malloc.so

RM	= rm -f

SRCS	= ./linked_list.c \
	  ./malloc.c \

LIB	= -lmy -L

OBJS	= $(SRCS:.c=.o)

LDFLAGS	= -fPIC -g -c -Wall -Wextra -lpthread -D_REENTRANT

LSFLAGS	= -shared -Wl

all: $(NAME)

$(NAME):
	gcc $(LDFLAGS) $(SRCS)
	gcc $(LSFLAGS),-soname,$(NAME) \
	-o $(NAME) *.o -lc

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
