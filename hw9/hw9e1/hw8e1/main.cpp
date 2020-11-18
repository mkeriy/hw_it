#include "MergeSort.hpp"
#include <algorithm>

int main()
{
    int size;
    std::cout << "Enter size of sequance: ";
    std::cin >> size;
    std::cout << std::endl;

    double* sequence = new double[size];
    double sequence_static[6] = { 11, 240, 4 , 578, 0, 1 };

    std::cout << "Enter items of sequence." << std::endl;
    for (auto i = 0; i < size; i++)
    {

        std::cin >> sequence[i];

    }

    ::merge_sort(sequence, size, [] (double i, double j) { return i > j; });
    ::merge_sort_(sequence_static, [](double lhs, double rhs) {return lhs < rhs; });

    std::cout << "Sorted sequence." << std::endl;
    for (auto i = 0; i < size; i++)
    {
        std::cout << sequence[i] << ' ';
    }

    delete[] sequence;
    std::cout << std::endl;

    for (auto i = 0; i < 6; i++)
    {
        std::cout << sequence_static[i] << ' ';
    }
    

	return 0;
}