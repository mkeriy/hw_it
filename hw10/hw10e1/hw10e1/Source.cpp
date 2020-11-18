#include <iostream>

template <typename ... Types>
std::size_t sum_of_types(Types ... t)
{
	return (sizeof(t) + ...);
}

std::size_t sum_of_types_() { return 0; }
template <typename T, typename ... Types>
std::size_t sum_of_types_(T arg, Types ... args)
{
	std::size_t result = sizeof(arg) + sum_of_types_(args...);
	return result;
}


int main()
{
	std::cout << sum_of_types(1, 2.022, 'c', 0.00000001) << std::endl;
	std::cout << sum_of_types_(1, 2.022, 'c', 0.000000001) << std::endl;

	return 0;

}