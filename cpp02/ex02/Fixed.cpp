#include "Fixed.hpp"

//Shifting << fbits, is the same as multiplying 2^fbits, 1 << fbits = 256

bool Fixed::verbose = false;

const int Fixed::fbits = 8;

Fixed::Fixed() : fp(0)
{
	if (verbose)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	fp = n << fbits;
	if (verbose)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f)
{
	fp = roundf(f *(1 << fbits));
	if (verbose)
		std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt() const
{
	return fp >> fbits;
}

float Fixed::toFloat() const
{
	return (float)fp / (1 << fbits);
}

Fixed::~Fixed()
{
	if (verbose)
		std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	if (verbose)
		std::cout << "Copy constructor called" << std::endl;
	fp = other.fp;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (verbose)
		std::cout << "Copy assignment operator called" << std::endl;
	fp = other.fp;
	return *this;
}

int	Fixed::getRawBits() const
{
	if (verbose)
		std::cout << "getRawBits member function called" << std::endl;
	return fp;
}

void Fixed::setRawBits(int const raw)
{
	fp = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed &other) const
{
	return fp < other.fp;
}

bool Fixed::operator>(const Fixed &other) const
{
	return fp > other.fp;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return fp <= other.fp;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return fp >= other.fp;
}

bool Fixed::operator==(const Fixed &other) const
{
	return fp == other.fp;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return fp != other.fp;
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed fixed;
	fixed.fp = fp + other.fp;
	return fixed;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed fixed;
	fixed.fp = fp - other.fp;
	return fixed;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed fixed;
	fixed.fp = (fp * other.fp) / (1 << fbits);
	return fixed;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed fixed;
	fixed.fp = (fp * (1 << fbits)) / other.fp;
	return fixed;
}

Fixed &Fixed::operator++()
{
	fp++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	fp++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	fp--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	fp--;
	return tmp;
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
