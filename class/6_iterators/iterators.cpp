#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5};

    std::cout << "auto num : numbers // Doesn't modify original vector" << std::endl;
    for (auto num : numbers) {
        num *= 2;  // This will not affect the original vector because num is a copy
    }
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reset vector
    numbers = {1, 2, 3, 4, 5};

    std::cout << "auto& num : numbers // Can modify original vector" << std::endl;
    for (auto& num : numbers) {
        num *= 3;  // This will modify the original vector because num is a reference
    }
    for (auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reset vector
    numbers = {1, 2, 3, 4, 5};

    std::cout << "const auto& num : numbers // Cannot modify original vector" << std::endl;
    for (const auto& num : numbers) {
        // num *= 2; // error: cannot assign to variable 'num' with const-qualified type 'int const &' because num is const
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}