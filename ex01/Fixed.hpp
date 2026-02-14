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
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif