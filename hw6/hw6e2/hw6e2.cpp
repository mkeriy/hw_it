#include <iostream>
#include "Header.hpp"



int main() {
	Fraction f(0,0);
	Fraction f1(0,0);
	std::cout << "Enter fractions." << std::endl;
	f.input();
	f1.input();
	if(f <= f1)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	f += f1;
	f1 = f1 + 10;
	++f;
	f--;
	f1.reduction();
	f1.print();
	f.reduction();
	f.print();
	std::cout << f.toDouble();
	return 0;
}
