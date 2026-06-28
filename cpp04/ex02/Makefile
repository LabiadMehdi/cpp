NAME = animal
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Animal.o Dog.o Cat.o WrongAnimal.o WrongCat.o Brain.o

fclean: clean
	rm -f $(NAME)

re: fclean all