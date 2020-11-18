#include <iostream>

// основной шаблон
template<typename>
struct is_function : std::false_type{};

// перегрузка шаблона для обычных функций
template<typename T, typename ... Types>
struct is_function<T(Types ...)> : std::true_type {};


void f(int x, double z)
{}

int main()
{
	int x = 1;
	std::cout << is_function<decltype(f)>::value;

	return 0;
}