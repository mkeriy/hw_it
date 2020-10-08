#include <iostream>
#include <string>

   

class Pressure
{
    private:
    double m_value;
   

    public:
    Pressure (double value):
    m_value(value)
    {};

    ~Pressure (){};
    
    
    auto getter()
    {
        return m_value;
    }

    auto setterBar(double v)
    {
        m_value = v * c_bar;
        
    }
    
   auto setterAtm(double v)
    {
        m_value = v * c_atm;
        
    }
    auto setterMmHg(double v)
    {
        m_value = v * c_mmhg;
        
    }
    
    

    
    static constexpr double c_bar = 100000; 
    static constexpr double c_atm = 98066.5;
    static constexpr double c_mmhg = 133.3224;


    friend std::ostream & operator << (std::ostream & out, const Pressure & val);
    friend std::istream & operator >> (std::istream & in, Pressure & val);
};

enum class type
{
    bar = 1 ,
    atm,
    mmHg
};

int main()
{
    Pressure m_value(0);
    double a;
    int m_type;
    type t;
    

    std::cout << "This program can only convert values from bar, mmHg and atmospheres to Pascals" << std::endl;
    std::cout << "Enter the value" << std::endl;
    std::cin >> a;
    

   std::cout << "1 - bar \n" << "2 - atm \n" << "3 - mmHg\n" << std::endl;
   std::cout << "Enter a Number : ";
    std::cin >> m_type;
    std::cout << std::endl;
    t = static_cast <type> (m_type);
    switch (t)
    {
        case type::bar:
                m_value.setterBar(a);
            break;
        case type::atm:
                m_value.setterAtm(a);
            break;
        case type::mmHg:
                m_value.setterMmHg(a);
            break;
        default:
            std::cout << "Wrong value of mesurement. Try again... " << std::endl;
            break;

    }
   
    std::cout << "Converted value: " << m_value.getter() << " Pa" << std::endl;

    return 0;
}

std::ostream & operator <<(std::ostream & out, const Pressure & val)
{
    out << val.m_value;
    return out;
}

std::istream & operator >>(std::istream & in, Pressure & val)
{
    in >> val.m_value;
    return in;
}