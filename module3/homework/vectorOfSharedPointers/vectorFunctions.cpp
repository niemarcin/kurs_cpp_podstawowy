#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> newVector;
    newVector.reserve(count);
    for (size_t i = 0; i < count; ++i){
        newVector.emplace_back(std::make_shared<int>(i));
    }
    return newVector;
}

void print(const std::vector<std::shared_ptr<int>>& newVector){
    for (const auto& element : newVector){
        std::cout << *element << "\n";
    }
}

void add10(const std::vector<std::shared_ptr<int>>& newVector){
    for (const auto& element : newVector){
        if (element){
            *element += 10;
        }
    }
}

void sub10(int* const ptr){
    if (ptr){
        *ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& newVector){
    for (const auto& element : newVector){
        sub10(element.get());
    }
}
