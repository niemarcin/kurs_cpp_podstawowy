#include <iostream>
#include "fibonacci.hpp"

int main() {
    std::cout << fibonacci_iterative(13) << "\n";
    std::cout << fibonacci_recursive(13) << "\n";

    return 0;
}
