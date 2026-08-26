#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int occ)
{
	return std::find(container.begin(), container.end(), occ);
}