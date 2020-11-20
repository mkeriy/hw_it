#include <iostream>


template<typename>
struct is_function : std::false_type{};


template<typename T, typename ... Types>
struct is_function<T(Types ...)> : std::true_type {};

template<typename T>
constexpr bool is_function_v =  is_function<T>::value;


void f(int x, double z)
{}

int main()
{
	int x = 1;
	std::cout << is_function<decltype(f)>::value;
	std::cout << is_function_v<decltype(f)>;

	return 0;
}