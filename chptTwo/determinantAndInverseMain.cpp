#include <iostream>
#include "determinant.h"
#include "matrixPrinter.h"

int main(int argc, char** argv) {
    int ints[] = {1, 3, 5, 9, 1, 3, 1, 7, 4, 3, 9, 7, 5, 2, 0, 9};
    Determinant d(4, 4, ints);
    MatrixPrinter m;
    m.printMatrix(d.getMatrix(), 4, 4);
    std::cout << d.getDet() << "\n";
    return 0;
}