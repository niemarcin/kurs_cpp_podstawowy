#include <iostream>
#include <string>

// TODO: Implement foo()
// It should modify passed string to text "Other string"
void foo(std::string& str) {
    str = "Other string";
}

int main() {
    std::string str("Some string");
    foo(str);
    std::cout << str << '\n';
    return 0;
}
