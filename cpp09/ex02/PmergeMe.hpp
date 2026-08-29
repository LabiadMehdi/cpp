#pragma once

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe
{

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	fordJohnsonVector(std::vector<int> vec);
		std::vector<std::pair<int,int> > insertSortPairsVector(std::vector<std::pair<int,int> > pairs);
		std::vector<size_t> jacobsthalOrderVector(size_t n);
		void binaryInsertVector(std::vector<int> &chain, int value, int upperBoundValue);
		std::deque<int>	fordJohnsonDeque(std::deque<int> vec);
		std::deque<std::pair<int,int> > insertSortPairsDeque(std::deque<std::pair<int,int> > pairs);
		std::deque<size_t> jacobsthalOrderDeque(size_t n);
		void binaryInsertDeque(std::deque<int> &chain, int value, int upperBoundValue);
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void	sortVector();
		void	sortDeque();

		std::vector<int>	getVector() const;
		std::deque<int>		getDeque() const;
};