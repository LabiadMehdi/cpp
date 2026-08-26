#include <exception>
#include <cstddef>

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other._size;
	_arr = new T[_size]();
	
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;

	if (_arr)
		delete[] _arr;

	_size = other._size;
	_arr = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}