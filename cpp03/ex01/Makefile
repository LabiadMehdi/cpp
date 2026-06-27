NAME = scavtrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o ClapTrap.o ScavTrap.o

fclean: clean
	rm -f $(NAME)

re: fclean all