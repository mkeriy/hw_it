#include <iostream>
#include <vector>


template <typename ... T>
T* func(T ... args)
{
	return new T(arg...);
}

int main()
{
	double* ex = func(1.0);
	std::cout << ex << std::endl;

	return 0;
}
