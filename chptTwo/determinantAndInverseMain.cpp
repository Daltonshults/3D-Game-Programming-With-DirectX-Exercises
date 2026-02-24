#include <iostream>
#include "determinant.h"
#include "inverse.h"
#include "matrixPrinter.h"

int main(int argc, char** argv) {
    int ints[] = {1, 3, 5, 9, 1, 3, 1, 7, 4, 3, 9, 7, 5, 2, 0, 9};
    Determinant d(4, 4, ints);
    MatrixPrinter m;
    m.printMatrix(d.getMatrix(), 4, 4);
    std::cout << d.getDet() << "\n";

    Inverse i(4, 4, ints, d);
    float** IA = i.getInverse();
    m.printMatrix(i.getC(), 4, 4);
    std::cout << "\n\n";
    m.printFMatrix(IA, 4, 4);

    return 0;
}