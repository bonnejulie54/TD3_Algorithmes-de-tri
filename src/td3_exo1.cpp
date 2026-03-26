#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

void bubble_sort(std::vector<int> & vec){
    int N =vec.size();

    for(int i=0; i< N;i++){
        for ( int j=0; j<N-1-i;j++){
            if (vec[j]>vec[j+1])
            {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}


int main()
{
    std::vector<int> array {3, 2, 7, 8, 1, 6, 5, 4, 7};
    bubble_sort(array);
    for( int k=0; k<array.size();k++){
        std::cout << array[k] << std::endl;
    }
    

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }


}