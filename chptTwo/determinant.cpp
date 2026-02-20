
#include "determinant.h"

Determinant::Determinant(int rows, int cols, int* ints)
    :matrix(nullptr), rows(rows), cols(cols), ints(ints)
{
    matrix = m.allocate(rows, cols);
    matrix = m.populateFromList(matrix, ints, rows, cols);
    det = fourByFourDet(matrix); 
}

int Determinant::getDet() {
    return this->det;
}

int** Determinant::getMatrix() {
    return this->matrix;
}

int Determinant::twoByTwoDet(int** matrix) {
    return (int) ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}
void Determinant::populateMats(int*** mats, int** matrix, int indexes) {

    for (int i = 0; i < indexes; i ++) {
        mats[i] = m.allocate(indexes-1, indexes-1);
    }

    int currentI = 0;
    int currentJ = 0;
    int rowI = 0;
    int colJ = 0;
    // For every matrix in mats
    for (int index = 0; index < indexes; index++) {

        // For every i in matrix[index]
        for (int i = 0; i < indexes; i++) {

            // If row matches current row skip
            if (i != rowI) {

                // For every j in matrix[index][i]
                for(int j = 0; j < indexes; j++) {

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
        
        // Increment the column we aren't using
        colJ++;
    }
}

int Determinant::threeByThreeDet(int** matrix) {
    int** mats[3];
    populateMats(mats, matrix, 3);

    return matrix[0][0] * twoByTwoDet(mats[0]) 
        - matrix[0][1] * twoByTwoDet(mats[1]) 
        + matrix[0][2] * twoByTwoDet(mats[2]); 
}

int Determinant::fourByFourDet(int** matrix) {
    int** mats[4];
    populateMats(mats, matrix, 4);

    return matrix[0][0] * threeByThreeDet(mats[0])
        - matrix[0][1] * threeByThreeDet(mats[1]) 
        + matrix[0][2] * threeByThreeDet(mats[2]) 
        - matrix[0][3] * threeByThreeDet(mats[3]); 
}
