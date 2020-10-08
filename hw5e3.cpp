#include <iostream>

class B
{
    int m_x = 10;
    int m_y = 20;
    int m_z = 30;
    
    public:


    class Key
    {
        friend void f(B a);
        Key(){};
    };
    
    auto getSmth()
    {
        return m_x;
    }

};

void f(B a)
{
    std::cout << a.getSmth() + 1 << std::endl;
}


int main()
{
    B e;
    f(e);  
    return 0;
}