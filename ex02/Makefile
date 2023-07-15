NAME = PmergeMe
SRC = main.cpp PMergeMe.cpp
CC = c++
CPPFLAGS = -Wall -std=c++98 #-Wextra -Werror
RM = rm -rf
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re