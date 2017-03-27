NAME    = libmy.so

RM      = rm -f

SRCS    = ./gen.cpp

LIB     = -lmy -L

OBJS    = $(SRCS:.c=.o)

LDFLAGS = -fPIC -g -c -Wall -Wextra -lpthread -D_REENTRANT

LSFLAGS = -shared -Wl

all: $(NAME)

$(NAME):
	g++ $(LSFLAGS),-soname,$(NAME) -o $(NAME) *.o -lc

clean:
	$(RM) libmy.so

re: clean all

.PHONY: all clean fclean re
