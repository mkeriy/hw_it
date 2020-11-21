#include <iostream>


template<typename T>
constexpr bool is_function_v = std::is_function<T>::value;
template<typename T>
constexpr bool is_array_v = std::is_array<T>::value;

template <typename T>
struct decay 
{ 
	using T1 = std::remove_reference_t<T>;
	using type = typename std::conditional_t<is_array_v<T>, std::add_pointer_t<std::remove_extent_t<T1>>,
		std::conditional_t<is_function_v<T>, std::add_pointer_t<T1>, std::remove_const_t<T1>>>;
	

};

template <typename T>
using decay_t = typename decay<T>::type;


int f() { return 0;  }

int main()
{
	int a[1];
	std::cout << std::is_same<decay<decltype(f)>::type, int(*)()>::value;
	std::cout << std::is_same<decay<decltype(a)>::type, int*>::value;
	std::cout << std::is_same<decay<const int&>::type, int>::value;
	std::cout << std::is_same<decay<int&&>::type, int>::value;
	return 0;
}