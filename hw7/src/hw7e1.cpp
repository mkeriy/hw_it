#include <iostream>
#include "Figures.hpp"


int main() {

	std::vector<Figure*> figs(6);
	Figure * f = new Ellipse(2, 1) ;
	Figure  * f1   = new Rectangle(1, 2);
	Figure * f2 = new Square(3);



		figs.push_back(f);
		figs.push_back(f1);
		figs.push_back(f2);

		for (auto i = 0U; i < figs.size(); ++i)
		{
			figs[i]->about();
		}



		delete f;
		delete f1;
		delete f2;

	return 0;
}
