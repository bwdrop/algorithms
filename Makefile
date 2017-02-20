NAME			= algorithms

SRC_DIR		= sort

SRC				= $(SRC_DIR)/main.cpp \

OBJ				= $(SRC:.cpp=.o)

CC				= g++

RM				= rm -f

CPPFLAGS	+= -Wall -Wextra -W -Werror
CPPFLAGS	+= -std=c++11

all: 			$(NAME)

$(NAME):	$(OBJ)
					$(CC) -o $(NAME) $(OBJ)

clean:
					$(RM) $(OBJ)

fclean:		clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean re
