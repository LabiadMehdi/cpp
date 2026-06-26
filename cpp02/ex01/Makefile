NAME = fixed
SRCS = main.cpp Fixed.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Fixed.o

fclean: clean
	rm -f $(NAME)

re: fclean all