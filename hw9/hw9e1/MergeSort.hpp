#pragma once

#include <iostream>
#include <vector>
#include <functional>

template <typename T, typename FUNC>
void merge_sort(T * array, std::size_t size, FUNC f = [](const T& lhs, const T& rhs) {return lhs > rhs; })
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

template <typename T, std::size_t size>
void merge_sort_(T (&array) [size])
{
    if (size != 0)
    {
        T* newArray = new T[size];
        for (auto i = 0; i < size; ++i)
        {
            newArray[i] = array[i];
        }
        ::merge(newArray, size, 0, size - 1, [](const T& lhs, const T& rhs) {return lhs > rhs; });
        for(auto i = 0; i < size; ++i)
        {
            array[i] = newArray[i];
        }
        delete[] newArray;
    }
    else
    {
        std::cout << "Sequence with zero items." << std::endl;
        abort();
    }
}





   

