NAME = violence
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o HumanA.o HumanB.o Weapon.o

fclean: clean
	rm -f $(NAME)

re: fclean all