NAME = Form
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f main.o Bureaucrat.o AForm.o PresidentialPardonForm.o RobotomyRequestForm.o ShrubberyCreationForm.o Intern.o

fclean: clean
	rm -f $(NAME)

re: fclean all