#include "inverse.h"

Inverse::Inverse(int rows, int cols, int* ints, Determinant& d)
    :rows(rows), cols(cols), ints(ints), d(d), matrix(nullptr) 
{
    this->matrix = m.allocate(rows, cols);
    this->IA = m.allocateF(rows, cols);
    this->matrix = m.populateFromList(matrix, ints, rows, cols);
    this->det = d.getDet();
    this->C = m.allocate(rows, cols);
    int** mats[16];
    convertC(this->matrix, this->C, mats);
    transposeC();
    calculateInverse();
}
int** Inverse::getMatrix() {
    return this->matrix;
}

void Inverse::populateMats(int*** mats, int** matrix, int indexes) {
    int mIndex = indexes / 4;
    for (int i = 0; i < indexes; i ++) {
        mats[i] = m.allocate(mIndex-1, mIndex-1);
    }

    int currentI = 0;
    int currentJ = 0;
    int rowI = 0;
    int colJ = 0;
    // For every matrix in mats
    for (int index = 0; index < indexes; index++) {

        // For every i in matrix[index]
        for (int i = 0; i < mIndex; i++) {

            // If row matches current row skip
            if (i != rowI) {

                // For every j in matrix[index][i]
                for(int j = 0; j < mIndex; j++) {

                    // If collumn matches skip
                    if (j != colJ){
                        mats[index][currentI][currentJ] = matrix[i][j];
                        currentJ++;                        
                    }
                }

                // reset currentJ and increment currentI
                currentJ = 0;
                currentI++;
            }
        }
        // reset currentJ and currentI
        currentJ = 0;
        currentI = 0;
        
        if (colJ == 3) {
            colJ = 0;
            rowI++;
        } else {
            // Increment the column we aren't using
            colJ++;
        }
    }
}

void Inverse::convertC(int** matrix, int** C, int*** mats) {
    Inverse::populateMats(mats, matrix, 16);
    int rowI = 0;
    int colJ = 0;
    for (int i = 0; i < 16; i++) {
        int sign = ((rowI + colJ) % 2 == 0) ? 1 : -1;
        int detC = sign * d.threeByThreeDet(mats[i]);
        C[rowI][colJ] = detC;
        if (colJ == 3) {
            rowI++;
            colJ = 0;
        } else {
            colJ++;
        }
    }
}

void Inverse::transposeC() {
    Transpose t(this->C, 4, 4);
    this->CT = t.getMatrixT();
}

float** Inverse::getInverse() {
    return this->IA;
}

int** Inverse::getCT() {
    return this->CT;
}

int** Inverse::getC() {
    return this->C;
}

void Inverse::calculateInverse() {
    int rowI = 0;
    int rowJ = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->IA[i][j] = (1.0f / this->det) * this->CT[i][j];
        }
    }
}