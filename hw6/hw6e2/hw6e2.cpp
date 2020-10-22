#include <iostream>
#include "Header.hpp"



int main() {
	Fraction f(0,1);
	Fraction f1(0,1);
	std::cout << "Enter fractions." << std::endl;
	std::cout << "1: ";
	std::cin >> f;
	std::cout << "\n 2: " << std::endl;
	std::cin >> f1;
	std::cout << std::endl;

	f += f1;
	std::cout << f << std::endl;
	f1++;
	++f1;
	f = f1;
	std::cout << f <<std::endl;
	std::cout << static_cast <double> (f) << std::endl;
	return 0;
}
