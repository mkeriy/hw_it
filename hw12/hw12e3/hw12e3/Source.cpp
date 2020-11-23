#include <iostream>



constexpr int fact(int n)
{
	int result = 1;
	for (auto i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}




constexpr double exp(int n)
{
	double result = 0.0;
	for (auto i = 0; i <= n; ++i) 
	{
		result += 1.0/fact(i);
	}
	return result;
}


int main()
{
	constexpr int N = 10;
	constexpr double e = exp(10);
	std::cout << e << std::endl;
	return 0; 
}
