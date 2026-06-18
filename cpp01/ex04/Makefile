NAME = mySed
SRCS = main.cpp Error.cpp Replace.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Error.o Replace.hpp

fclean: clean
	rm -f $(NAME)

re: fclean all