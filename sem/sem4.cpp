#include <iostream>

struct person{
    //constructor
    person(const std::string & n, std::size_t a, int s):
        name(n), age(a), salary(s)
    {}
    //CTOR
    //0. 
    //1. Выделение памяти под члены и инициализация
    //2. выполнение тела конструктора
    
    std::string name;
    std::size_t age;
    int salary;
};

int main() {
    
    
    person p("a", 10, 10);
    


    return 0;
}