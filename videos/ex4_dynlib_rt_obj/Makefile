NAME_EXE = example4
SRC_EXE = main.cpp
OBJ_EXE = $(SRC_EXE:.cpp=.o)


NAME_LIB = libkoala.so
SRC_LIB = Koala.cpp
OBJ_LIB = $(SRC_LIB:.cpp=.o)


NAME_LIB2 = libpanda.so
SRC_LIB2 = Panda.cpp
OBJ_LIB2 = $(SRC_LIB2:.cpp=.o)


LDFLAGS += -ldl
CXXFLAGS += -fPIC

CXX = g++

all: $(NAME_LIB) $(NAME_LIB2) $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

$(NAME_LIB): $(OBJ_LIB)
	$(CXX) -shared -o $(NAME_LIB) $(OBJ_LIB)

$(NAME_LIB2): $(OBJ_LIB2)
	$(CXX) -shared -o $(NAME_LIB2) $(OBJ_LIB2)

clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE) $(OBJ_LIB2)

fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB) $(NAME_LIB2)

re: fclean all
