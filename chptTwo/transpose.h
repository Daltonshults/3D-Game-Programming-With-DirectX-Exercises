#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "matrixPrinter.h"
#include "matrix.h"

class Transpose {
public:
    Transpose(int** matrix, int rows, int cols);
    // ~Transpose() = default;

    void run();
    int** getMatrixT();

private:
    Matrix m;
    int rows;
    int cols;
    int* ints;
    int rowsT;
    int colsT;
    int** matrix;
    int** matrixT;

    // int** allocate(int rows, int cols);
    // void populate(int** matrix);
    int** transposeMatrix(int** matrix, int** matrixT);
    void freeMatrix(int** matrix, int rows);
};
