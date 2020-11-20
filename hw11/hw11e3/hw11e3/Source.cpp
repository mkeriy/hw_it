#include <iostream>
#include <vector>


template <typename T>
struct decay 
{ 
	using T1 = std::remove_reference_t<T>;
	using T2 = typename std::_Select<std::is_function_v<T1>>::template _Apply<std::add_pointer<T1>, std::remove_cv<T1>>;
	using type = typename std::_Select<std::is_array_v<T1>>::template _Apply<std::add_pointer<std::remove_extent_t<T1>>, T2>::type;
};

template <typename T>
using decay_t = typename decay<T>::type;


int f() { return 0;  }

int main()
{
	int a[1];
	std::cout << std::is_same<decay<decltype(f)>::type, int*>::value;
	std::cout << std::is_same<decay<decltype(a)>::type, int*>::value;
	std::cout << std::is_same<decay<const int&>::type, int>::value;
	std::cout << std::is_same<decay<int&&>::type, int>::value;
	return 0;
}