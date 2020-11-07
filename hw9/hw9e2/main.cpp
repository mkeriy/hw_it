#include "Container.hpp"
#include <vector>
int main()
{
	blr::victor<double> a(4, 1);
	blr::victor<double> b(4, 2);
	std::vector<double> ar{ 1, 2, 3 ,4 };
	for (auto i = 0; i < 4; ++i)
	{
		a[i] = ar[i];
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	swap(a, b);
	a.insert(1.0, 1);
	a.print();
	std::cout << a[1] << std::endl;
	return 0;
}