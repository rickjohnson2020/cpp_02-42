#include "./Fixed.hpp"

Fixed::Fixed() : _raw(0) {
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int n) {
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = n << Fixed::fractionalBits;
}

Fixed::Fixed(const float f) {
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = static_cast<int>(roundf(f * (1 << Fixed::fractionalBits)));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
};
Fixed::Fixed(const Fixed& obj) {
	// std::cout << "Copy constructor called" << std::endl;
	this->_raw = obj._raw;
};

Fixed& Fixed::operator=(const Fixed& obj) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	this->_raw = obj._raw;
	return *this;
}

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->_raw) / (1 << Fixed::fractionalBits);
}

int Fixed::toInt() const {
	return this->_raw >> Fixed::fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed& obj) const {
	return this->_raw < obj._raw;
}

bool Fixed::operator>(const Fixed& obj) const {
	return obj < *this;
}

bool Fixed::operator<=(const Fixed& obj) const {
	return !(*this > obj);
}

bool Fixed::operator>=(const Fixed& obj) const {
	return !(*this < obj);
}

bool Fixed::operator==(const Fixed& obj) const {
	return this->_raw == obj._raw;
}

bool Fixed::operator!=(const Fixed& obj) const {
	return !(*this == obj);
}

Fixed Fixed::operator+(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(this->_raw + obj._raw);
	return result;
}

Fixed Fixed::operator-(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(this->_raw - obj._raw);
	return result;
}

Fixed Fixed::operator*(const Fixed& obj) const {
	Fixed result;
	result.setRawBits((static_cast<long long>(this->_raw) * obj._raw) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& obj) const {
	Fixed result;
	result.setRawBits((static_cast<long long>(this->_raw) << fractionalBits) / obj._raw);
	return result;
}

Fixed& Fixed::operator++() {
	this->_raw += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	this->_raw -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_raw += 1;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_raw -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a <= b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a <= b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a >= b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a >= b) ? a : b;
}