NAME	= algorithms
TSTNAME	= run_tests

# compiler
CXX	= g++
CXXFLAGS = -Wall -Wextra -W -Werror -std=c++11
CPPFLAGS =
LDFLAGS	=
LDLIBS	= -lboost_program_options
TSTLIBS	= -lcppunit

# directory names
SRCDIR	= sort
TSTDIR	= test

SRC	= $(SRCDIR)/main.cpp
TSTSRC	= $(TSTDIR)/runner.cpp \
	$(TSTDIR)/SortTest.cpp

OBJ	= $(SRC:.cpp=.o)
TSTOBJ	= $(TSTSRC:.cpp=.o)

RM	= rm -f

all: 	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

check:	$(TSTOBJ)
	$(CXX) -o $(TSTNAME) $(TSTOBJ) -I$(SRCDIR) $(TSTLIBS)
	./$(TSTNAME)

clean:
	$(RM) $(OBJ) $(TSTOBJ)

fclean:	clean
	$(RM) $(NAME) $(TSTNAME)

re:	fclean all

.PHONY:	all clean re
