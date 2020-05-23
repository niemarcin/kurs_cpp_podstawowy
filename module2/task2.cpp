#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> concatenateVector(std::vector<int> first, std::vector<int> second){
  std::vector<int> result;
  int i, j;
  
  for (i = 0, j = 0; i < std::min(first.size(), second.size()); ++i, ++j){
   result.push_back(first[i]);
   result.push_back(second[i]);
  }
  
  while (i<first.size()){
      result.push_back(first[i++]);
  }
  
  while (j<second.size()){
      result.push_back(second[j++]);
  }
    
  return result;
}

int main() {
    std::vector<int> vec1 {1, 2};
    std::vector<int> vec2 {11, 12, 13, 14, 15};
    
    auto vec = concatenateVector(vec1, vec2);
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    return 0;
}
