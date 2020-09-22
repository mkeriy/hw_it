#include <iostream>
#include <vector>

void merge_sort(std::vector <double> & v, int left , int right);
void merge(std::vector <double> & v, int left, int right);

int main() {
    
    int size;
    std::cout << "Enter size of sequance: ";
    std::cin >> size;
    std::cout << std::endl;

    std::vector <double> sequence(size, 0);

    std::cout << "Enter items of sequence." << std::endl;
    for(double & element : sequence)
    {

        std::cin >> element;
    
    }

    merge_sort(sequence, 0, sequence.size()-1);


    std::cout << "Sorted sequence." << std::endl;
    for (double item : sequence)
    {
        std::cout << item << ' ';
    }



    return 0;
}



void merge_sort(std::vector <double> & v, int left , int right){

    if  (left < right)
    {
        merge_sort(v, left,  left + (right - left)/2); 
        merge_sort(v, left + (right - left)/2 + 1, right); 

        merge(v, left, right);
    }
    else    
    {
        return;
    }
}

void merge(std::vector <double> & v, int left, int right)
{

    int middle =  left + (right - left)/2;
    int first = left;
    int last = middle + 1; 
 
    
    std::vector <double> v1(v.size());
    
    
    for(int j = left; j <= right; j++)
    {
        if ( (first <= middle) && ((last > right) || (v[first] < v[last])))
        {
            v1[j] = v[first];
            ++first;
        }
        else
        {
            v1[j] = v[last];
            ++last;
        }
    }

    for (int j = left; j <= right; j++) 
    {    
        v[j] = v1[j];
    }    
}







