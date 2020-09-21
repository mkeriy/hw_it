#include <iostream>
#include <vector>

void merge_sort(std::vector <double> & v);
void merge(const std::vector <double> & v1, const std::vector <double> & v2, std::vector <double> & v);

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

    merge_sort(sequence);


    std::cout << "Sorted sequence." << std::endl;
    for (double & item : sequence)
    {
        std::cout << item << ' ';
    }



    return 0;
}


void merge_sort(std::vector <double> & v){
    std::vector <double> l;
    std::vector <double> r;
    if(v.size() <= 1)
    {
        return;
    }
    else
    {
        
        for(int i = 0; i < v.size()/2; ++i)
        {
            l.push_back(v[i]);
        }

        for(int i = v.size()/2; i < v.size(); ++i)
        {
            r.push_back(v[i]);
        } 
    }

    
    merge_sort(l);
    merge_sort(r);
   
    merge(l, r, v);

}

void merge(const std::vector <double> & v1, const std::vector <double> & v2, std::vector <double> & v){
   
    int i = 0;
    int j = 0;
    int k = 0;
    

    while(i < v1.size() && j < v2.size() && k < v.size())
    {
        if(v1[i] <= v2[j])
        {
            v[k] = v1[i];
            ++i;
            
        }
        else
        {
            v[k] = v2[j];
            ++j;
            
        }
        ++k;
    
    }

   if (i < v1.size()) 
    {
		for (; i < v1.size() && k < v.size(); ++i, ++k)
        {
			v[k] = v1[i];
        }    
	}

	if (j < v2.size()) 
    {
		for (; j < v2.size() && k < v.size(); ++j, ++k)
        {
			v[k] = v2[j];
        }    
	}
    
    

    
}





