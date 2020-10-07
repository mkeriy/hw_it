#include <iostream>
#include <cmath>
#include "header.hpp"

	double Creature::discr()
	{
			double D = m_coef2 * m_coef2 - 4 * m_coef1 *m_coef3;
	        return D;
	}

	void Creature::printEqu()
	{
		std::cout << m_coef1 << "x^2 + (" << m_coef2 <<")x + (" << m_coef3 << ") = 0" << std::endl;
	}

	std::ostream & operator <<(std::ostream & out, const Creature & val)
	{
	    out << val.m_coef1;
	    out << val.m_coef2;
	    out << val.m_coef3;
	    return out;
	}

	std::istream & operator >>(std::istream & in, Creature & val)
	{
	    in >> val.m_coef1;
	    in >> val.m_coef2;
	    in >> val.m_coef3;
	    return in;
	}

	void Creature::solutionEqu(double d)
	{
		double x1, x2;
		std::cout << "Solution:" << std::endl;
		std::cout << "The discriminant of this equation is " << d << "therefore" << std::endl;

		if(d > 0)
		{
			std::cout << "Solution:" << std::endl;
			x1 = (- m_coef2 + std::sqrt(d))/(2 * m_coef1);
			x2 = (- m_coef2 - std::sqrt(d))/(2 * m_coef1);
			std::cout << "x1 = " << x1 << "\n" <<  "x1 = " << x2 << std::endl;
		}
			else if(d == 0)
			{
		             x1 = -m_coef2/(2*m_coef1);
					std::cout << "x = " << x1 << std::endl;
			}
			else
			{
				std::cout << "Quadratic equation has no solutions" << std::endl;
			}



	}
