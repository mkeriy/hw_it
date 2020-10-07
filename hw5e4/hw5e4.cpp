#include <iostream>
#include "h.hpp"

class B
{
    int x;
    public:
    void f()
    {
    	return x;
    }
};

void g(int a);//добавить определение функции

int main()
{
	g(5);

    return 0;
}
