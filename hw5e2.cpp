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
    
    
    
   
    void bar()
    {
        m_value *= c_bar;    
    }
    void atm()
    {
        m_value *= c_atm; 
    } 
    void mmHg()
    {
        m_value *= c_mmhg;
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
    std::string m_type;
    type t;
    

    std::cout << "This program can only convert values from bar, mmHg and atmospheres to Pascals" << std::endl;
    std::cout << "Enter the value and the pressure mesurement separated by a space." << std::endl;
    std::cin >> m_value;
    std::cin >> m_type;

    if (m_type == "bar")
    {
        t = static_cast <type> (1);
    }
    else
    {
          std::cout << "Wrong value of mesurement. Try again... " << std::endl;
    }
    if (m_type == "atm")
    {
        t = static_cast <type> (2);
    }
    else
    {
          std::cout << "Wrong value of mesurement. Try again... " << std::endl;
    }
     if (m_type == "mmHg")
    {
        t = static_cast <type> (3);
    }
    else
    {
          std::cout << "Wrong value of mesurement. Try again... " << std::endl;
    }

    switch (t)
    {
        case type::bar:
            m_value.bar();
            break;
        case type::atm:
            m_value.atm();
            break;
        case type::mmHg:
            m_value.mmHg();
            break;
        default:
            std::cout << "Wrong value of mesurement. Try again... " << std::endl;
            break;

    }

    std::cout << "Converted value: " << m_value << " Pa" << std::endl;

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