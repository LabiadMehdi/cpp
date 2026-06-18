NAME = harl
SRCS = main.cpp Harl.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Harl.cpp

fclean: clean
	rm -f $(NAME)

re: fclean all