#include <iostream>



template <typename ... Types>
auto* func(Types... t)
{
	return new auto(t ...);
}

int main()
{
	double* ex = func<double>(1.0);
	std::cout << ex << std::endl;
	delete ex;
	return 0;
}
