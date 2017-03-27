NAME_EXE = example1
SRC_EXE = main.c
OBJ_EXE = $(SRC_EXE:.c=.o)


NAME_LIB = libkoala.a
SRC_LIB = koala.c
OBJ_LIB = $(SRC_LIB:.c=.o)


LDFLAGS += -L. -lkoala
CFLAGS +=

CC = gcc
AR = ar rcs

all: $(NAME_LIB) $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CC) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

$(NAME_LIB): $(OBJ_LIB)
	$(AR) $(NAME_LIB) $(OBJ_LIB)

clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE)

fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB)

re: fclean all
