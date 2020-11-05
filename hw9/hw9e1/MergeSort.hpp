#pragma once

#include <iostream>
#include <vector>
#include <functional>

template <typename T, typename T1, typename FUNC = std::function<bool(const T& lhs, const T& rhs)>>
void merge_sort(T * array, T1 size, FUNC f = [](const T& lhs, const T& rhs) {return lhs > rhs; })
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
  
template <typename T, typename T1, typename T2, typename FUNC>
void merge(T * array, T1 size, T2 left, T2 right, FUNC f)
{
    if (left < right)
    {
        ::merge(array, size, left, left + (right - left) / 2, f);
        ::merge(array, size, left + (right - left) / 2 + 1, right, f);
    }
   
    int middle = left + (right - left) / 2;
    int first = left;
    int last = middle + 1;


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
    
 

    for (int j = left; j <= right; j++)
    {
        array[j] = v1[j];
    }
}

template <typename T, int size >
void merge_sort_(T (&array) [size])
{
    if (size != 0)
    {
        ::merge_(array, 0, size - 1);
    }
    else
    {
        std::cout << "Sequence with zero items." << std::endl;
        abort();
    }
}

template <typename T, int size, typename T2>
void merge_(T (&array) [size], T2 left, T2 right)
{
    if (left < right)
    {
        ::merge_(array, left, left + (right - left) / 2);
        ::merge_(array, left + (right - left) / 2 + 1, right);
    }

    int middle = left + (right - left) / 2;
    int first = left;
    int last = middle + 1;


    std::vector <T> v1(size);

    for (int j = left; j <= right; j++)
    {
        if ((first <= middle) && ((last > right) || (array[first] < array[last])))
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



    for (int j = left; j <= right; j++)
    {
        array[j] = v1[j];
    }
}


