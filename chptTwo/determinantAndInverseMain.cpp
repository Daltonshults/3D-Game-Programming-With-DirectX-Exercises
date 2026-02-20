#include <iostream>
#include "transpose.h"

int main(int argc, char** argv) {

    int ints[] = {1, 3, 5, 9, 1, 3, 1, 7, 4, 3, 9, 7, 5, 2, 0, 9};
    int** matrix = allocate(4, 4);
    populateFromList(matrix, ints, 4, 4);

    printMatrix(matrix, 4, 4);
    int fourDet = fourByfourDet(matrix);
    std::cout << fourDet << "\n";



    return 0;
}