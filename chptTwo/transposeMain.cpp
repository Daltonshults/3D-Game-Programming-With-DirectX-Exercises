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

    Transpose t(rows, cols);
    t.run();
    return 0;
}