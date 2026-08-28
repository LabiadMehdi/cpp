#include "RPN.hpp"
#include <stack>
#include <cctype>
#include <sstream>
#include <exception>

int	RPN::evaluate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;
	std::stack<int> numStack;
	while (ss >> token)
	{
		if (token.length() != 1)
			throw std::exception();

		char c = token[0];
		if (std::isdigit(static_cast<unsigned char>(c)))
			numStack.push(c - '0');
		else if (c == '+' || c == '-' || c == '/' || c == '*')
		{
			if (numStack.size() < 2)
				throw std::exception();
			
			int b = numStack.top(); numStack.pop();
			int a = numStack.top(); numStack.pop();

			int result;
			if (c == '+') result = a + b;
			else if (c == '-') result = a - b;
			else if (c == '*') result = a * b;
			else if (c == '/')
			{
				if (b == 0)
					throw std::exception();
				result = a / b;
			}
			numStack.push(result);
		}
		else
			throw std::exception();
	}
	if (numStack.size() != 1)
		throw std::exception();
	
	return numStack.top();
}