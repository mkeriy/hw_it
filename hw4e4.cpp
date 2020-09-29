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

void daysMonth(month mth, int n){

    switch (mth)
    {
        case month::yan:
            std::cout << "In Yanuary 31 days" << std::endl;
            break;
        case month::feb:
            std::cout << "In February " << n << " days" << std::endl;
            break;
        case month::march:
            std::cout << "In March 31 days" << std::endl;
            break;
        case month::april:
            std::cout << "In april 30 days" << std::endl;
            break;
        case month::may:
            std::cout << "In may 31 days" << std::endl;
            break;
        case month::june:
            std::cout << "In June 30 days" << std::endl;
            break;
        case month::july:
            std::cout << "In July 31 days" << std::endl;
            break;
        case month::aug:
            std::cout << "In August 31 days" << std::endl;
            break;
        case month::sept:
            std::cout << "In September 30 days" << std::endl;
            break;
        case month::oct:
            std::cout << "In October 31 days" << std::endl;
            break;
        case month::nov:
            std::cout << "In November 30 days" << std::endl;
            break;
        case month::dec:
            std::cout << "In December 31 days" << std::endl;
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
    int n = 28;

    std::cout << "Enter the year starting from 1900: ";
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
    mth = (month) m;
    
   if ((year - 1900) % 4 == 0)
   {
       ++n;
       daysMonth(mth, n);
   }
   else 
   {
       daysMonth(mth, n);
   }
     


    return 0;
}