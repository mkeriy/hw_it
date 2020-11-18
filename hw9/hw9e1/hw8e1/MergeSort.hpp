#pragma once

#include <iostream>
#include <vector>
#include <functional>

template <typename T, typename FUNC>
void merge_sort(T * array, std::size_t size, FUNC f)
{
    if (size != 0)
    {
        ::merge(array, size, 0, size - 1, f);
    }
    else
    {
        std::cout << "Sequence with zero items." << std::endl;
        abort();
    }
}
  
template <typename T,  typename FUNC>
void merge(T * array, std::size_t size, std::size_t left, std::size_t right, FUNC f)
{
    if (left < right)
    {
        ::merge(array, size, left, left + (right - left) / 2, f);
        ::merge(array, size, left + (right - left) / 2 + 1, right, f);
    }
   
    auto middle = left + (right - left) / 2;
    auto first = left;
    auto last = middle + 1;


    std::vector <T> v1(size);

    for (int j = left; j <= right; j++)
    {
         if ((first <= middle) && ((last > right) || f(array[first], array[last])))
         {
                v1[j] = array[first];
                ++first;
         }
          else
          {
                v1[j] = array[last];
                ++last;
          }
    }
    
 

    for (auto j = left; j <= right; j++)
    {
        array[j] = v1[j];
    }
}

template <typename T, std::size_t size, typename FUNC>
void merge_sort_(T (&array) [size], FUNC f)
{
    if (size != 0)
    {
        
        ::merge(array, size, 0, size - 1, f);
      
    }
    else
    {
        std::cout << "Sequence with zero items." << std::endl;
        abort();
    }
}





   

