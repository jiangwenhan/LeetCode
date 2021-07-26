#pragma once

#include <vector>
#include "src/include/algorithms/swap.h"

template <typename T>
void next_permute(std::vector<std::vector<T>>& result, std::vector<T>& array, int index) {
  if (index >= array.size()) {
    result.push_back(array);
  }

  for (int i = index; i < array.size(); ++i) {
    swap(array, i, index);
    next_permute(result, array, index + 1);
    swap(array, i, index);
  }
}

template <typename T>
std::vector<std::vector<T>> permutation(std::vector<T>& array) {
  std::vector<std::vector<T>> result;
  next_permute(result, array, 0);
  return result;
}
