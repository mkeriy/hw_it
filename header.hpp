#pragma once

class Creature
{
public:
	Creature( double a, double b, double c) :
		m_coef1(a), m_coef2(b), m_coef3(c)
	{}
	double discr();
	void printEqu();
	void solutionEqu(double d);
	~Creature()
	{}
	 friend std::ostream & operator << (std::ostream & out, const Creature & val);
	 friend std::istream & operator >> (std::istream & in, Creature & val);
private:
    double m_coef1;
    double m_coef2;
    double m_coef3;

};

void solutionEqu(double d, const Creature & p);
