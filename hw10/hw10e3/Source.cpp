#include <iostream>


template <typename FUNC, typename ... Types>
void function(FUNC f, Types ... args)
{
	f(args...);
}


template <typename ... T>
void print(T ... args)
{
	(std::cout << ... << args);
}

int main()
{
	function([](int x, int y, int z) {std::cout << x + y << " " << y - z << " " << x*y*z; }, 500, 2, 3000);

	std::cout << std::endl;

	function(print<double, int, int>, 0.0001, 2, 3);

	return 0;
}