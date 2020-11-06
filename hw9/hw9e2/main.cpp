#include "Container.hpp"
#include <vector>
int main()
{
	blr::victor<double> a(4, 1);
	std::vector<double> ar{ 1, 2, 3 ,4 };
	for (auto i = 0; i < 4; ++i)
	{
		a[i] = ar[i];
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	a.insert(1.0, 1);
	for (auto i = 0; i < a.lenth(); ++i)
	{
		std::cout << a[i] << ' ';
	}
	return 0;
}