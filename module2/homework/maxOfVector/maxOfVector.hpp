#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int maxValue = INT32_MIN;
    for (const auto& element : vec) {
        if (element > maxValue) {
            maxValue = element;
        }
    }

    return maxValue;
}
