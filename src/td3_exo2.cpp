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

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left >= right) return;
    size_t middle = (left + right) / 2;
    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);
    merge_sort_merge(vec, left, middle, right);
}

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right) {

    std::vector<int> leftVec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> rightVec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t i = 0; 
    size_t j = 0; 
    size_t k = left; 
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < leftVec.size()) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < rightVec.size()) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}


int main()
{

{
ScopedTimer timer("chrono exo2");
    std::vector<int> array {3, 2, 7, 8, 1, 6, 5, 4, 7};
    merge_sort(array);
    for( int k=0; k<array.size();k++){
        std::cout << array[k] << std::endl;
    }


    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}

}