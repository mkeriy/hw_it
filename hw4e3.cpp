#include <iostream>

struct Time{
        Time (int y, int m, int d, int h, int min, int s, int ms):
            year(y), month(m), day(d), hour(h), minute(min), second(s), millisecond(ms)
            {};
        ~Time ()
        {};
    int year : 12;
    int month : 5;
    int day : 6;
    int hour : 6;
    int minute : 7;
    int second : 7;
    int millisecond : 8;
};


int main(){

    Time e(2020, 12, 3, 23, 59, 59, 99);

   std::cout << e.year << '.' << e.month << '.' << e.day 
             << "    " << e.hour << ':' << e.minute << ':'
             << e.second << '.' << e.millisecond << std::endl;

    return 0;
}