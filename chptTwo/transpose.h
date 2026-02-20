#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>

class Transpose {
public:
    Transpose(int rows, int cols);
    ~Transpose();

    void run();

private:
    int rows;
    int cols;
    int rowsT;
    int colsT;
    int** matrix;
    int** matrixT;

    int** allocate(int rows, int cols);
    void populate(int** matrix);
    void transposeMatrix(int** matrix, int** matrixT);
    void freeMatrix(int** matrix, int rows);
};
