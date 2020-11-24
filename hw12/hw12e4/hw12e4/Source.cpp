#include <iostream>
#include <array>




template <int n>
constexpr int prime()
{
    std::array<int, n> a = { 2 }; 
  
     for (auto i = 3, j = 1; j < n ; ++i, ++j)
     {
         for (auto k = 0; k < n; ++k)
         {
             if (a[k] != 0 && i% a[k] != 0)
             {
                 a[j] = i;
             }
                 else
                 {
                 if (j > k)
                 {
                     --j;
                    }
                     break;
                 }
         }
       
     }
     
         return a[n-1];
}

int main()
{
    std::cout << prime<10>() << std::endl;
	return 0;
}