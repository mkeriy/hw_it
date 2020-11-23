#include <iostream>



template<std::size_t n>
struct fact
{
	static constexpr std::size_t value = n*fact<n - 1>::value;
};

template<>
struct fact<0>
{
	static constexpr std::size_t value = 1;
};

template<std::size_t n, std::size_t k>
struct doBinom
{
	static constexpr std::size_t value = fact<n>::value / (fact<k>::value * fact<n - k>::value);
};





int main()
{
	
	constexpr int a = doBinom<4, 4>::value;
	std::cout << a << std::endl;

	return 0;
}



