NAME = zombie
SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Zombie.o randomChump.o newZombie.o

fclean: clean
	rm -f $(NAME)

re: fclean all