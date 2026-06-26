#include "Fixed.hpp"

//Shifting << fbits, is the same as multiplying 2^fbits

const int Fixed::fbits = 8;

Fixed::Fixed() : fp(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	fp = n << fbits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f)
{
	fp = roundf(f *(1 << fbits));
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
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	fp = other.fp;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fp = other.fp;
	return *this;
}

int	Fixed::getRawBits() const
{
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