#include "PmergeMe.hpp"
#include <sstream>
#include <exception>

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::stringstream ss;
		ss << av[i];
		int value;
		if (!(ss >> value) || !ss.eof())
			throw std::exception();

		if (value < 0)
			throw std::exception();

		_vec.push_back(value);
		_deq.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	_vec = other._vec;
	_deq = other._deq;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<int> PmergeMe::getVector() const
{
    return _vec;
}

std::deque<int> PmergeMe::getDeque() const
{
    return _deq;
}

std::vector<std::pair<int,int> > PmergeMe::insertSortPairsVector(std::vector<std::pair<int,int> > pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int,int> key = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
    return pairs;
}

std::vector<size_t> PmergeMe::jacobsthalOrderVector(size_t n)
{
    std::vector<size_t> order;
	if (n < 2)
    	return order;

	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (jacobsthal.back() < n)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	size_t prevBoundary = 1;
	for (size_t k = 2; k < jacobsthal.size(); k++)
	{
		size_t boundary = jacobsthal[k];
		if (boundary > n)
			boundary = n;

		for (size_t idx = boundary; idx > prevBoundary; idx--)
			order.push_back(idx);

		prevBoundary = jacobsthal[k];
		if (jacobsthal[k] >= n)
			break;
	}
	return order;
}

void PmergeMe::binaryInsertVector(std::vector<int> &chain, int value, int upperBoundValue)
{
    size_t upperIndex = 0;
    while (upperIndex < chain.size() && chain[upperIndex] != upperBoundValue)
        upperIndex++;

    size_t low = 0;
    size_t high = upperIndex;
    while (low < high)
    {
        size_t mid = low + (high - low) / 2;
        if (chain[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }

    chain.insert(chain.begin() + low, value);
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return vec;

	bool hasStraggler = (vec.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
	{
		straggler = vec.back();
		vec.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	pairs = insertSortPairsVector(pairs);

	std::vector<int> chain;
	for (size_t i = 0; i < pairs.size(); i++)
		chain.push_back(pairs[i].first);

	chain.insert(chain.begin(), pairs[0].second);

	std::vector<size_t> order = jacobsthalOrderVector(pairs.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i] - 1;
		binaryInsertVector(chain, pairs[idx].second, pairs[idx].first);
	}

	if (hasStraggler)
	{
		size_t low = 0, high = chain.size();
		while (low < high)
		{
			size_t mid = low + (high - low) / 2;
			if (chain[mid] < straggler)
				low = mid + 1;
			else
				high = mid;
		}
		chain.insert(chain.begin() + low, straggler);
	}

	return chain;
}


















std::deque<std::pair<int,int> > PmergeMe::insertSortPairsDeque(std::deque<std::pair<int,int> > pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int,int> key = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
    return pairs;
}

std::deque<size_t> PmergeMe::jacobsthalOrderDeque(size_t n)
{
    std::deque<size_t> order;
	if (n < 2)
    	return order;

	std::deque<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (jacobsthal.back() < n)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	size_t prevBoundary = 1;
	for (size_t k = 2; k < jacobsthal.size(); k++)
	{
		size_t boundary = jacobsthal[k];
		if (boundary > n)
			boundary = n;

		for (size_t idx = boundary; idx > prevBoundary; idx--)
			order.push_back(idx);

		prevBoundary = jacobsthal[k];
		if (jacobsthal[k] >= n)
			break;
	}
	return order;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &chain, int value, int upperBoundValue)
{
    size_t upperIndex = 0;
    while (upperIndex < chain.size() && chain[upperIndex] != upperBoundValue)
        upperIndex++;

    size_t low = 0;
    size_t high = upperIndex;
    while (low < high)
    {
        size_t mid = low + (high - low) / 2;
        if (chain[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }

    chain.insert(chain.begin() + low, value);
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> vec)
{
	if (vec.size() <= 1)
		return vec;

	bool hasStraggler = (vec.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
	{
		straggler = vec.back();
		vec.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	pairs = insertSortPairsDeque(pairs);

	std::deque<int> chain;
	for (size_t i = 0; i < pairs.size(); i++)
		chain.push_back(pairs[i].first);

	chain.insert(chain.begin(), pairs[0].second);

	std::deque<size_t> order = jacobsthalOrderDeque(pairs.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i] - 1;
		binaryInsertDeque(chain, pairs[idx].second, pairs[idx].first);
	}

	if (hasStraggler)
	{
		size_t low = 0, high = chain.size();
		while (low < high)
		{
			size_t mid = low + (high - low) / 2;
			if (chain[mid] < straggler)
				low = mid + 1;
			else
				high = mid;
		}
		chain.insert(chain.begin() + low, straggler);
	}

	return chain;
}

void PmergeMe::sortVector()
{
	_vec = fordJohnsonVector(_vec);
}

void PmergeMe::sortDeque()
{
	_deq = fordJohnsonDeque(_deq);
}