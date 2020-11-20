#include <iostream>


template<bool C,typename T = void>
struct enable_if{};//ничего не происходит C = false

template<typename T>
struct enable_if<true, T>
{
	using type = T; // используетс€ тип T так как — = true
};
template<bool C, typename T>
using enable_if_t = enable_if<C, T>::type;


int f() { return 1; }


int main()
{
	int a = 1;
	int b = 2;
	std::enable_if_t<std::is_same_v<int, decltype(f)>, int> f();
	
	return 0;
}