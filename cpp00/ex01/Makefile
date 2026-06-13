NAME = phonebook

all: $(NAME)

$(NAME): main.cpp
	c++ -Wall -Wextra -Werror -std=c++98 main.cpp Contact.cpp PhoneBook.cpp ErrIns.cpp -o $(NAME)

clean:
	rm -rf main.o Contact.o PhoneBook.o ErrIns.o

fclean: clean
	rm -f $(NAME)

re: fclean all