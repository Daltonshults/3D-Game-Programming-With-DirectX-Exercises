#include "./transpose.h"
#include "./matrixPrinter.h"

Transpose::Transpose(int rows, int cols)
    :rows(rows), cols(cols), rowsT(cols), colsT(rows), matrix(nullptr), matrixT(nullptr)  
{
    std::srand(time(NULL));
    matrix = allocate(rows, cols);
    matrixT = allocate(rowsT, colsT);
    populate(this->matrix);
    transposeMatrix(this->matrix, this->matrixT);
}

Transpose::~Transpose() {
    freeMatrix(this->matrix, this->rows);
    freeMatrix(this->matrixT, this->rowsT);
}

int** Transpose::allocate(int rows, int cols) {
    int **matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int*));
    }

    return matrix;
}

void Transpose::populate(int** matrix) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            matrix[i][j] = std::rand() % 10;
        }
    }
}

void Transpose::transposeMatrix(int** matrix, int** matrixT) {
    for (int j = 0; j < this->rows; j++) {
        for (int i = 0; i < this->cols; i++) {
            this->matrixT[i][j] = this->matrix[j][i];
        }
    }
}

void Transpose::freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        std::free(matrix[i]);
    }
    std::free(matrix);
}

void Transpose::run() {
    MatrixPrinter m;
    m.printMatrix(this->matrix, this->rows, this->cols);
    std::cout << "\n";
    m.printMatrix(this->matrixT, this->rowsT, this->colsT);
}
