#include <iostream>
#include <vector>



//начальный шаблон
template<typename T>
struct decay	
{
	using type = T;
};

//перегрузка для различных ссылок
template<typename T>
struct decay<T&>
{
	using type = T;
};

template<typename T>
struct decay<T&&>
{
	using type = T;
};

//перегрузка для константных ссылок
template<typename T>
struct decay<const T&>
{
	using type = T;
};

template<typename T>
struct decay<const T&&>
{
	using type = T;
};

//перегрузка для функций
template<typename T, typename ... Types>
struct decay<T(Types ...)>
{
	using type = T*;
};

//перегрузка для массивов
template<typename T, std::size_t i>
struct decay<T[i]>
{
	using type = T*;
};
void f(int z, double y, char x) { }

int main()
{
	int a[1];
	std::cout << std::is_same<decay<decltype(f)>::type, void*>::value;
	std::cout << std::is_same<decay<decltype(a)>::type, int*>::value;
	std::cout << std::is_same<decay<const int&>::type, int>::value;
	std::cout << std::is_same<decay<int&&>::type, int>::value;
	return 0;
}