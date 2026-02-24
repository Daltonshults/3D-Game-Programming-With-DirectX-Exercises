#pragma once
#include <cstdlib>

class Matrix {
public:
    Matrix() = default;
    ~Matrix() = default;

    float** allocateF(int rows, int cols);
    int** allocate(int rows, int cols);
    int** populate(int** matrix, int rows, int cols);
    int** populateFromList(int** matrix, int* ints, int rows, int cols);

};