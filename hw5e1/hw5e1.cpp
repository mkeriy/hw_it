#include <iostream>
#include "header.hpp"
#include <string>



int main()
{
	Creature qe(0,0,0);
	std::cout << "Enter the coefficients of the quadratic equation." << std::endl;
	std::cin >> qe;
	qe.discr();
	qe.printEqu();
	qe.solutionEqu(qe.discr());

	return 0;
}

