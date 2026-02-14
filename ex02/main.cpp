#include "./Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	Fixed c(Fixed(8.5f) + Fixed(2.3f));
	std::cout << c << std::endl;

	Fixed d = ++c;
	std::cout << d << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}