#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int n;

    int size;
    std::cout << "Enter size of sequence: ";
    std::cin >> size;
    std::cout << std::endl;

    std::vector <double> sequence(size, 0);

     std::cout << "Enter items of sequence." << std::endl;
    for(double & item : sequence)
    {

        std::cin >> item;
    
    }

    std::cout << "Select sort." << std::endl;
    std::cout << "Enter 1 if from smallest to largest" << std::endl;
    std::cout << "Enter 2 if from largest to smallest" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> n;

    switch (n){
        case 1:
            std::sort (sequence.begin(), sequence.end(), [](double i, double j){ return i < j;});
            std::cout << "Sorted sequence." << std::endl;
            for(double & item : sequence)
            {

                std::cout << item << ' ';
    
            }
            break;
        case 2:
            std::sort (sequence.begin(), sequence.end(), [](double i, double j){ return i > j;});
            std::cout << "Sorted sequence." << std::endl;
            for(double & item : sequence)
            {

                std::cout << item << ' ';
    
            }
            break;
        default:
            std::cout << "Wrong number. Try again.";
            break;

    }


}