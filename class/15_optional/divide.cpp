/*
 * Credit to Sarah McCarthy '23 for this example
 */

//compile with: g++ -std=c++20 practice.cpp -o practice
//run with: ./practice (on mac)

#include <iostream>
#include <optional>

std::optional<int> divide(int numerator, int denominator) {
    if (denominator != 0) return numerator / denominator;
    return std::nullopt;
}

int main() {
  /* CALL HERE WITH (10, 2)*/
  std::optional<int> first = divide(10, 2);
  /* CALL HERE WITH (10, 0)*/
  std::optional<int> second = divide(10, 0);

  std::cout << "first: " << first.has_value() << " value=" << first.value() << std::endl;
  std::cout << "second: " << second.has_value() << " value=" << second.value_or(0) << std::endl;

  return 0;
}