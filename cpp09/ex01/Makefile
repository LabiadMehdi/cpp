NAME = RPN
SRCS = main.cpp RPN.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o RPN.o

fclean: clean
	rm -f $(NAME)

re: fclean all