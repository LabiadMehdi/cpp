#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span(unsigned int N) : _max_size(N)
{
}

void	Span::addNumber(int n)
{
	if (_arr.size() >= _max_size)
		throw std::exception();
	_arr.push_back(n);
}

int		Span::shortestSpan() const
{
	if (_arr.size() < 2)
		throw std::exception();
	
	std::vector<int> sorted = _arr;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
		if ((sorted[i] - sorted[i - 1]) < shortest)
			shortest = sorted[i] - sorted[i - 1];
	return shortest;
}

int		Span::longestSpan() const
{
	if (_arr.size() < 2)
		throw std::exception();

	std::vector<int>::const_iterator minInt = std::min_element(_arr.begin(), _arr.end());
	std::vector<int>::const_iterator maxInt = std::max_element(_arr.begin(), _arr.end());
	return *maxInt - *minInt;
}

Span::Span(const Span &other) : _arr(other._arr), _max_size(other._max_size)
{
}

Span	&Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_arr = other._arr;
	_max_size = other._max_size;
	return *this;
}

Span::~Span()
{}