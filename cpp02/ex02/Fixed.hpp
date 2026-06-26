#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fp;
		static const int fbits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(int n);
		Fixed(float n);
		
		~Fixed();
		
		float toFloat() const;
		int toInt() const;
		int	getRawBits() const;
		void setRawBits(int const raw);
		
		Fixed &operator=(const Fixed &other);
		
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed& a, Fixed& b);
		static const Fixed &min(const Fixed& a, const Fixed& b);
		static Fixed &max(Fixed& a, Fixed& b);
		static const Fixed &max(const Fixed& a, const Fixed& b);

		static bool verbose;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif