#include <iostream>
#include <sstream>
#include <string>

int stringToInt(const std::string & str) {
    std::istringstream iss(str);

    int result; int remain;
    if (!(iss >> result) || (iss >> remain)) {
        throw std::invalid_argument("Invalid integer string: " + str);
    }
    return result;
}

int main() {
    try {
        std::string input = "12345";
        int value = stringToInt(input);
        std::cout << "The integer value is: " << value << std::endl;

        input = "12abc34"; // Invalid input
        value = stringToInt(input);
        std::cout << "The integer value is: " << value << std::endl;

        input = "abc"; // Invalid input
        value = stringToInt(input);
        std::cout << "The integer value is: " << value << std::endl;
    } catch (const std::invalid_argument & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}