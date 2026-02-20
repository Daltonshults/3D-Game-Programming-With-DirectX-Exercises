#pragma once
#include <iostream>
#include "matrix.h"
class Determinant {

public:
    Determinant(int rows, int cols, int* ints);
    ~Determinant() = default;

    void run();

    int getDet();
    int** getMatrix();

private:
    Matrix m;
    int** matrix;
    int rows;
    int cols;
    int *ints;
    int det;

    // void populateFromList(int** matrix, int ints[], int rows, int cols);
    // int** allocate(int rows, int cols);
    int twoByTwoDet(int** matrix);
    void populateMats(int*** mats, int** matrix, int indexes);
    int threeByThreeDet(int** matrix);
    int fourByFourDet(int** matrix);
};