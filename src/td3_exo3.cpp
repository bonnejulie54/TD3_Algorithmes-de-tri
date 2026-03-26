#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

int main()
{
    std::vector<int> array {3, 2, 7, 8, 1, 6, 5, 4, 7};
    
    for( int k=0; k<array.size();k++){
        std::cout << array[k] << std::endl;
    }
    

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }


}