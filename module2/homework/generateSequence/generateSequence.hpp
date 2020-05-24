#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> result;
    if (count > 0) {
        result.resize(count);
        result[0] = step;

        for (auto it = result.begin() + 1; it < result.end(); ++it) {
            *it = *(it - 1) + step;
        }
    }
    return result;
}
