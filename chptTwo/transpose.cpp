#include <cstdlib>
#include <iostream>

int **matrix;
int rows = 4, cols = 4;

void allocate(int rows, int cols) {
    matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < 4; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int*));
    }
}

void populate(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i+j;
        }
    }
}

void printMatrix(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        std::cout << "\n";
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    
    allocate(rows, cols);
    populate(rows, cols);
    printMatrix(rows, cols);

    
    return 0;
}