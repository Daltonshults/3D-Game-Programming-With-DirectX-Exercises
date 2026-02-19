#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

int rows, cols, rowsT, colsT;

int** allocate(int rows, int cols) {
    int **matrix = (int**) malloc(rows * sizeof(int *));
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

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        std::free(matrix[i]);
    }
    std::free(matrix);
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
    colsT = rows;
    cols = std::stoi(*&argv[2]);
    rowsT = cols;

    // Seeding srand
    srand(time(NULL));

    // Creating matrix of correct size
    int** matrix = allocate(rows, cols);
    populate(matrix);
    printMatrix(matrix, rows, cols);

    // Creating matrix to transpose
    int** matrixT = allocate(rowsT, colsT);
    matrixT = transposeMatrix(matrix, matrixT);
    std::cout << "\n";
    printMatrix(matrixT, rowsT, colsT);

    freeMatrix(matrix, rows);
    freeMatrix(matrixT, rowsT);
    return 0;
}