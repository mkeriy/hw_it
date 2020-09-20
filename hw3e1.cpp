#include <iostream>


//первый случай
int f1(int a, int b){

    std::cout << a + b << std::endl;

}

double f1(double a, double b){

    std::cout << a + b << std::endl;

}

//второй случай
int f2(int a, int d = 1){

    std::cout << a / d << std::endl;

}

//третий случай
void f3(char k){

    std::cout << 2 * k << std::endl;    

}

void f3(unsigned char k){

    std::cout << k - 1 << std::endl;

}

int main() {

    f1(1, 1.0);
    f2(2);
    f3(19);



    return 0;
}