#include <iostream>



template<std::size_t n>
struct fibonachi_number
{
	static constexpr std::size_t value = fibonachi_number<n - 1>::value + fibonachi_number<n- 2>::value;
};

template<>
struct fibonachi_number<1>
{
	static constexpr std::size_t value = 1;
};

template<>
struct fibonachi_number<0>
{
	static constexpr std::size_t value = 0;
};


int main()
{
	constexpr std::size_t n = 30;
	std::cout << fibonachi_number<n>::value << std::endl;
	return 0;
}
