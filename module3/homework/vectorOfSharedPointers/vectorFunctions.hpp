#pragma once
#include <memory>
#include <vector>

std::vector<std::shared_ptr<int>> generate(int count);
void print(const std::vector<std::shared_ptr<int>>& newVector);
void add10(const std::vector<std::shared_ptr<int>>& newVector);
void sub10(int* const ptr);
void sub10(const std::vector<std::shared_ptr<int>>& newVector);
