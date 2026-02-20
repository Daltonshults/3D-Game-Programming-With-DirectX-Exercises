#include <iostream>

void populateFromList(int** matrix, int ints[], int rows=4, int cols=4) {
    int num = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ints[num];
            num++;
        }
    }
}

int** allocate(int rows, int cols) {
    int **matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int*));
    }

    return matrix;
}

int twoByTwoDet(int** matrix) {
    return (int) ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}
void populateMats(int*** mats, int** matrix, int indexes) {
    for (int i = 0; i < indexes; i ++) {
        mats[i] = allocate(indexes-1, indexes-1);
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

int threeByThreeDet(int** matrix) {
    int** mats[3];
    populateMats(mats, matrix, 3);

    return matrix[0][0] * twoByTwoDet(mats[0]) 
        - matrix[0][1] * twoByTwoDet(mats[1]) 
        + matrix[0][2] * twoByTwoDet(mats[2]); 
}

int fourByfourDet(int** matrix) {
    int** mats[4];
    populateMats(mats, matrix, 4);

    return matrix[0][0] * threeByThreeDet(mats[0])
        - matrix[0][1] * threeByThreeDet(mats[1]) 
        + matrix[0][2] * threeByThreeDet(mats[2]) 
        - matrix[0][3] * threeByThreeDet(mats[3]); 
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char** argv) {

    int ints[] = {1, 3, 5, 9, 1, 3, 1, 7, 4, 3, 9, 7, 5, 2, 0, 9};
    int** matrix = allocate(4, 4);
    populateFromList(matrix, ints, 4, 4);

    printMatrix(matrix, 4, 4);
    int fourDet = fourByfourDet(matrix);
    std::cout << fourDet << "\n";



    return 0;
}