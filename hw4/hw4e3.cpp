#include <iostream>

struct Time{
        Time (unsigned int y, unsigned int m, unsigned int d, unsigned int h, unsigned int min, unsigned int s, unsigned int ms):
            year(y), month(m), day(d), hour(h), minute(min), second(s), millisecond(ms)
            {};
        ~Time ()
        {};
    unsigned int year : 11;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int hour : 5;
    unsigned int minute : 6;
    unsigned int second : 6;
    unsigned int millisecond : 10;
};


int main(){

    Time e(2020, 12, 3, 23, 59, 59, 999);

   std::cout << e.year << '.' << e.month << '.' << e.day 
             << "    " << e.hour << ':' << e.minute << ':'
             << e.second << '.' << e.millisecond << std::endl;

    return 0;
}