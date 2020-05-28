#include <iostream>
#include <memory> 
// TODO: Implement foo()
// It should take 2 int values and return their product as a shared_ptr.
// Additionally, check how many owners are there.

std::shared_ptr<int> foo(const int& a, const int& b) {
    auto result = std::make_shared<int> (a*b);

    std::cout << "result: " << *result << " | owners: " << result.use_count() << "\n";

    return result;
}

int main() {
    auto number = foo(10, 20);
    std::cout << "num: " << *number << " | owners: " << number.use_count() << "\n";

    return 0;
}
