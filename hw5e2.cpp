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

    auto setter(double v)
    {
        m_value = v;
        return m_value;
    }
    
    auto bar()
    {
        m_value *= c_bar;
        return m_value;    
    }
    auto atm()
    {
        m_value *= c_atm; 
        return m_value;
    } 
    auto mmHg()
    {
        m_value *= c_mmhg;
        return m_value;
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
    int m_type;
    type t;
    

    std::cout << "This program can only convert values from bar, mmHg and atmospheres to Pascals" << std::endl;
    std::cout << "Enter the value" << std::endl;
    std::cin >> m_value;
    

   std::cout << "1 - bar \n" << "2 - atm \n" << "3 - mmHg\n" << std::endl;
   std::cout << "Enter a Number : ";
    std::cin >> m_type;
    std::cout << std::endl;
    t = static_cast <type> (m_type);
    switch (t)
    {
        case type::bar:
                m_value.setter(m_value.bar());
            break;
        case type::atm:
                m_value.setter(m_value.atm());
            break;
        case type::mmHg:
                m_value.setter(m_value.mmHg());
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