NAME_EXE = example3
SRC_EXE = main.c
OBJ_EXE = $(SRC_EXE:.c=.o)


NAME_LIB = libkoala.so
SRC_LIB = koala.c
OBJ_LIB = $(SRC_LIB:.c=.o)


LDFLAGS += -ldl
CFLAGS += -fPIC

CC = gcc

all: $(NAME_LIB) $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CC) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

$(NAME_LIB): $(OBJ_LIB)
	$(CC) -shared -o $(NAME_LIB) $(OBJ_LIB)

clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE)

fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB)

re: fclean all
