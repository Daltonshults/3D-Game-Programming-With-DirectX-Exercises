#include <iostream>
#include <string>
#include "transpose.h"

int rows, cols;

int main(int argc, char** argv) {

    if (argc < 3) {
        std::cout << "Usuage './transpose int int'\n";
        return 1;
    } else if (argc > 3) {
        std::cout << "Usuage './transpose int int'\n";
        return 1;
    }
    
    rows = std::stoi(*&argv[1]);
    cols = std::stoi(*&argv[2]);
    int ints[] = {1, 3, 5, 9, 1, 3, 1, 7, 4, 3, 9, 7, 5, 2, 0, 9};

    Transpose t(rows, cols, ints);
    t.run();
    return 0;
}