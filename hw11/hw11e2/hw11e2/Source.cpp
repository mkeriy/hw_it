#include <iostream>


template <typename T>
struct add_const 
{
	using tp = const T;
};


template <typename T>
struct remove_const
{
	using tp =  T;
};

template <typename T>
struct remove_const<const T>
{
	using tp = T;
};
template<typename T>
void f(T ard)
{
	std::cout << ++ard;
}

int main()
{	
	int x = 1;
	add_const<decltype(x)>::tp y = 1;
	remove_const<decltype(y)>::tp z = 1;
	
	return 0;
}