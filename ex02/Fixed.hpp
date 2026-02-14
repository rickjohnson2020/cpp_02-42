#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _raw;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed(const Fixed& obj);

	Fixed& operator=(const Fixed& obj);

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;

	// comparison operators
	bool operator<(const Fixed& obj) const;
	bool operator>(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;

	// arithmetic operators
	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& obj1, Fixed& obj2);
	static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
	static Fixed& max(Fixed& obj1, Fixed& obj2);
	static const Fixed& max(const Fixed& obj1, const Fixed&obj2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif