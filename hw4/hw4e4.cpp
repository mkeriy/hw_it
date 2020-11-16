#include <iostream>
#include <string>

enum class month{

    yan = 1,
    feb = 2,
    march = 3,
    april = 4,
    may = 5,
    june = 6,
    july = 7,
    aug = 8,
    sept = 9,
    oct = 10,
    nov = 11,
    dec = 12

};

void daysMonth(month mth, int year){
    int n = 28;
    if (year % 4 == 0)
    {
       ++n;
    }

    switch (mth)
    {
        case month::yan:
        case month::march:
        case month::may:
        case month::july:
        case month::aug:
        case month::oct:
        case month::dec:
            std::cout << "31 days" << std::endl;
            break;
            
        case month::feb:
            std::cout << "In February " << n << " days" << std::endl;
            break;
        
        case month::april:
        case month::june:
        case month::sept:
        case month::nov:
            std::cout << "30 days" << std::endl;
            break;
        default:
            std::cout << "Wrong number of month. Try again..." << std::endl;
            break;


    }
}

int main(){

    int year;
    month mth;
    int m;


    std::cout << "Enter the year starting: ";
    std::cin >> year;

    std::cout << "Select the month in which you want to know the number of days." << std::endl;
    std::cout << "1 - Yanuary\n" 
              << "2 - February\n"
              << "3 - March\n"
              << "4 - April\n"
              << "5 - May\n"
              << "6 - June\n"
              << "7 - July\n"
              << "8 - August\n"
              << "9 - September\n"
              << "10 - October\n"
              << "11 - November\n"
              << "12 - December" << std::endl;
    std::cout << "Enter a number of month: ";
    std::cin >> m;
    std::cout << std::endl; 
    
    mth = static_cast <month> (m);
    
    daysMonth(mth, year); 


    return 0;
}