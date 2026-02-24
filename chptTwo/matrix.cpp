#include "matrix.h"

int** Matrix::allocate(int rows, int cols) {
    int **matrix = (int**) std::malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) std::malloc(cols * sizeof(int*));
    }

    return matrix;
}

float** Matrix::allocateF(int rows, int cols) {
    float **matrix = (float**) std::malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float*) std::malloc(cols * sizeof(float*));
    }

    return matrix;
}

int** Matrix::populate(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = std::rand() % 10;
        }
    }
    
    return matrix;
}
int** Matrix::populateFromList(int** matrix, int* ints, int rows, int cols) {
    int num = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ints[num];
            num++;
        }
    }

    return matrix;
}