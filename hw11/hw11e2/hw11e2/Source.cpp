#include <iostream>

template<typename T>
using constant_type = const T;

template <typename T>
struct add_const 
{
	using tp = constant_type<T>;
};

template <typename T>
using add_const_t = add_const<T>::tp;

template <typename T>
struct remove_const
{
	using tp =  T;
};

template <typename T>
struct remove_const<constant_type<T>>
{
	using tp = T;
};

template <typename T>
using remove_const_t = remove_const<T>::tp;


int main()
{	
	int x = 1;
	add_const<decltype(x)>::tp y = 1;
	remove_const<decltype(y)>::tp z = 1;
	
	return 0;
}