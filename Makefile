NAME			= algorithms
TSTNAME		= run_tests

# compiler
CXX				= g++
CPPFLAGS	= -Wall -Wextra -W -Werror -std=c++11
TSTLIBS		= -lcppunit

# directory names
SRCDIR		= sort
TSTDIR		= test

SRC				= $(SRCDIR)/main.cpp
TSTSRC		= $(TSTDIR)/runner.cpp \
						$(TSTDIR)/SortTest.cpp

OBJ				= $(SRC:.cpp=.o)
TSTOBJ		= $(TSTSRC:.cpp=.o)

RM				= rm -f

all: 			$(NAME)

$(NAME):	$(OBJ)
					$(CXX) -o $(NAME) $(OBJ)

check:		$(TSTOBJ)
					$(CXX) -o $(TSTNAME) $(TSTOBJ) -I$(SRCDIR) $(TSTLIBS)
					./$(TSTNAME)

clean:
					$(RM) $(OBJ) $(TSTOBJ)

fclean:		clean
					$(RM) $(NAME) $(TSTNAME)

re:				fclean all

.PHONY:		all clean re
