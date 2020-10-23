#include <iostream>
#include "Figures.hpp"


int main() {

	Ellipse e(3, 2);
	Circle c(1);
	Parallelogram p(1, 2, 1);
	Rhombus rh(12, 2);
	Rectangle r(10,15);
	Square sq(2);

	    Figures *figs[] = { &e, &c, &p, &rh, &r, &sq};
	    for (int i=0; i < 6; ++i)
	    {
	        figs[i]->about();
	    }
	return 0;
}
