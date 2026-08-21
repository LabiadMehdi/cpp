NAME = Form
SRCS = main.cpp Bureaucrat.cpp Form.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Bureaucrat.o Form.o

fclean: clean
	rm -f $(NAME)

re: fclean all