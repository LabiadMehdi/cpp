NAME = horde
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Zombie.o zombieHorde.o

fclean: clean
	rm -f $(NAME)

re: fclean all