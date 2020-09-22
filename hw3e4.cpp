#include <iostream>
#include <vector>
#include <functional>

double calculate(double x, double y, const std::function <double(double, double)> & v);

int main(){

    double i;
    double j;
    std::cout << "Enter floating point number." << std::endl;
    std::cout << "First number: ";
    std::cin >> i;
    std::cout << std::endl;

    std::cout << "Second number: "; 
    std::cin >> j;
    std::cout << std::endl;

    std::vector <std::function <double(double, double)>> lambda;

    lambda.push_back([](double i, double j){ return i + j; });
    lambda.push_back([](double i, double j){ return i - j; });
    lambda.push_back([](double i, double j){ return i * j; });
    lambda.push_back([](double i, double j){ return i / j; });
    
    for(auto & e : lambda)
    {
        calculate(i, j, e);
    }
    return 0;
}

double calculate(double x, double y, const std::function <double(double, double)> & v){
    
    std::cout << v(x, y) << std::endl;
    
    return 0;
}