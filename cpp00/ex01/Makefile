NAME = phonebook

all: $(NAME)

$(NAME): main.cpp
	c++ -Wall -Wextra -Werror -std=c++98 main.cpp Contact.cpp PhoneBook.cpp -o $(NAME)

clean:
	rm -rf main.o Contact.cpp PhoneBook.cpp

fclean: clean
	rm -f $(NAME)

re: fclean all