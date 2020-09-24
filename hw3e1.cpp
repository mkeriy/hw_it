#include <iostream>



//первый случай
void f1(int a, double b = 0.0){}

void f1(int a){}

//второй случай
void f2(double * a, int d = 2){}



void f2(int *b, double a = 0){}

//третий случай
void f3(int k){}

void f3(double k){}

int main(){
   

    f1(1);
    f2(nullptr);
    f3(0U);



    return 0;
}