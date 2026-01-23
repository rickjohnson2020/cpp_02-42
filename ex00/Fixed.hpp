#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _raw;
	static const int fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& obj);

	Fixed& operator=(const Fixed& obj);

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif