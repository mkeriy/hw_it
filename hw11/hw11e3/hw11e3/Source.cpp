#include <iostream>



template <typename T>
struct decay 
{ 
	using T1 = std::remove_reference_t<T>;
	using type = typename std::conditional<std::is_array_v<T1>, std::add_pointer_t<std::remove_extent<T1>>, 
		std::conditional<std::is_function_v<T1>, std::add_pointer<std::remove_cv_t<T1>>, T1 >>;
	

};

template <typename T>
using decay_t = typename decay<T>::type;


int f() { return 0;  }

int main()
{
	int a[1];
	std::cout << std::is_same<std::decay<decltype(f)>::type, int*>::value;
	std::cout << std::is_same<std::decay<decltype(a)>::type, int*>::value;
	std::cout << std::is_same<std::decay<const int&>::type, int>::value;
	std::cout << std::is_same<std::decay<int&&>::type, int>::value;
	return 0;
}