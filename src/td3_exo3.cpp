#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"
#include <cstdlib>


std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

int main()
{

    {
    ScopedTimer timer("chrono std::sort");
        std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::sort(array.begin(), array.end());
    }
    

}
/* On observe que std::sort est beacoup plus rapide que nos deux algorithmes de tri : 
    1- chrono std::sort : 1.959us (0.001959ms)
    2- chrono exo1 : 22.625us (0.022625ms)
    3- chrono exo2 : 36.167us (0.036167ms)
 */