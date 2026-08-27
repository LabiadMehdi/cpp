#pragma once

#include <vector>

class Span
{
	private:
		std::vector<int>	_arr;
		unsigned int		_max_size;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span				&operator=(const Span &other);
		~Span();

		void				addNumber(int n);
		int					shortestSpan() const;
		int					longestSpan() const;
		template <typename InputIterator>
		void				addRange(InputIterator first, InputIterator last);
};

template <typename InputIterator>
void						Span::addRange(InputIterator first, InputIterator last)
{
	for (InputIterator it = first; it != last; it++)
		addNumber(*it);
}