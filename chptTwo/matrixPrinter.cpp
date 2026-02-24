#include "matrixPrinter.h"
#include <iomanip>

void MatrixPrinter::printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void MatrixPrinter::printFMatrix(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::fixed << std::setprecision(6) 
                << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}