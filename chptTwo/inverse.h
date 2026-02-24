#pragma once
#include "matrix.h"
#include "determinant.h"
#include "transpose.h"

class Inverse {

public:
    Inverse(int rows, int cols, int* ints, Determinant& d);
    ~Inverse() = default;

private:
    int rows, cols;
    Matrix m;
    Determinant& d;
    int** matrix;
    int** C;
    int** CT;
    int *ints;
    int det;
    float** IA;

public:
    void convertC(int** matrix, int** C, int*** mats);
    void populateMats(int*** mats, int** matrix, int indexes);
    void transposeC();
    void calculateInverse();
    float** getInverse();
    int** getMatrix();
    int** getCT();
    int** getC();
    void run();
};