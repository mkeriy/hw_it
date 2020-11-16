#include <iostream>
#include <vector>
#include "functions.cpp"

class Arrays
{
	private:
	std::size_t m_size;
	double *ar = new double[m_size];
	std::vector <double> sequence(m_size, 0);

	public:
	Arrays(){}

	Arrays(int size):
		m_size(size)
	{}

};





int main() {

	return 0;
}
