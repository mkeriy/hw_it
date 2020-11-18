#include <iostream>


template<bool C,typename T>
struct enable_if{};//ничего не происходит C = false

template<typename T>
struct enable_if<true, T>
{
	using type = T; // используетс€ тип T так как — = true
};

int main()
{
	return 0;
}