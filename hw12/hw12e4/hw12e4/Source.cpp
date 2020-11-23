#include <iostream>
#include <array>

constexpr int prime_number(int n)
{
    int i = 1;
    int j = 1;
    int ind = 1;
    bool a[100] = { true };

    int b[100] = { 2 };

    for (i = 1; i < 100; ++i)
    {
        a[i] = true;
    }

    for (i = 1; 2 * i * (i + 1) < 100; ++i)
    {
        for (j = i; ind = 2 * i * j + i + j, ind < 100; ++j)
        {
            a[ind] = false;
        }
    }
    
    for (i = 1, j = 1; i < 100; ++i)
    {

            if (a[i])
            {


                b[j] = 2 * i + 1;
                ++j;
                
            }  
    }




    return b[n-1];
}

template <int n>
constexpr int prime()
{
    std::array<int, n> a = { 2 }; 

    bool f = true;
    int r = 0;

 
   
     
     

     for (auto i = 3, j = 1; j < n ; ++i, ++j)
     {
         for (auto k = 0; k < n; ++k)
         {
                 if (a[k] != 0 && i % a[k] != 0)
                 {
                     a[j] = i;

                 }
                 else
                 {
                     r = k;
                     f = false;
                     break;
                 }


         }

         if (f == false && j > r)
         {
             --j;
         }

     }
     
         return a[n-1];
}

int main()
{
    constexpr std::size_t N = 10;
    std::cout << std::endl;
    std::cout << prime_number(10) << std::endl;
    std::cout << prime<2000>() << std::endl;
	return 0;
}