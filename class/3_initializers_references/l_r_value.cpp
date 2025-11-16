#include <iostream>
#include <math.h>

// Passed by reference
void squareN(int& n) {
    n = std::pow(n, 2);
}

int main() {
    int num = 5;
    squareN(num);

    std::cout << num << std::endl;

    return 0;
}