#include <iostream>

class Determinant {

    Determinant();
    ~Determinant();

    void run();

private:
    void populateFromList(int** matrix, int ints[], int rows, int cols);
    int** allocate(int rows, int cols);
    int twoByTwoDet(int** matrix);
    void populateMats(int*** mats, int** matrix, int indexes);
    int threeByThreeDet(int** matrix);
    int fourByFourDet(int** matrix);
};