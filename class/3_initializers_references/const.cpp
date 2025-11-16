#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    const std::vector<int> const_vec{10, 20, 30, 40, 50};
    std::vector<int> & ref_vec{vec};
    const std::vector<int> & const_ref_vec{const_vec};
    const std::vector<int> & const_ref_non_const_vec{vec};
    // std::vector<int> & non_const_ref_const_vec{const_vec}; // cannot bind non-const lvalue reference to a const vector

    vec.push_back((6)); // OK
    // const_vec.push_back(60); // Error: cannot modify a const vector
    ref_vec.push_back((7)); // OK
    // const_ref_vec.push_back(70); // Error: cannot modify a const vector
    // const_ref_non_const_vec.push_back(8); // Error: cannot modify through a const reference

    return 0;
}