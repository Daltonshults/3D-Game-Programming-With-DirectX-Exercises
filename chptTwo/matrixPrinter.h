#pragma once
#include <iostream>

class MatrixPrinter {

public:
    MatrixPrinter() = default;
    ~MatrixPrinter() = default;

    void printMatrix(int** matrix, int rows, int cols);
    void printFMatrix(float**, int rows, int cols);
};