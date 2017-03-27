NAME    = libmy.so

RM      = rm -f

SRCS    = ./gen.cpp

LIB     = -lmy -L

OBJS    = $(SRCS:.cpp=.o)

LDFLAGS = -fPIC -g -c -Wall -Wextra -lpthread -D_REENTRANT

LSFLAGS = -shared -Wl

all: $(NAME)

$(NAME):$(OBJS)
	g++ $(LSFLAGS),-soname,$(NAME) -o $(NAME) *.o -lc

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) libmy.so

re: fclean all

.PHONY: all clean fclean re
