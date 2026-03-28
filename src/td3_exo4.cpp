#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int search(const std::vector<int>& tab, int value) {
    int left = 0;
    int right = tab.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (tab[middle] == value) {
            return middle;
        }
        else if (tab[middle] > value) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return -1;
}

int afficherResultat(const std::vector<int>& tab, int value) {
    int result = search(tab, value);

    if (result != -1) {
        std::cout << "Valeur " << value << " trouvée à l'indice : " << result << std::endl;
    } else {
        std::cout << "Valeur " << value << " non trouvée dans le tableau" << std::endl;
    }

    return 0;
}

int main()
{

    std::vector<int> t1 = {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> t2 = {1, 2, 3, 3, 6, 14, 12, 15}; 
    std::vector<int> t3 = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> t4 = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> t5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    afficherResultat(t1, 8);
    afficherResultat(t2, 15);
    afficherResultat(t3, 16);
    afficherResultat(t4, 6);
    afficherResultat(t5, 10);
    


}