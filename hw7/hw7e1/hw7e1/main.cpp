#include "Figure.hpp"

int main()
{

	std::vector<Figure*> figs;
	Figure* f = new Rectangle({ 0,0 }, { 0,5 }, { 0,4 });
	



	figs.push_back(f);
	

	for (auto i = 0U; i < figs.size(); ++i)
	{
		figs[i]->about();
	}


	delete f;
	

	return 0;
}