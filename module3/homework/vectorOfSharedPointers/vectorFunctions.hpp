#pragma once
#include <memory>
#include <vector>

std::vector<std::shared_ptr<int>> generate(int);
void print(std::vector<std::shared_ptr<int>>& newVector);
void add10(std::vector<std::shared_ptr<int>>& newVector);
void sub10(int* const ptr);
void sub10(std::vector<std::shared_ptr<int>>& newVector);
