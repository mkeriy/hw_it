#include <iostream>
#include <string>


struct Creature
{
	Creature( double a, double b, double c) :
		coef1(a), coef2(b), coef3(c)
    {}

	void discr() 
	{
		double D = coef2 * coef2 - 4 * coef1 *coef3;
        std::cout << "The discriminant of a quadratic equation is " << D << std::endl;

	}

	~Creature() 
	{}
   
    double coef1;
    double coef2;
    double coef3;

};




int main()
{
	Creature qe( 7, 79, 2500);

	qe.discr();

	return 0;
}