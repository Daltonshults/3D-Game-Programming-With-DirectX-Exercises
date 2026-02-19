#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

// int **matrix;
int rows, cols, rowsT, colsT;

int** allocate() {
    int **matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int*));
    }

    return matrix;
}

int** allocateT() {
    int **matrix = (int**) malloc(cols * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int*));
    }

    return matrix;
}

void populate(int** matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = std::rand() % 10;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int** transposeMatrix(int** matrix, int** matrixT) {
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            matrixT[i][j] = matrix[j][i];
        }
    }

    return matrixT;
}

int main(int argc, char** argv) {

    if (argc < 3) {
        std::cout << "Usuage './transpose int int'\n";
        return 1;
    } else if (argc > 3) {
        std::cout << "Usuage './transpose int int'\n";
        return 1;
    }
    
    rows = std::stoi(*&argv[1]);
    colsT = std::stoi(*&argv[1]);
    cols = std::stoi(*&argv[2]);
    rowsT = std::stoi(*&argv[2]);


    srand(time(NULL));
    int** matrix = allocate();
    populate(matrix);
    printMatrix(matrix, rows, cols);

    int** matrixT = allocateT();
    matrixT = transposeMatrix(matrix, matrixT);
    std::cout << "\n";
    printMatrix(matrixT, rowsT, colsT);


    return 0;
}